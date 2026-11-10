class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            if (dp[i] == 1e18) continue;
            
            for (int jump = 1; jump <= 3; ++jump) {
                int j = i + jump;
                if (j <= n) {
    
                    long long cost = dp[i] + costs[j - 1] + (long long)(j - i) * (j - i);
                    dp[j] = min(dp[j], cost);
                }
            }
        }
        
        return dp[n];
    }
};