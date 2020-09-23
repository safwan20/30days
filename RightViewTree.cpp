class Solution {
public:
    vector<int>res;

    void RSV(TreeNode* root , int l, int *ml) {
        if (root == NULL) {
            return;
        }
        if (*ml < l) {
            res.push_back(root->val);
            *ml = l;
        }
        RSV(root->right, l + 1, ml);
        RSV(root->left, l + 1, ml);
    }

    vector<int> rightSideView(TreeNode* root) {
        int ml = 0;
        RSV(root, 1, &ml);
        return res;
    }
};