class Solution {
public:
    // TC:O(n) , SC:O(1) as such we don't have use any other DS,we only used two
    // pointers(variables) to tackle & solve this problem
    // ✅ Uses Floyd's Tortoise and Hare Cycle Detection
    int findDuplicate(vector<int>& arr) {
        // Using Slow Fast Pointer Approach :=
        // Using Floyd's Cycle Detection Algorithm
        // In this Approach,we imagine array as a LinkedList where index of
        // array represents original node of LL & elements  of array represents
        // nextNode of LL
        // Now, we initialize the slow & fast to starting value of array
        int slow = arr[0], fast = arr[0];
        do {
            // update slow to one step forward => +1
            slow = arr[slow];
            // update fast to two steps forward at double pace(speed) => +2
            fast = arr[arr[fast]];
        } while (slow !=
                 fast); // keep updating until both point to the same node

        slow = arr[0];
        while (slow != fast) {
            // move(update) both slow & fast to one step forward
            slow = arr[slow]; // +1
            fast = arr[fast]; // +1
        }

        // Both pointers now point to the entrance of the cycle,
        // which represents the duplicate number.
        return fast; // resultant duplicate value occur in an array
    }
};