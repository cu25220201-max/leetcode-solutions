class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string dir;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {

                if (dir == "" || dir == ".") {
                    
                }
                else if (dir == "..") {
                    
                    if (!st.empty())
                        st.pop_back();
                }
                else {
                    
                    st.push_back(dir);
                }

                dir = "";
            }
            else {
                dir += path[i];
            }
        }

        
        string result = "/";

        for (int i = 0; i < st.size(); i++) {
            result += st[i];

            if (i != st.size() - 1)
                result += "/";
        }

        return result;
    }
};