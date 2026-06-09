#include <iostream>
#include <array>
using namespace std;
// Qs : 02
// Write a function to calculate the sum and average of all array elements.

// calculate the sum of Array
int calcSum(array<int, 5> &arr, int j, int total) {
  if (j >= arr.size()) {
    return total;
  }
  total += arr[j];
  return calcSum(arr, ++j, total);
}

// calculate the average of array
double calcAvg(array<int, 5> &arr) {
  int total = calcSum(arr, 0, 0);
  double avg = static_cast<double>(total) / arr.size();
  return avg;
}
int main() {

  cout << "\n \t \t \t \t \t \t Write a function to calculate the sum and "
          "average of all array elements."
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t=================================================================="
          "=============="
       << endl;
  const int size = 5;

  // declare and create an object array:
  array<int, size> arr;

  // take the elements of array as input from the user
  cout << "Please, Enter the elements in an Array:..." << endl;
  for (size_t i{0}; i < size; i++) {
    cin >> arr[i];
  }

  // print Message
  cout << "The user inputted elements of array are :..." << endl;

  // print the elements of the whole array
  // loop to print Array
  for (int i{0}; i < size; ++i) {
    cout << "arr[" << i << "] = " << arr[i] << endl; // print each element
  }

  // call/invoke the sum function
  cout << "sum : " << calcSum(arr, 0, 0) << endl;
  // call/invoke the average function
  cout << "Average of array is : " << calcAvg(arr) << endl;
}