#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "header.h"

void view(FILE *fp)
{
    char tag[5];
    int size;
    char info[100];
    int count=0;
    unsigned char s[4];
    printf("---------------------------------------------------------------\n");
    printf("MP3 TAG INFORMATIONS\n");
    printf("---------------------------------------------------------------\n");
    fseek(fp,10,SEEK_SET);

    while(count<6){
        fread(tag,1,4,fp);
        tag[4]='\0';
        
        fread(s,1,4,fp);

        size = (s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3];
        

        fseek(fp, 2, SEEK_CUR);
        if (size > 99)
            size = 99;
        fseek(fp, 1, SEEK_CUR);
        fread(info,size-1,1,fp);
        info[size-1]='\0';
        

        if((strcmp(tag,"TIT2"))==0)
        {
            printf("%-10s= %s\n","Title",info);
            count++;
        }
        else if((strcmp(tag,"TYER"))==0)
        {
            printf("%-10s= %s\n","Year",info);
            count++;
        }
        else if((strcmp(tag,"TPE1"))==0)
        {
            printf("%-10s= %s\n","Artist",info);
            count++;
        }
        else if((strcmp(tag,"TALB"))==0)
        {
            printf("%-10s= %s\n","Album",info);
            count++;
        }
        else if((strcmp(tag,"TCON"))==0)
        {
            printf("%-10s= %s\n","Genre",info);
            count++;
        }
        else if((strcmp(tag,"COMM"))==0)
        {
            printf("%-10s= %s\n","Comment",info);
            count++;
        }
    }


}