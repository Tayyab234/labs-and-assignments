#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE  *f;
    FILE  *F1;
    f=fopen("input.txt","r");
    F1=fopen("output.txt","w");
    char ch;
    while( (ch=getc(f)) != EOF ){
        if(ch>=65 && ch<=90 || ch>=97 && ch<=122){
            putc(ch,F1);
            printf("%c",ch);
        }
    }
    printf("\n");
    fclose(f);
    fclose(F1);
}
