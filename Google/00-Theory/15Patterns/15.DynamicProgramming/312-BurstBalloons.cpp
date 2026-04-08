// A ideia é que em DP precisamos ter subproblemas independentes
// então não podemos escolher o próximo balão a ser estourado
// já que os dois subproblemas formados iriam ser dependentes (iam ser adjacentes);
// A ideia é calcular como se K fosse o último balão a ser estourado

class Solution {
public:
    int n;
    int t[501][501]; 
                     
    int solve(vector<int> &nums, int i, int j){
		if(i > j) return 0;

        // 1 element
        if(i == j){
            int temp = nums[i];
            if(i - 1 >= 0) temp *= nums[i - 1];
            if(i + 1 < n)  temp *= nums[i + 1];
            return temp;
        }

        // memoization
		if(t[i][j] != -1) return t[i][j];

        int ans = 0;
		
        for(int k = i; k <= j; k++){
            int temp = nums[k];
			
            if(j + 1 < n) temp *= nums[j + 1];
            if(i - 1 >= 0) temp *= nums[i - 1];
				
            temp += (solve(nums, i, k - 1) + solve(nums, k + 1, j));
            ans = max(ans, temp);
        }

        return t[i][j] = ans;
    }
    
    int maxCoins(vector<int> &nums) {
        memset(t, -1, sizeof(t));
		vector<int> arr;

        arr.push_back(1);
        for(int num : nums) arr.push_back(num);
        arr.push_back(1);

        n = arr.size();
		
        return solve(arr, 1, arr.size() - 2);
    }
};
