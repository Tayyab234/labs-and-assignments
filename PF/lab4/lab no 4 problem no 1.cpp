//problem 1
#include <iostream>
using namespace std;
int main()
{
  int n,s,r=1;
  cin>>n;
  if(n>=0){
      if(n=0){
      cout<<" 1"<<endl;
  }
      if(n>0){
      for(s=1;s<=n;s++)
          r=r*s;}
  }
  else{
      cout<<"Invalid input"<<endl;
  }
  cout<<"fictorial of a given number is :"<<r<<endl;

    return 0;
}
