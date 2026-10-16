class Solution {
    public int longestSubstring(String s, int k) {
        int maxLen = 0;
        int n = s.length();
        for(int i =0;i<n;i++){
            int[] counts = new int[26];
            for(int j = i;j<n;j++){
                counts[s.charAt(j) - 'a']++;

                boolean isValid = true;
                for(int count : counts){
                    if(count > 0 && count < k){
                        isValid = false;
                        break;
                    }
                }
                if(isValid){
                    maxLen = Math.max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    }
}