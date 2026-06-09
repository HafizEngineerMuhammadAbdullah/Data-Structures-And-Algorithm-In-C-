#include <iostream>
#include <vector>
using namespace std;
// Qs : 04
// Display the array elements in reverse order.

// function that display the array elements
void printArray(vector<int> &, int); // function protoype
// function that display the array elements in reverse order
void displayReverse(vector<int> &, int); // function protoype
int main() {

  cout << "\n \t \t \t \t \t \t Display the array elements in reverse order."
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t================================================"
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
  printArray(arr, 0);

  // print Message
  cout << "Reverse Elements of array are:..." << endl;

  displayReverse(arr, size);
}
void displayReverse(vector<int> &arr, int sz) {
  if (sz == 0) {
    cout << endl;
    return;
  }
  cout << arr[sz - 1] << " ";
  displayReverse(arr, --sz);
}
// function that print the elements of the whole array
void printArray(vector<int> &arr, int i) {
  if (i >= arr.size()) {
    return;
  }
  cout << "arr[" << i << "] = " << arr[i++] << endl; // print each element
  printArray(arr, i);
}