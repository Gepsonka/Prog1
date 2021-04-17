#include <iostream>
#include <vector>


int main(){

    int* p1=new int{7};
    // std::cout<<p1<<"\n"<<*p1<<"\n";


    int* p2=new int[7]{1,2,4,8,16,32,64};
    // std::cout<<p2<<"\n";
    //for (int i=0;i<7;++i){
    //    std::cout<<p2[i]<<"\n";
    //}

    int* p3=p2;

    p2=p1;
    p2=p3;

    //std::cout<<p1<<"\n";
    std::cout<<p1<<"\n"<<*p1<<"\n";


    std::cout<<p2<<"\n";
    for (int i=0;i<7;++i){
        std::cout<<p2[i]<<"\n";
    }

    delete[] p1;
    delete[] p2;

    int* ppp1=new int[10]{1,2,4,8,16,32,64,128,256,512};
    int* ppp2=new int[10];

    for(int i=0;i<10;++i){
        ppp2[i]=ppp1[i];
    }

    delete[] ppp1;
    delete[] ppp2;

    std::vector<int> pp1{1,2,4,8,16,32,64,128,256,512};
    std::vector<int> pp2(10,0);

    for(int i=0;i<pp1.size();i++){
        pp2[i]=pp1[i];
        std::cout<<pp1[i]<<"\n"<<pp2[i]<<"\n";
    }

    
}