//関数のオーバーロード
#if 0
#include <iostream>
void print(const char* v)   { std::cout << v << std::endl; }
void print(int v)           { std::cout << v << std::endl; }
void print(float v)         { std::cout << v << std::endl; }
void print(double v)        { std::cout << v << std::endl; }

int main()
{
    print("AKB");
    print(48);
    print(3.14f);
    print(0.123456);

    system("pause>0");
}
#endif
//テンプレート関数
#if 0 
#include<iostream>

template<typename T>
void print(T v) { std::cout << v << std::endl; }

int main()
{
    print("AKB");
    print(48);
    print(3.14f);
    print(0.123456);

    system("pause>0");
}
#endif
//参照、演算子のオーバーロード
#if 0
#include<iostream>
struct MyArray
{
    int elems[5];
    int& at(int i) { return elems[i]; }
    int& operator[](int i) { return elems[i]; }
    int size() { return 5; }
};
int main()
{
    MyArray arr;
    for (int i = 0; i < arr.size(); i++) {
      //arr.at(i) = i + 1;
        arr[i]    = i + 1;
    }
    for (int i = 0; i < arr.size(); i++) {
      //std::cout << arr.elems[i] << std::endl;
      //std::cout << arr.at(i) << std::endl;
        std::cout << arr[i]    << std::endl;
    }
    system("pause>0");
}
#endif
//テンプレートクラス
#if 0
#include<iostream>
template<typename T, int N>
struct MyArray
{
    T elems[N];
    T& at(int i) { return elems[i]; }
    T& operator[](int i) { return elems[i]; }
    int size() { return N; }
};
int main()
{
    {
        MyArray<float, 5> arr;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (i + 1) / 2.0f;
        }
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << std::endl;
        }
        std::cout << std::endl;
    }
    {
        struct int2
        {
            int x, y;
            int2() :x(0), y(0) { }
            int2(int x, int y) :x(x), y(y) { }
        };
        MyArray<int2, 5> arr;
        for (int i = 0; i < arr.size(); i++) {
            arr[i].x = i + 1; 
            arr[i].y = i + 11;
        }
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i].x << ' ';
            std::cout << arr[i].y << std::endl;
        }
    }
    system("pause>0");
}
#endif
//標準テンプレートライブラリ std::array
#if 0
#include <iostream>
#include <array>
#include <algorithm>
int main()
{
    {
        std::array<float, 5> arr;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (i + 1) / 1.3f;
        }
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << std::endl;
        }
        std::cout << std::endl;
    }
    {
        struct int2
        {
            int x, y;
            int2() :x(0), y(0) { }
            int2(int x, int y) :x(x), y(y) { }
        };
        std::array<int2, 5> arr;
        for (int i = 0; i < arr.size(); i++) {
            arr[i].x = i + 1;
            arr[i].y = i + 11;
        }
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i].x << ' ';
            std::cout << arr[i].y << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::array<int, 7> arr;
        srand(time(0));
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rand()%10;
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;

        std::sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }

    system("pause>0");
}
#endif
//標準テンプレートライブラリ std::vector
#if 0
#include<iostream>
#include<vector>
int main()
{
    {
        std::vector<float> arr;
        //arr.push_back(3.14f);
        //arr.push_back(3.14f * 2);
        //arr.push_back(3.14f * 3);
        int num = 3;
        for (int i = 0; i < num; i++) {
            arr.push_back((i + 1) / 5.0f);
        }
        for (auto elem : arr) {
            std::cout << elem << std::endl;
        }
        std::cout << std::endl;
    }
    {
        struct int2
        {
            int x, y;
            int2() :x(0), y(0) { }
            int2(int x, int y) :x(x), y(y) { }
        };
        std::vector<int2> arr;
        int num = 3;
        for (int i = 0; i < num; i++) {
            //arr.push_back(int2(i + 1, i + 11));
            arr.emplace_back(i + 1, i + 11);
        }
        for (auto& elem : arr) {
            std::cout << elem.x << ' ' << elem.y << std::endl;
        }
    }
    system("pause>0");
}
#endif
