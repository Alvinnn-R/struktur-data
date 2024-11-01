#include <stdio.h>

struct barang {
	char nama[50];
	int ukuran;
	char supplier[50];
	int qty;
	bool isAvailable;
};

typedef struct barang Barang;

int main() {
	int input;
	
//	Barang sepatu;
	Barang sepatu = {"Adidas", 39, "Pt. Adidas Ind", 50, 1};
	
//	printf("Masukkan Nama : ");
//  	gets(sepatu.nama);
//  	printf("Masukkan Supplier : ");
//  	gets(sepatu.supplier);
//  	printf("Masukkan Ukuran : ");
//  	scanf("%d", &sepatu.ukuran);
//  	printf("Masukkan Qty : ");
//  	scanf("%d", &sepatu.qty);
//  	printf("Masukkan Is Available (1 = true/0 = false): ");
//  	scanf("%d", &sepatu.isAvailable);

	
	printf("\nNama \t\t: %s", sepatu.nama);
	printf("\nUkuran \t\t: %d", sepatu.ukuran);
	printf("\nSupplier \t: %s", sepatu.supplier);
	printf("\nQty \t\t: %d", sepatu.qty);
	printf("\nIs Available \t: %d (1=true/2=false)", sepatu.isAvailable);
}
