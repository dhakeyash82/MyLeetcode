class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        for (int num : nums) {
            min_val = min(min_val, num);
        }
        
        int moves = 0;
        for (int num : nums) {
            moves += (num - min_val);
        }
        
        return moves;
    }
};