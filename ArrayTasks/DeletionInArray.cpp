#include <iostream>
using namespace std;
int main(){
    //declare,create and initialize an array with a fixed size of 3
    int LA[3] = {1,3,5};
    int n = 3;


    //print Message
    cout << "The original elements of array are :..." << endl;

     //print the elements of the whole array before deleting any of the elements of the Array
    for(int  i = 0; i < 3; ++i){
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    //shift the last element of array to the left side.
    for(int i = 1; i < n; i++){
        LA[i] = LA[i + 1];
        n = n - 1;
    }
  

    //print Message
    cout << "The array elements after deletion are:" << endl;

     //print the remaining elements of the array after deleting  last element(reducing) of the Array
    for(int  i = 0; i < n; ++i){
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }





}