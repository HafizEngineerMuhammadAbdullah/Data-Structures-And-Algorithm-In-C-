#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;


// Three Sum Problem :-
// TC:O(n^2 + (uniqueTriplet)*log(uniqueTriplet)) , SC:O(uniqueTriplet) + O(n)
// TC : O(n³ log M) where M = number of unique triplets
// SC : O(M)
// we have to find three values such that the sum of the three elements is equal to zero(0)
// arr[i] + arr[j] + arr[k] == 0 provided (i != j != k)
// 1.Pick first element (i)
// 2.Pick second element (j)
// 3.Find the third element using 2 Sum Approach i.e. (c = -(a + b))
// 4.if the third element already exists in set DS,so we have found unique Triplets
// 5.Store the triplets in vector
// 6.Sort the triplet
// 7.Store it in a set
// 8.Copy unique triplets into ans

vector<vector<int>> threeSum(const vector<int>& nums) {
    // store only the unique Triplets
    set<vector<int>> uniqueTriplets;

    // pick the first Number
    for (int i = 0; i < nums.size(); i++) {// TC: O(n)
        int firstNum = nums[i];
        // we have to find those 2 numbers(say b & c) whose sum is equal to a negative of first picked number so that the sum of all the three numbers is equla to zero( b + c = -ve of firstNum)
        int target = -firstNum;
        unordered_set<int> seen;
        
        // pick the second Number & find the third Number in set DS
        for (int j = i + 1; j < nums.size(); j++) {// TC: O(n)
            // secondNum => b
            int secondNum = nums[j];
            // complement => c
            int complement = target - secondNum;
            // if (seen.count(complement)) {
            //     result.push_back({nums[i], nums[j], complement});
            // }
            // if the number(third Number) exist in set DS then we have found the triplet
            // duplicates disappear.
            if(seen.count(complement)) {
                vector<int> triplet = {firstNum, secondNum, complement};
                sort(triplet.begin(), triplet.end());
                // uniqueTriplets.insert(triplet);
                if (uniqueTriplets.insert(triplet).second) {
                    // newly inserted
                    uniqueTriplets.insert(triplet);
                }
            }

            seen.insert(nums[j]);
        }
        
    }
    
    vector<vector<int>> result(uniqueTriplets.begin(),uniqueTriplets.end());
    return result;
}
int main() {

    cout << "\n \t \t \t \t \t Three (3) Sum Problem Using 2 Sum Approach & Hashing Approach " <<endl;
    cout << "\n \t \t \t \t \t -------------------------------------------------------------- " <<endl;

   cout << "Enter the size of the array: ";
   int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
   vector<vector<int>> nums = threeSum(arr);

   cout << "\n \t \t \t \t \t \t The unique triplets whose sum equals to zero(0) are: " << endl;
   cout << "\n \t \t \t \t \t \t=======================================================" << endl;
   for(int i=0; i<nums.size(); i++){
       cout << "[ ";
       for(int j=0; j<nums[i].size(); j++){
           cout << nums[i][j];
           if(j < nums[i].size()-1){
               cout << ", ";
           }
       }
       cout << "]" << endl;
   }
    


    return 0;
}