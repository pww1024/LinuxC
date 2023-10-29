#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void func(int **p,int n)
{
	*p=malloc(n*sizeof(int));
	if (*p==NULL)
	{
		perror("out of mem");
		exit(1);
	}
	return;
}
int main()
{
	int num=10;
	int *p=NULL;
	func(&p,num);
	
	int i;
	for (i=0;i<num;i++)
		p[i]=i;
	for(i=0;i<num;i++)
		printf("%d ",p[i]);
	printf("\n");	

	free(p);
	
	exit(0);
}
