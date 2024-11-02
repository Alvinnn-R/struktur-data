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
    
	struct node *left;
    struct node *right;  
};

typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
// Tugas Doubly Linkedlist
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
                tambahAkhir(&pHead);
                break;
            case 4:
                hapusAwal(&pHead);
                break;
            case 5:
                hapusTengah(&pHead);
                break;
            case 6:
                hapusAkhir(&pHead);
                break;
            case 7:
                pencarianData(pHead);
                break;
            case 8:
                hitungJumlah(pHead);
                break;
            case 9:
                hitungPenjumlahan(pHead);
                break;
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


//========================================================

void tambahAwal(node **pHead) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->left = NULL;
        pNew->right = *pHead;

        if (*pHead != NULL) {
            (*pHead)->left = pNew;
        }

        *pHead = pNew;
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **pHead) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*pHead);
    printf("\n(Gunakan Urutan Maju)");
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *pHead;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->right = pCur->right;
        pNew->left = pCur;

        if (pCur->right != NULL) {
            pCur->right->left = pNew;
        }

        pCur->right = pNew;
    }
}

//========================================================

void tambahAkhir(node **pHead) {
    int bil;
    node *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = NULL;
        pNew->left = NULL;

        if (*pHead == NULL) {
            pNew->left = NULL;
            *pHead = pNew;
        } else {
            pLast = *pHead;
            while (pLast->right != NULL) {
                pLast = pLast->right;
            }
            pLast->right = pNew;
            pNew->left = pLast;
        }
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **pHead) {
    node *pDel;

    if (*pHead == NULL) {
        printf("List kosong\n");
    } else {
        pDel = *pHead;
        *pHead = (*pHead)->right;

        if (*pHead != NULL) {
            (*pHead)->left = NULL;
        }

        free(pDel);
        printf("\nData di awal berhasil dihapus.. (tekan enter)\n");
    }
    getch();
}

//========================================================

void hapusTengah(node **pHead) {
    int data;
    system("cls");
    tranverse(*pHead);
    printf("\n\nMasukkan data yang ingin dihapus di tengah: ");
    scanf("%d", &data);

    node *pCur = *pHead;

    if (*pHead == NULL) {
        printf("\nList kosong\n");
    } else {
        while (pCur != NULL && pCur->data != data) {
            pCur = pCur->right;
        }

        if (pCur == NULL) {
            printf("\nData tidak ditemukan\n");
        } else {
            if (pCur->left != NULL) {
                pCur->left->right = pCur->right;
            } else {
                *pHead = pCur->right;
            }

            if (pCur->right != NULL) {
                pCur->right->left = pCur->left;
            }

            free(pCur);
            printf("\nData di tengah berhasil dihapus.. (tekan enter)\n");
        }
    }
    getch();
}

//========================================================

void hapusAkhir(node **pHead) {
    node *pCur, *pLast;

    if (*pHead == NULL) {
        printf("List kosong\n");
    } else if ((*pHead)->right == NULL) {
        free(*pHead);
        *pHead = NULL;
    } else {
        pLast = *pHead;
        while (pLast->right != NULL) {
            pLast = pLast->right;
        }

        pCur = pLast->left;
        pCur->right = NULL;
        free(pLast);
        printf("\nData di akhir berhasil dihapus.. (tekan enter)\n");
    }
    getch();
}

//========================================================

void pencarianData(node *pHead) {
    int data;
    system("cls");
    tranverse(pHead);
    printf("\n\n(Gunakan Urutan Maju)");
    printf("\nMasukkan data yang ingin dicari : ");
    scanf("%d", &data);

    node *pCur = pHead;
    int posisi = 0;
    int found = 0;


    pCur = pHead;

    while (pCur != NULL && pCur->data != data) {
        pCur = pCur->right;
        posisi++;
    }

    if (pCur != NULL)
        found = 1;
    else
        found = 0; 

    if (found) {
        printf("\nUrutan data dimulai dari posisi ke-0");
        printf("\nData ditemukan di posisi ke-%d.. (tekan enter)\n", posisi);
    } else {
        printf("\nData tidak ditemukan.. (tekan enter)\n");
    }
    getch();
}

//========================================================

void hitungJumlah(node *pHead) {
    system("cls");
    tranverse(pHead);
    node *pCur = pHead;
    int jumlah = 0;

    while (pCur != NULL) {
        jumlah++;
        pCur = pCur->right;
    }
    printf("\n\nJumlah data di linked list: %d\n", jumlah);
    getch();
}

//========================================================

void hitungPenjumlahan(node *pHead) {
    system("cls");
    tranverse(pHead);
    node *pCur = pHead;
    int total = 0;

    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->right;
    }
    printf("\n\nTotal penjumlahan data di linked list: %d\n", total);
    getch();
}

void tranverse(node *pHead) {
    node *pWalker;

    system("cls");
    printf("Urutan maju:\n");
    pWalker = pHead;
    while (pWalker != NULL) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->right;  
        printf(" -> ");
    }
    printf("NULL\n");

    pWalker = pHead;
    if (pWalker != NULL) {
        while (pWalker->right != NULL) {
            pWalker = pWalker->right;
        }

        printf("Urutan mundur:\n");
        while (pWalker != NULL) {
            printf("%d\t", pWalker->data);
            pWalker = pWalker->left;
            printf(" <- ");
        }
        printf("NULL\n");
    }
}

//========================================================
