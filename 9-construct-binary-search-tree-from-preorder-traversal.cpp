// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* f(vector<int> &preorder , int &i , int mx)
    {
        // reaching at the end
        if(i == preorder.size() || preorder[i] > mx)
        {
            return NULL ;
        }

        TreeNode* root = new TreeNode(preorder[i]) ;
        i++ ;

        // root->left => must be smaller than its parent
        root->left = f(preorder , i , root->val) ;

        // must be greater than its parent
        root->right = f(preorder , i , mx) ;

        return root ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;

        return f(preorder , i , INT_MAX ) ;
    }
};
