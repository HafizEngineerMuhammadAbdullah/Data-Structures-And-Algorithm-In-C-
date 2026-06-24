class Solution {
public:
   // TC:O(n^2) , SC:O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        // BASE CASE :
        if(nums.empty()){
            return {};
        }

        int n = nums.size();
         // create an ans vector
         vector<int> ans(nums.size(),1);

         for (size_t i = 0; i < n; i++)
         {
            // int product = 1
             // calculate the product of whole array except when index i = jth index
             for (size_t j = 0; j < n; j++)
             {
                if(i != j){
                  // product *= nums[j];
                   ans[i] *= nums[j];
                }
             }
            //  ans[i] = product;
         }
       
    return ans;

    }
};