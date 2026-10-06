class Solution {
public:
    vector<string> result;

    bool isValid(string part) {
        
        if (part.length() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);

        return num >= 0 && num <= 255;
    }

    void backtrack(string& s, int index, int parts, string current) {

        
        if (parts == 4) {
            
            if (index == s.length()) {
                current.pop_back(); 
                result.push_back(current);
            }
            return;
        }

       
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.length())
                break;

            string part = s.substr(index, len);

            if (!isValid(part))
                continue;

            backtrack(
                s,
                index + len,
                parts + 1,
                current + part + "."
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();

        
        if (s.length() < 4 || s.length() > 12)
            return result;

        backtrack(s, 0, 0, "");

        return result;
    }
};