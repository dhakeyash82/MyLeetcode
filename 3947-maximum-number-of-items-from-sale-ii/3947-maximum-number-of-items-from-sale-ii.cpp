class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto &x : items) {
            freq[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                freq[i] += freq[j];
            }
        }

        vector<pair<int, int>> v;

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            int freeItems = freq[factor] - 1;

            if (price < 2 * minPrice && freeItems > 0) {
                v.push_back({price, freeItems});
            }
        }

        sort(v.begin(), v.end());

        long long ans = 0;

        for (auto &x : v) {
            int price = x.first;
            int count = x.second;

            int buy = min(count, budget / price);

            ans += 2LL * buy;
            budget -= buy * price;
        }

        ans += budget / minPrice;

        return (int)ans;
    }
};
