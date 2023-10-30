#include<stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include<stdlib.h>

int main(int argc,char ** argv)
{
	struct passwd * pwdline;

	if (argc<2)
	{
		fprintf(stderr,"usage..\n");
		exit(1);
	}
	/*
	传入用户id号,返回用户名,
	1000-buntu,0-root,
	cat /etc/passwd
	*/
	pwdline = getpwuid(atoi(argv[1]));
	
	puts(pwdline->pw_name);

	exit(0);
}

