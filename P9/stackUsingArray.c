#include <stdio.h>
#define MAX 5

// Operasi stack using array
// push, pop, top, isFull, isEmpty, makeEmpty

int stackArr[MAX];
int top = 0;

int isFull(){
	if (top == MAX){
		return 1;
	} else{
		return 0;
	}
}

int isEmpty(){
	if(top == 0){
		return 1;
	}else{
		return 0;
	}
}

void push(int data){
	if(isFull()){
		printf("Stack penuh\n");
	} else{
		stackArr[top] = data;
		top++;
	}
}

void pop(){
	if(isEmpty()){
		printf("Stack kosong\n");
	} else{
		stackArr[top-1] = NULL;
		top--;
	}
}

int makeEmpty(){
	if(isEmpty()){
		printf("Stack sudah kosong\n");
	} else{
		top=0;
	}
}

void stackTop() {
    if (!isEmpty()) {
        printf("\nStack Top: %d\n", stackArr[top-1]);
    } else {
        printf("Stack kosong\n");
    }
}

void display(){
	if(isEmpty()){
		printf("Stack kosong\n");
	} else{
		printf("\nData Stack Array:\n");
		for(int i = top; i >= 0; i--){
			if(stackArr[i] != NULL){
				printf("Data: %d\n", stackArr[i]);
			}
		}
	}
}


int main() {
	
	display();
	push(1);
	push(3);
	push(5);
	display();
	pop();
	display();
	pop();
	display();
	push(3);
	push(5);
	push(7);
	push(9);
	display();
	stackTop();
	push(11);
	makeEmpty();
	display();
	
	return 0;
}
