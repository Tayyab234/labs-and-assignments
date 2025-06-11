#include<iostream>
using namespace std;
int main(){
    int A[6],a=0,p=0,m,k,l;
    for(int i=0;i<6;i++){
        cin>>A[i];
        if(a<A[i])
           a=A[i];
        if(p!=0){
           if(p<A[i])
             m=p;
           else
             p=A[i];
             
        }
        if(p==0)
           p=A[i];
    }
  for(int j=0;j<6;j++){
      if(A[j]==a)
          k=j;
      if(A[j]==p)
          l=j;
  }
  cout<<"Maximum : "<<a<<" ,"<<"Index :"<<k<<endl<<"Minimum : "<<p<<" ,"<<"Index : "<<l;
    
}