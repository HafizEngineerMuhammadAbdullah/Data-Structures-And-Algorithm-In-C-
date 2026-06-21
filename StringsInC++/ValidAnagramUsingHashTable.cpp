class Solution {
public:
    // Anagram is a word or phrase formed by rearranging the letters(characters)
    // of another word to form a new meaningful word.
    // TC:O(m + n + N) where m
    // and n are the length of string s & t respectively
    // SC:O(N)
    bool isAnagram(string s, string t) {

        // unordered_map to store the occurrence(frequency) of each
        // letter(character) contained in a string s means how many times each
        // character appeared in string s
        // it basically store each character along it's(corresponding to)
        // frequency in string s
 

        //If the lengths differ, they can never be anagrams, so return immediately.
        if (s.length() != t.length())
              return false;
        unordered_map<char, int> m;

        // scan the string s
        for (char ch : s) { // TC:O(m)
            // store the character(letter) as key along the(corresponding to)
            // the frequency of character as value
            m[ch]++;
        }

        // scan string t
        for (char ch : t) { // TC:O(n)
            // decrement the frequency of each letter in
            // map by one
            if (m.find(ch) != m.end()) { // it means that char exists in map
                m[ch]--;
            }
            // else if char not found means string t is not a Valid Anagram
            else {
                return false;
            }
        }

        // check whether every occurrence of letter becomes 0 or not if not then
        // the given word 't' is not a valid Anagram
        for (const auto& [key, value] : m) { // TC:O(N) where N is the unique
                                             // character contained in string s
            if (value != 0) {
                return false; // string t is not a valid Anagram of the string s
            }
        }

        // return true if & only if every character's frequency(occurrence) is 0
        // in the freq vector this means that each letter in string s also
        // appeared in string t which is the condition of Anagram
        return true;
    }
};