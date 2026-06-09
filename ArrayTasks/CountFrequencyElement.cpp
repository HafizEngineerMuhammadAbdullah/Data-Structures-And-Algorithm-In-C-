#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// Qs : 06
// Write a function that calculates the frequency of each unique element in the
// array
void countFrequencyOfEachElement(vector<int> &, int); // function prototype
static int frequency[10];
int main() {
  cout << "\n \t \t \t \t \t \t Program to count the frequency of each element "
          "of the array"
       << endl;
  cout << "\n \t \t \t \t \t "
          "\t================================================================"
       << endl;
  int size;

  cout << "Please, Enter the size of Array:..." << endl;
  cin >> size;

  // Create a vector (Dynamic Array)
    vector<int> arr(size);

  // take the elements of array as input from the user
  cout << "Please, Enter the elements in an Array(0-9):..." << endl;
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

  // count frequency of each element
  countFrequencyOfEachElement(arr, 0);
  return 0;
}

void countFrequencyOfEachElement(vector<int> &arr, int i) {
  if (i >= arr.size()) {
    cout << "\n" << setw(10) << "Number" << setw(15) << "Frequency" << endl;
    // output each array element's value
    for (int num = 0; num < 10; num++)
      cout << setw(9) << num << setw(14) << frequency[num] << endl;
    return;
  }
  ++frequency[arr[i]];
  countFrequencyOfEachElement(arr, ++i);
}