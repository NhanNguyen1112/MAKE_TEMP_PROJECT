
#include "main.h"

int a;
int b;
int Total;
int Subtraction;

int main(void)
{
	a=1;
	b=2;
	
	Total = Sum(a,b);
	Subtraction = Sub(b,a);
	
	printf("a+b= %d\n", Total);
	printf("b-a= %d\n", Subtraction);
	
	return 0;
}
