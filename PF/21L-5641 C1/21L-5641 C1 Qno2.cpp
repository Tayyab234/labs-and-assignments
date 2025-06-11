#include<iostream>
#include<Windows.h>
using namespace std;
int countcharacter(int l,char t[],char c){
	int k=0;

	for(int i=0;i<l;i++){
		if(t[i]==c)
			k=k+1;

	}
	
	return k;
	}
	
	




int main(){
	int length=37,p,h,k;
	char c;
	char text[37]="she sells sea shells on the seashore";
	for(int i=0;i<length;i++){
		if(text[i]<=123&&text[i]>=97)
			text[i]=text[i]-32;
	}
	for(int j=0;j<length;j++){
		if(j!=0){
			if(text[j]!=0){
			k=0;
			h=0;
		for( p=0;p<j;p++){
	        if(text[p]!=text[j])
				h=h+1;
			k=k+1;
		}
		}
		}
		else if(text[j]!=0)
			c=text[j];
		if(h==k)
			c=text[j];
		else if (p!=0&&j!=0)
			c=0;

		if(c!=0)
		  cout<<"Occurence of "<< c<<" are : "<<countcharacter(length,text,c)<<endl;
	}



	Sleep(-1);
}