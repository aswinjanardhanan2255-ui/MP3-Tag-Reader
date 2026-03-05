#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "header.h"
int main()
{
    printf("-v --> view\n");
    printf("-e --> edit\n");
    printf("-h --> help\n");
    char file_name[100],operation[3];
    printf("Enter the operation:");
    scanf(" %[^\n]",operation);

if(strcmp(operation,"-v")==0)
{
        printf("Enter the file name:");
        scanf(" %[^\n]",file_name);
        printf("\n");
        FILE *fp;
        if((fp=fopen(file_name,"r"))==NULL)
        {
            fprintf(stderr,"File not found\n");
            return 0;
        }
        char buffer[4];
        fread(buffer,3,1,fp);
        buffer[3]='\0';
        if((strcmp(buffer,"ID3"))!=0)
        {
            fprintf(stderr,"File is not mp3 Format\n");
            return 0;
        }
        view(fp);
        fclose(fp);
}
else if(strcmp(operation,"-e")==0){
    char tag[5],info[100];
    printf("Enter the tag:");
    scanf(" %[^\n]",tag);

    printf("Enter the new data:");
    scanf(" %[^\n]",info);

    printf("Enter the file name:");
    scanf(" %[^\n]",file_name);

    printf("\n");
    FILE *fp;
    if((fp=fopen(file_name,"r"))==NULL)
    {
        fprintf(stderr,"File not found\n");
        return 0;
    }
    char buffer[4];
    fread(buffer,3,1,fp);
    buffer[3]='\0';
    if((strcmp(buffer,"ID3"))!=0)
    {
        fprintf(stderr,"File is not mp3 Format\n");
        return 0;
    }

    if(strcmp(tag,"-t")==0)
        strcpy(tag,"TIT2");
    else if(strcmp(tag,"-y")==0)
        strcpy(tag,"TYER");
    else if(strcmp(tag,"-a")==0)
        strcpy(tag,"TPE1");
    else if(strcmp(tag,"-A")==0)
        strcpy(tag,"TALB");
    else if(strcmp(tag,"-g")==0)
        strcpy(tag,"TCON");
    else if(strcmp(tag,"-c")==0)
        strcpy(tag,"COMM");

    edit(fp,tag,info,file_name);
    printf("File editted successfully\n");
    

}
else if(strcmp(operation,"-h")==0)
{
    
    printf("-t --> tittle\n");
    printf("-y --> year\n");
    printf("-a --> artist\n");
    printf("-A --> album\n");
    printf("-g --> genre\n");
    printf("-c --> comment\n");
}
    
}