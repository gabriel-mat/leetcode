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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        recPath(root);
        return maxSum;
    }

    int recPath(TreeNode *node){
        if (!node) return 0;

        int left = max(recPath(node->left), 0);
        int right = max(recPath(node->right), 0);

        maxSum = max(maxSum, node->val + left + right); // opção fechando o caminho
        return node->val + max(left, right);            // opção aumentando o caminho pra cima
    }
};
