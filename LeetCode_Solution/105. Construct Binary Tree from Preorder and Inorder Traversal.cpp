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
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
        if(l1>r1) return NULL;
        auto t = new TreeNode(preorder[l1]);
        
        int i;
        for( i = l2; i <= r2; i++) if(inorder[i] == preorder[l1]) break; 
        
        t->left = createTree(preorder, inorder, l1+1, l1-l2+i, l2, i-1);
        t->right = createTree(preorder, inorder, l1-l2+i+1, r1, i+1, r2);
        return t;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return createTree(preorder, inorder, 0, n-1, 0, n-1);
    }
    
};