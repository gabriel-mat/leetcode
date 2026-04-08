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

// Resolução mais trivial: BFS com inversão no final
// O(N) em espaço e em tempo

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> ans;

        q.push(root);

        while (!q.empty()) {
            vector<int> vec;
            int s = q.size();

            for (int i = 0; i < s; i++) {
                TreeNode* tree = q.front();
                q.pop();

                if(!tree) continue;

                q.push(tree->left);
                q.push(tree->right);
                vec.push_back(tree->val);
            }

            if(q.empty())break;
            ans.push_back(vec);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
