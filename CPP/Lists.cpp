#include <iostream>
#include <list>

bool func(int n);
void print(std::list<int>& l);

int main(){
    std::list<int> l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    // Inserts a copy of value BEFORE pos
    l1.insert(l1.begin(), 0);
    l1.insert(l1.end(), 6); // insert nao sobrescreve, mas rearranja os links

    print(l1);

    std::list<int> l2;

    l2.push_back(8);
    l2.push_back(9);
    l2.push_back(10);
    l2.push_back(11);
    l2.push_back(12);
    l2.insert(l2.begin(), 7);
    l2.insert(l2.end(), 13);
    print(l2);    

    l1.splice(l1.end(), l2, l2.begin());
    print(l1);
    print(l2);

    l1.merge(l2);
    // ou l1.splice(l1.end(), l2);
    print(l1);
    print(l2);

    std::cout << std::endl;

    l1.reverse();
    print(l1);

    l1.remove(13);
    print(l1);

    l1.remove_if(func);
    print(l1);

    l1.sort();
    print(l1);

    // usando lambda functions
    l1.remove_if([](int x){ return x < 3 || x > 9; });
    print(l1);

    return 0;
}

void print(std::list<int>& l){
    for(auto i : l)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool func(int n){
    return n % 2;
}