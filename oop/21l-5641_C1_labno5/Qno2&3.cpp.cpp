#include<iostream>
#include<string>
using namespace std;
class student{
	int* mark{};
	
public:
	student() {
		mark = new int[5];

	}
	//student(student& s) {
		//for (int i = 0;i < 5;i++) {
			//mark[i] = s.mark[i];
		//}
	//}
	void setmarks(){
		for (int i = 0;i < 5;i++) {
			cout << "\nPlease enter the marks of subject " << i + 1 << " : ";
			cin >> mark[i];
		}
	}
    void display() {
		for (int i = 0;i < 5;i++) {
			cout << "\nStudent marks of subject " << i + 1 << " is : "
				<< mark[i];
		}
	}
	
	~student() {
		delete[]mark;
	}

};
int main() {
	student student1;
	student1.setmarks();
	student student2(student1);
	cout << "Student 1 data are :";
	student1.display();
	cout << "\n___________________________________________";
	cout << "\nstudent 2 data are : ";
	student2.display();
	
	return 0;
}