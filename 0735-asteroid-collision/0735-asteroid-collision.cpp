class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i =0; i< asteroids.size(); i++){
            int num = asteroids[i];
            while(!s.empty() && s.top() > 0 && num < 0){
                if(s.top() < -num){
                    s.pop();
                } else if(s.top() == -num){
                    s.pop();
                    num = 0;
                    break;
                } else {
                    num = 0;
                    break;
                }
            }
            if(num != 0){
                s.push(num);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};