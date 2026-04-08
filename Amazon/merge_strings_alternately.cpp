#include <iostream>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int w1s = word1.size(), w2s = word2.size();
        int size = max(w1s, w2s);

        for (int i = 0; i < size; i++)
        {
            if (i < w1s)
                ans += word1[i];

            if (i < w2s)
                ans += word2[i];
        }

        return ans;
    }
};