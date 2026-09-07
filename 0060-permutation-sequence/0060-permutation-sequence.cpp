class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        
        int factorial = 1;
        for (int i = 1; i < n; i++) {
            factorial *= i;
        }

        
        k--;

        string ans = "";

        for (int i = n; i > 0; i--) {
            int index = k / factorial;

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            k %= factorial;

            if (i > 1) {
                factorial /= (i - 1);
            }
        }

        return ans;
    }
};