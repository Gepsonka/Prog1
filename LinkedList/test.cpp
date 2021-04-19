#include "linkedl.h"
#include <initializer_list>
#include <iostream>

using namespace std;

template<class Elem>
List<Elem>::List(){
    first=nullptr;
    last=nullptr;
}


template<class Elem>
List<Elem>::List(initializer_list<Elem> lst){
    Link<Elem>* adder=new Link<Elem>;
    for(int i=0;i<lst.size();i++){
        if (i==0){
            adder->prev=nullptr;
            if (lst.size()!=1){
                adder->succ=new Link<Elem>;
                adder->succ->prev=adder;
                adder->val=*(lst.begin());
                first=adder;
                adder=adder->succ;

            } else {
                adder->succ=nullptr;
                adder->val=*(lst.end()-1);
                last=adder;
                first=adder;
                
            }
            
        } else if (i==lst.size()-1){
            adder->succ=nullptr;
            adder->val=*(lst.end()-1);
            last=adder;

        } else {
            adder->val=*(lst.begin()+i);
            adder->succ=new Link<Elem>;
            adder->succ->prev=adder;
            adder=adder->succ;
        }
    }

    // adder->succ=nullptr;
    // adder->val=*(lst.end()-1);
    // last=adder;
}

template<class Elem>
List<Elem>::~List(){
    if (first!=last){
        Link<Elem>* element=first;
        while (element->succ!=nullptr){
            delete element->prev;
            element=element->succ;
        }
        delete element;
    } else if (first==last){
        delete first;
    }
}


template<class Elem>
auto List<Elem>::begin(){
    if (first!=nullptr) return List<Elem>::iterator(first);
}




template<class Elem>
auto List<Elem>::end(){
    if(first!=nullptr){
        return List<Elem>::iterator(last->succ);
    }
}




template<class Elem>
auto List<Elem>::insert(List<Elem>::iterator p,const Elem& v){
    if (first==nullptr){
        throw std::runtime_error("need at least on element");
    }
    if (p!=end()){
        Link<Elem>* x=new Link<Elem>;
        x->succ=p->succ;
        x->prev=p.get_curr();
        x->val=v;
        p->succ->prev=x;
        p->succ=x;
        return List<Elem>::iterator(p->succ);
    } else {
        last->succ=new Link<Elem>;
        last->succ->succ=nullptr;
        last->succ->val=v;
        last->succ->prev=last;
        last=last->succ;
        return List<Elem>::iterator(last);

    }
}

template<class Elem>
void List<Elem>::erase(List<Elem>::iterator p){
    if (first==nullptr){
        throw runtime_error("no items in the container");
    }
    if (first->succ==nullptr){
        delete[] first;
        first=last=nullptr;
    } else if(p.get_curr()==first){
        first=first->succ;
        delete[] first->prev;
        first->prev=nullptr;
    } else if(p==end()){
        last=last->prev;
        delete[] last->succ;
        last->succ=nullptr;
    } else {
        Link<Elem>* pprev=p->prev;
        Link<Elem>* psucc=p->succ;
        delete[] p->prev->succ;
        pprev->succ=psucc;
        psucc->prev=pprev;
    }

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
    if (first!=nullptr){
        first->prev=new Link<Elem>;
        first->prev->succ=first;
        first->prev->val=v;
        first=first->prev;
    } else {
        push_back(v);
    }
    

}



// template<class Elem>
// List<Elem>::iterator List<Elem>::erase(iterator p){
    
// }



int main(){

    List<int> l {};
    l.erase(l.begin());
    


    for (List<int>::iterator i=l.begin();i!=l.end();++i){
        cout<<*i<<' ';
        
    }


    return 0;

}