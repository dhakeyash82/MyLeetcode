class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_sum = INT_MAX;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                int length = j - i + 1;
                
                if (length >= l && length <= r) {
                    if (current_sum > 0) {
                        min_sum = min(min_sum, current_sum);
                    }
                }
                
                if (length > r) {
                    break;
                }
            }
        }
        
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};