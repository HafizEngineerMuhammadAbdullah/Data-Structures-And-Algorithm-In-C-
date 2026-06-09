#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: ❌ O(2^n) (very slow)
// Space Complexity: O(n)
int getFibonacci(int n) {
  // BASE CASE: if n is 0 or 1, return n
  if (n == 0 || n == 1)
    return n;
  return getFibonacci(n - 1) +
         getFibonacci(n - 2); // call the recursive function to get the sum of
                              // the two preceding numbers
}

// Time Complexity: O(n) (much faster than the recursive version)
// Space Complexity: O(n)
bool isSorted(const vector<int> &arr, int n) {
  // Base Case: if the array has only one element or is empty, it is already
  // sorted
  if (n == 0 || n == 1) {
    return true;
  }
  // Recursive Case: check if the last two elements are in order and then
  // recursively check the rest of the array
  return (arr[n - 1] >= arr[n - 2]) && isSorted(arr, n - 1);
}

// Time Complexity: O(log n) (much faster than linear search)
// Space Complexity: O(log n) (due to recursive call stack)
// function to perform binary search on a sorted array
int binarySearch(const vector<int> &arr, int st, int end, int target) {
  if (st <= end) {
    int mid = st + (end - st) / 2; // Calculate the middle index
    // Check if the target is present at mid
    if (arr[mid] == target) {
      return mid; // Target found at index mid
    }
    // If target is smaller than mid, search in the left half
    else if (target < arr[mid]) {
      return binarySearch(arr, st, mid - 1, target);
    }
    // If target is larger than mid, search in the right half
    else {
      return binarySearch(arr, mid + 1, end, target);
    }
  }
  // Base Case: If the range is invalid, return -1 (not found)
  return -1; // Target not found in the array
}
int main() {
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;
  int a = 0, b = 1, c;
  cout << "Fibonacci Series Using Loop : ";
  for (int i = 1; i <= n; i++) {
    cout << a << " ";
    c = a + b;
    a = b;
    b = c;
  }

  cout << "\nFibonacci Series using Recursion: ";
  for (int i = 0; i < n; i++) {
    cout << getFibonacci(i) << " ";
  }

  cout << endl;
  cout << boolalpha; // to print boolean values as true/false instead of 1/0
  vector<int> arr1{1, 2, 3, 4, 5};
  vector<int> arr2{1, 3, 2, 4, 5};
  cout << "Is arr1 sorted? " << isSorted(arr1, arr1.size()) << endl;
  cout << "Is arr2 sorted? " << isSorted(arr2, arr2.size()) << endl;

  cout << "Enter the target number to search: ";
  int target;
  cin >> target;
  vector<int> sortedArr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result = binarySearch(sortedArr, 0, sortedArr.size() - 1, target);
  cout << "Target " << target << (result != -1 ? " found at index " + to_string(result) : " not found in the array") << endl;
  return 0;

}