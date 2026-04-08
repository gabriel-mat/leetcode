#include <vector>
#include <iostream>

using namespace std;

/*
    A sacada é que a pilha não é só de múltiplos, mas também de strings
    A lógica é bonita, mas a performance é bem pior
*/

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        string s;
        vector<string> ans;
        ans.reserve(n);


        for(int i = 1; i <= n; i++){
            s = "";
            
            if(i % 3 == 0)
                s += "Fizz";
            if(i % 5 == 0)
                s += "Buzz";
            if(s.empty())
                s += to_string(i);

            ans.push_back(s);
        }

        return ans;
    }   
};