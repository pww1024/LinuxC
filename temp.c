#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char * argv[])
{
	char str[14] = "Hello, world.\n";
	int a[]={1,2,3,4,5,6,7,8,9,10};
	// printf("%s",str);
	printf("%d\n",5[a]);
	char *endptr;
    long long N = strtol(argv[1], &endptr, 10);
	long long num=2001630309;
	printf("my xuehao %lld\n",N*10);

	pid_t pid=fork();
	if(pid==0)
	{
		printf("current %d parent %d \n",getpid(),getppid());
		while(1);
	}
	else if(pid>0)
	{
		printf("parent process\n");
		printf("current %d parent %d \n",getpid(),getppid());
		while(1);
	}

	while (1);
	
	return 0;
}
