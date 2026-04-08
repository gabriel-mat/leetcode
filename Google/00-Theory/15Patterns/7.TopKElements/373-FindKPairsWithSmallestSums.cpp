class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        auto cmp = [](const vector<int>& a, const vector<int>& b) { return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        for (int i = 0; i < nums1.size() && i < k; ++i)
            minHeap.push({nums1[i] + nums2[0], i, 0});

        while (k-- > 0 && !minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int i = curr[1];
            int j = curr[2];
            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) // expandindo pra direita
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
        }

        return ans;
    }
};
