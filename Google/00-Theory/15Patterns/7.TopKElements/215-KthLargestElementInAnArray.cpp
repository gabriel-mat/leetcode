// Usando min heap:
// O(N*logK)
// isso porque usamos um heap de K nós, guardando os K maiores
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> ans(k);

        for(int i = 0; i < k; ++i)
            ans[i] = nums[i];

        make_heap(ans.begin(), ans.end(), greater<>{}); // min heap
        
        for(int i = k; i < nums.size(); ++i)
            if(nums[i] > ans[0]){
                pop_heap(ans.begin(), ans.end(), greater<>{});
                ans[k - 1] = nums[i];
                push_heap(ans.begin(), ans.end(), greater<>{});
            }

        return ans[0];
    }
};

// Usando uma priority queue o código fica mais limpo
// (mantém a complexidade)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i < nums.size(); ++i) {
            minHeap.push(nums[i]);

            if(minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};

//
// É possível resolver em O(n) usando o QuickSelect
//
// mesma ideia do quicksort, mas não ordena tudo
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }

    int quickselect(vector<int>& nums, int l, int r, int k) {
        if (l >= r)
            return nums[k];

        // 1. Calculamos um índice à sorte que esteja entre 'l' e 'r'
        int randomIndex = l + rand() % (r - l + 1);
        
        // 2. Trocamos o elemento que estava nesse índice aleatório com o da posição 'l'
        swap(nums[l], nums[randomIndex]);

        // O nums[l] agora tem um valor aleatório, garantindo rapidez.
        int pivot = nums[l];
        int i = l + 1;
        int j = r;

        while (i <= j) {
            while (i <= j && nums[i] < pivot)
                i++;
            while (i <= j && nums[j] > pivot)
                j--;

            if (i >= j) break;

            swap(nums[i++], nums[j--]);
        }
        
        swap(nums[l], nums[j]);

        if (k == j) return nums[j];
        
        if (k < j) return quickselect(nums, l, j - 1, k);
        
        return quickselect(nums, j + 1, r, k);
    }
};
