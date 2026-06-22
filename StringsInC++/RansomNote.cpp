class Solution {
public:
    // TC:O(m+n) , SC:O(k) where m and n are the size of magazine & ransomNote
    // word respectively & k is the number of distinct letter in the word
    // magazine
    bool canConstruct(string ransomNote, string magazine) {

        // ransom Note can be constructed from magazine word if & only if each
        // letter in ransomNote must also be present(exist) in magazine.In other
        // words ,we can say ransomNote should be the subset of magazine.
        // also remember that each letter in string magazine can only be used
        // once in ransomNote

        // if the ransomNote word size is greater than magazine word length,it
        // can never be constructed using the letters of magazine
        // If the ransom note is longer than the magazine, it's impossible to
        // construct it.
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        // count the frequency of each letter in a string called magazine by
        // using HashTable
        unordered_map<char, int>
            m; // unordered-map(key,value) => (letter, count) store each
               // letter/character along it's count(occurrence/frequency)
        // it stores character as key & it's occurrence as value
        for (char ch : magazine) { // TC:O(m)
            m[ch]++;
        }

        // check whether every character(letter) that occurs in string
        // ransomNote are also present in string maganize or not
        // if not return false
        // for (char ch : ransomNote) { // TC:O(n)
        //     if (m.find(ch) != m.end()) {
        //         m[ch]--; // decrement the frequency(count/occurrence) by 1
        //         if(m[ch] < 0){
        //             return false;
        //         }
        //     } else {     // if the letter not found in map,ransomNote can't
        //     be
        //                  // constructed
        //         return false;
        //     }
        // }
        for (char ch : ransomNote) { // TC:O(n)
            // if the character doesn't exist in map or if the character exists
            // but has been used too many times return false
            if (m.find(ch) == m.end() || m[ch] <= 0) {
                // if the letter not found in map,ransomNote can't be
                // constructed
                return false;
            }
            m[ch]--; // decrement the frequency(count/occurrence) by 1
        }

        // for (const auto& [key, value] : m) { // TC:O(k)
        //     // if key value is lesser than 0 means a specific letter of
        //     string
        //     // ransomNote occur(used) more than letter occurred(used) in
        //     string magazine if (value < 0) {
        //         return false;
        //     }
        // }

        return true;
    }
};