class Solution {
public:
    // TC:O(nlogk+2k)=>TC:O(nlogk+k) , SC:O(k)
    int mostFrequentEven(vector<int>& nums) {
        // We use Map DS to count efficiently the occurrences of each Even
        // Elements from an Array DS

        // Map will store even element as key(which should be unique) along with
        // (corresponding to) it's occurrence as it's value so far

        // occurrences means how many times that particular(specific) element
        // appears in an array
        map<int, int> m; //=>(key,value) = (element,occurrences)

        for (int val : nums) { // TC :O(nlogk)
            if (val % 2 == 0) {
                m[val]++; // increment the count of occurrence of specific even
                          // element by 1
            }
        }

        int maxFreq = INT_MIN;
        // we have to find most frequent even element so since all the
        // occurrences of each even elements are present in Hash Table(Map) but
        // we don't know in Hash Table that which even element is mostly
        // occurred(appeared/frequent) so we have to know firstly that which one
        // is the even element which was occurred most  so due to this reason i
        // am firstly finding out the maximum occurrences of a particular even
        // element if exist in Hash table

        for (const auto& [key, value] :
             m) { // TC:O(k) where k is the number of even elements that exist
                  // in array
            if (maxFreq < value) {
                maxFreq = value;
            }
        }

        // matching the key's value with max so that we could find those even
        // element which was occurrd most. It is guaranteed that we exactly get
        // the smallest element if there is a tie between the occurrences of
        // even elements because map is automatically sorted in increasing order
        // internally
        for (const auto& [key, value] :
             m) { // TC:O(k) where k is the number of even elements that exist
                  // in array
            if (maxFreq == value) {
                return key;
            }
        }
        return -1;
    }
};