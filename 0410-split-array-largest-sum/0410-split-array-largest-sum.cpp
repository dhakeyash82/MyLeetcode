class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;
        for (int num : nums) {
            low = max(low, (long long)num); 
            high += num;                    
        } 
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isValid(nums, k, mid)) {
                ans = mid;         
                high = mid - 1;
            } else {
                low = mid + 1;      
            }
        }
        
        return ans;
    }
    
private:
    bool isValid(vector<int>& nums, int k, long long targetSum) {
        int subarrays = 1;
        long long currentSum = 0;
        
        for (int num : nums) {
            if (currentSum + num <= targetSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
            }
        }
        return subarrays <= k;
    }
};