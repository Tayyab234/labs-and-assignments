#include <iostream>
using namespace std;

template<class T>
class my_vector {
    int size;
    int capacity;
    T* arr;
public:
    my_vector() {
        size = -1;
        capacity = 1;
        arr = new T[capacity];
    }
    //destructor
    ~my_vector() {

    }
    //operator overloading
    void operator +(T val) {
        for (int i = 0;i < size + 1;i++)
            arr[i] += val;
    }
    void operator=(my_vector g) {
        size = g.size;
        for (int i = 0;i <= g.size;i++) {
            arr[i] = g.arr[i];
        }
    }
    my_vector operator+(my_vector g) {
        my_vector<int>k;
        k.size = size + g.size - 1;
        T* tem;
        tem = new T[k.size];
        int w = 0;
        for (int i = 0;i < size;i++) {
            tem[w] = arr[i];
            w++;
        }
        for (int i = 0;i < g.size;i++) {
            tem[w] = g.arr[i];
            w++;
        }
        k.arr = tem;
        tem = NULL;
        delete tem;
        return k;
    }
    void push_back(T val) {
        if (size < capacity) {
            arr[size + 1] = val;
            size++;
        }
        else {
            T* tem;
            tem = new T[capacity * 2];
            for (int i = 0;i < size + 1;i++)
                tem[i] = arr[i];
            tem[size + 1] = val;
            arr = tem;
            tem = NULL;
            size++;
            capacity *= 2;
            delete tem;
        }
    }
    T pop_back(void) {
        T val;
        if (size > capacity/2) {
           val= arr[size] ;
           arr[size] = NULL;
            size--;
        }
        else {
            T* tem;
            tem = new T[capacity/ 2];
            for (int i = 0;i < size;i++)
                tem[i] = arr[i];
           val= arr[size];
           arr[size + 1] = NULL;
            arr = tem;
            tem = NULL;
            size--;
            capacity = capacity / 2;
            delete tem;
        }
        return val;
     }
    void display_list(void) {
        cout << "Elements present in list are:\n";
        for (int i = 0; i < size+1;i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

};

int main()
{
    my_vector<int> list;
    for (int i = 0; i < 8; i++) {
        list.push_back(i + 1);
        list.display_list();
    }
    for (int j = 0; j <= 4; j++) {
        cout << "Extracted\t" << list.pop_back() << "\tfrom list" << endl;
        list.display_list();
    }
    my_vector<int> oop;
    for (int i = 0; i < 5; i++)
        oop.push_back(i + 1);
    cout << "\n______________________________________operator overloading +____________________________________________\n";
    oop + 5;
    oop.display_list();
    cout << "\n______________________________________operator overloading =____________________________________________\n";
    list = oop;
    list.display_list();
    my_vector<int> un;
    for (int i = 0; i < 7; i++)
        un.push_back(i + 1);
    cout << "\n______________________________________operator overloading + union of two array____________________________________________\n";
    my_vector<int> newa;
    newa = oop + un;
    newa.display_list();
    return 0;
}