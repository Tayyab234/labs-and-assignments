#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE* f1, *f2;
    f1=fopen("input.txt","r");
  
    f2=fopen("Q3output.txt","w");
    
    char c;
    int n=0;
    char s[100][30]; 
    int i = 0;
    while((c=fgetc(f1)) != EOF){ 
       if(c == ' ' || c == '\n'){ 
          s[n][i] = '\0'; 
          n++;
          i=0;
       } 
       else {
          s[n][i++] = c; 
       }
    }
    s[n][i] = '\0'; 

    int flag;
    for(i=0; i<=n; i++){
        flag=1;
        for(int j=0; j<strlen(s[i]); j++){
            if(s[i][j] >= 'a' && s[i][j] <= 'z' || s[i][j] >= 'A' && s[i][j] <= 'Z'){
                  flag=0;
                  break;
            }
        }
        if(flag==1){
          fputs(s[i], f2);
          fputs("\n", f2); 
        }  
    }
    fclose(f1); 
    fclose(f2); 
    return 0;
}
