#include <vector>
#include <iostream>

using namespace std;

/*
    Algoritmo de Boyer-Moore
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int counter = 0, major;

        for (int n : nums)
        {
            if (!counter)
                major = n;

            if (n == major)
                counter++;
            else
                counter--;
        }

        return major;
    }
};