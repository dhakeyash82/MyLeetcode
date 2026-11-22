class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int cnt=0;
        for(int i = 0;i<n;i++) {
            if(isupper(word[i])) {
                cnt++;
            }
        }
        if(cnt == 0 || cnt == n) {
            return true;
        }
        if(isupper(word[0]) && cnt == 1) {
            return true;
        }
        return false;
    }
};