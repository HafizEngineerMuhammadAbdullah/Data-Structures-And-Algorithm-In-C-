#include <iostream>
#include <vector>
using namespace std;

void getAllSubsets(int arr[], int n, int index, vector<int> &currentSubset,
                   vector<vector<int>> &allSubsets) {
  // Base case: if we've considered all elements
  if (index == n) {
    // store the current subset in the list of all subsets
    allSubsets.push_back({currentSubset});
    return;
  }

  // Recursive case 1: Include the current element
  currentSubset.push_back(arr[index]);
  getAllSubsets(arr, n, index + 1, currentSubset, allSubsets);

  // Recursive case 2: Exclude the current element
  currentSubset.pop_back();
  getAllSubsets(arr, n, index + 1, currentSubset, allSubsets);
}
int main() {
  cout << "\n \t \t \t \t \t \t Program to find all subsets of a set using recursion in C++" << endl;
  cout << "\n \t \t \t \t \t \t===============================================================" << endl;
  cout << "Enter the number of elements in the set: ";
  int n;
  cin >> n;
  int arr[n];
  cout << "Enter the elements of the set: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "The subsets of the set are: " << endl;
  // function to find all subsets of a set using recursion
  vector<int> currentSubset;
  vector<vector<int>> allSubsets;
  getAllSubsets(arr, n, 0, currentSubset, allSubsets);

  for (auto x : allSubsets) {
    cout << "{ ";
    for (int y : x) {
      cout << y << " ";
    }
    cout << "}" << endl;
  }
}