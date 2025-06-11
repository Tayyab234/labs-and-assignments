#include <iostream>
using namespace std;
int main()
{
int Counter = 0;
double Number, sum,ave;
while (Counter < 10){
cout<<"Please Enter a Number ";
cin>> Number;
sum+= Number;
Counter++;
}
ave=sum/10;
cout<<endl<<"Sum of the 10 numbers is "<<sum<<endl;
cout<<"average of numbers is :"<<ave<<endl;
return 0;
}
