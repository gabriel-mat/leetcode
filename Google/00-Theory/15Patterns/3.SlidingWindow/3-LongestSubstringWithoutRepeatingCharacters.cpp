class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left, right, maxL = 0;
        vector<int> positions(128, -1);

        for(left = 0, right = 0; right < s.size(); right++){
            if(positions[s[right]] >= left)
                maxL = max(maxL, right - left), left = positions[s[right]] + 1;

            positions[s[right]] = right;
        }

        return max(maxL, right - left);
    }
};
