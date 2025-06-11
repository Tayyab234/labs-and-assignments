#include<iostream>
#include<string>
using namespace std;
void ispalindrome(string c){
	int j=0,h=0,t;
	j=c.length();
	t=j-1;
	int i=0;
	j=j/2;
	for(;t<=j;t--){
		if(c[t]==c[i])
			h=h+1;
		i=i+1;
	}
	
	if(h==i)
		cout<<endl<<"It is a palindrome";
	else
		cout<<endl<<"it is not a palindrome";
}
int main(){
	string c;
	cout<<"Enter a text"<<endl;
	cin>>c;
	ispalindrome(c);
	int t;
	cin>>t;
	return 0;
}

