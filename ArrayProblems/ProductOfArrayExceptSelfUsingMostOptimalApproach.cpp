class Solution {
public:
    // TC:O(n) , SC:O(1)
    // Product Of Array Except Self Using Most Optimal Approach
    vector<int> productExceptSelf(vector<int>& nums) {
        // BASE CASE :
        if (nums.empty()) {
            return {};
        }

        int n = nums.size();
        // create an ans vector
        vector<int> ans(n, 1);

        // calculate prefix for ith index which means calculate or to find the
        // product of the elements appeared in the left side of the element at
        // ith index inside ans vector
        for (size_t i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // calculate suffix for ith index which means calculate or to find the
        // product of the elements appeared in the right side of the element at
        // ith index inside ans vector along with calculate ans also
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};