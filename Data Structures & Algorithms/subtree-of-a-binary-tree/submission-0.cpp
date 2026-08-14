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
    bool compareTree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr && root == nullptr) return true;
        if (subRoot == nullptr || root == nullptr ) return false;
        if (root->val != subRoot->val) return false;
        return compareTree(root->left, subRoot->left) && compareTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        bool compare = false;
        if (root->val == subRoot->val) {
            compare = compareTree(root,subRoot);
        }
        return compare || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
