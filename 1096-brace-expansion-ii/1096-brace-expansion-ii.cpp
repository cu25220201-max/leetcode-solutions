class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        vector<set<string>> parts;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; 
                parts.push_back(parse(s, i));
                i++; 
            }
            else if (s[i] == ',') {
                i++; 
                continue;
            }
            else {
                
                set<string> temp;
                temp.insert(string(1, s[i]));
                parts.push_back(temp);
                i++;
            }
        }

        
        set<string> current;

        if (!parts.empty()) {
            current = parts[0];

            for (int k = 1; k < parts.size(); k++) {
                set<string> next;

                for (string a : current) {
                    for (string b : parts[k]) {
                        next.insert(a + b);
                    }
                }

                current = next;
            }
        }

        return current;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        
        function<set<string>()> dfs = [&]() {
            set<string> unionSet;
            set<string> current = {""};

            while (i < expression.size() && expression[i] != '}') {

                if (expression[i] == ',') {
                    
                    unionSet.insert(current.begin(), current.end());
                    current = {""};
                    i++;
                }
                else {
                    set<string> part;

                    if (expression[i] == '{') {
                        i++; 

                        part = dfs();

                        i++; 
                    }
                    else {
                        part.insert(string(1, expression[i]));
                        i++;
                    }

                    
                    set<string> next;

                    for (const string &a : current) {
                        for (const string &b : part) {
                            next.insert(a + b);
                        }
                    }

                    current = next;
                }
            }

            
            unionSet.insert(current.begin(), current.end());

            return unionSet;
        };

        set<string> ans = dfs();

        return vector<string>(ans.begin(), ans.end());
    }
};