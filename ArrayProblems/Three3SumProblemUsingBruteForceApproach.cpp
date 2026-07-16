#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Three Sum Problem :-
// TC:O(n^3 + (uniqueTriplet)*log(uniqueTriplet)) , SC:O(uniqueTriplet) + O(uniqueTriplet) = O(uniqueTriplet)
// TC : O(n³ log M)
// SC : O(M)
// 1.Pick first element (i)
// 2.Pick second element (j)
// 3.Pick third element (k)
// 4.Check if the sum of the three elements is equal to zero(0)
// arr[i] + arr[j] + arr[k] == 0
// 5.Sort the triplet
// 6.Store it in a set
// 7.Copy unique triplets into ans
vector<vector<int>> threeSum(const vector<int> &arr){
    // ans vector stores all the unique triplets whose sum equals to zero(0)
    vector<vector<int>> ans;
    set<vector<int>> s; // set to store the unique triplets
    int n = arr.size();
    
    // TC: O(n^3)
    for(int i=0; i<n ; i++){//TC:O(n)
        for(int j=i+1; j<n; j++){//TC:O(n)
            for(int k=j+1; k<n; k++){//TC:O(n)
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> triplet = { arr[i] , arr[j], arr[k] };
                    sort(triplet.begin(),triplet.end());
                    
                    // if the triplet not found in the set(not exists) means the triplet is unique/distinct
                    if(s.find(triplet) == s.end()){
                        //now store the unique triplets in the set as well as in the ans vector
                        // why? set because it tracks whether the triplet is unique or not by checking whether the triplet already exists in set or not because we only need to return distinct triplet
                        s.insert(triplet);
                       ans.push_back(triplet);
                    }

                }
            }
        }
    }

    return ans;//return all the unique triplets

}

int main() {
   cout << "\n \t \t \t \t \t \t Three Sum Problem Using Brute Force Approach & Hashing" << endl;
   cout << "\n \t \t \t \t \t \t=========================================================" << endl;
   
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