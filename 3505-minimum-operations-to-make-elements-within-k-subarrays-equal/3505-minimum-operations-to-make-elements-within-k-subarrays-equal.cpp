class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1, 0);
        
        multiset<long long> L, R;
        long long l_sum = 0, r_sum = 0;

        auto balance = [&]() {
            while (L.size() > R.size() + 1) {
                long long v = *L.rbegin();
                L.erase(L.find(v)); l_sum -= v;
                R.insert(v); r_sum += v;
            }
            while (R.size() > L.size()) {
                long long v = *R.begin();
                R.erase(R.find(v)); r_sum -= v;
                L.insert(v); l_sum += v;
            }
        };

        auto add = [&](long long v) {
            if (L.empty() || v <= *L.rbegin()) { L.insert(v); l_sum += v; }
            else { R.insert(v); r_sum += v; }
            balance();
        };

        auto rem = [&](long long v) {
            if (L.find(v) != L.end()) { L.erase(L.find(v)); l_sum -= v; }
            else { R.erase(R.find(v)); r_sum -= v; }
            balance();
        };

        for (int i = 0; i < x; ++i) add(nums[i]);
        cost[0] = (r_sum - R.size() * *L.rbegin()) + (L.size() * *L.rbegin() - l_sum);

        for (int i = 1; i <= n - x; ++i) {
            rem(nums[i - 1]);
            add(nums[i + x - 1]);
            cost[i] = (r_sum - R.size() * *L.rbegin()) + (L.size() * *L.rbegin() - l_sum);
        }

        const long long INF = 1e18;
        vector<long long> dp(n + 1, 0);

        for (int j = 1; j <= k; ++j) {
            vector<long long> next_dp(n + 1, INF);
            long long min_prev = INF;
            for (int i = 1; i <= n; ++i) {
                if (i >= x) min_prev = min(min_prev, dp[i - x] + cost[i - x]);
                next_dp[i] = min(next_dp[i - 1], min_prev);
            }
            dp = move(next_dp);
        }

        return dp[n];
    }
};