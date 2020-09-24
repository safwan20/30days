class Solution {
public:

    TreeNode* create_node(int &key) {
        TreeNode* root = new TreeNode();
        root->val = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    TreeNode* insert(TreeNode* root, int &key) {

        if (root == NULL) {
            root = create_node(key);
            return root;
        }

        else if (key > root->val) {
            root->right = insert(root->right, key);
        }

        else {
            root->left = insert(root->left, key);
        }
        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for (auto x : preorder)  {
            root = insert(root, x);
        }
        return root;
    }
};