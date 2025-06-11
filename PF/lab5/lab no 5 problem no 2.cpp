
#include <iostream>
using namespace std;
int main()
{
 int a=0,b,n,r,h,sum,t,s=0;
 cout<<"please enter a positive number"<< "    :";
 cin>>n;
 sum=0;
 t=0;
 while(n>0){
    sum=sum+t;
    
    cout<<"please enter number again and negative number for loop terminating  :";
    cin>>n;
    b=a++;
    if(t>n)
       r=t;
    if(t<n&&t!=0){
       if(n<s||s==0){
        s=t;
        h=s;
     }
  }
       
    t=n;
 }
 cout<<"sum = "<<sum<<endl<<"average ="<<sum/b<<endl<<"maximum  ="<<r<<endl<<"minimum ="<<h<<endl;
 

    return 0;
}
