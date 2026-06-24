class Solution {
public:
    // TC:O(n) , SC:O(1)
    // It also fails when the array contains zeros.
    // nums = [1, 2, 0, 4]
    // The total product becomes 0, and division cannot produce the correct answers.
    
    vector<int> productExceptSelf(vector<int>& nums) {
        // BASE CASE :
        if(nums.empty()){
            return {};
        }
         // create an ans vector
         vector<int> ans(nums.size(),1);

         // Using Division Operator
         int product = 1;
         // calculate product of the whole array
         for (size_t i = 0; i < nums.size(); i++)
         {
            product *= nums[i];
         }

          for (size_t i = 0; i < nums.size(); i++)
         {
            ans[i] = product / nums[i];
         }
       
    return ans;

    }
};