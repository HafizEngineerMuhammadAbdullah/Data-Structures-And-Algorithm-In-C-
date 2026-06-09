#include <iostream>
#include <vector>
using namespace std;
// TC : O(n-k) where n is the total size of array
void rotate(vector<int> &arr, int k) {
  int n = arr.size() - k;

  vector<int> first(arr.begin(), arr.begin() + n);
  vector<int> second(arr.begin() + n, arr.end());
  for (size_t i = 0; i < first.size(); i++) {
    second.push_back(first[i]);
  }
}
// TC : O(n), SC: O(n)
void rotateArr(vector<int> &arr, int k) {
  int n = arr.size() - k;
  vector<int> temp;
  for (int i = n; i < arr.size(); i++) { // O(k)
    temp.push_back(arr[i]);
  }
  for (int i = 0; i < n; i++) { // O(n)
    temp.push_back(arr[i]);
  }
}
// TC : O(n), SC: O(1)
// this approach is based on the reverse of array
// 1. reverse the whole array
// 2. reverse the first k elements of the array
// 3. reverse the last n-k elements of the array
void rotateArray(vector<int> &arr, int k) {
  for (size_t i = 0; i < k; i++) {//O(n*k),SC:O(1)
    int curr = arr[arr.size() - 1];
    // shift the elments to the right side
    for (size_t j = arr.size() - 1 ; j > 0; j--)
    {
        arr[j] = arr[j-1];
    }
    arr[0] = curr;
  }
}
int main() {
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array : ";
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k : ";
    int k;
    cin >> k;
    rotateArray(arr, k);
    cout << "The rotated array is : ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;
}