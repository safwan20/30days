class Solution {
public:
    vector<int>arr;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        inorder(root);
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};