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

/*
 * Outras abordagens:
 * 1 - Morris traversal: N em tempo e 1 em espaço, mas menos legível
 * 2 - InOrder + armazenar em array: N em tempo e espaço    
 */    


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack< TreeNode * > stk;
        TreeNode *current = root;
        int counter = 0;

        while(current != nullptr || !stk.empty()){
            while(current != nullptr){
                stk.push(current);
                current = current->left;
            }

            current = stk.top();
            stk.pop();
            counter++;

            if(counter == k)
                return current->val;

            current = current->right;
        }

        return 0;
    }
};
