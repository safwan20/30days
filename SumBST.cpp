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

    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            if (arr[i] + arr[j] == k) {
                return true;
            }
            else if (arr[i] + arr[j] > k) {
                j = j - 1;
            }
            else {
                i = i + 1;
            }
        }
        return false;
    }
};