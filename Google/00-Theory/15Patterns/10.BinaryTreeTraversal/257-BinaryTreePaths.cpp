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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        recPath(root, "", ans);

        return ans;
    }

    void recPath(TreeNode *node, string currPath, vector<string> &ans){
        currPath += to_string(node->val);
        
        if(!node->left && !node->right){
            ans.push_back(currPath);
            return;
        }
        
        currPath += "->";
        
        if(node->left) recPath(node->left, currPath, ans);
        if(node->right) recPath(node->right, currPath, ans);
    }
};


// Possível otimização com backtracking
// passando as strings (paths) por referência

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string currPath = "";
        recPath(root, currPath, ans);

        return ans;
    }

    void recPath(TreeNode *node, string &currPath, vector<string> &ans){
        int originalLen = currPath.length();

        currPath += to_string(node->val);

        if(!node->left && !node->right){
            ans.push_back(currPath);
        } else {
            currPath += "->";
            
            if(node->left) recPath(node->left, currPath, ans);
            if(node->right) recPath(node->right, currPath, ans);
        }

        currPath.resize(originalLen); // como é a mesma string para os demais caminhos, precisamos que seja um uso "limpo"
    }
};
