/******************************************************************************

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
    int amout,a,b,c,e,d,h,g,i;
    cin>>amout;
    if(amout%500==0&&amout>500){
        a=amout/5000;
        h=amout%5000;
        if(a>0){
            cout<<"no of notes of 5000 :"<<a<<endl;
            b=h/1000;
            g=h%1000;
            if(b>0){
                cout<<"no of notes of 1000 :"<<b<<endl;
                c=g/500;
                if(c>0){
                    cout<<"no of notes of 500 :"<<c<<endl;
                }
            
                }
            }
        }else{
            e=amout/1000;
            i=amout%1000;
            if(e>0){
                cout<<"no. of notes of 1000 :"<<e<<endl;
                d=i/500;
                if(d>0){
                    cout<<"no. of notes of 500 :"<<d<<endl;
                }
            }
            
        }
    return 0;
}

