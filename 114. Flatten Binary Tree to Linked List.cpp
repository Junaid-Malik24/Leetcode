//leetcode: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

//Approach 1 (Recursion)

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
    TreeNode* previous=nullptr;
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right=previous;
        root->left=NULL;
        previous=root;
    }
};

//Approach 2 (Using Stack)

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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            if (current->right) {
                s.push(current->right);
            }
            if (current->left) {
                s.push(current->left);
            }
            if (!s.empty()) {
                current->right = s.top();
            }
            current->left = nullptr;
        }
    }
};
