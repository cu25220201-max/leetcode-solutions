class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        
        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> current;

            while (right + wordLen <= s.size()) {

                
                string word = s.substr(right, wordLen);
                right += wordLen;

                
                if (required.find(word) == required.end()) {
                    current.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                
                current[word]++;
                count++;

                
                while (current[word] > required[word]) {
                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }

               
                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};