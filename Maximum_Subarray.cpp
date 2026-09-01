#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            
            // Agar currentSum negative ho jaye toh reset kar do
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl;

    return 0;
}