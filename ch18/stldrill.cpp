#include <vector>
#include <iostream>

using namespace std;

vector<int> gv {1,2,4,8,16,32,64,128,256,512};

void f(vector<int> vec){
    // vector<int> lv = gv;
    vector<int> lv (vec.size());
    copy(gv.begin(),gv.end(),lv.begin());
    for (auto i:lv){
        cout<<i<<' ';
    }
    cout<<endl;
    vector<int> lv2 {vec};
    for (auto i:lv2){
        cout<<i<<' ';
    }
    cout<<endl;

}

int main(){

    f(gv);

    vector<int> vv {1,1*2,1*2*3,1*2*3*4,1*2*3*4*5,1*2*3*4*5*6,1*2*3*4*5*6*7,1*2*3*4*5*6*7*8,1*2*3*4*5*6*7*8*9,1*2*3*4*5*6*7*8*9*10};
    f(vv);




}