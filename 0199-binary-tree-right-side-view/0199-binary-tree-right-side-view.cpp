class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(i == n-1) {
                    ans.push_back(temp->val);
                }
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }       
        return ans;
    }
};
