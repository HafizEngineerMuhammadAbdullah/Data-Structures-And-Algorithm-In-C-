#include <iostream>
using namespace std;
// Qs : 01
// Modify the program to input values from the user instead of hardcoded values.
int main() {

  cout << "\n \t \t \t \t \t \t Modify the program to input values from the "
          "user instead of hardcoded values."
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t=================================================================="
          "=============="
       << endl;
  int size;

  cout << "Please, Enter the size of Array:..." << endl;
  cin >> size;

  // declare,create and initialize a built-in array:
  int arr[size];

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
}