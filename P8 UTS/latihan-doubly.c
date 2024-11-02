#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int data;

	struct node *right;
	struct node *left;
};

typedef struct node node;

void tambahAwal(node **pHead);
void tambahTengah(node **pHead);
void tranverse(node *pHead);

int main(){
	node *pHead = NULL;

	int pilih;
    int cari, data;

    do{
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1.  Tambah data di awal\n");
        printf("2.  Tambah data di tengah list\n");
        printf("3.  Tambah data di akhir\n");
        printf("4.  Hapus data di awal\n");
        printf("5.  Hapus data di tengah\n");
        printf("6.  Hapus data di akhir\n");
        printf("7.  Pencarian data\n");
        printf("8.  Hitung jumlah data\n");
        printf("9.  Hitung penjumlahan data\n");
        printf("10. Cetak isi list\n");
        printf("11. Keluar\n");
        printf("MASUKKAN PILIHAN (tekan 11 untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                tambahAwal(&pHead);
                break;
            case 2:
                tambahData(&pHead);
                break;
            case 3:
//                tambahAkhir(&pHead);
//                break;
//            case 4:
//                hapusAwal(&pHead);
//                break;
//            case 5:
//                hapusTengah(&pHead);
//                break;
//            case 6:
//                hapusAkhir(&pHead);
//                break;
//            case 7:
//                pencarianData(pHead);
//                break;
//            case 8:
//                hitungJumlah(pHead);
//                break;
//            case 9:
//                hitungPenjumlahan(pHead);
//                break;
            case 10:
                tranverse(pHead);
                getch();
                break;
            default:
                pilih = 11;
                break;
        }

    } while (pilih != 11);

	return 0;
}

void tambahAwal(node **pHead){
	node *pNew;
	int data;

	printf("Masukan data: ");
	scanf("%d", &data);

	pNew = (node*)malloc(sizeof(node));

	pNew->data = data;
	pNew->left = NULL;
	pNew->right = *pHead;

	*pHead = pNew;

}

void tambahTengah(node **pHead){
	int pos, data;
	node *pNew;
	node *pCur;
	
	tranverse(pHead);
	
	printf("Masukan data sesudah posisi: ");
	scanf("%d", &pos);
	printf("Masukan data: ");
	scanf("%d", &data);
	
	pNew = (node *)malloc(sizeof(node));
	
	pCur = pHead;
	while(pCur->data != pos){
		pCur = pCur->right;
	}
	
	pNew->data = data;
	pNew->right = pCur->right;
	pNew->left = pCur->left;
	pCur->right = pNew;
	
	
}

void tranverse(node *pHead){
	node *pWalker;
	system("cls");
	pWalker = pHead;
	while(pWalker != NULL){
		printf("%d", pWalker->data);
		pWalker = pWalker->right;
		printf(" -> ");
	}
	printf("NULL");
}
