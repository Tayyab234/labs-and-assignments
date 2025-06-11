#include<iostream>
using namespace std;
int main(){
	string text,word;
	int h=0,c=0,j,k,i,u;
	text="Enter your  winter vacation";
	word=" winter";
	j=text.length();
	k=word.length();
	for( i=0;i<j;i++){
		if(text[i]==32||text[i]!=32){
			h=0;
			c=0;
		}
		u=i;
			for(int t=0;t<k;t++){
				if(text[u]==0)
					break;
				if(text[u]==word[t])
					h=h+1;
				c=c+1;
				u=u+1;
			}
		if(h!=0&&c!=0){
			if(h==c)
				break;
		}
		}
	if(h==c)
		cout<<"word was found at index "<<i;
	else 
		cout<<"word was not found";
	int p;
	cin>>p;
	return 0;
}
