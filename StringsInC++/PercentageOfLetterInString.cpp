class Solution {
public:
    // 🟢 Time Complexity: O(n)
    // 🟢 Space Complexity: O(1)
    int percentageLetter(string s, char letter) {
        // variable to count the occurrence of a given particular 'letter'(how
        // many times a particular letter occurred/appeared) in a string.
        int count = 0;
        // loop through (scan) string & count the frequency of a given
        // particular letter in a string
        for (char ch : s) {
            // if character of a string & letter matches , increment the count
            // of frequency of that particular character
            if (ch == letter) {
                count++;
            }
        }

        // calculate percentage of letter in string by rounding down the total
        // frequency of the particular character in string divide by length
        // of string multiply with 100
        // C++ integer division discards the decimal part
        // instead of Integer division , we will divide floating number by
        // integer which gives floating point value
        // int percentageOfLetter = floor((count * 100.0) / s.length());
        int percentageOfLetter = ((count * 100.0) / s.length());

        return percentageOfLetter; // return percentage
    }
};