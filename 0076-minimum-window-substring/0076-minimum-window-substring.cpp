class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        vector<int> count(128, 0);

        for (char c : t) {
            count[c]++;
        }

        int left = 0;
        int right = 0;
        int required = t.size();

        int minLength = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            if (count[s[right]] > 0) {
                required--;
            }

            count[s[right]]--;
            right++;

            while (required == 0) {

                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                count[s[left]]++;

                if (count[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};