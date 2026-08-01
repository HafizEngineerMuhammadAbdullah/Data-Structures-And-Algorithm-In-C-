#include <iostream>
#include <vector>
using namespace std;


// Function to print all possible subarrays
// Time Complexity: O(n³) because of the three nested loops. For an array of size n, the total number of printed subarrays is exactly n*(n+1)/2.
// Space Complexity: O(1) auxiliary space because the program modifies and copies no data in memory while iterating
void printAllSubarrays(const vector<int> & arr){

      int n = arr.size();

      // Outer loop picks the starting point
    for(int st=0; st<n; st++){
        cout << st << " : ";

        // Middle loop picks the ending point
        for(int end=st; end<n; end++){
            // Inner loop prints elements from starting to ending point(in a specified interval)
            for(int i=st; i<=end; i++){
                cout << arr[i];
            }
            if(end != n-1){
                cout << " , ";
            }
        }
        cout << endl;
    }
}


int main() {
    cout << "\n \t \t \t \t \t \t \t \t Program to  Print All Possible Subarrays of an Array" << endl;
    cout << "\n \t \t \t \t \t \t \t \t=======================================================" << endl;

     // Example array
    vector<int> arr = {1, 2, 3};
    
    cout << "All possible subarrays:\n";
    printAllSubarrays(arr);
    
    return 0;
}