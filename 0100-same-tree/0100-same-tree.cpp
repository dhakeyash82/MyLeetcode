class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p == q;
        }

        bool isleftSame  = isSameTree(p->left, q->left);
        bool isrightSame = isSameTree(p->right, q->right);
        return isleftSame && isrightSame && p->val == q->val;
    }
};