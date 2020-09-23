class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res, ans;

    int Height(TreeNode* root) {
        if (root ==  NULL) {
            return 0;
        }
        return max(Height(root->left), Height(root->right)) + 1;
    }

    void Traversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level == 1) {
            temp.push_back(root->val);
        }
        Traversal(root->left, level - 1);
        Traversal(root->right, level - 1);
    }


    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        int height = Height(root);
        for (int i = 0; i <= height; i++) {
            Traversal(root, i + 1);
            res.push_back(temp);
            temp.clear();
        }
    }



    vector<vector<int>> levelOrder(TreeNode* root) {
        inorder(root);
        for (auto x : res) {
            if (x.size() != 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};