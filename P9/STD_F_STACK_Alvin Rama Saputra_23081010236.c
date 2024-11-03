#include <stdio.h>
#include <stdlib.h>

#define MAX 5
// ========================================================
// Nama		: Alvin Rama Saputra
// NPM		: 23081010236
// MatKul	: Struktur Data (F081)
//========================================================

// Tugas Stack menggunakan Linked List
/* Operasi stack: Push Stack, Pop Stack, Stack Top, Empty Stack (isEmpty), Full Stack (isFull), Stack Count, Destroy Stack*/

struct node {
	int data;
	struct node *next;
};

typedef struct node node;

struct stack {
	int count;
	struct node *top;
};

typedef struct stack stack;

stack* createStack();
void push(stack *stack);
void pop(stack *stack);
void stackTop(stack *stack);
int isEmpty(stack *stack);
int isFull(stack *stack);
void stackCount(stack *stack);
void destroyStack(stack *stack);
void displayStack(stack *stack);

int main(){
	stack *myStack = createStack();
	int pilih;
	
	do {
		system("cls");
        printf("\nMasukan pilihan menu:\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Stack Top (Lihat data teratas)\n");
        printf("4. Stack Count (Menjumlah seluruh data)\n");
        printf("5. Display Stack (Tampilkan stack)\n");
        printf("6. Destroy Stack (Hapus semua data)\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                push(myStack);
                break;
            case 2:
                pop(myStack);
                break;
            case 3:
            	stackTop(myStack);
                break;
            case 4:
                stackCount(myStack);
                break;
            case 5:
                displayStack(myStack);
            	break;
           	case 6:
                destroyStack(myStack);
                break;
            case 7:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilih != 7);
	
	return 0;
}

//========================================================

stack* createStack() {
    stack *newStack = (stack *)malloc(sizeof(stack));
    if (newStack != NULL) {
        newStack->count = 0;
        newStack->top = NULL;
    }
    return newStack;
}

void push(stack *stack){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("Masukkan data : ");
  fflush(stdin);
  scanf("%d", &bil);
  
  pNew = (node *)malloc(sizeof(node));

  	if (pNew != NULL){
	  	if(isFull(stack)){
	  		printf("\nStack penuh! Tidak bisa menambahkan data lagi. (Enter)");
	  		free(pNew);
		} else{
			pNew->data = bil;
		    pNew->next = stack->top;
		      
			stack->top = pNew;
		    stack->count++;
		    printf("\nData %d berhasil ditambahkan ke stack. (Enter)", bil);
		} 
  	} else{
      printf("\nAlokasi memori gagal (Enter)");
  	}
  	getch();
}

void pop(stack *stack) {
    if (isEmpty(stack)) {
        printf("\nStack kosong! Tidak ada data yang bisa dihapus. (Enter)");
    } else {
        node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->count--;
        printf("\nData teratas berhasil dihapus. (Enter)");
    }
    getch();
}

void stackTop(stack *stack) {
    if (isEmpty(stack)) {
    	printf("\nStack kosong! Tidak ada data yang bisa ditampilkan.\n");
    } else {
    	printf("\nData teratas pada stack: %d\n", stack->top->data);
    }
    printf("\n(Enter)");
    getch();
}

void displayStack(stack *stack) {
    node *current = stack->top;
     if (current == NULL) {
        printf("\nStack kosong! Tidak ada data yang bisa ditampilkan.\n");
    } else {
	    printf("\nIsi stack: \n\n");
	    while (current != NULL) {
	        printf(" %d\n", current->data);
	        current = current->next;
	    }
	}
	printf("\n(Enter)");
	getch();
}

int isEmpty(stack *stack) {
	if(stack->top == NULL){
		return 1;
	}else{
		return 0;
	}
}

int isFull(stack *stack) {
	if (stack->count == MAX){
		return 1;
	} else{
		return 0;
	}
}

void stackCount(stack *stack) {
    printf("Jumlah data saat ini di stack: %d. (Enter)\n", stack->count);
    getch();
}

void destroyStack(stack *stack) {
    while (!isEmpty(stack)) {
    	node *temp = stack->top;
    	stack->top = stack->top->next;
        free(temp);
    }
    stack->count = 0;
    printf("\nSeluruh data dalam stack telah dikosongkan. (Enter)");
    getch();
}
