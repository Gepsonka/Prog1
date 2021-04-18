#include <initializer_list>

using namespace std;


template<typename T>
struct Link{
    Link* prev=nullptr;
    Link* succ=nullptr;
    T val;
};



template<typename Elem>
class List{
    Link<Elem>* first;
    Link<Elem>* last;

public:

    List();
    List(initializer_list<Elem> lst);
    ~List();

    class iterator;

    auto begin();
    auto end();

    auto insert(iterator p, const Elem& v);
    void erase(iterator p);

    void push_back(const Elem& v);
    void push_front(const Elem& v);

    Elem& front();
    Elem& back();

};





template<typename Elem>
class List<Elem>::iterator{
    Link<Elem>* curr;

public:
    iterator(Link<Elem>* p):curr{p}{}

    Link<Elem>* get_curr(){return curr;}

    iterator& operator++(){curr=curr->succ; return *this;}
    iterator& operator--(){curr=curr->prev; return *this;}
    Link<Elem>* operator->(){return curr;}
    Elem& operator*(){return curr->val;}

    bool operator==(const iterator& b) const {return curr==b.curr;}
    bool operator!=(const iterator& b) const {return curr!=b.curr;} 
};