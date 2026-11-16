class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_round = "";
            for (int i = 0; i < s.length(); i += k) {
                int current_sum = 0;
                for (int j = i; j < min((int)s.length(), i + k); j++) {
                    current_sum += (s[j] - '0'); 
                }
                next_round += to_string(current_sum);
            }
            s = next_round;
        }        
        return s;
    }
};