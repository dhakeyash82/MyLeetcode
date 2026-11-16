class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;
        
        if (s.length() < totalLen) return result;
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seenWords;
            int count = 0; 

            while (right + wordLen <= s.length()) {
                string subWord = s.substr(right, wordLen);
                right += wordLen;
                if (wordCount.find(subWord) != wordCount.end()) {
                    seenWords[subWord]++;
                    count++;
                    while (seenWords[subWord] > wordCount[subWord]) {
                        string leftWord = s.substr(left, wordLen);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};