#include "vector_class.h"
#include <iostream>



int main(){
    vector a {1,2,3,4,5};
    vector b {a};
    vector c(10);
    vector d(5);
    c=d;

    d[3]=12.4;
    std::cout<<d[3]<<std::endl<<"cocain"<<std::endl;
}