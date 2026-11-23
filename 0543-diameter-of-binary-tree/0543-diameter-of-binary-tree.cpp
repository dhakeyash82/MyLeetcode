class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        return max(leftHt, rightHt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);
        int currDiam = height(root->left) + height(root->right);

        return(max(currDiam, max(leftDiam,rightDiam)));
    }
};