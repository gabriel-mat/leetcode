#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int rev = 0;

        if(x < 0 || x && !(x % 10))
            return false;

        while(x > rev){
            rev = 10 * rev + x % 10;
            x /= 10;
        }

        if(x == rev || x == rev / 10)
            return true;
        return false;
    }
};