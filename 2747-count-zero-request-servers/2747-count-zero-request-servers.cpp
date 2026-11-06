class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int numQueries = queries.size();
        vector<pair<int, int>> sortedQueries(numQueries);
        for (int i = 0; i < numQueries; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());
        
       
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> result(numQueries);
        unordered_map<int, int> serverRequestCount; 
        int left = 0;
        int right = 0;
        int totalLogs = logs.size();
        
        for (int i = 0; i < numQueries; ++i) {
            int queryTime = sortedQueries[i].first;
            int originalIdx = sortedQueries[i].second;
            
            int windowStart = queryTime - x;
            int windowEnd = queryTime;
            
            while (right < totalLogs && logs[right][1] <= windowEnd) {
                int serverId = logs[right][0];
                serverRequestCount[serverId]++;
                right++;
            }
            
            while (left < totalLogs && logs[left][1] < windowStart) {
                int serverId = logs[left][0];
                serverRequestCount[serverId]--;
                
                if (serverRequestCount[serverId] == 0) {
                    serverRequestCount.erase(serverId);
                }
                left++;
            }
            
            result[originalIdx] = n - serverRequestCount.size();
        }
        
        return result;
    }
};