#include <stdio.h>

int kuadrat(int kud){
	return kud * kud;
}

int main() {
	printf("\nContoh Pointer");
//	No pointer
	int a = 5;
	int b = a;
	int c = b;
	int d = c;
	
	printf("a = %p", &a);
	printf("\nb(a) = %p", &b);
	printf("\nc(b) = %p", &c);
	printf("\nd(c) = %p", &d);
	
//	Pointer
	int e;
	
	e = 5;
	int *f = &e;
	int *g = &f;
	int	*h = &g;
	
	printf("\ne = %p", &e);
	printf("\nf(e) = %p", f);
	printf("\ng(f) = %p", g);
	printf("\nh(g) = %p", h);
	
	printf("\nLearn Pointer");
	int x = 10;
	printf("\nVar : %d", x);
	printf("\n%d",kuadrat(x));
	printf("\nVar : %d", x);
	return 0;
}
