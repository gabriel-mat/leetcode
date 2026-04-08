/*
 * Edge cases:
 * 1 - Strings cannot be empty
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      string merged = "";

      for(int i = 0, j = 0; i < word1.size() || j < word2.size(); ){
          if(i < word1.size())
            merged += word1[i++];
          
          if(j < word2.size())
            merged += word2[j++];
        }

      return merged;
    }
};
