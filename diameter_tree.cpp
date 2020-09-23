class Solution {
public:
    int Height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(Height(root->left), Height(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int option1 = Height(root->left) + Height(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);

        return max(option1, max(option2, option3));
    }
};