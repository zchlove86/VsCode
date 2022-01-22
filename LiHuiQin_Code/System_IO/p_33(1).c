#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<pwd.h>
int main(int argc,char *argv[])
{
    struct passwd *pwdline;
    if(argc<2)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    pwdline=getpwuid(atoi(argv[1]));
    puts(pwdline->pw_passwd);

    exit(0);
}