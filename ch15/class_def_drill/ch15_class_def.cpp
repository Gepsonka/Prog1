#include <string>
#include <iostream>
#include <vector>


struct Person {
    Person(){
        first_name="";
        second_name="";
        age=0;
    }
    Person(std::string str,std::string str2,int n) : first_name(str),second_name(str2), age(n) {
        check_age(age);
        check_name(first_name);
        check_name(second_name);
        
    }

    friend std::ostream &operator<<(std::ostream &output, Person &P);
    friend std::istream &operator>>(std::istream &input, Person &P);

    void check_age(int n);
    void check_name(std::string n);

    std::string const get_name(){
        return first_name+" "+second_name;
    }

    int const get_age(){
        return age;
    }

    void set_first_name(std::string x){
        first_name=x;
    }

    void set_second_name(std::string x){
        second_name=x;
    }

    void set_age(int x){
        age=x;
    }
private:

    std::string first_name;
    std::string second_name;
    int age;

};


std::ostream &operator<<(std::ostream &output, Person &P){
    output<<"Name:"<<P.first_name<<" "<<P.second_name<<", age:"<<P.age;
    return output;
}

std::istream &operator>>(std::istream &input, Person &P){
    input>>P.first_name>>P.second_name>>P.age;
    P.check_age(P.get_age());
    P.check_name(P.get_name());

    return input;

}

void Person::check_age(int n){
    if (n<0 || n>150){
        throw ("Bad age range!");
    }
}

void Person::check_name(std::string n){
    for (auto i : n){
        switch (i){
        case ';':
            throw ("Bad char",i);
            break;
        case ':':
            throw ("Bad char", i);
            break;
        case '"':
            throw ("Bad char", i);
            break;
        case '\'':
            throw ("Bad char", i);
            break;
        case '[':
            throw ("Bad char", i);
            break;
        case ']':
            throw ("Bad char", i);
            break;
        case '*':
            throw ("Bad char", i);
            break;
        case '&':
            throw ("Bad char", i);
            break;
        case '^':
            throw ("Bad char", i);
            break;
        case '%':
            throw ("Bad char", i);
            break;
        case '$':
            throw ("Bad char", i);
            break;
        case '#':
            throw ("Bad char", i);
            break;
        case '@':
            throw ("Bad char", i);
            break;
        case '!':
            throw ("Bad char", i);
            break;
        }
    }
    
}


int main(){

    // Person per;
    // std::cin>>per;
    // std::cout<<per;


    std::vector<Person> prs;

    Person p;

    while (std::cin>>p){
        prs.push_back(p);
    }

    for (auto x : prs){
        std::cout<<x;
        std::cout<<"\n";
    }


    return 0;

}


