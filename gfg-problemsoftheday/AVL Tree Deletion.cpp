// AVL Tree Deletion
// HardAccuracy: 47.98%Submissions: 13K+Points: 8
// Win from a prize pool of INR 15K and get exciting merch! Register your team for Hack-A-Thon today!

// Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

// Example 1:

// Tree = 
//         4
//       /   \
//      2     6
//     / \   / \  
//    1   3 5   7

// N = 4
// Values to be deleted = {4,1,3,6}

// Input: Value to be deleted = 4
// Output:
//         5    
//       /   \
//      2     6
//     / \     \  
//    1   3     7

// Input: Value to be deleted = 1
// Output:
//         5    
//       /   \
//      2     6
//       \     \  
//        3     7

// Input: Value to be deleted = 3
// Output:
//         5    
//       /   \
//      2     6
//             \  
//              7

// Input: Value to be deleted = 6
// Output:
//         5    
//       /   \
//      2     7

// Your Task:  
// You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

// Note: The tree will be checked after each deletion. 
// If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
// If instead all deletion are successful, inorder traversal of tree will be printed.
// If every single node is deleted from tree, 'null' will be printed.

// Expected Time Complexity: O(height of tree)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ N ≤ 500


int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node* leftRotate(Node* root) {
    Node* newMid = root->right;
    Node* temp = newMid->left;

    // rotation
    newMid->left = root;
    root->right = temp;

    // updating height
    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    // return new root after rotation
    return newMid;
}

Node* rightRotate(Node* root) {
    Node* newMid = root->left;
    Node* temp = newMid->right;

    // rotation
    newMid->right = root;
    root->left = temp;

    // updating height
    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    // return new root after rotation
    return newMid;
}

Node* inorderSucc(Node* root) {
    Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteAVL(Node* root, int val) {
    // Normal BST deletion
    if (root == NULL) {
        return NULL;
    }

    if (val < root->data) {
        root->left = deleteAVL(root->left, val);
    } else if (val > root->data) {
        root->right = deleteAVL(root->right, val);
    } else {
        // Node has no child
        if (root->left == NULL and root->right == NULL) {
            return NULL;
        }

        // Node with only one child or no child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = inorderSucc(root->right);

        // Copy the inorder successor's content to this Node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteAVL(root->right, temp->data);
    }

    if (root == NULL) {
        return root;
    }

    // 2. Update height of ancestor Node
    root->height = max(height(root->left), height(root->right)) + 1;

    // 3. Get the balance factor of the ancestor
    int balance = getBalanceFactor(root);

    // if balanced then simply return
    if (balance <= 1 && balance >= -1) {
        return root;
    }

    // if current Node is unbalanced, then
    // check for 4 cases

    // Left Left case
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}

Node* deleteNode(Node* root, int data) {
    return deleteAVL(root, data);
}


















