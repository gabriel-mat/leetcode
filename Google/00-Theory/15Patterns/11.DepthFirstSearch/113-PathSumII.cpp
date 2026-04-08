/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        recSum(root, targetSum, 0);
        return ans;
    }

    void recSum(TreeNode *root, int target, int sum){
        sum += root->val;
        path.push_back(root->val);
        int vSize = path.size();

        // leaf case
        if(!root->left && !root->right){
            if(sum == target)
                ans.push_back(path);

            return;
        }

        if(root->left)  recSum(root->left, target, sum);

        path.resize(vSize);

        if(root->right) recSum(root->right, target, sum);
    }
};
