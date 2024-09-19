//leetcode: https://leetcode.com/problems/binary-tree-paths/

//Approach 1 (Changing recursive call to maintain path easily)
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
    void buildPaths(TreeNode* root, string path, vector<string> &result) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            path += "->";
            buildPaths(root->left, path, result);
            buildPaths(root->right, path, result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        buildPaths(root, "", result);
        return result;
    }
};

//Approach 2 (The more efficient one)
//(Takes path from left and right side and keeps adding into the path from previous calls)
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
    void buildPaths(TreeNode* root, string path, vector<string> &result) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            path += "->";
            buildPaths(root->left, path, result);
            buildPaths(root->right, path, result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        buildPaths(root, "", result);
        return result;
    }
};
