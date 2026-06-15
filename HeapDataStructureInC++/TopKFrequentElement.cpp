class Solution {
public:
    // Tc : O(n log k) , SC : O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a vector that store Kth Frequent element
        vector<int> kthFrequentEl;
        // create a Priority Queue pair to store all the Kth Frequent Element &
        // also store the element along it's frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;                    // MIN-HEAP({count,element})
        unordered_map<int, int> m; //(key,value) => (element,count)

        // scan the array TC : O(N)
        for (int num : nums) {
            // if the element doesn't found in the Map, it means it occurs first
            // time
            if (m.find(num) == m.end()) {
                m[num] = 1; // set the count to 1
            } else {
                m[num]++; // increment the count of element by 1
            }
        }

        for (auto it : m) { // TC : O(total unique element)
            pq.push({it.second, it.first}); //({frequency,value})
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            kthFrequentEl.push_back(pq.top().second);
            pq.pop();
        }
        return kthFrequentEl;
    }
};