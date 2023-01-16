#pragma once
#include "Libraries.h"

template <class T>
class MyArr
{
    T* data;
    int size;   
public:
    MyArr() { data = new T[5]; };
    MyArr(int n) { size = n; if (size != 0) data = new T[size]; else data = nullptr; };
    ~MyArr() { delete[] data; };

    int GetSize() const { return size; };

   T& operator[](int i) {
        if (i < 0 || i >= size)
        { cout << "out of range" << endl; exit(1); }
         else
            return data[i];
    };

   void Random() {
       for (int i = 0; i < size; ++i) {
           data[i] = rand();
       }
   };

   void Print() {
       for (int i = 0; i < size; i++) {
           std::cout << data[i] << " ";
       }
       cout << endl;
   }

   void resize() {
       T* newData = new T[size * 2];
       for (int i = 0; i < size; i++) {
           newData[i] = data[i];
       }
       delete[] data;
       data = newData;
      size *= 2;
   }
   void Sort() { sort(data, data + size); };
};

template <class T>
class Printt {
public:
    void Print(T example) { cout << example << endl; }
};
template<>
class Printt <string> {
public:
    void Print(string example) { cout <<"_____"<< example << "_____" << endl; }
};


int main()
{
    srand(time(NULL));
    MyArr<int> t(5);
    MyArr<float> f;
    t.Random();
    t.Print();
    t.Sort();
    t.Print();
    cout<<t.GetSize()<<endl;
    t.resize();
    t.Print();
    cout << t.GetSize() << endl;
    cout << "<----------->" << endl;
    Printt<char> a;
    a.Print('$');
    Printt<string> b;
    b.Print("$");

    //Frame mf(10);
	//mf.main_cycle();
	return 0;
}
