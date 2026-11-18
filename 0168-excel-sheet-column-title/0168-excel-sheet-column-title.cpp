
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--;
            int rem = columnNumber % 26;
            char ch = 'A' + rem;
            ans = ch + ans;
            columnNumber = columnNumber / 26;
        }
        return ans;
    }
};
