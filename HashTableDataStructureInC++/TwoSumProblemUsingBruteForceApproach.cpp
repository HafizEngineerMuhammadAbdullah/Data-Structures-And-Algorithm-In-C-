#include<iostream>
#include<vector>
using namespace std;

// Brute Force Approach 
vector<int> twoSum(vector<int> arr,int target){
   // Step 1 : find all possible pairs say first & second
   // Step 2 : check whether the sum of pair of elements meets(equals) the target value
   // if so return the index as final answer
   // otherwise, return {-1,-1}
   // Time Complexity : O(n^2)
   for (int i = 0; i < arr.size() ;i++)
   {
    // pick the first element of the pair
     int first = arr[i];
     // inner loop to pick the second element of the pair
     for (int j = i+1; j < arr.size(); j++)
     {
        // pick the second element of the pair
        int second = arr[j];
        // sum of the pair of elements
        int sum = first + second;
        // check whether the sum of pair of elements meets(equals) the target value
        if(sum == target){
            // if so return the index as final answer
            return {i,j};
        }
     }
   }
   // otherwise, return {-1,-1}
   return {-1,-1};
}
int main() {
    cout << "\n \t \t \t \t \t Two Sum Problem Using Brute Force Approach" << endl;
    cout << "\n \t \t \t \t \t---------------------------------------------" << endl;
   cout<<"Enter the size of the array : ";
   int n;
   cin>>n;
   vector<int> arr(n);
   cout<<"Enter the elements of the array : ";
   for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
   cout<<"Enter the target value : ";
   int target;
   cin>>target;
   vector<int> ans = twoSum(arr,target);
   cout<<"The indices of the two numbers such that they add up to target value are : ";
   cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;

}