#include<iostream>
#include<vector>
using namespace std;


// Function to find Majority Element Using Brute Force Approach 
// Majority Element is the element whose frequency is greater than n/2(more than half of the array) where n is the size of array
// it is the element more tha floor ⌊n/2⌋ times
// Our Majority Element should exists more than half size times in the given array
// Majority Element should occupied places more than  ⌊n/2⌋ times in the given array  
// it means Majority Element occupies placed more than half of array and the remaining element ocurred less than half of array
// TC:O(n*n) , SC:O(1) 
int majorityElement(vector<int> &nums){
    int n = nums.size();
    
    //pick each element & find the frequency(count/occurrence) of that particular element/entity in the whole array
    for(int val : nums){
        // reset the frequency to zero each time when counting the occurrence of each index of element 
        int freq = 0;
        // Calculate/Count frequency
        for(int el: nums){
            //if that element matches,increment the frequency by 1
            if(el == val){
                freq++;
            }
        }

        if(freq > n/2){
            return val;
        }
    }
    return -1;

}
int main()
{
   cout << "\n \t \t \t \t \t \t Program to find Majority Element Using Brute Force Approach" <<endl;
   cout << "\n \t \t \t \t \t \t===============================================================" << endl;


   int size;
   cout << "Enter the size of array:..." << endl;
   cin >> size;
   vector<int> arr(size);

   cout << "Enter the Elements in an array:..." << endl;
   for(int i=0; i<size; i++){
    cin >> arr[i];
   }

   int majorityEl = majorityElement(arr);
   cout << "Majority Element is : " << majorityEl << endl;
}