#include <stdio.h>
#include <conio.h>

int main() {
	int i = 5, j = 10;
	int *ptr;
	int **pptr;
	ptr = &i;
	pptr = &ptr;
	
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory i : %d", &i);
	printf("\nMemory ptr = i : %d", ptr);
	printf("\nptr : %d", *ptr);
	printf("\n\nMemori ptr : %d", &ptr);
	printf("\nMemory pptr = ptr : %d", pptr);
	printf("\npptr : %d", **pptr);
//	
//	*ptr + 1;
//	printf("\n\nptr + 1");
//	printf("\n\n i = %d, j = %d", i, j);
//	printf("\nMemory i : %d", &i);
//	printf("\nMemory ptr = i : %d", ptr);
//	printf("\nptr : %d", *ptr);
//	printf("\n\nMemori ptr : %d", &ptr);
//	printf("\nMemory pptr = ptr : %d", pptr);
//	printf("\npptr : %d", **pptr);
//	
//	*ptr - 1;
//	printf("\n\nptr - 1");
//	printf("\n\n i = %d, j = %d", i, j);
//	printf("\nMemory i : %d", &i);
//	printf("\nMemory ptr = i : %d", ptr);
//	printf("\nptr : %d", *ptr);
//	printf("\n\nMemori ptr : %d", &ptr);
//	printf("\nMemory pptr = ptr : %d", pptr);
//	printf("\npptr : %d", **pptr);
//	
//	*ptr * 2;
//	printf("\n\nptr * 2");
//	printf("\n\n i = %d, j = %d", i, j);
//	printf("\nMemory i : %d", &i);
//	printf("\nMemory ptr = i : %d", ptr);
//	printf("\nptr : %d", *ptr);
//	printf("\n\nMemori ptr : %d", &ptr);
//	printf("\nMemory pptr = ptr : %d", pptr);
//	printf("\npptr : %d", **pptr);
//	
//	*ptr / 2;
//	printf("\n\nptr / 2");
//	printf("\n\n i = %d, j = %d", i, j);
//	printf("\nMemory i : %d", &i);
//	printf("\nMemory ptr = i : %d", ptr);
//	printf("\nptr : %d", *ptr);
//	printf("\n\nMemori ptr : %d", &ptr);
//	printf("\nMemory pptr = ptr : %d", pptr);
//	printf("\npptr : %d", **pptr);

*ptr = 3;
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory ptr = 3 : %d", ptr);
	printf("\nptr : %d", *ptr);
	printf("\npptr : %d", **pptr);
	
	**pptr = 7;
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory pptr = 7 : %d(pptr = ptr)", pptr);
	printf("\nptr : %d", *ptr);
	printf("\npptr : %d", **pptr);
	
	ptr = &j;
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory ptr = &j : %d(ptr)", ptr);
	printf("\nptr : %d", *ptr);
	printf("\npptr : %d", **pptr);
	
	**pptr = 9;
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory pptr = 9 : %d(pptr = ptr)", pptr);
	printf("\nptr : %d", *ptr);
	printf("\npptr : %d", **pptr);
	
	*pptr = &i;
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory *pptr = &i : %d(*pptr = ptr)", *pptr);
	printf("\nptr : %d", *ptr);
	printf("\npptr : %d", **pptr);
	
	*ptr = -2;
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory ptr = -2 : %d", ptr);
	printf("\nptr : %d", *ptr);
	printf("\npptr : %d", **pptr);
	
	printf("\n\n--------------------------------------------------\n\n");
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory i : %x", &i);
	printf("\nMemory ptr = i : %x", ptr);
	printf("\nptr : %d", *ptr);
	printf("\n\nMemori ptr : %x", &ptr);
	printf("\nMemory pptr = ptr : %x", pptr);
	printf("\npptr : %d", **pptr);
	
	ptr + 1;
	printf("\n\nptr + 1 = %x", ptr + 1);
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory i : %x", &i);
	printf("\nMemory ptr = i : %x", ptr);
	printf("\nptr : %d", *ptr);
	printf("\n\nMemori ptr : %x", &ptr);
	printf("\nMemory pptr = ptr : %x", pptr);
	printf("\npptr : %d", **pptr);
	
	ptr - 1;
	printf("\n\nptr - 1");
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory i : %d", &i);
	printf("\nMemory ptr = i : %d", ptr);
	printf("\nptr : %d", *ptr);
	printf("\n\nMemori ptr : %d", &ptr);
	printf("\nMemory pptr = ptr : %d", pptr);
	printf("\npptr : %d", **pptr);
	
//	ptr * 2;
	printf("\n\nptr * 2");
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory i : %d", &i);
	printf("\nMemory ptr = i : %d", ptr);
	printf("\nptr : %d", *ptr);
	printf("\n\nMemori ptr : %d", &ptr);
	printf("\nMemory pptr = ptr : %d", pptr);
	printf("\npptr : %d", **pptr);
	
//	ptr / 2;
	printf("\n\nptr / 2");
	printf("\n\n i = %d, j = %d", i, j);
	printf("\nMemory i : %d", &i);
	printf("\nMemory ptr = i : %d", ptr);
	printf("\nptr : %d", *ptr);
	printf("\n\nMemori ptr : %d", &ptr);
	printf("\nMemory pptr = ptr : %d", pptr);
	printf("\npptr : %d", **pptr);
	return 0;
}
