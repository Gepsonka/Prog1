#include <algorithm>
#include <iostream>
#include <cstring>



using namespace std;

int gaa[10]={1,2,4,8,16,32,62,124,248,596};

// int* f(int ar[],int n){
//     for(int i=0;i<n;++i){
//         ar[i]=gaa[i];
//         return ar;
//     }
    
// };

// int* f(int ar[10],int n){
//     static int la[10];
//     copy(ar,ar+n,la);
//     for (int i=0;i<10;++i){
//         cout<<arr[i]<<' ';
//     }
//     cout<<endl;
//     return la;
// } c++ stl



int* f(int arr[],int n){
    static int la[10];
    memcpy(la,arr,10*sizeof(int));
    for (int i=0;i<10;++i){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    int* p=new int(10);
    memcpy(p,arr,10*sizeof(int));
    for (int i=0;i<10;++i){
        cout<<p[i]<<' ';
    }
    cout<<endl;
    delete[] p;
    return la;
} // c version




int main(){

    int* i=f(gaa,10);

    int aa[10];
    for (int i=0;i<10;++i){
        int fac=1;
        for(int j=1;j<=i+1;++j){
            fac*=j;
        }
        aa[i]=fac;
    }

    int* xd=f(aa,10);

    // int* arr=f(gaa,10);
    // for(int i=0;i<10;++i){
    //     cout<<arr[i]<<' ';
    // }
    // cout<<endl;

    // int* p=new int(10);
    // copy(gaa,gaa+10,p);
    
    // for(int i=0;i<10;++i){
    //     cout<<p[i]<<' ';
    // }
    // cout<<endl;

    // delete[] p;

}