#include <map>
#include <string>
#include <iostream>

/*
    - Map: Red-black
    - Unordered Map: Hashmap
*/

using namespace std;

int main(){
    map<string, string> Dictionary;

    // Insert
    Dictionary.insert(pair<string, string>("Oi", "Salut"));
    Dictionary.insert(pair<string, string>("Ele", "il"));
    Dictionary.insert(pair<string, string>("Ela", "Elle"));
    Dictionary.insert(pair<string, string>("Feliz", "Content"));
    
    // Update
    Dictionary["Ele"] = "Il";

    // Delete
    Dictionary.erase("Feliz");

    for(auto p : Dictionary)
        cout << p.first << " - " << p.second << endl;

    return 0;
}