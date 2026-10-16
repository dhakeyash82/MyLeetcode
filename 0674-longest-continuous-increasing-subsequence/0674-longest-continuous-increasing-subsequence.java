class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int freq = 1;
        int maxLen = 1;
        int n = nums.length;
        for(int i =1;i<n;i++){
            if(nums[i]>nums[i-1]){
                freq++;
            }
            else{
                freq = 1;
            }
            maxLen = Math.max(maxLen,freq);
        }
        return maxLen;
    }
}