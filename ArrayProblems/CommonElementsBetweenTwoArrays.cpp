class Solution {
public:
    // function that dump the values of array into the set
    // void dumpValues(set<int>& s, const vector<int> arr) {
    //     if (!s.empty()) {
    //         s.clear();// TC: O(k)
    //     }
    //     for (int val : arr) {// TC: O(k) where k is the size of array arr
    //         s.insert(val);
    //     }
    // }
    // TC : O(m + n) , SC: O(m + n)
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        // stores how many indices in first array are such that those elements
        // at that indices are also  present in another array & also this will
        // be same to the second array
        vector<int> result(2, 0);
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

        // dump all the values of nums2 in set so that we could check if the
        // elements in nums1 also present in set(means in the second array) and
        // also count how many elements in nums1 are such that they also exist
        // in nums2
        // dumpValues(s, nums2);

        for (int val : nums1) {// TC: O(m)
            // check if the values of nums1 exits in set,if so increment count
            if (s2.count(val)) {
                result[0]++;
            }
        }

        // dump all the values of nums1 in set so that we could check if the
        // elements in nums2 also present in set(means in the first array) and
        // also count how many elements in nums2 are such that they also exist
        // in nums1

        // dumpValues(s, nums1);

        for (int val : nums2) {//TC:O(nlogm)
            // check if the values of nums2 exits in set,if so increment count
            if (s1.count(val)) {
                result[1]++;
            }
        }
        return result;
    }
};