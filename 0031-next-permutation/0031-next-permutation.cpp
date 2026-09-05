class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the first decreasing element from right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If found, find the smallest element greater than nums[i]
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};