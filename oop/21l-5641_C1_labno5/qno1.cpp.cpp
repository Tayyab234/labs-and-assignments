#include<iostream>
#include<string>
using namespace std;
class lumbourghini {
	string colour, owner_name;
	int seat, cubic_space, engine_no, frame_no, year;
public:
	lumbourghini() {
		colour = "Hot Red";
		seat = 4;
		cubic_space = 90;
		engine_no = 6012;
		frame_no = 7812;
		year = 2021;
    }
	lumbourghini(lumbourghini& s) {
		colour = s.colour;
		seat = s.seat;
		cubic_space = s.cubic_space;
	}
	void oset() {
		cout << "Please enter the owner name : ";
		getline(cin, owner_name);
    }
	void eset() {
		cin.ignore();
		cout << "\nPlease enter the engine no : ";
		cin >> engine_no;
	}
	void yset() {
		cout << "\nPlease enter the year of manufacture : ";
		cin >> year;
	}
	void fset() {
		cout << "\nPlease enter the frame no : ";
		cin >> frame_no;
	}
	string ooset() {
		return owner_name;
	}
	int eeset() {
		return engine_no;;
	}
	int yyset() {
		return year;
	}
	int ffset() {
		return frame_no;
	}
	string ccolour() {
		return colour;
	}
	int sseat() {
		return seat;
	}
	int cubicspace() {
		return cubic_space;
	}
};
int main() {
	lumbourghini ob1;
	lumbourghini ob2(ob1);
	ob2.oset();
	ob2.yset();
	ob2.eset();
	ob2.fset();
	cout << "\n___________________________________________"<<endl;
	cout << "Owner name is : " << ob2.ooset() << "\nEngine no : " << ob2.eeset() << "\nmanufacture year is : " << ob2.yyset() << "\nframe no : " << ob2.ffset() << "\ncolour is : "<<ob2.ccolour()<<"\nseat are : "<<ob2.sseat()<<"\ncubic space is : "<<ob2.cubicspace();
	return 0;
}