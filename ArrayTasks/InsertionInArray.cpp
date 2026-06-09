#include <iostream>
using namespace std;
int main(){
    //declare and create an empty array called "LA" of fixed-size 3
    int LA[3] = {};

    cout << "Array Before Insertion" << endl;

    //print the elements of the whole array before inserting any of the elements in the Array
    for(int  i = 0; i < 3; ++i){
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }

    cout << "Inserting elements.." << endl;
    cout << "Array after Insertion:" << endl;

    //insert(add/push) an element and print (display) it in the window
    for(int i = 0; i < 3; ++i){
        LA[i] = i + 2;
        cout << "LA[" << i << "] = " << LA[i] << endl;
    }



    return 0;
}