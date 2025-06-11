//problem no 5
#include <iostream>
using namespace std;
int main()
{
 int n,i;
 cin>>n;
 if(n<0)
    n=-1*n;
 if(n>0){
    for(i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";}
 }
 }
 if(n==0)
    cout<<"every number is a factor of zero"<<endl;
  return 0;
}
