// https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

class Solution {
public:
    Node* insert(Node* node, int data) 
    {
        // If the tree is empty, create a new node and return it
        if (node == NULL) 
        {
            return new Node(data);
        }
        
        Node* curr = node;
        
        // Traverse the tree to find the correct position to insert the new node
        while (true) 
        {
            if (curr->data < data) 
            {  // Insert in the right subtree
                if (curr->right != NULL) 
                {
                    curr = curr->right;
                } 
                else 
                {
                    curr->right = new Node(data);
                    break;
                }
            } 
            else if (curr->data > data) 
            {  // Insert in the left subtree
                if (curr->left != NULL) 
                {
                    curr = curr->left;
                } 
                else 
                {
                    curr->left = new Node(data);
                    break;
                }
            } 
            else 
            {
                // **Correction**: Do nothing if `curr->data == data` (to avoid duplicates)
                break;
            }
        }
        
        // Return the root node after insertion
        return node;
    }
};
