
#include<stdio.h>
#include<string.h>
#include<conio.h>

unsigned char getKey(int x);
int havFile(char *fname);
int fileWrite(char *inFileName, char *outFileName, unsigned char key);
int getExt(char fileName[],char ext[]);

void havKey(void)
{
    char choice,fileName[100],deFileName[100],fext[10];
    unsigned char key;
    int exErr,err;

    printf("\nEnter file Name (with extension):");
    gets(fileName);
    while(!havFile(fileName))
    {
        printf("\n\aFile Not Found! Make sure you have entered correct file name with extension.\nPlease enter again: \n");
        gets(fileName);
    }
    key=getKey(0);
    printf("\nEnter New File Name: \n");
    gets(deFileName);

    printf("\nWant to use automatic file type detection?\n\tY=Yes\n\tAnyKey=No\n");
    choice=getch();
    if(choice=='y' || choice=='Y')
    {
        exErr=getExt(fileName,fext);
        if(exErr<0)
        {
            printf("\nAutomatic file type detection failed!\nPlease Enter File extension:\n");
            gets(fext);
            strcat(deFileName,".");
            strcat(deFileName,fext);
        }

        else
        {
            strcat(deFileName,fext);
            printf("\nFile Type Detected: %s\n",fext);
        }
    }

    else
    {
        printf("\nEnter file extension: \n");
        gets(fext);
        strcat(deFileName,".");
        strcat(deFileName,fext);
    }

    printf("\nDecrypting File...\n");
    err=fileWrite(fileName,deFileName,key);
    if(err)
        printf("\n\aOperation Failed.\n");
    else
        printf("\nOperation Completed!\n");
}
