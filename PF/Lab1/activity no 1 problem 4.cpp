/******************************************************************************
 print number in decending order
*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   if(a<b&&a<c){
       cout<<a<<endl;
       if(b<c){
           cout<<b<<c;
       }
       else{
           cout<<c<<b;
       }
   }
   if(b<a&&b<c){
       cout<<b<<endl;
       if(a<c){
           cout<<a<<c;
       }
       else{
           cout<<c<<a;
       }
           
   }
   if(c<a&&c<b){
       cout<<c<<endl;
       if(a<b){
           cout<<a<<b;
       }
       else{
           cout<<b<<a;
       }
   }

    return 0;
}
