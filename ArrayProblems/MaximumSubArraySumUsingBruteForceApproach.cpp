#include <iostream>
#include <vector>
using namespace std;


// Function to find Maximum SubArray Sum of an Array
// Time Complexity: O(n^2) because of the two nested loops, for an array of size n
// Space Complexity: O(1) auxiliary space because the program modifies and copies no data in memory while iterating
// SubArray : A continuous(contiguous) part of a given array
int maxSubArray(const vector<int> & arr){

      int n = arr.size();
      int maxSum = INT_MIN;//=> maxSum = -∞
      
      // Outer loop picks the starting point
    for(int st=0; st<n; st++){
        int currSum = 0;

        // Inner loop picks the ending point
        for(int end=st; end<n; end++){
            // adds the value(current value) of array to currSum
            // reuses the previous computation.
               currSum += arr[end];
            //calculate maxSum
               maxSum = max(maxSum,currSum);
           
        }
    }
    return maxSum;
}


int main() {
    cout << "\n \t \t \t \t \t \t \t \t Program to Find the Maximum SubArray Sum of an Array Using Brute Force Approach" << endl;
    cout << "\n \t \t \t \t \t \t \t \t================================================================================" << endl;

     // Example array
    vector<int> arr = {1, 2, 3};
    
    cout << "Maximum SubArray Sum :\n";
    int max = maxSubArray(arr);
    cout << max << endl;
    
    return 0;
}