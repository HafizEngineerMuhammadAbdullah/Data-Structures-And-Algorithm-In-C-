#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// Qs : 03
// Find the maximum and minimum value in the array.

//calculate Minimum Element in an Array
int calculateMinElement(vector<int> &arr, int i) {
  static int min = INT_MAX;
  if (i >= arr.size()) {
    int tempMin = min;
    min = INT_MAX; // Reset for future calls
    return tempMin;
  }
  if (min > arr[i]) {
    min = arr[i];
  }
  return calculateMinElement(arr, ++i);
}


//calculate Maximum Element in an Array
int calculateMaxElement(vector<int> &arr, int i) {
  static int max = INT_MIN;
  if (i >= arr.size()) {
    int tempMax = max;
    max = INT_MIN; // Reset for future calls
    return tempMax;
  }
  if (max < arr[i]) {
    max = arr[i];
  }
  return calculateMaxElement(arr, ++i);
}
int main() {

  cout << "\n \t \t \t \t \t \t Program to Find the maximum and minimum value "
          "in the array."
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t==============================================================="
       << endl;
  int size;

  cout << "Please, Enter the size of Array:..." << endl;
  cin >> size;

  // Create a vector (Dynamic Array)
  vector<int> arr(size);

  // take the elements of array as input from the user
  cout << "Please, Enter the elements in an Array:..." << endl;
  for (size_t i = 0; i < size; i++) {
    cin >> arr[i];
  }

  // print Message
  cout << "The user inputted elements of array are :..." << endl;

  // print the elements of the whole array
  // loop to print Array
  for (int i = 0; i < size; ++i) {
    cout << "arr[" << i << "] = " << arr[i] << endl; // print each element
  }

  cout << "The Maximum and Minimum Element of Inputted Array are respectively "
          "given below:... "
       << endl;
  cout << "Max: " << calculateMaxElement(arr, 0) << endl;
  cout << "Min: " << calculateMinElement(arr, 0) << endl;
}