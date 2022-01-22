/*stdio(standard IO)   sysio(system IO)    everything is one file;
Standtard IO is preferred;the portability of standard IO is good;
(1)stdio:  FILE --throughout 
        fopen():
                FILE *fopen(const char *path,const char *mode);
                FILE *fdopen(int fd,const char *mode);
                FILE *freopen(const char *path,const char *mode);
        fclose()://close a stream
                int fclose(FILE *fp) 

        fgetc():
                int *fgetc(FILE *stream);
                char *fgets(char *s,int size ,FILE *stream);
                int getc(FILE *stream)
                int getchar(void);
                char *gets(char *s)(notice :there is a bug.)
                int ungetc(int c,FILE *stream)
        fputc():
                int fputc(int c,FILE *stream);
        fgets()
        fputs():
                int fputs(const char *s,FILE *stream);
        fread():binary stream input/output    ;return the number of items successfully read or written.
                size_t fread(void *ptr,size_t size,size_t nmemb,FILE *stream);
        fwrite()
                size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE *stream);

        printf():
                int printf(const char *format,...);
                int fprintf(FILE *stream,const char *format,...);
                int sprintf(char *str,const char *format,...);
                int snprintf(char *str,size_t size,const char *format,...);
        scanf()

        fseek():
                int fseek(FILE *stream,long offset,int whence);
                                offset is type(int),whence --SEEK_SET,SEEK_CUR,SEEK_END
                long ftell(FILE *stream);//return the number of bytes in the file.
                void rewind(FILE *stream);//function 
        ftell()
        rewind()

        fflush()//flush buffer.

        getline():
                ssize_t getline(char **lineptr,size_t *n,FILE *stream)
(2)void perror(const char *s);//Print a system error message.
char *strerror(int errnum);the header file is <string.h>
(3)Tempfile  1,How not to conflict.2,Destroy in time.
        char *tmpnam(char *s)//create a name for a temporary file
        FILE *tempfile(void);//create a tempporary file
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
/*Example_1
int main()
{
        FILE *fp;
        fp=fopen("tmp","r");
        if(fp==NULL)
        {               //->the first form of reporting an error
                // fprintf(stderr,"fopen() failed! errno =%d\n",errno);
                // exit(1);
                        //->the second form of reporting an error
                //perror("fopen()");
                        //the third form of reporting an error
                fprintf(stderr,"fopen():%s/n",strerror(errno));
        }
        puts("ok!");
        fclose(fp);

        exit(0);
}*/
/*Example_2
#define BUFSIZE
int main(int argc,char *argv[])
{
        int n=0;
        char *buf[BUFSIZE];
        FILE *fps,*fpd;
        if(argc<3)
        {
                fprintf(stderr,"Usage:%s <src_file> <dest_file>\n",errno);
                exit(1);
        }
        fps=fopen(argv[1],"r");
        if(fps==NULL)
        {
                perror("fopen()");
                exit(1);
        }
        fpd=fopen(argv[2],"w");
        if(fpd==NULL)
        {
                fclose(fps);
                perror("fopen()");
                exit(1);
        }

        while(1)
        {
              int ch=fgetc(fps); 
              if(ch==EOF)
                break;
              fputc(ch,fpd);
        }
        
//the second form 
        while((n=fread(buf,1,BUFSIZE,fps))>0)
                fwrite(buf,1,n.fpd);
        fclose(fpd);
        fclose(fps);

        exit(0);
}*/
/*//counting bytes
int main(int argc,char *argv[])
{
        FILE *fp;
        int count=0;
        // if(argc<2)
        // {
        //         fprintf(stderr,"Usage...\n");
        //         exit(1);
        // }
        fp = fopen("tmp","r");
        if(fp==NULL)
        {
                perror("fopen()");
                exit(1);
        }
        while(fgetc(fp)!=EOF)
        {
                count++;
        }
        printf("count=%d\n",count);
        fclose(fp);

        exit(0);
}*/
/*//some example about of printf
int main()
{
        char buf[1024];
        int year=2012,month=1,day=1;
        sprintf(buf,"%d-%d-%d\n",year,month,day);//write the contents to buf;
        puts(buf);//output the contents of buf;

        exit(0);

}*/
/*the application of getline*/
/*int main()
{
        FILE *fp;
        char *linebuf;
        size_t linesize;
        fp=fopen("tmp","r");
        if(fp==NULL)
        {
                perror("fopen()");
                exit(0);
        }
        linebuf=NULL;//note here :Initialize 
        linesize=0;
        while(1)
        {
                if(getline(&linebuf,&linesize,fp)<0)//Note the use of secondary  pointers here;
                        break;
                printf("%d\n",strlen(linebuf));
                printf("%d\n",linesize);
        }
        fclose(fp);
        exit(0);
}*/

