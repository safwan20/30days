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
    vector<int>arr, res;

    void inorder(TreeNode* root, vector<int>& arr) {

        if (root == NULL) {
            arr.push_back(100000);
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        inorder(root, arr);

        for (auto x : arr) {
            if (x != 100000)
                res.push_back(x);
        }

        return res;
    }
};