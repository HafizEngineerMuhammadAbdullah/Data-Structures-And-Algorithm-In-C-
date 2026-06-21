class Solution {
public:
    // Anagram is a word or phrase formed by rearranging the letters(characters) of another word to form a new meaningful word.
    // TC:O(m + n + 26) where m and n are the length of string s & t
    // respectively
    bool isAnagram(string s, string t) {


        //If the lengths differ, they can never be anagrams, so return immediately.
        if (s.length() != t.length())
              return false;
        // freq vector to store the occurrence(frequency) of each
        // letter(character)contained in a string s means how many times each
        // character appeared in string s
        vector<int> freq(26, 0);

        // scan the string s
        for (char ch : s) {
            // try to map the letter(character) with vector idx
            int letterIdx = ch - 'a';
            freq[letterIdx]++; // count the frequency of each letter in a string
                               // s
        }

        // scan string t
        for (char ch : t) {
            // try to map the letter(character) with vector idx
            int letterIdx = ch - 'a';
            freq[letterIdx]--; // decrement the frequency of each letter in
                               // frequency vector
        }

        // check whether every occurrence of letter becomes 0 or not if not then
        // the given word 't' is not a valid Anagram
        for (int val : freq) {
            if (val != 0) {
                return false; // string t is not a valid Anagram of the string s
            }
        }

        // return true if & only if every character's frequency(occurrence) is 0
        // in the freq vector this means that each letter in string s also
        // appeared in string t which is the condition of Anagram
        return true;
    }
};