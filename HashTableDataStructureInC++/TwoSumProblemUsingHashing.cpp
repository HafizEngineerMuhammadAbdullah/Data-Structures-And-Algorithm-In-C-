#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Using Hashing Approach 
vector<int> twoSum(vector<int> arr,int target){
    //  Using Hashing Approach, we can solve the problem in O(n) time complexity
    // Step 1 : create an unordered_map to store the elements of the array as key(must be unique) and their indices as value
    // Step 2 : iterate through the array and for each element, check if the complement value(target - arr[i]) exists in the unordered_map
    // if it exists, return the indices of the current element and the complement
    // if it does not exist, add the current element and its corresponding index to the unordered_map
    // if no such pair is found, return {-1,-1}
    // Time Complexity : O(n)
    // we use map to fast searching & fast retrieving of the complement value in O(1) time complexity
    unordered_map<int,int> mp;
   for (int i = 0; i < arr.size(); i++)
   {
      int first = arr[i];
      int second = target - first;
      if(mp.find(second) != mp.end()){
        return {i,mp[second]};
      }

      //otherwise , add the current element & it's corresponding idx in the unordered_map
      mp[first] = i;
   }
   // otherwise, return {-1,-1}
   return {-1,-1};
}
int main() {
    cout << "\n \t \t \t \t \t Two Sum Problem Using Hashing Approach" << endl;
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