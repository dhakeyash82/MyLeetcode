class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int dominant = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                dominant = nums[i];
            }

            if (nums[i] == dominant) {
                count++;
            } else {
                count--;
            }
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant) {
                total++;
            }
        }

        int left = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                left++;
            }

            int right = total - left;

            if (left * 2 > i + 1 &&
                right * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};