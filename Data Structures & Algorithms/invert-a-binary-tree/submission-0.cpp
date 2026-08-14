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
    TreeNode* invertTree(TreeNode* root) {
        // assign current
        // recursive call left = right
        // recursive clal right = left
        if (root == nullptr) return nullptr;
        TreeNode* new_node = new TreeNode(root->val);
        new_node->left=invertTree(root->right);
        new_node->right=invertTree(root->left);
        return new_node;
    }
};
