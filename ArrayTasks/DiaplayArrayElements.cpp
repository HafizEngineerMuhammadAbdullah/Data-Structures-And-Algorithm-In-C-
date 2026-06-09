#include <iostream>
using namespace std;
int main() {
  // declare and initialize a built-in array:
  int LA[] = {1, 2, 3, 4, 5, 6};
  //calculate the size of Array
  int  n = sizeof(LA)/ sizeof(int);
  // item to search
  int item = 3;

  // print Message
  cout << "The original elements of array are :..." << endl;

  // print the elements of the whole array
  //loop to print Array
  for (int i = 0; i < n; ++i) {
    cout << "LA[" << i << "] = " << LA[i] << endl; // print each element
  }

}