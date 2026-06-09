#include <iostream>
#include <vector>
using namespace std;

// function to print all subsets of a given array using backtracking
// Time Complexity: O(2^n) (since each element can either be included or excluded)
// Space Complexity: O(n) (due to the recursive call stack and subset storage)
void printSubsets(const vector<int> &arr, vector<int> &subset, int index) {
  // Base Case: If we have considered all elements, print the current subset
  if (index == arr.size()) {
    cout << "{ ";
    for (int num : subset) {
      cout << num << " ";
    }
    cout << "}" << endl;
    return;
  }
  // Recursive Case: Include the current element and move to the next
  subset.push_back(arr[index]);
  printSubsets(arr, subset, index + 1);
  // Backtracking Process =>  Exclude the current element and move to the next
  subset.pop_back();
  printSubsets(arr, subset, index + 1);
}
int main() { 
    cout << "\n \t \t \t \t \t \t \t Recursion & Backtracking in C++" << endl;
    cout << "\n \t \t \t \t \t \t \t---------------------------------" << endl;
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> subset; // To store the current subset
    cout << "All subsets of the array are: " << endl;
    printSubsets(arr, subset, 0); // Start backtracking from index 0
    return 0; 

}