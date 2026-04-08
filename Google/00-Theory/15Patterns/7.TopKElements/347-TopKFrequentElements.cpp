// 
// Bucket Sort resolveria em O(N)
// mas com Heap fazemos em O(N * logK)
//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int n : nums) 
            freq[n]++;

        auto cmp = [](const pair<int, int> &a,  const pair<int, int> &b){ return a.second > b.second; };

        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> minHeap;

        for(const auto &p : freq){
            minHeap.push(p);

            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> ans(k);

        for(int i = 0; i < k; ++i)
            ans[i] = minHeap.top().first, minHeap.pop();

        return ans;
    }
};
