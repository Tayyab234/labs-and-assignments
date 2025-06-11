#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* f1;
    f1=fopen("input.txt","r");
    char c;
    while((c=fgetc(f1)) != EOF){ 
         printf("%c",c);
    }
    fclose(f1); 
    return 0;
}
