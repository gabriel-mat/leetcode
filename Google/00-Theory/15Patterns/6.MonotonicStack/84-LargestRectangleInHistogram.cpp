class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);

        for(int i = 0; i < n; ++i) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>();

        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; ++i) {
            int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
