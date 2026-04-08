class Solution{
    public:
      string longestCommonPrefix(vector<string>& strs) {
        char character;
        string prefix = "";

        for(int i = 0; ; ++i){
            character = strs[0][i];

            for(const string &str : strs){
                if(i == str.size())
                  return prefix;

                if(str[i] != character)
                  return prefix;
              }

            prefix += character;
          }

        return prefix;
      }
  };
