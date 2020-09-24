class Solution {
public:
    vector<int>arr;
    int min;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        for (int i = 0; i < k; i++) {
            min = arr[i];
        }
        return min;

    }
};