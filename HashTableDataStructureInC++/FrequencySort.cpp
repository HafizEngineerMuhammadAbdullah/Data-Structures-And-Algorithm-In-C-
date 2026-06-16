class Solution {
public:
    // TC:O(n + klogk) , SC:O(n + k)
    string frequencySort(string s) {

        // store the sorted string in the decreasing order
        string sortedString;
        // Frequency of character is the
        // number of times it appeared in the given string

        // unordered_map track the frequency of each character in a string,
        // it basically store character along it's (corresponding to) frequency
        // we have seen so far
        unordered_map<char, int> m; //(key,value) => (character,occurrence)
        for (auto ch : s) {        // TC:O(n) where n is the total number of
                                    // characters in the string
            m[ch]++;
        }

        // create a Priority Queue that store the character along the frequency
        // of the character in the given string.

        // Max-Heap DS that maintain the largest element to be present at the
        // top of Priority Queue this is the default behaviour of PQ

        // priority_queue (max-heap) to keep characters ordered by frequency.
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for (const auto& [key, value] :
             m) { // TC:O(klogk) where k is the unique character in a string
            pq.push({value, key}); // because we want that character is arranged
                                   // in PQ according to the decreasing order of
                                   // the frequency of character of the string
        }

        // loop until pq becomes empty
        while (!pq.empty()) { // TC:O(n)
            const int freq = pq.top().first;
            for (int i = 0; i < freq; i++) {
                sortedString += pq.top().second;
            }
            pq.pop();
        }

        return sortedString;
    }
};