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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *p;
        while(!s.empty()){
            p = s.top();
            s.pop();
            if(!p) continue;
            ret.push_back(p->val);
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }
        
        return ret;
    }
};