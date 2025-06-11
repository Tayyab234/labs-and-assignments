/******************************************************************************
area and roof of cubic shape
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
 int l,b,w,a,v;
 cin>>l>>b>>w;
 if(l>0&&b>0&&w>0){
     a=l*w;
     cout<<"area of wall :"<<a<<endl;
     v=l*w*b;
     cout<<"roof of cubiod :"<<v<<endl;
     
 }
 else{
     cout<<"number must be positive"<<endl;
 }

    return 0;
}
