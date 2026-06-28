class Solution {
public:
    // TC : O(logn) , SC:O(1)
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        // Perform Binary Search because the array is already in Sorted order &
        // we are asked to solve it  in O(logn) TC , so this task can only be
        // achieved by performing Binary Search Algorithm which reduced the half
        // search space in every level(iteration/step) resulting TC reduced to
        // O(logn) & SC:O(1)

        // Edge Case: if there is a single element exist in an array
        if (n == 1) {
            return arr[0]; // this element would definitely be a single Element
        }

        int st = 0, end = n - 1;
        while (st <= end) {
            // calculate mid firstly
            int mid = st + (end - st) / 2;

            // Corner Cases: Those prevent accessing invalid indices.
            // if the first element doesn't match  with the second element
            if (mid == 0 && arr[mid] != arr[mid + 1])
                return arr[mid];
            // if the last element doesn't match  with the second last element
            if (mid == n - 1 && arr[mid] != arr[mid - 1])
                return arr[mid];

            // check if the mid element is a single element
            if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }

            // when left & right half have even number of elements
            if (mid % 2 == 0) {
                // if the mid element matches with the previous element,search
                // in the left half
                if (arr[mid - 1] == arr[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1; // search in the right half
                }
            } else { // when left & right half have odd number of elements
                // if the mid element matches with the previous element,search
                // in the right half
                if (arr[mid - 1] == arr[mid]) {
                    st = mid + 1; // search in the right half
                } else {
                    end = mid - 1; // else search in the left half
                }
            }
        }
        // This line is never reached because the problem guarantees that
        // exactly one element appears only once.
        return -1; // never hit because at least one single element must be
                   // appear in an array
    }
};