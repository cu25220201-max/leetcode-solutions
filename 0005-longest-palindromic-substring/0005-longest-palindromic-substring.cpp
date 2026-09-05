class Solution {
public:
    int start=0;
    int maxlen=1;

    void expand(string  &s, int left, int right){
        while(left >=0 && right < s.size() && s[left] == s[right]){
            if(right - left+1 > maxlen){
                maxlen = right - left+1;
                start=left;
            }
            left --;
            right ++;
        }
    }
    string longestPalindrome(string s) {
        if(s.length() <=1)
            return s;

        for(int i=0;i<s.length();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        
        return s.substr(start,maxlen);
    }
};