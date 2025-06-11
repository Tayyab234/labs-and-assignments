#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ,m;
    int max=0;
    printf("Please enter the number of integers you want to input : ");
    scanf("%d",&n);
    int i=0;
    while(i<n){
        printf("\nPlease enter the integer no %d : ",i+1);
        scanf("%d",&m);
        if(max < m)
            max=m;
        i=i+1;
    }
    printf("Max integer is : %d",max);
    return 0;
}
