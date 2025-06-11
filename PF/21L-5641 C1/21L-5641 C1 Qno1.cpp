#include<iostream>
#include<Windows.h>
using namespace std;
int countcharacter(int l,char t[],char c){
	int k=0;
	char character='s';
	for(int i=0;i<l;i++){
		if(t[i]==c)
			k=k+1;
	}
	
	return k;


}

int main(){
	int length=37;
	char character='E';
	char text[37]="she sells sea shells on the seashore";
	for(int i=0;i<length;i++){
		if(text[i]<=123&&text[i]>=97)
			text[i]=text[i]-32;
	}

	cout<<"Occurence of "<<character<<" are : "<<countcharacter(length,text,character);


	Sleep(-1);
}

 
