#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int i, vector<int> &nums, vector<int> &ds,
                 vector<vector<int>> &ans) {
  if (i >= nums.size()) {
    ans.push_back(ds);
    return;
  }
  ds.push_back(nums[i]);
  findSubsets(i + 1, nums, ds, ans);
  ds.pop_back();
  int idx = i + 1;
  while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
    idx++;
  }
  findSubsets(idx, nums, ds, ans);
}
int main() {
  cout << "\n \t \t \t \t \t Program to find all the subsets of a given set of "
          "integers with duplicates."
       << endl;
  cout << "\n \t \t \t \t "
          "\t=================================================================="
          "============"
       << endl;

    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    cout << "All the subsets of the given set of integers with duplicates are: " << endl;
    for(auto it : ans) {
      cout << "[ ";
      for (auto i : it) {
        cout << i << " ";
      }
      cout << "]" << " ";
    }
    cout << endl;
  return 0;
}