#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2 Sum → Hash Map / Two Pointers
// 3 Sum → Fix one element + Two Sum
// 4 Sum → Fix two elements + Two Sum

    // Basically in this problem we have to find the combination/groups of 4
    // numbers (actually quadruplets) such that whose sum equals to zero(0)
    // provided i != j != k != l or i != j != p != q .Or we have to pick those 4
    // numbers which should not overlap. Moreover, groups are such that the sum
    // of those 4 numbers(quadruplets) equals '0'.This Problem is popularly
    // known as 4 Sum Problem TC:O(n^3 + nlogn) in terms of SC : O(k) where M
    // denotes the uniqueGroup of 4 numbers k = uniqueGroup(number of
    // quadruplets)
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        // 2D vectore to store all the unique groups
        vector<vector<int>> ans;
        int n = arr.size();

        // firstly, sort the whole/entire array by passing the beginning and
        // ending iterator of array
        // Necessary because
        // Two Pointer only works on sorted arrays.
        // Duplicate skipping becomes very easy.
        // Without sorting,
        // Two Pointer never works.
        sort(arr.begin(), arr.end()); // TC : O(n*log(n))

        // pick unique first number each time
        for (int i = 0; i < n; i++) { // TC : O(n)

            // 1st optimization to prevent duplicate combination
            // skip the duplicate group(quadruplets)
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            // pick unique second number every time
            for (int j = i + 1; j < n;) { // TC : O(n)

                // Apply Two Pointer Approach here
                int p = j + 1;
                int q = n - 1;

                // since the array is sorted,so we can use Two Pointers Approach
                // to pick(track) the sum that is easy & efficient
                while (p < q) { // TC : O(n)
                    // calculate sum
                    long long sum = (long long)arr[i] + (long long)arr[j] +
                                    (long long)arr[p] + (long long)arr[q];

                    // depending upon the sum value, we would take decision that
                    // where to move p & q pointers if sum is leseer than
                    // target(<target) value, means we have to increase the sum
                    // value
                    if (sum < target) {
                        p++;
                    }
                    // else if sum is greater than target(>target) value, means
                    // we have to decrease the sum value to reach at target
                    else if (sum > target) {
                        q--;
                    }
                    // else sum == target ,found unique quadruplets
                    else {
                        // store the group(unqiue quadruplets) in the ans vector
                        ans.push_back({arr[i], arr[j], arr[p], arr[q]});
                        // move both
                        p++;
                        q--;

                        // 2nd optimization to avoid duplicate combination of
                        // numbers or skip the duplicate quadruplets which is
                        // not allowed
                        while (p < q && arr[p] == arr[p - 1])
                            p++;
                        // remove duplicates from the right side
                        // the same quadruplet can be produced again
                        // So this optimization should also be enabled.
                        while (p < q && arr[q] == arr[q + 1])
                            q--;
                    }
                }

                j++;

                // 3rd optimization to always get the unique group of 4
                // numbers(quadruplets) skip the duplicate group(remove
                // duplicates quadruplets)
                while (j < n && arr[j] == arr[j - 1])
                    j++;
            }
        }
        return ans;
    }
int main()
{
    cout << "\n \t \t \t \t \t Program to Solve 4 Four Sum Problem Using the most Optimized Approach also known as Two Pointer Approach" << endl;
    cout << "\n \t \t \t \t \t===========================================================================================================" << endl;
}