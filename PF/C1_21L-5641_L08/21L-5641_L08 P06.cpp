#include <iostream>
using namespace std;
int main(){
    int a[4],b[4];
    for(int i=0;i<4;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int j=3;j>-1;j--)
        cout<<b[j]<<" ,";
    return 0;
}