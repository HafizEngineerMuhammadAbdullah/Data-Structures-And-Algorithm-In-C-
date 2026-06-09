#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Qs : 05
// Write a function to find the second largest element in the array.

//calculate second largest Element in an Array
int calculateSecondLargestElement(vector<int> &, int, int,
                                  int); // function prototype
//calculate Minimum Element in an array 
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

//calculate Maximum Element in an array 
int calculateMaxElement(vector<int> &arr, int i) {
  static int myMax = INT_MIN;
  if (i >= arr.size()) {
    int tempMax = myMax;
    myMax = INT_MIN; // Reset for future calls
    return tempMax;
  }
  if (myMax < arr[i]) {
    myMax = arr[i];
  }
  return calculateMaxElement(arr, ++i);
}
int main() {

  cout << "\n \t \t \t \t \t \t Program to find the second largest element in "
          "the array."
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t============================================================"
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

  int max = calculateMaxElement(arr, 0);
  int secondLargest = INT_MIN;
  cout << "The Second Largest Element of Inputted Array is "
          "given below:... "
       << endl;
  cout << calculateSecondLargestElement(arr, 0, max, secondLargest) << endl;
}

int calculateSecondLargestElement(vector<int> &arr, int i, int max,
                                  int secondLargest) {
  if (i >= arr.size()) {
    return secondLargest;
  }
  if (secondLargest < arr[i] && arr[i] < max) {
    secondLargest = arr[i];
  }
  return calculateSecondLargestElement(arr, ++i, max, secondLargest);
}