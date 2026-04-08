class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
      vector<int> WordsContaining;
      WordsContaining.reserve(words.size());

      for(int i = 0; i < words.size(); i++)
        if (words[i].find(x) != string::npos)
          WordsContaining.push_back(i);

      return WordsContaining;
    }
};
