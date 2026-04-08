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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        dfs_path(root, diameter);

        return diameter;
    }

private:
    int dfs_path(TreeNode *root, int &max_path){
        if(root == nullptr) return 0;

        int left_val = dfs_path(root->left, max_path);
        int right_val = dfs_path(root->right, max_path);

        max_path = max(max_path, left_val + right_val);
        return (max(left_val, right_val) + 1);
      }
};

