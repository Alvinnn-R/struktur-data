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
// Tugas Linkedlist
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
	    printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
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
			    pilih = 'q';
			    break;
		}
		
	} while (pilih != 'q');
  
  return 0;
}

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
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
    node *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pLast = *head;
            while (pLast->next != NULL) {
                pLast = pLast->next;
            }
            pLast->next = pNew;
        }
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
    } else {
        pDel = *head;
        *head = (*head)->next;
        free(pDel);
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
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        pCur = *head;
        pPre = NULL;
        while (pCur->next != NULL) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = NULL;
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

    while (pCur != NULL) {
        if (pCur->data == data) {
        	printf("\nurutan data dimulai dari posisi ke-0");
            printf("\nData ditemukan di posisi ke-%d.. (tekan enter)\n", posisi);
            getch();
            return;
        }
        pCur = pCur->next;
        posisi++;
    }
    printf("\nData tidak ditemukan.. (tekan enter)\n");
    getch();
}

//========================================================

void hitungJumlah(node *head) {
    system("cls");
    tranverse(head);
    node *pCur = head;
    int jumlah = 0;

    while (pCur != NULL) {
        jumlah++;
        pCur = pCur->next;
    }
    printf("\n\nJumlah data di linked list: %d\n", jumlah);
    getch();
}

//========================================================

void hitungPenjumlahan(node *head) {
    system("cls");
    tranverse(head);
    node *pCur = head;
    int total = 0;

    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }
    printf("\n\nTotal penjumlahan data di linked list: %d\n", total);
    getch();
}

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
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
