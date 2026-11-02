class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int j = 0;

        for (int i = 0; i < n; ) {

            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            chars[j] = ch;
            j++;

            if (count > 1) {

                string s = to_string(count);

                for (int k = 0; k < s.size(); k++) {
                    chars[j] = s[k];
                    j++;
                }
            }
        }

        return j;
    }
};