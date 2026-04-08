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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode *> q;
        TreeNode *current;
        int levelSize;
        
        q.push(root);

        while(!q.empty()){
            levelSize = q.size();
            vector<int> level;

            while(levelSize--){
                current = q.front(); q.pop();
                if(current->left)  q.push(current->left);
                if(current->right) q.push(current->right);
                level.push_back(current->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
