#include<vector>
#include<list>
#include <functional>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename Iter1>
Iter1 js_arraymap(Iter1 i1,Iter1 i2,function<void()> const& lambda){
    for (Iter1 i=i1;i1!=i2;i++){
        lambda(*i);
    }
    return i1;
}

template<typename Iter1, typename Iter2>
Iter2 cpy(Iter1 f1, Iter1 e1, Iter2 f2){
    if (f1==e1) return f2;
    while (f1!=e1){
        *f2=*f1;
        ++f2;
        ++f1;
    }
    return f2;
}




int main(){
    int ten[]={0,1,2,3,4,5,6,7,8,9};
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    list<int> lst {0,1,2,3,4,5,6,7,8,9};

    int ten2[10];
    copy(ten,ten+10,ten2);
    vector<int> vec2{vec};
    list<int> lst2{lst};

    for(int i=0;i<vec.size();i++){
        vec[i]+=3;
        // cout<<vec[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<10;i++){
        ten[i]+=2;
    }
    
    for(list<int>::iterator i=lst.begin();i!=lst.end();i++){
        *i=*i+5;
        // cout<<*i<<" ";
    }
    cout<<endl;

    cpy<int*,vector<int>::iterator>(begin(ten),end(ten),vec2.begin());
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<" ";
    }
    cout<<endl;


    vector<int>::iterator p=find(vec.begin(),vec.end(),3);
    if(p==vec.end()){
        cout<<endl<<"Int not in vector"<<endl;
    } else {
        cout<<endl<<*p<<endl;
    }

}