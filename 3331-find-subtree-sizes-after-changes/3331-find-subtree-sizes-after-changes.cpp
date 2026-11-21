
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans, parent;
    int last[26];
    void dfs(int node, string &s) {
        int index = s[node] - 'a';
        int old = last[index];
        last[index] = node;
        for (int child : adj[node]) {
            int ch = s[child] - 'a';
            if (last[ch] != -1) {
                parent[child] = last[ch];
            }
            dfs(child, s);
        }
        last[index] = old;
    }
    void calculate(int node, vector<vector<int>>& newTree) {
        ans[node] = 1;
        for (int child : newTree[node]) {
            calculate(child, newTree);
            ans[node] += ans[child];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        parent = p;
        adj.resize(n);
        ans.resize(n);
        fill(last, last + 26, -1);
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }
        dfs(0, s);
        vector<vector<int>> newTree(n);
        for (int i = 1; i < n; i++) {
            newTree[parent[i]].push_back(i);
        }
        calculate(0, newTree);
        return ans;
    }
};
