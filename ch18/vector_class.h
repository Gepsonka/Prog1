#include <initializer_list>
#include <algorithm>
#include <iostream>

using namespace std;

class vector{
public:
    int sz;
    double* elem;

    explicit vector(int s);
    vector(initializer_list<double> lst);
    vector(const vector& vec);

    ~vector();

    vector& operator=(const vector& vec){
        sz=vec.sz;
        double* p=new double[vec.sz]; // make place for vec elements
        delete[] elem; // delete older elements
        elem=p; // assign p to elem
        copy(vec.elem,vec.elem+vec.sz,elem);
        return *this; // return a self reference
    }

    double& operator[](int n){
        return elem[n];
    }

    double operator[](int n) const{
        return elem[n];
    }



};