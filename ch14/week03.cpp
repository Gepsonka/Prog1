#include <iostream>
#include <string>

struct B1 {
public:
    void virtual pvf()=0; 
    void virtual vf() {
        std::cout<<"B1::vf()\n";
    }

    void f(){
        std::cout<<"B1::v()\n";
    }

};

struct D1 :  B1 {
public:
    void pvf() override{
        std::cout<<"D1::pvf()\n";
    }
    void vf() override{
        std::cout<<"D1::vf()\n";
    }

    void f(){
        std::cout<<"D1::f()\n";
    }
};

struct D2 : D1 {
    void pvf() override{
        std::cout<<"D2::pvf()\n";
    }

    void vf() override{
        std::cout<<"D2::vf()\n";
    }

    void f(){
        std::cout<<"D2::f()\n";
    }
};


struct B2 {
    void virtual pvf()=0;

};

struct D21 : B2 {
    void pvf() override{
        std::cout<<str<<"\n";
    }
    private:
    std::string str="coco";
};


struct D22 : B2{
    void pvf() override{
        std::cout<<n<<"\n";
    }

    void f(B2& b2){
        b2.pvf();
    }
    private:
    int n=25;
};


int main(){

    //B1 b1;
    //b1.vf();
    //b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1& bref {d1};
    bref.vf();
    bref.f();

    D2 d2;
    d2.pvf();
    d2.vf();
    d2.f();

    D21 d21;
    d21.pvf();

    D22 d22;
    d22.pvf();
    d22.f(d22);
    d22.f(d21); 


}