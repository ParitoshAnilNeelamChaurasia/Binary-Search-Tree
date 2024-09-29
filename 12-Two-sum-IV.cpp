// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    vector<int> ans;

    // In-order traversal to get sorted values of the BST
    void f(TreeNode* root) {
        if (root == nullptr)
            return;

        f(root->left);
        ans.push_back(root->val);
        f(root->right);
    }

    // Function to find if there are two elements that sum up to k
    bool findTarget(TreeNode* root, int k) {
        // Perform in-order traversal to get sorted values
        f(root);

        // Edge case: If the tree has only one node
        if (ans.size() < 2) {
            return false;
        }

        // Check if the sum of the two largest values is smaller than k
        int mx_sum = ans[ans.size() - 1] + ans[ans.size() - 2];
        if (mx_sum < k) {
            return false;
        }

        // Use two-pointer technique to find two numbers that sum to k
        int left = 0;
        int right = ans.size() - 1;

        while (left < right) {
            int sum = ans[left] + ans[right];

            if (sum == k) {
                return true; // Found two numbers that sum up to k
            } else if (sum < k) {
                left++; // Increase left pointer to get a larger sum
            } else {
                right--; // Decrease right pointer to get a smaller sum
            }
        }

        return false; // No two numbers sum up to k
    }
};
