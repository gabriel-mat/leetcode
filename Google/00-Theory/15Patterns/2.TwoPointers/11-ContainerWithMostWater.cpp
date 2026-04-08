class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmount = 0, current;
        
        for(int left = 0, right = height.size() - 1; left < right; ){
            current = Area(left, right, height);
            maxAmount = max(current, maxAmount);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return max(current, maxAmount);
    }

    inline int Area(int left, int right, vector<int> &height){
        return (right - left) * (min(height[left], height[right]));
    }
};
