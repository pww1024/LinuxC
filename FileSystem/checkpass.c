/*
输入用户名与密码,检查正确与否
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<shadow.h>
#include <unistd.h> 
#include <string.h>
#include <crypt.h>

int main(int argc,char **argv)
{
    char * input_pass, * crypted_pass;
    struct spwd *shadow_line;

	if (argc<2)
	{
		fprintf(stderr,"usage...\n");
		exit(1);
	}

    input_pass = getpass("PassWord:");

    shadow_line = getspnam(argv[1]);
    
    crypted_pass = crypt(input_pass,shadow_line->sp_pwdp);
    // crypt只认得第三个$之前的内容

    if (strcmp(shadow_line->sp_pwdp,crypted_pass)==0)
        puts("ok");
    else
        {
            puts("false");
        }

	exit(0);

}

