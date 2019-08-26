/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode *> q;
        vector<vector<int>> ret;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> level;
            for(int i = 0; i < len; i++){
                auto p = q.front();
                q.pop();
                level.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ret.push_back(level);
        }
        return ret;
    }
};