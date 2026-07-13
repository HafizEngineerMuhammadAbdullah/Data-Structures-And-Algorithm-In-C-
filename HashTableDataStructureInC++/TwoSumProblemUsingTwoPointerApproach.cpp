#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Using Two Pointer Approach 
vector<int> twoSum(vector<int> arr,int target){
    // Step 1 : sort the array in ascending order using sort(arr.begin(),arr.end());
    // Step 2 : initialize two pointers say st & end
    // set the start pointer(st) to the first index (left corner) of the array and the end pointer(end) to the last index(right corner) of the array
    // Step 3 : run a while loop until st < end
   // Step 4 : check whether the sum of pair of elements meets(equals) the target value
   // if so return the index as final answer
   // if target value is less than the sum of pair of elements than decrement the end pointer(end) by 1
   // if target value is greater than the sum of pair of elements than increment the start pointer(st) by 1
   // keep repeating the above steps until st < end
   // otherwise, return {-1,-1}
   // Time Complexity : O(nlogn)
   int st = 0;
   int end = arr.size()-1;
   while(st < end){
    // pick the first element of the pair
      int first = arr[st];
      // pick the second element of the pair
      int second = arr[end];
      // sum of the pair of elements
      int sum = first + second;
      // check whether the sum of pair of elements meets(equals) the target value or not
      if(sum == target){
        return {st,end};
      } else if(sum > target){
        end--;
      } else{
        st++;
      }
   }
   // otherwise, return {-1,-1}
   return {-1,-1};
}
int main() {
    cout << "\n \t \t \t \t \t Two Sum Problem Using Two Pointers Approach" << endl;
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
    sort(arr.begin(),arr.end());
   cout<<"Enter the target value : ";
   int target;
   cin>>target;
   vector<int> ans = twoSum(arr,target);
   cout<<"The indices of the two numbers such that they add up to target value are : ";
   cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;

}