#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Circular Linkedlist ETS Struktur Data
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
void tambahMahasiswaTengah(mahasiswa **head, int *count);
void hapusMahasiswa(mahasiswa **head);
void tranverse(mahasiswa *head);
void pisahLingkaran(mahasiswa *head);
void tranverseLaki(mahasiswa *head);
void tranversePerempuan(mahasiswa *head);

int main() {
    mahasiswa *head = NULL;
    int pilih, count = 0;

    do {
        system("cls");
        printf("Menu:\n");
        printf("1. Tambah mahasiswa (Bebas dan Cindy yg hanya bergandeng dengan siswi)\n");
        printf("2. Tambah mahasiswa khusus tengah (Irsyad dan Arsyad)\n");
        printf("3. Hapus mahasiswa\n");
        printf("4. Pisah Lingkaran (Laki & Perempuan)\n");
        printf("5. Tampilkan Semua Mahasiswa\n");
        printf("6. Tampilkan Mahasiswa Laki-laki\n");
        printf("7. Tampilkan Mahasiswa Perempuan\n");
        printf("Masukkan pilihan (tekan selain 1 - 7 untuk keluar): ");
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
                if (count < 19) {
                    tambahMahasiswaTengah(&head, &count);
                } else {
                    printf("Lingkaran penuh atau tidak cukup ruang untuk Irsyad dan Arsyad!\n");
                    getch();
                }
                break;
            case 3:
                hapusMahasiswa(&head);
                if (count > 0) count--;
                break;
            case 4:
                pisahLingkaran(head);
                break;
            case 5:
                tranverse(head);
                getch();
                break;
            case 6:
                tranverseLaki(head);
                getch();
                break;
            case 7:
                tranversePerempuan(head);
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
    mahasiswa *pNew, *pLast;

    system("cls");
    printf("Masukkan nama mahasiswa: ");
    scanf(" %[^\n]%*c", nama);

    // Cek untuk Cindy
    if (strcmp(nama, "Cindy") == 0 && (*count == 0 || (*head)->jenisKelamin == 'L')) {
        printf("Cindy hanya ingin bergandengan dengan sesama mahasiswi!\n");
        getch();
        return;
    }

    printf("Masukkan jenis kelamin mahasiswa (L/P): ");
    scanf(" %c", &jenisKelamin);
    
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

    pNew = (mahasiswa *)malloc(sizeof(mahasiswa));
    
    if (pNew != NULL) {
        strcpy(pNew->nama, nama);
        pNew->jenisKelamin = jenisKelamin;

        if (*head == NULL) {
            pNew->next = pNew; // Circular linked list
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            pNew->next = *head;
            pLast->next = pNew;
        }
        (*count)++;
        printf("Mahasiswa %s berhasil ditambahkan\n", nama);
    } else {
        printf("Alokasi memori gagal\n");
    }
    getch();
}

void tambahMahasiswaTengah(mahasiswa **head, int *count) {
    char nama[30];
    mahasiswa *pIrsyad, *pArsyad, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nama mahasiswa setelah mana Irsyad dan Arsyad ingin ditambahkan: ");
    scanf(" %[^\n]%*c", nama);

    if (*head == NULL) {
        printf("Lingkaran kosong, tidak dapat menambahkan.\n");
        getch();
        return;
    }

    pCur = *head;
    do {
        if (strcmp(pCur->nama, nama) == 0) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    if (strcmp(pCur->nama, nama) != 0) {
        printf("Nama %s tidak ditemukan dalam lingkaran.\n", nama);
        getch();
        return;
    }

    pIrsyad = (mahasiswa *)malloc(sizeof(mahasiswa));
    if (pIrsyad == NULL) {
        printf("Alokasi memori gagal untuk Irsyad\n");
        return;
    }
    strcpy(pIrsyad->nama, "Irsyad");
    pIrsyad->jenisKelamin = 'L';

    pArsyad = (mahasiswa *)malloc(sizeof(mahasiswa));
    if (pArsyad == NULL) {
        printf("Alokasi memori gagal untuk Arsyad\n");
        free(pIrsyad);
        return;
    }
    strcpy(pArsyad->nama, "Arsyad");
    pArsyad->jenisKelamin = 'L';

    pArsyad->next = pCur->next;
    pCur->next = pIrsyad;
    pIrsyad->next = pArsyad;

    *count += 2;
    printf("Mahasiswa Irsyad dan Arsyad berhasil ditambahkan setelah %s\n", nama);
    getch();
}

void hapusMahasiswa(mahasiswa **head) {
    char nama[30];
    mahasiswa *pCur, *pPre;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nama yang ingin dihapus: ");
    scanf(" %[^\n]%*c", nama);

    if (*head == NULL) {
        printf("List kosong\n");
        getch();
        return;
    }

    pCur = *head;
    pPre = NULL;

    do {
        if (strcmp(pCur->nama, nama) == 0) break;
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    if (strcmp(pCur->nama, nama) != 0) {
        printf("Mahasiswa tidak ditemukan\n");
    } else {
        if (pCur == *head) {
            if (pCur->next == *head) {
                *head = NULL;
            } else {
                pPre = *head;
                while (pPre->next != *head) {
                    pPre = pPre->next;
                }
                *head = (*head)->next;
                pPre->next = *head;
            }
        } else {
            pPre->next = pCur->next;
        }
        free(pCur);
        printf("Mahasiswa berhasil dihapus\n");
    }
    getch();
}

void tranverse(mahasiswa *head) {
    mahasiswa *pWalker;

    system("cls");
    if (head != NULL) {
        pWalker = head;
        do {
            printf("Nama: %s, Kelamin: %c\n", pWalker->nama, pWalker->jenisKelamin);
            pWalker = pWalker->next;
        } while (pWalker != head);
    } else {
        printf("Lingkaran kosong\n");
    }
        printf("Head/Melingkar(kembali ke %s)", pWalker->nama);
}


void pisahLingkaran(mahasiswa *head) {
    mahasiswa *mahasiswaHead = NULL, *mahasiswaTail = NULL;
    mahasiswa *mahasiswiHead = NULL, *mahasiswiTail = NULL;
    mahasiswa *pCur = head, *pNext;

    if (head == NULL) {
        printf("Lingkaran kosong!\n");
        getch();
        return;
    }

    do {
        pNext = pCur->next;
        
        if (pCur->jenisKelamin == 'L') {
            if (mahasiswaHead == NULL) {
                mahasiswaHead = pCur;
                mahasiswaTail = pCur;
            } else {
                mahasiswaTail->next = pCur;
                mahasiswaTail = pCur;
            }
        } else {
            if (mahasiswiHead == NULL) {
                mahasiswiHead = pCur;
                mahasiswiTail = pCur;
            } else {
                mahasiswiTail->next = pCur;
                mahasiswiTail = pCur;
            }
        }
        pCur = pNext;
    } while (pCur != head);

    if (mahasiswaTail != NULL) mahasiswaTail->next = mahasiswaHead;
    if (mahasiswiTail != NULL) mahasiswiTail->next = mahasiswiHead;

    printf("\nLingkaran Mahasiswa (Laki-laki):\n");
    if (mahasiswaHead != NULL) {
        tranverseLaki(mahasiswaHead);
    } else {
        printf("Tidak ada mahasiswa laki-laki\n");
    }

    printf("\nLingkaran Mahasiswi (Perempuan):\n");
    if (mahasiswiHead != NULL) {
        tranversePerempuan(mahasiswiHead);
    } else {
        printf("Tidak ada mahasiswi perempuan\n");
    }
    getch();
}

void tranverseLaki(mahasiswa *head) {
    mahasiswa *pWalker = head;
    do {
        printf("Nama: %s, Kelamin: %c\n", pWalker->nama, pWalker->jenisKelamin);
        pWalker = pWalker->next;
    } while (pWalker != head);
}

void tranversePerempuan(mahasiswa *head) {
    mahasiswa *pWalker = head;
    do {
        printf("Nama: %s, Kelamin: %c\n", pWalker->nama, pWalker->jenisKelamin);
        pWalker = pWalker->next;
    } while (pWalker != head);
}

