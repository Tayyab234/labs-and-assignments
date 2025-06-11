//problem no 3
#include <iostream>
using namespace std;
int main()
{
 int n,i,j=1;
 cin>>n;
 if(n>=0){
     for(i=0;i<=n;i++){
         cout<<j<<" ";
         j=j+2;
     }
 }
 else{
     cout<<"index cannot be negative"<<endl;
 }

    return 0;
}
