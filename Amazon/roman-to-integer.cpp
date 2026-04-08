#include <iostream>

using namespace std;

/*
    A performance já é ideal, mas a legibilidade pode melhorar
    Switch case é mais legível e ligeiramente mais eficiente
*/

class Solution {
    public:
        int romanToInt(string s) {
            int ans = 0, size = s.size();
            
            auto cti = [](char c){
                if(c == 'I') return 1;
                if(c == 'V') return 5;
                if(c == 'X') return 10;
                if(c == 'L') return 50;
                if(c == 'C') return 100;
                if(c == 'D') return 500;
                if(c == 'M') return 1000;
                return 0;
            };

            auto eval = [](int a, int b){
                int r = 0;

                if(a < b)
                    r = -2 * a;
                r += b;

                return r;
            };
            

            ans += cti(s[0]);
            for(int i = 1; i < size; i++)
                ans += eval(cti(s[i - 1]), cti(s[i]));

            return ans;
        }
    };