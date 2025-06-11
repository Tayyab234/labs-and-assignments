#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* f1 , *f2;
    f1=fopen("input.txt","r");
    f2=fopen("Q2output.txt","w");
    char c;
    while((c=fgetc(f1)) != EOF){ 
        if(c>=48 && c<=57){
            fputc( c, f2 );
        }
    }
    fclose(f1); 
    fclose(f2); 
    return 0;
}
