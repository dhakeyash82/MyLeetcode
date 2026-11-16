class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto x : ops){
            if(x == "C"){
                s.pop();
            } else if(x == "D"){
                int a = s.top();
                s.push(a * 2);
            } else if(x == "+"){
                int a = s.top();
                s.pop();
                int y = s.top();
                s.push(a);
                s.push(a + y);
            } else {
                s.push(stoi(x));
            }
        }
        int ans = 0;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};