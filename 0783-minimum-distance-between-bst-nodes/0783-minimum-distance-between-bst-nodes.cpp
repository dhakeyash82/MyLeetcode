class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;

        ans = min(ans, minDiffInBST(root->left));

        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        ans = min(ans, minDiffInBST(root->right));

        return ans;
    }
};