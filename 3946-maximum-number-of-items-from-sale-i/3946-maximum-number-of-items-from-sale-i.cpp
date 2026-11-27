class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheapest = INT_MAX;

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            cheapest = min(cheapest, price);

            int freeCnt = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeCnt++;
                }
            }

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b],
                            dp[b - price] + freeCnt + 1);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans,
                      dp[b] + (budget - b) / cheapest);
        }

        return ans;
    }
};
