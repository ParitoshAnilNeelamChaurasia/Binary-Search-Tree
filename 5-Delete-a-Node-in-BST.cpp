// https://leetcode.com/problems/delete-node-in-a-bst/

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

class Solution
{
public:
    // Function to handle the deletion of a node from the BST
    TreeNode *f(TreeNode *root)
    {
        // If the node to be deleted has no left child, return its right child
        if (root->left == NULL)
        {
            return root->right;
        }
        // If the node to be deleted has no right child, return its left child
        else if (root->right == NULL)
        {
            return root->left;
        }

        // If the node to be deleted has both children
        TreeNode *right_child = root->right;                // Store the right child temporarily
        TreeNode *last_right = find_last_right(root->left); // Find the last right node of the left subtree

        // Connect the right subtree to the last right node of the left subtree
        last_right->right = right_child;

        // Return the left subtree which now includes the right subtree
        return root->left;
    }

    // Helper function to find the last right node in the left subtree
    TreeNode *find_last_right(TreeNode *root)
    {
        // Traverse to the rightmost node of the left subtree
        if (root->right == NULL)
        {
            return root; // Return the last right node
        }
        return find_last_right(root->right); // Recursively search to the right
    }

    // Function to delete a node with the specified key from the BST
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // If the tree is empty, return NULL
        if (root == NULL)
        {
            return NULL;
        }

        // If the current node is the one to be deleted
        if (root->val == key)
        {
            return f(root); // Call the helper function to delete it
        }

        TreeNode *curr = root; // Maintain a reference to the root

        // Traverse the tree to find the node with the specified key
        while (curr != NULL)
        {
            // If the key is less than the current node's value, go to the left subtree
            if (curr->val > key)
            {
                // If the left child is the node to be deleted
                if (curr->left != NULL && curr->left->val == key)
                {
                    curr->left = f(curr->left); // Delete the left child and update the link
                    break;                      // Exit the loop once the node is deleted
                }
                else
                {
                    curr = curr->left; // Move to the left child
                }
            }
            // If the key is greater than the current node's value, go to the right subtree
            else
            {
                // If the right child is the node to be deleted
                if (curr->right != NULL && curr->right->val == key)
                {
                    curr->right = f(curr->right); // Delete the right child and update the link
                    break;                        // Exit the loop once the node is deleted
                }
                else
                {
                    curr = curr->right; // Move to the right child
                }
            }
        }

        // Return the original root of the tree, unchanged
        return root;
    }
};
