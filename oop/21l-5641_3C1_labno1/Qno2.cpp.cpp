#include <iostream>
using namespace std;

template<class T>
class my_vector_bad {
    int size;
    int capacity;
    T* arr;
public:
    my_vector_bad() {
        size = -1;
        capacity = 1;
        arr = new T[capacity];
    }
    //copy constructor
   /* my_vector_bad(my_vector_bad h) {
        size = h.size;
        capacity = h.capacity;
        arr = new T[capacity];
        for (int i = 0;i < size;i++)
            
        
    }*/
    //destructor
    ~my_vector_bad() {

    }
    //operator overloading
    void operator +(T val) {
        for (int i = 0;i < size + 1;i++)
            arr[i] += val;
    }
    void operator=(my_vector_bad g) {
        size = g.size;
        for (int i = 0;i <=g.size;i++) {
            arr[i] = g.arr[i];
        }
    }
    my_vector_bad operator+(my_vector_bad g) {
        my_vector_bad<int>k;
        k.size = size+g.size;
        T* tem;
        tem = new T[k.size];
        int w = 0;
        for (int i = 0;i < size;i++) {
            tem[w] = arr[i];
            w ++ ;
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
            tem = new T[capacity+1];
            for (int i = 0;i < size + 1;i++)
                tem[i] = arr[i];
            tem[size + 1] = val;
            arr = tem;
            tem = NULL;
            size++;
            capacity+=1;
            delete tem;
        }
    }
    T pop_back(void) {
        T val;
            val = arr[size];
            arr[size] = NULL;
            size--;
            capacity--;
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
    my_vector_bad<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(i + 1);
        list.display_list();
    }
    for (int j = 0; j <= 4; j++) {
        cout << "Extracted\t" << list.pop_back() << "\tfrom list" << endl;
        list.display_list();
    }
    my_vector_bad<int> oop;
    for (int i = 0; i < 5; i++) 
        oop.push_back(i + 1);
    cout << "\n______________________________________operator overloading +____________________________________________\n";
     oop + 5;
     oop.display_list();
     cout << "\n______________________________________operator overloading =____________________________________________\n";
     list = oop;
     list.display_list();
     my_vector_bad<int> un;
     for (int i = 0; i < 7; i++)
         un.push_back(i + 1);
     cout << "\n______________________________________operator overloading + union of two array____________________________________________\n";
     my_vector_bad<int> newa;
    newa = oop + un;
     newa.display_list();
     return 0;
}