#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX2(a,b) ({typeof(a) A=(a),B=(b);A>B?A:B;})
int main()
{
	int i=5,j=3;
	printf("i=%d,\tj=%d\n",i,j);
	printf("%d\n",MAX2(i++,j++));
	printf("i=%d,\tj=%d\n",i,j);
	exit(0);
}
