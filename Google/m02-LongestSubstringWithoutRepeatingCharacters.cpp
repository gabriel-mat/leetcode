class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
        vector<int> chars(128, -1);

        for(int left = 0, right = 0; right < s.size(); right++){
            if(chars[s[right]] >= left)
                left = chars[s[right]] + 1;

            chars[s[right]] = right;
            maxCount = std::max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};
