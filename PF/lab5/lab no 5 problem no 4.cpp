
#include <iostream>
using namespace std;
int main()
{
 int n,t,s=0,r=1,b=0,u,k,m;
 cin>>n;
 for(t=1;t<=n;k=t++){
     cin>>u;
     if(u>s){
         b=b+1;
     }
     m=s;
     if(s!=0){
         if(m>u)
         r=r+1;
     }
     s=u;
 }
 if(b==k)
    cout<<"strickly increasing"<<endl;
 else if (r==k)
    cout<<"strickly decreasing"<<endl;
 else 
    cout<<"neither"<<endl;
    return 0;
}
