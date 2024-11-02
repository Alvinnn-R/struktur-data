#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Circular Linkedlist
/*Keterangan:
-- Tambah data satu per satu mahasiswa
- max 20 orang
- cindy hanya berdekatan dengan sesama cewek
- irsyad dan arsyad saudara kembar yang tidak mau dipisahkan
-- Hapus mahasiswa yang ingin keluar saya
-- Memisahkan lingkaran mahasiswi dan mahasiswa*/

struct mahasiswa {
	char nama[30];
	char jenisKelamin;
	
	struct mahasiswa *next;
};

typedef struct mahasiswa mahasiswa;

void tambahMahasiswa(mahasiswa **head, int *count);
void hapusMahasiswa(mahasiswa **head);
void tranverse(mahasiswa *head);
void pisahLingkaran(mahasiswa **head);

int main() {
	
	mahasiswa *head;
	int pilih, count = 0;
	
	head = NULL;
	do{
		system("cls");
		printf("masukkan pilihan\n");
		printf("1.  Tambah mahasiswa di awal\n");
		printf("2.  Hapus mahasiswa\n");
		printf("3.  Pisah Lingkaran\n");
		printf("4.  Tranverse\n");
	    printf("MASUKKAN PILIHAN (tekan selain 1 - 4 untuk keluar) : ");
	    fflush(stdin);
		scanf("%d", &pilih);
		
		switch (pilih) {
		    case 1:
		        if (count < 20) {
                    tambahMahasiswa(&head, &count);
                } else {
                    printf("Lingkaran penuh (max 20 orang)!\n");
                    getch();
                }
		        break;
		    case 2:
		        hapusMahasiswa(&head);
		        count--;
		        break;
		    case 3:
				pisahLingkaran(&head);
		        break;
		    case 4:
		    	tranverse(head);
		        getch();
		        break;
		    default:
			    pilih = 0;
			    break;
		}
		
	} while (pilih != 0);
	
	return 0;
}

void tambahMahasiswa(mahasiswa **head, int *count) {
    char nama[30], jenisKelamin;
    mahasiswa *pNew, *pList;

    system("cls");
    fflush(stdin);
    printf("Masukkan nama mahasiswa: ");
	fflush(stdin);
    gets(nama);
    
    // Cek untuk Cindy
    if (strcmp(nama, "Cindy") == 0 && (*count == 0 || (*head)->jenisKelamin == 'L')) {
        printf("Cindy hanya ingin bergandengan dengan sesama mahasiswi!\n");
        getch();
        return;
    }
    
    printf("Masukkan jenis kelamin mahasiswa(L/P): ");
	fflush(stdin);
    scanf("%c", &jenisKelamin);
    
      // Cek untuk Irsyad dan Arsyad
    if ((strcmp(nama, "Irsyad") == 0 || strcmp(nama, "Arsyad") == 0) && *count > 0) {
        if (*head && (strcmp((*head)->nama, "Arsyad") == 0 || strcmp((*head)->nama, "Irsyad") == 0)) {
            printf("Irsyad dan Arsyad tidak boleh dipisahkan!\n");
        } else {
            printf("Saudara kembar harus bersama-sama!\n");
        }
        getch();
        return;
    }
    
    pNew = (mahasiswa*)malloc(sizeof(mahasiswa));

    if (pNew != NULL) {

        strcpy(pNew->nama, nama);
		pNew->jenisKelamin = jenisKelamin;

        if (*head == NULL) {
            pNew->next = pNew;  // Node menunjuk dirinya sendiri jika hanya ada 1 node. (Circular)
            *head = pNew;
        } else {
            pList = *head;
            while (pList->next != *head) {
                pList = pList->next;
            }
            pNew->next = *head;
            *head = pNew;
            pList->next = *head;  // Node terakhir menunjuk ke head. (Circular)
        }
        (*count)++;
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

void hapusMahasiswa(mahasiswa **head) {
    char nama[30];
    
    system("cls");
    tranverse(*head);
    printf("\n\nMasukkan nama yang ingin dihapus: ");
	fflush(stdin);
    gets(nama);

    mahasiswa *pCur, *pPre;
    if (*head == NULL) {
        printf("\nList kosong\n");
    } else {
        pCur = *head;
        pPre = NULL;
		
        while (pCur != NULL && strcmp(pCur->nama, nama) != 0) {
            pPre = pCur;
            pCur = pCur->next;
        }

        if (pCur == NULL) {
            printf("\nMahasiswa tidak ditemukan\n");
        } else {
            if (pPre != NULL) {
                pPre->next = pCur->next;
            } else {
                *head = pCur->next;
            }
            free(pCur);
            printf("\nMahasiswa berhasil dilepas (tekan enter)\n");
        }
    }
    getch();
}

void tranverse(mahasiswa *head) {
    mahasiswa *pWalker;

    system("cls");
    if (head != NULL) {
        pWalker = head;
        do {
            printf("Nama: %s, ", pWalker->nama);
            printf("Kelamin: %c", pWalker->jenisKelamin);
            pWalker = pWalker->next;
            printf(" -> ");
        } while (pWalker != head);
    }
    printf(" Head/Melingkar(kembali ke %s)", pWalker->nama);
}


void pisahLingkaran(mahasiswa **head) {
    mahasiswa *mahasiswaHead = NULL, *mahasiswaTail = NULL;
    mahasiswa *mahasiswiHead = NULL, *mahasiswiTail = NULL;
    mahasiswa *pCur, *pNext;

    if (*head == NULL) {
        printf("Lingkaran kosong!\n");
        return;
    }

    pCur = *head;

    do {
        pNext = pCur->next; // Simpan node berikutnya karena pCur bisa berubah
        
        if (pCur->jenisKelamin == 'L') {
            // Tambahkan ke lingkaran mahasiswa
            if (mahasiswaHead == NULL) {
                mahasiswaHead = pCur;
                mahasiswaTail = pCur;
            } else {
                mahasiswaTail->next = pCur;
                mahasiswaTail = pCur;
            }
        } else {
            // Tambahkan ke lingkaran mahasiswi
            if (mahasiswiHead == NULL) {
                mahasiswiHead = pCur;
                mahasiswiTail = pCur;
            } else {
                mahasiswiTail->next = pCur;
                mahasiswiTail = pCur;
            }
        }
        
        pCur = pNext; // Lanjutkan ke node berikutnya
    } while (pCur != *head);

    // Pastikan circular nature dipertahankan
    if (mahasiswaHead != NULL) {
        mahasiswaTail->next = mahasiswaHead; // Tutup lingkaran mahasiswa
    }
    if (mahasiswiHead != NULL) {
        mahasiswiTail->next = mahasiswiHead; // Tutup lingkaran mahasiswi
    }

    // Tampilkan hasil pemisahan
    if (mahasiswiHead != NULL) {
        printf("\nLingkaran mahasiswi:\n");
        tranverse(mahasiswiHead);
    } else {
        printf("\nTidak ada mahasiswi.\n");
    }

    if (mahasiswaHead != NULL) {
        printf("\nLingkaran mahasiswa:\n");
        tranverse(mahasiswaHead);
    } else {
        printf("\nTidak ada mahasiswa.\n");
    }

    getch();
}
