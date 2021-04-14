#include "vector_class.h"

vector::vector(int s):sz{s},elem{new double[sz]}
{
    for(int i=0;i<sz;i++){
        elem[i]=0;
    }
}

vector::vector(initializer_list<double> lst):sz{lst.size()},elem{new double[sz]} //initializer_list enables vector v {1,2,3,4...}
{
    copy(lst.begin(),lst.end(),elem);
}

vector::vector(const vector& vec):sz{vec.sz},elem{new double[vec.sz]}{
    copy(vec.elem,vec.elem+vec.sz,elem);
}

vector::~vector()
{
    delete[] elem;
}