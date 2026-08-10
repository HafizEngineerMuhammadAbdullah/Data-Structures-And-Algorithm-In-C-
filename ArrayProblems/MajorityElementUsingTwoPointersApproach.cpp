#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Boyer–Moore Voting Algorithm
// You only have:
// i → traversal index
// freq → candidate's voting count
// Think of the algorithm as cancellation.
// majority element → +1 vote
// other element     → -1 vote
// The majority element has more than half of all votes, so the other elements cannot completely cancel it.
// That's the fundamental mathematical reason Boyer–Moore works.
// Function to find Majority Element Using Two Pointers(Optimal)/Moore's Voting  Approach 
// Majority Element is the element whose frequency is greater than n/2 ⌊n/2⌋ times(more than half of the array) where n is the size of array
// it is the element more tha floor ⌊n/2⌋ times
// Our Majority Element should exists more than half size times in the given array
// Majority Element should occupied places more than  ⌊n/2⌋ times in the given array
// it means Majority Element occupies placed more than half of array and the remaining element ocurred less than half of array
// More's Voting Algorithm said that among all the elements frequency/count ,it is must/compulsory that the Majority Element have a higher frequency/occurrence than the others as it occurred most times than others
// as well as More's voting Algorithm said that if the elements other than Majority element want to decrease the frequency/count of Majority element,eventually at the end of traversing/iterating array Majority element must have higher frequency than remaining entities in the array  
// since we know that MaJority Element reserved spaces/placed more than half of array as it has more power in the array 
// TC:O(n) , SC:O(1) 
int majorityElement(vector<int> &nums){
    int n = nums.size();
    
    int freq = 0, ans;
    for(int i=0; i<n; i++){
        
        // if the frequency of element becomes '0' ,new element has occurred store it in ans
        // If the current candidate gets completely cancelled,
// choose the current element as the new candidate.
// Because freq == 0 doesn't literally mean "a new element occurred." It means the previous candidate has been completely cancelled by other elements.
        if(freq == 0){
            ans = nums[i];
        }
        // if the ans element matches with the curr element ,increase the frequency by 1
        if(ans == nums[i]) freq++;
        // else decrease the frequency by 1
        else freq--;
    }
    
    // now,we are ensuring whether the elemment stored in ans is a Majority element or not as it is not confirmed that there must be an always Majority Element exists in the array 
    // That's important when the problem doesn't guarantee that a majority element exists
    freq = 0;
    for(int val : nums){
        if(val == ans){
            freq++;
        }
    }

    if(freq > n/2){
        return ans;
    } else return -1;

}
int main()
{
   cout << "\n \t \t \t \t \t \t Program to find Majority Element Using Optimal(Boyer-Moore Voting Algorithm) Approach" <<endl;
   cout << "\n \t \t \t \t \t \t=======================================================================" << endl;


   int size;
   cout << "Enter the size of array:..." << endl;
   cin >> size;
   vector<int> arr(size);

   cout << "Enter the Elements in an array:..." << endl;
   for(int i=0; i<size; i++){
    cin >> arr[i];
   }

   int majorityEl = majorityElement(arr);
   cout << "Majority Element is : " << majorityEl << endl;
}