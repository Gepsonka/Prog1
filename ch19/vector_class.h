#include <initializer_list>
#include <algorithm>
#include <iostream>

using namespace std;

class vector{
public:
    int sz;
    double* elem;
    int space;

    vector();
    explicit vector(int s);
    vector(initializer_list<double> lst);
    vector(const vector& vec);

    void reserve(int newalloc);
    void resize(int newsize);
    int capacity() const;

    void push_back(double d);

    ~vector();

    vector& operator=(const vector& vec){
        if (this==&vec) return *this;

        double* p=new double[vec.sz]; // make place for vec elements
        for(int i=0;i<vec.sz;i++) p[i]=vec.elem[i];
        delete[] elem;
        space=sz=vec.sz;
        elem=p;
        return *this;   
    }

    double& operator[](int n){
        if(n>=sz || n<0) throw std::runtime_error("Out of range");
        return elem[n];
    }

    double operator[](int n) const{
        if(n>=sz || n<0) throw std::runtime_error("Out of range");
        return elem[n];
    }



};