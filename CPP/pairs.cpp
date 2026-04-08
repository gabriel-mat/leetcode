#include <tuple>
#include <string>
#include <iostream>

// tuple é uma generalização do pair

using namespace std;

int main(){
    pair<string, int> x;
    x.first = "Name";
    x.second = 1;

    cout << x.first << " - " << x.second << endl;

    pair<string, int> y = pair<string, int>("Name", 2);
    pair<string, int> z = make_pair<>("Name", 2);
    
    x = {"Name", 3}; // packing - Uniform Initialization
    auto[name, age] = x; // unpacking - Structured Bindings
    cout << name << " - " << age << endl; 

    /*
        name e age funcionam como variaveis, mas 
        sao copias dos valores do pair

        para usar referencia, o unpacking seria:
        auto& [name, age] = x

        assim, elas teriam ligacao com os valores do pair
    */

    return 0;
}