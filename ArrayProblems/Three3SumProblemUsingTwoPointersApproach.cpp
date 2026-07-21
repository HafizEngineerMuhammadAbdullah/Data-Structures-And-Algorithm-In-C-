class Solution {
public:
    // TC:O(nlogn + n^2) , SC:O(uniqueTriplets)
    vector<vector<int>> threeSum(vector<int>& nums) {
        // we have to find those triplets (combination of three numbers) whose
        // sum should be equals to zero.
        //  2D array to store all the unique triplets values
        vector<vector<int>> ans;
        // firstly, sort the whole array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // skip the duplicate triplets(avoid duplicate triplets) which is
            // not allowed
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = nums.size() - 1;
            while (j < k) { // i != j != k
                // calculate sum
                int sum = nums[i] + nums[j] + nums[k];
                // if sum is negative(<0) value, means we have to increase the
                // sum value
                if (sum < 0)
                    j++;
                // else if sum is positive(>0) value, means we have to decrease
                // the sum value
                else if (sum > 0)
                    k--;
                // else sum == 0 ,found unique triplet
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // to remove duplicates(avoid duplicate triplets)
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }
        return ans;
    }
};