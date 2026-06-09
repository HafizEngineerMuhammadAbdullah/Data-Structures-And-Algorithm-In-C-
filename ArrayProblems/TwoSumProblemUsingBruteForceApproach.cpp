#include<iostream>
#include<vector>
using namespace std;

class TwoSumProblem{

public :

    vector<int> twoSumProblem(vector<int> &nums, int target){
    for(int i = 0; i < nums.size(); i++){//TC:O(n),SC:O(1)
            for(int j = i + 1; j < nums.size(); j++){
                  if(target == nums[i] + nums[j]){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
int main(){
     TwoSumProblem p1;

    vector<int> arr = {1,2,3,4,5,6}; 

    vector<int> v = p1.twoSumProblem(arr, 10);

    cout<< "[" ;
    for(int i = 0; i < v.size(); ++i){
        cout << v[i];
        if(i < v.size() - 1)
            cout << " , ";
    }
    cout << "]" << endl;
}