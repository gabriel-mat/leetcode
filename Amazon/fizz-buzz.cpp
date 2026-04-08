#include <vector>
#include <iostream>

using namespace std;

/*
    Uma possível otimização é a construção de uma tabela com as strings dos números
*/

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> v(n);

        for(int i = 1; i <= n; i++){
            if(i % 3 && i % 5)
            {
                v[i - 1] = to_string(i);
                continue;
            }
            
            if(!(i % 15))
            {
                v[i - 1] = "FizzBuzz";
                continue;
            }

            if(!(i % 3))
                v[i - 1] = "Fizz";
            else
                v[i - 1] = "Buzz";
        }

        return v;
    }
};