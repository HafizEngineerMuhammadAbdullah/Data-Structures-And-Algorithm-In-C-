#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Function to find Majority Element Using Better(Sorting) Approach 
// it is the element more tha floor ⌊n/2⌋ times
// Our Majority Element should exists more than half size times in the given array
// Majority Element should occupied places more than  ⌊n/2⌋ times in the given array
// Majority Element is the element whose frequency is greater than n/2 times(more than half of the array) where n is the size of array
// it means Majority Element occupies placed more than half of array and the remaining element ocurred less than half of array
// TC:O(nlogn+n) , SC:O(1) 
int majorityElement(vector<int> &nums){
    int n = nums.size();
    
    int freq = 1, ans = nums[0];
    for(int i=1; i<n; i++){
        
        // if the element matches with the old(previous) element,increase the frequency by 1
        if(nums[i] == ans) freq++;
        // else reset the frequency to 1 as new element occurred/found
        else {
            freq = 1;
            ans = nums[i];
        }
        // if the MJE found return from here
        if(freq > n/2){
            return ans;
        }
    }
    return -1;

}
int main()
{
   cout << "\n \t \t \t \t \t \t Program to find Majority Element Using Better(Sorting) Approach" <<endl;
   cout << "\n \t \t \t \t \t \t=========================================================" << endl;


   int size;
   cout << "Enter the size of array:..." << endl;
   cin >> size;
   vector<int> arr(size);

   cout << "Enter the Elements in an array:..." << endl;
   for(int i=0; i<size; i++){
    cin >> arr[i];
   }

   sort(arr.begin(),arr.end());

   int majorityEl = majorityElement(arr);
   cout << "Majority Element is : " << majorityEl << endl;
}