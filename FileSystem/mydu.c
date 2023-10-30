#include<stdio.h>
#include<stdlib.h>
int mydu()
{

}

int main(int argc,char ** argv)
{
	if(argc<2)
	{
		fprintf(stderr,"usage\n");
		exit(1);
	}

	printf("mydu=%d",mydu(argv[1]));

	exit(0);
}
