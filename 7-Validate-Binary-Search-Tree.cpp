// https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
    bool f(TreeNode* root, long long min_value, long long max_value) {
        if (root == nullptr) {
            return true;
        }

        // Check if the current node's value is within the valid range
        if (root->val <= min_value || root->val >= max_value) {
            return false;
        }

        // Recursively check left and right subtrees with updated ranges
        return f(root->left, min_value, root->val) && f(root->right, root->val, max_value);
    }

    bool isValidBST(TreeNode* root) 
    {
        return f(root, LLONG_MIN, LLONG_MAX);
    }
};
