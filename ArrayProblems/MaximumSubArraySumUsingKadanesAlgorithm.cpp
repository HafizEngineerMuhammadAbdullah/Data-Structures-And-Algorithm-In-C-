#include <iostream>
#include <vector>
using namespace std;


// Function to find Maximum SubArray Sum of an Array Using the Most Optimal Approach
// Time Complexity: O(n) because of the one loop, for an array of size n. 
// Space Complexity: O(1) auxiliary space because the program modifies and copies no data in memory while iterating
// SubArray : A continuous(contiguous) part of a given array
int maxSubArray(const vector<int> & arr){

      int n = arr.size();
      int maxSum = INT_MIN;//=> maxSum = -∞
      int currSum = 0;
      
      // Outer loop picks the starting point
    for(int i=0; i<n; i++){
        
       // adds the value(current value) of array to currSum
    //    reuses the precious computation
               currSum += arr[i];
            //calculate maxSum
               maxSum = max(maxSum,currSum);

               // Kadane's Algorrithm Says if the currSum becomes negative at a specific time,then reset the currSum to zero
              // If the current sum becomes negative, discard it because extending a negative sum can only reduce the sum of any future subarray. Therefore, restart from the next element.
            //   start summing with a fresh new currsum
               if(currSum < 0){
                 currSum = 0;
               }

    }
    return maxSum;
}


int main() {
    cout << "\n \t \t \t \t \t \t \t Program to Find the Maximum SubArray Sum of an Array Using Kadane's Algorithm" << endl;
    cout << "\n \t \t \t \t \t \t \t===============================================================================" << endl;

     // Example array
    vector<int> arr = {1, 2, 3};
    
    cout << "Maximum SubArray Sum :\n";
    int maxSum = maxSubArray(arr);
    cout << maxSum << endl;
    
    return 0;
}