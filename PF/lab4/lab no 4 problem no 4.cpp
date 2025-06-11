//problem no 4
#include <iostream>
using namespace std;
int main()
{
 int i,n,j=0;
 cin>>n;
 if(n>0){
     for(i=1;i<=n;i++){
         if(n%i==0)
            j++;
     }
     if(j==2)
    cout<<"given number is prime number"<<endl;
 else
    cout<<"given number is not a prime number"<<endl;

 }
 else{
     cout<<"please enter a positive integer"<<endl;
 }
 
    return 0;
}
