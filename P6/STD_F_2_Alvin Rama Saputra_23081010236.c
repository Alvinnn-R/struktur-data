#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// ========================================================
// Nama		: Alvin Rama Saputra
// NPM		: 23081010236
// MatKul	: Struktur Data (F081)
//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
// Tugas Circular Linkedlist
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void pencarianData(node *head);
void hitungJumlah(node *head);
void hitungPenjumlahan(node *head);

//========================================================

int main()
{
	node *head;
	int pilih;
	int cari, data;
	
	head = NULL;
	do{
		system("cls");
		printf("masukkan pilihan\n");
		printf("1.  tambah data di awal\n");
		printf("2.  tambah data di tengah list\n");
		printf("3.  tambah data di akhir\n");
		printf("4.  hapus data di awal\n");
		printf("5.  hapus data di tengah\n");
		printf("6.  hapus data di akhir\n");
		printf("7.  pencarian data\n");
		printf("8.  hitung jumlah data\n");
		printf("9.  hitung penjumlahan data\n");
	    printf("10. cetak isi list\n");
	    printf("MASUKKAN PILIHAN (tekan selain 1 - 10 untuk keluar) : ");
	    fflush(stdin);
		scanf("%d", &pilih);
		
		switch (pilih) {
		    case 1:
		        tambahAwal(&head);
		        break;
		    case 2:
		        tambahData(&head);
		        break;
		    case 3:
		        tambahAkhir(&head);
		        break;
		    case 4:
		        hapusAwal(&head);
		        break;
		    case 5:
		        hapusTengah(&head);
		        break;
		    case 6:
		        hapusAkhir(&head);
		        break;
		    case 7:
		        pencarianData(head);
		        break;
		    case 8:
		        hitungJumlah(head);
		        break;
		    case 9:
		        hitungPenjumlahan(head);
		        break;
		    case 10:
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

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew, *pList;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

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
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nAlokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pList;

    system("cls");
    fflush(stdin);
    tranverse(*head);
    printf("\n\nmasukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            pNew->next = pNew;  // Node menunjuk dirinya sendiri. (Circular)
            *head = pNew;
        } else {
            pList = *head;
            while (pList->next != *head) {
                pList = pList->next;
            }
            pList->next = pNew;
            pNew->next = *head;  // Node terakhir menunjuk ke head. (Circular)
        }
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}


//========================================================

void hapusAwal(node **head) {
    node *pDel, *pList;

    if (*head == NULL) {
        printf("List kosong\n");
    } else {
        pDel = *head;

        if ((*head)->next == *head) {
            // Jika hanya ada satu node
            free(pDel);
            *head = NULL;
        } else {
            pList = *head;
            while (pList->next != *head) {
                pList = pList->next;
            }
            *head = (*head)->next;
            pList->next = *head;  // Node terakhir menunjuk ke head yang baru. (Circular)
            free(pDel);
        }
        printf("\nData di awal berhasil dihapus.. (tekan enter)\n");
    }
    getch();
}


//========================================================

void hapusTengah(node **head) {
    int data;
    system("cls");
    tranverse(*head);
    printf("\n\nMasukkan data yang ingin dihapus di tengah: ");
    scanf("%d", &data);

    node *pCur, *pPre;
    if (*head == NULL) {
        printf("\nList kosong\n");
    } else {
        pCur = *head;
        pPre = NULL;

        while (pCur != NULL && pCur->data != data) {
            pPre = pCur;
            pCur = pCur->next;
        }

        if (pCur == NULL) {
            printf("\nData tidak ditemukan\n");
        } else {
            if (pPre != NULL) {
                pPre->next = pCur->next;
            } else {
                *head = pCur->next;
            }
            free(pCur);
            printf("\nData di tengah berhasil dihapus.. (tekan enter)\n");
        }
    }
    getch();
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pPre;

    if (*head == NULL) {
        printf("List kosong\n");
    } else if ((*head)->next == *head) {
        // Jika hanya ada satu node
        free(*head);
        *head = NULL;
    } else {
        pCur = *head;
        pPre = NULL;

        while (pCur->next != *head) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = *head;  // Node sebelum terakhir menunjuk ke head. (Circular)
        free(pCur);
        printf("\nData di akhir berhasil dihapus.. (tekan enter)\n");
    }
    getch();
}


//========================================================

void pencarianData(node *head) {
    int data;
    system("cls");
    tranverse(head);
    printf("\n\nMasukkan data yang ingin dicari : ");
    scanf("%d", &data);

    node *pCur = head;
    int posisi = 0;
    int ditemukan = 0;

    if (head != NULL) {
        do {
            if (pCur->data == data) {
                printf("\nUrutan data dimulai dari posisi ke-0");
                printf("\nData ditemukan di posisi ke-%d.. (tekan enter untuk melanjutkan)\n", posisi);
                ditemukan = 1;
                break;
            }
            pCur = pCur->next;
            posisi++;
        } while (pCur != head);

        if (!ditemukan) {
            printf("\nData tidak ditemukan.. (tekan enter untuk melanjutkan)\n");
        }
    } else {
        printf("\nList kosong.. (tekan enter untuk melanjutkan)\n");
    }

    getch();
}

//========================================================

void hitungJumlah(node *head) {
    system("cls");
    tranverse(head);
    node *pCur = head;
    int jumlah = 0;

    if (head != NULL) {
        do {
            jumlah++;
            pCur = pCur->next;
        } while (pCur != head);
    }
    printf("\n\nJumlah data di Circular Linked List: %d\n", jumlah);
    getch();
}

//========================================================

void hitungPenjumlahan(node *head) {
    system("cls");
    tranverse(head);
    node *pCur = head;
    int total = 0;

    if (head != NULL) {
        do {
            total += pCur->data;
            pCur = pCur->next;
        } while (pCur != head);
    }
    printf("\n\nTotal penjumlahan data di Circular Linked List: %d\n", total);
    getch();
}

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    if (head != NULL) {
        pWalker = head;
        do {
            printf("%d\t", pWalker->data);
            pWalker = pWalker->next;
            printf(" -> ");
        } while (pWalker != head);
    }
    printf(" Head");
}


//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================
