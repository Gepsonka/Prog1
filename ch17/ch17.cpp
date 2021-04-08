#include <iostream>
#include <vector>

void print_array(std::ostream& os,int* n,int s){
    for(int i=0;i<s;++i){
        os<<n[i]<<"\n";
    }
}

template <typename T>
void print_vector(std::ostream& os,const std::vector<T>& vec){
    for(int i=0;i<vec.size();++i){
        os<<vec[i]<<"\n";
    }
}


int main(){

    int* nums=new int[10]{100,101,102,103,104};
    int* more_nums=new int[11]{100,101,102,103,104,105};
    int* most_nums=new int[20]{100,101,102,103,104,105,106,107,108,109,110,112};

    // print_array(std::cout,nums,10);
    // print_array(std::cout,more_nums,11);
    // print_array(std::cout,most_nums,20);

    delete[] nums;
    delete[] more_nums;
    delete[] most_nums;

    std::vector<int> vec_nums {100,101,102,103,104};
    std::vector<int> more_vec_nums {100,101,102,103,104,105};
    std::vector<int> most_vec_nums {100,101,102,103,104,105,106,107,108,109,110,112};

    print_vector<int>(std::cout,vec_nums);
    print_vector<int>(std::cout,more_vec_nums);
    print_vector<int>(std::cout,most_vec_nums);

    return 0;
}