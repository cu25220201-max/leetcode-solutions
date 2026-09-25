class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            
            while (j < n) {
                if (lineLength + words[j].size() + (j - i) > maxWidth)
                    break;

                lineLength += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int spaces = maxWidth - lineLength;

            string line;

            
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += ' ';

                    line += words[k];
                }

                
                line += string(maxWidth - line.size(), ' ');
            }
            else {
               
                int gaps = wordCount - 1;

                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        
                        int currentSpaces = spacesPerGap;

                        if (k - i < extraSpaces)
                            currentSpaces++;

                        line += string(currentSpaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};