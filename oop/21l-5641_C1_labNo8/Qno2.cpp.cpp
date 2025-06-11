#include <iostream>

using namespace std;


class Point
{
	int x;
	int y;

public:

	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
		cout << "Point() CALLED " << endl;
		cout << endl;
	}

	void print()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}

	~Point()
	{
		cout << endl << " THE DESTRUCTOR ~Point() IS CALLED ";
	}
};

class Style
{
	char color[10];
	bool isFilled;

public:

	Style(string c)
	{
		int i = 0;
		for (; c[i] != '\0'; i++)
		{
			color[i] = c[i];
		}
		color[i] = '\0';

		isFilled = false;
	}

	void setcolor()
	{
		cout << " ENTER COLOR: ";
		cin >> color;
	}

	char getcolor()
	{
		return color[10];
	}

	void setfilled()
	{
		if (color[0] != '\0')
		{
			isFilled = true;
		}
		else
		{
			isFilled = false;
		}
	}

	void print()
	{
		cout << "---------------------------------" << endl;
		cout << " THE COLOR IS: " << color << endl;
		if (isFilled == 1)
		{
			cout << " FILLED " << endl;
		}
		else
		{
			cout << " NOT FILLED " << endl;
		}
		cout << "---------------------------------" << endl;
	}


	~Style()
	{
		cout << " THE DESTRUCTOR ~Style() IS CALLED " << endl;
	}
};

class Circle {
	Point centre;
	float radius;
	Style* st;
	char c[10];

public:
	Circle(int x, int y, float r) : centre(x, y)
	{
		radius = r;
		cout << " Cirle() " << endl;
		st = NULL;
		cout << " st to NULL " << endl;
	}

	void setstyle(Style* a)
	{

	}

	void setColor(Style& a)
	{
		a.setcolor();
		c[10] = a.getcolor();
	}

	void setFilled(bool flag)
	{
		if (c[0] != '\0')
		{
			flag = true;
		}
		else
		{
			flag = false;
		}

	}

	void Print()
	{
		cout << " RADIUS: " << radius << endl;
		cout << " CENTRE: ";
		centre.print();
		cout << "------------------------------------" << endl;
	}


	~Circle()
	{
		cout << endl << " THE DESTRUCTOR ~Circle() IS CALLED " << endl;
	}
};


int main()
{

	Point obj1(4, 5);
	obj1.print();

	Style s1("COLOR");
	s1.setcolor();
	s1.setfilled();
	s1.print();

	Circle c1(4, 5, 2.5);
	bool c = false;
	cout << "------------------------------------" << endl;
	c1.setColor(s1);
	c1.setFilled(c);
	c1.Print();
	s1.print();
	cout << endl << "------------------------------------" << endl;
	return 0;
}
