
#include <iostream>
using namespace std;
void staircase(int r)
{
  int a,h;
  cin>>r;
  for(a=1;a<=r;a++){
      for(h=1;h<=a;h++){
          cout<<"#";
      }
      cout<<endl;
  }

}

int main()
{
    int r;
    cin>>r;
    staircase(r);
}
