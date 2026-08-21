#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr = {60,40,50,80,50,100,90};
    
    int sum = 0;
    for(int i=0; i < arr.size();i++){
        sum = arr[i];
    }
    cout << "Sum : " <<  sum << endl;
}