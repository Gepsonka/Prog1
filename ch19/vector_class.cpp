#include "vector_class.h"


vector::vector():sz{0},elem{nullptr},space{0}{}

vector::vector(int s):sz{s},elem{new double[sz]},space{sz}
{
    for(int i=0;i<sz;i++){
        elem[i]=0;
    }
}

vector::vector(initializer_list<double> lst):sz{lst.size()},elem{new double[sz]},space{sz} //initializer_list enables vector v {1,2,3,4...}
{
    copy(lst.begin(),lst.end(),elem);
}

vector::vector(const vector& vec):sz{vec.sz},elem{new double[vec.sz]},space{sz}{
    copy(vec.elem,vec.elem+vec.sz,elem);
}

void vector::reserve(int newalloc){
    if (newalloc<=space) return;
    double* p=new double[newalloc];
    for(int i=0;i<newalloc;i++) p[i]=elem[i];
    delete[] elem;
    elem=p;
    space=newalloc;

}

void vector::resize(int newsize){
    reserve(newsize);
    for(int i=sz;i<newsize;i++) elem[i]=0;
    sz=newsize;
}

int vector::capacity() const {
    return space;
}

void vector::push_back(double d){
    if (space==0){
        reserve(8);
    } else if (sz==space) {
        reserve(2*space);
    }
    elem[sz]=d;
    ++sz;
}

vector::~vector()
{
    delete[] elem;
}