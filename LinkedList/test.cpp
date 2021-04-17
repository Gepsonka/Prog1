#include "linkedl.h"
#include <initializer_list>

using namespace std;

template<class Elem>
List<Elem>::List(){
    first=nullptr;
    last=nullptr;
}


template<class Elem>
List<Elem>::List(initializer_list<Elem> lst){

}

template<class Elem>
List<Elem>::~List(){
    if (first!=last){
        Link<Elem>* element=first->succ;
        while (element->succ!=nullptr){
            delete element->prev;
            element=element->succ;
        }
        delete element;
    }
}


template<class Elem>
auto List<Elem>::begin(){
    return List<Elem>::iterator(first);
}




template<class Elem>
auto List<Elem>::end(){
    return List<Elem>::iterator(last->succ);
}




template<class Elem>
auto List<Elem>::insert(List<Elem>::iterator p,const Elem& v){
    p->succ->prev=new Link<Elem>;
    p->succ=p->succ->prev;
    p->succ->data=v;
    return List<Elem>::iterator(p->succ);
    
}

template<class Elem>
void List<Elem>::push_back(const Elem& v){
    if (first!=nullptr){
        last->succ=new Link<Elem>;
        last->succ->val=v;
        last->succ->prev=last;
        last=last->succ;
    } else {
        first=new Link<Elem>;
        last=first;
        first->val=v;

        
    }
}

template<class Elem>
void List<Elem>::push_front(const Elem& v){
    first->prev=new Link<Elem>;
    first->prev->succ=first;
    first->prev->val=v;
    first=first->prev;

}



// template<class Elem>
// List<Elem>::iterator List<Elem>::erase(iterator p){
    
// }



int main(){

    List<int> l;


    return 0;

}