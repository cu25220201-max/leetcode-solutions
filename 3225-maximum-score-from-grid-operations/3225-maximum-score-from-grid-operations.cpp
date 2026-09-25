class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        // prefix[j][i] = sum of first i cells in column j
        vector<vector<long long>> prefix(
            n, vector<long long>(n + 1, 0)
        );

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                prefix[j][i + 1] =
                    prefix[j][i] + grid[i][j];
            }
        }

        const long long NEG = LLONG_MIN / 4;

        /*
            dp[h1][h2]

            h1 = height of current column
            h2 = height of previous column
        */
        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(n + 1, NEG)
        );

        // Before the first column, previous height = 0
        for (int h = 0; h <= n; h++) {
            dp[h][0] = 0;
        }

        /*
            Process columns 0 ... n-2.
        */
        for (int col = 0; col < n - 1; col++) {

            vector<vector<long long>> ndp(
                n + 1,
                vector<long long>(n + 1, NEG)
            );

            for (int h1 = 0; h1 <= n; h1++) {

                /*
                    prefixMax[h2] =
                    max(dp[h1][0 ... h2])
                */
                vector<long long> prefixMax(n + 1, NEG);

                prefixMax[0] = dp[h1][0];

                for (int h2 = 1; h2 <= n; h2++) {
                    prefixMax[h2] =
                        max(prefixMax[h2 - 1],
                            dp[h1][h2]);
                }

                /*
                    suffixMax[h2] =
                    max over k >= h2 of

                    dp[h1][k]
                    + max(0, prefix[col][k]
                             - prefix[col][h1])
                */
                vector<long long> suffixMax(
                    n + 2, NEG
                );

                for (int h2 = n; h2 >= 0; h2--) {

                    if (dp[h1][h2] != NEG) {

                        long long extra = max(
                            0LL,
                            prefix[col][h2]
                                - prefix[col][h1]
                        );

                        suffixMax[h2] = max(
                            suffixMax[h2 + 1],
                            dp[h1][h2] + extra
                        );
                    }
                    else {
                        suffixMax[h2] =
                            suffixMax[h2 + 1];
                    }
                }

                /*
                    hp = height of next column
                */
                for (int hp = 0; hp <= n; hp++) {

                    /*
                        Case 1:
                        previous height <= next height

                        max(previous, next) = next
                    */
                    long long extra = max(
                        0LL,
                        prefix[col][hp]
                            - prefix[col][h1]
                    );

                    long long option1 = NEG;

                    if (prefixMax[hp] != NEG) {
                        option1 =
                            prefixMax[hp] + extra;
                    }

                    /*
                        Case 2:
                        previous height > next height

                        max(previous, next) = previous
                    */
                    long long option2 =
                        suffixMax[hp + 1];

                    ndp[hp][h1] = max(
                        option1,
                        option2
                    );
                }
            }

            dp = move(ndp);
        }

        /*
            Handle the last column.

            There is no right neighbour, so its
            right height is 0.
        */
        long long answer = 0;

        for (int h1 = 0; h1 <= n; h1++) {
            for (int h2 = 0; h2 <= n; h2++) {

                if (dp[h1][h2] == NEG)
                    continue;

                long long extra = max(
                    0LL,
                    prefix[n - 1][h2]
                        - prefix[n - 1][h1]
                );

                answer = max(
                    answer,
                    dp[h1][h2] + extra
                );
            }
        }

        return answer;
    }
};