class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available_servers;
        for (int i = 0; i < n; ++i) {
            available_servers.push({servers[i], i});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> unavailable_servers;

        long long current_time = 0;

        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);

            if (available_servers.empty() && !unavailable_servers.empty()) {
                current_time = max(current_time, get<0>(unavailable_servers.top()));
            }

            while (!unavailable_servers.empty() && get<0>(unavailable_servers.top()) <= current_time) {
                auto [free_time, weight, index] = unavailable_servers.top();
                unavailable_servers.pop();
                available_servers.push({weight, index});
            }

            auto [weight, index] = available_servers.top();
            available_servers.pop();

            ans[j] = index;
            unavailable_servers.push({current_time + tasks[j], weight, index});
        }

        return ans;
    }
};