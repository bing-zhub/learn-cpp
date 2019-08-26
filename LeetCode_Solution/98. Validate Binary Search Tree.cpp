/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 *  
 * 
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
    
    bool dfs(TreeNode* root, long long min, long long max){
        if(!root) return true;
        if(root->val < min || root->val > max) return false;
        
        return dfs(root->left, min, root->val-1ll) && dfs(root->right, root->val + 1ll, max);
    }
};