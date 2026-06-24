class Solution {
public:
    // TC:O(n) , SC:O(n)
    // Product Of Array Except Self Using Optimal Approach
    // prefix[i] = product of all elements before i
    // suffix[i] = product of all elements after i
    vector<int> productExceptSelf(vector<int>& nums) {
        // BASE CASE :
        if(nums.empty()){
            return {};
        }

        int n = nums.size();
         // create an ans vector
         vector<int> ans(n,1);
          // create a prefix vector
         vector<int> prefix(n,1);
          // create a suffix vector
         vector<int> suffix(n,1);

         // calculate prefix for ith index which means calculate or to find the product of the elements appeared in the left side of the element at ith index
         for (size_t i = 1; i < n; i++)
         {
            prefix[i] = prefix[i-1] * nums[i-1];
         }

          // calculate suffix for ith index which means calculate or to find the product of the elements appeared in the right side of the element at ith index
         for (int i = n-2; i >= 0; i--)
         {
            suffix[i] = suffix[i+1] * nums[i+1];
         }

         //calculate ans
         for(int i = 0; i < n; i++){
            ans[i] = prefix[i] * suffix[i];
         }
       
    return ans;

    }
};