#include<stdio.h>
#include<stdlib.h>
int N=0;
int a[100]={0};
int count=0;
void init_arr(int n)
{
	int i=0;
	for (i=0;i<n;i++)
	{
		a[i]=i+1;
	}
}
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void permutation(int * a, int l, int r)
{
	int i;
	if (l==r)
	{
		// print arr;
		int i;
		for(i=0;i<N;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		count++;
	}
	else
	{
		for (i=l;i<=r;i++)
		{
			//swap(i)
			swap(a+l,a+i);
			permutation(a, l+1, r);
			//swap back
			swap(a+l,a+i);
		}
	}
}
int main(int argc,char * argv[])
{
	if (argc==2)
	{
		char *endptr;
    	N = strtol(argv[1], &endptr, 10);
		init_arr(N);
		permutation(a,0,N-1);
		printf("total %d\n",count);
	}
	else
	{
		printf("error!\n");
	}
	
	return 0;
}
