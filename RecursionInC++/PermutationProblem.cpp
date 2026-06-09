#include <iostream>
#include <vector>
using namespace std;

// Function to generate all permutations of the given array
// Time Complexity: O(n! * n) where n is the size of the array
// Space Complexity: O(n) for the recursion stack
void getAllPermutations(vector<int> &arr, int idx,
                     vector<vector<int>> &allPermutation) {
  if (idx >= arr.size()) {
    allPermutation.push_back(arr);
    return;
  }

  // Generate permutations by swapping the current index with each subsequent
  // index
  for (int i = idx; i < arr.size(); ++i) {
    swap(arr[idx], arr[i]); // Swap the current index with the subsequent index
    getAllPermutations(arr, idx + 1, allPermutation); // Recur with the next index
    swap(arr[idx],
         arr[i]); // Backtrack by swapping back to restore the original array
  }
}
int main() {
  cout << "\n \t \t \t \t \t Program to find all the Permutations of a given "
          "Array/String."
       << endl;
  cout << "\n \t \t \t \t "
          "\t=================================================================="
          "============"
       << endl;
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> allPermutation;
  getAllPermutations(arr, 0, allPermutation);
  cout << "All the permutations of the given array are: " << endl;
  for (auto it : allPermutation) {
    cout << "[ ";
    for (auto i : it) {
      cout << i << " ";
    }
    cout << "]"
         << " ";
  }
  cout << endl;
  // string s = "abc";
  // sort(s.begin(), s.end());
  // cout << "All the permutations of the given string are: " << endl;
  // do {
  //     cout << s << " ";
  // } while (next_permutation(s.begin(), s.end()));
  cout << endl;
  return 0;
}