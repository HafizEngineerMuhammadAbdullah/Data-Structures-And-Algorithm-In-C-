#include <iostream>
#include <vector>
using namespace std;

// function to find those two numbers(pair) indices whose sum is equal to my target value
// TC:O(n), SC:O(1)
vector<int> pairSum(const vector<int> &arr, int target){
    int n = arr.size(); 
    int st = 0;
    int end = n-1;
    // loop through until st meets with end as st move from left to right while end moves from right to left so there comes a point where both pointer meet at the(point to the) same value
    // that will be our stopping condition because we solely want that our two numbers(pairs) should be different (pair can be  made only with 2 numbers)
    // keep the two pointers at the extreme position of array
    // means keep i to point to the start of array whereas keep j to point at the end of array
    while(st < end){
        // calculate pair sum
       int pairSum = arr[st] + arr[end];
       
    //    Then there are exactly three possibilities.
       // Three Cases could occur:-
    //    Case 1: Sum is too small
    // Since the array is sorted, move st right
// to increase the sum.
    // Because the array is sorted, moving st right gives us a larger value, therefore potentially a larger sum.
       // 1. if pairSum is smaller than my target value then we need to increase the pairSum,as we know our end ptr pointing to the maximum number so we couldn't further increase the end ptr to point to more larger number(array index out of bound exception can occur) instead what we can do? is we know that my array is already sorted (specifically in ascending order) and we know that in ascending order the element increases from left to right direction so we can update the st pointer to point to more larger number than the previous value in this way we could increase the pair sum value 
       if(pairSum < target){
         st++;
       } 
    //    Case 2: Sum is too large
    // Moving end left gives us a smaller value, therefore potentially a smaller sum.
       // 1. if pairSum is greater than my target value then we need to decrease the pairSum,as we know our st ptr pointing to the smallest number so we couldn't further decrease the st ptr to point to more smallest number(array index out of bound exception can occur) instead what we can do? is we know that my array is already sorted (specifically in ascending order) and we know that in ascending order the element increases from left to right direction & decreases from right to left direction so we can update the end pointer to point to more smaller number than the previous value in this way we could decrease the pair sum value
       
       else if(pairSum > target){
           end--;
       } 
       // pair sum found
    //    Case 3: Sum is exactly target
       else{
          return {st,end};
       }
    } 
     
    return {};
}


int main(){
    cout << "\n \t \t \t \t \t \t Program to find the pair sum using Optimized(Two Pointer) approach" << endl;
    cout << "\n \t \t \t \t \t \t--------------------------------------------------------------------" << endl;
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;
   

    vector<int> result = pairSum(arr,target);
    if(result.empty()){
        cout << "Pair not Found!" << endl;
    } else{
        cout << result[0] << " , " << result[1] << endl;
    }

}