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

    void LTraversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level == 1) {
            temp.push_back(root->val);
        }
        LTraversal(root->left, level - 1);
        LTraversal(root->right, level - 1);
    }

    void RTraversal(TreeNode* root, int level) {
        if (root == NULL) {
            return;
        }
        if (level == 1) {
            temp.push_back(root->val);
        }
        RTraversal(root->right, level - 1);
        RTraversal(root->left, level - 1);
    }

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        int height = Height(root);
        for (int i = 0; i <= height; i++) {
            if (i % 2 == 0) {
                LTraversal(root, i + 1);
            }
            else {
                RTraversal(root, i + 1);
            }
            res.push_back(temp);
            temp.clear();
        }
    }



    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        inorder(root);
        for (auto x : res) {
            if (x.size() != 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};