#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc,char **argv)
{
	if (argc<2)
	{
		fprintf(stderr,"usage...\n");
		exit(1);
	}

	FILE *fp = fopen(argv[1],"r");

	if(fp==NULL)
	{
		perror("fopen()");
		exit(1);
	}

	fseek(fp,0L,SEEK_END);

	printf("file size=%ld\n",ftell(fp));

	exit(0);

}

