//problem no 2
#include <iostream>
using namespace std;
int main()
{
 int n,i,j=0;
 cin>>n;
 if(n>0){
   while(n!=0){
      i=n%10;
      n=n/10;
      j=j+i;
 }
   cout<<"sum of given number is :"<<j<<endl;
 }
 else{
     cout<<"cannot find the digit sum"<<endl;
 }

    return 0;
}
