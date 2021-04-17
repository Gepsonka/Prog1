#include<iostream>
#include<string>
#include<vector>

using namespace std;


template<typename T>
struct S {
private:
    T val;

public:
    S(T x):val{x}{}
    const T& get() const;
    T& get();
    void operator=(const T& x){
        val=x;
    }
};

template<class T> const T& S<T>::get() const{
    return val;
}

template<class T> T& S<T>::get(){
    return val;
}


int main(){

    S<int> n(23);
    S<char> c('d');
    S<double> d(1.232);
    S<string> s("coco");
    S<vector<int>> v(*(new vector<int> {1,2,3,4,5,6}));

    cout<<n.get()<<endl;
    cout<<c.get()<<endl;
    cout<<d.get()<<endl;
    cout<<s.get()<<endl;

    for(int i=0;i<6;i++){
        cout<<v.get()[i]<<' ';
    }
    cout<<endl;



}