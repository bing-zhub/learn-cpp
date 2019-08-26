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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ret;
        TreeNode *p = root;
        stack<TreeNode *> s;
        while(!s.empty() || p){
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            ret.push_back(p->val);
            p = p->right;
        }
        return ret;
    }
};