    #include <iostream>
    #include <vector>
    using namespace std;

    // function to find those two numbers(pair) indices whose sum is equals to my target value
    // TC:O(n^2), SC:O(1)
    vector<int> pairSum(const vector<int> &arr, int target){
        // checks/find all/every possible pair.
        vector<int> result;
        // pick each element and check if there is a pair that sums to the target

        // firstly,pick the first element and then check for the second element in the remaining array
        for(int i = 0; i < arr.size(); i++){
            // pick the second element of the pair from the remaining array
            for(int j = i + 1; j < arr.size(); j++){
                // if the pair sum is equals to my target value,means we have found those two numbers(pair) return that pair values in the form of indices
                if(arr[i] + arr[j] == target){
                    // store the pair indices in results
                    result.push_back(arr[i]);
                    result.push_back(arr[j]);
                    return result;
                }
            }
        }
        return result;
    }


    int main(){
        cout << "\n \t \t \t \t \t \t Program to find the pair sum using brute force approach" << endl;
        cout << "\n \t \t \t \t \t \t---------------------------------------------------------" << endl;
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
    

        vector<int> ans = pairSum(arr,target);
        cout << ans[0] << " , " << ans[1] << endl;

    }