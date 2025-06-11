
#include <iostream>
using namespace std;
int main()
{
 int n,a,d,sum,t;
 double ave;
 cout<<"enter a number"<<endl;
 cin>>n;
 a=1;
 sum=0;
 while(a<=n){
     cout<<"enter number for sum and average"<<endl;
     cin>>d;
     sum=sum+d;
     t=a++;
 }
 ave=sum/t;
 cout<<"sum of numbers are  :"<<sum<<endl;
 cout<<"average of sum numbers is  :"<<ave<<endl;

    return 0;
}
