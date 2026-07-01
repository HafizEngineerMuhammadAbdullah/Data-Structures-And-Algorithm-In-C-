class Solution {
public:
    // TC:O(logn) , SC:O(1)
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;

        // perform Binary Search Algorithm since the array was sorted in
        // non-decreasing order(ascending order) but due to left rotated at a
        // particular index k,our array is now sorted not fully but partially
        // The array is no longer fully sorted because it has been rotated, but
        // one half is always sorted
        while (st <= end) {
            // Calculate mid firstly
            int mid = st + (end - st) / 2;

            // if target is found at mid index,return the mid index from here
            if (nums[mid] == target) {
                return mid;
            }

            // check if left half of array is sorted only w.r.t mid value
            // If the left half is sorted, first check whether the target
            // belongs there.

            if (nums[st] <= nums[mid]) {
                // condition for Left Half
                // check if our target actually lies in left half
                // Check whether the target lies within the sorted left half.
                if (nums[st] <= target && target <= nums[mid]) {
                    // if so search the target in the left half
                    end = mid - 1;
                }
                // else if our target is actually not lies in the left half
                else {
                    // if so then try to search in the right half
                    st = mid + 1;
                }
            }
            // else right half of array is sorted only w.r.t mid value
            // else if the right half is sorted, first check whether the target
            // belongs there.
            else {
                // condition for Right Half
                // check if our target lies in the right half
                // Check whether the target lies within the sorted right half.
                if (nums[mid] <= target && target <= nums[end]) {
                    // if lies then search in the right half
                    st = mid + 1;
                } else {
                    // if not then try to search in the left half
                    end = mid - 1;
                }
            }
        }
        // if the target is not found,return -1
        return -1;
    }
};