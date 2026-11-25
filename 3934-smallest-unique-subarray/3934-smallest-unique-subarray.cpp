class Solution {
public:
    int smallestUniqueSubarray(std::vector<int>& nums) {
        int n = nums.size();
        
        long long MOD1 = 1e9 + 7;
        long long MOD2 = 1e9 + 9;
        long long BASE1 = 100003;
        long long BASE2 = 100019;

        std::vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }

        std::vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
        }

        auto getHash = [&](int l, int r) {
            long long hash1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
            if (hash1 < 0) hash1 += MOD1;
            long long hash2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;
            if (hash2 < 0) hash2 += MOD2;
            return (hash1 << 32) | hash2; 
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            std::unordered_map<unsigned long long, int> freq;
            bool foundUnique = false;

            for (int i = 0; i <= n - mid; ++i) {
                unsigned long long currentHash = getHash(i, i + mid - 1);
                freq[currentHash]++;
            }

            for (auto& pair : freq) {
                if (pair.second == 1) {
                    foundUnique = true;
                    break;
                }
            }

            if (foundUnique) {
                ans = mid;    
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};