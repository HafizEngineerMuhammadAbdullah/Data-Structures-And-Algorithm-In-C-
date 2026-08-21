#include <iostream>
using namespace std;

class Solution {
public:
    // TC:O(logn), SC:O(1) as we repeatedly dividing the exponent by 2(halving
    // the power) n/2^0 ->  n/2^1 ->  n/2^2 ->  n/2^3 -> ... ->  n/2^k -> 1 => n
    // / 2^k = 1 n = 2^k in exponential form logn in logarithmic form

    // The deeper idea is:
//     Exponent even:
// x^n = (x^(n/2))²

// Exponent odd:
// x^n = x × x^(n-1)

//     answer stores the part of x n corresponding to the exponent bits we've already processed, while x keeps becoming x
// 1
// ,x
// 2
// ,x
// 4
// ,x
// 8
// ,….

// Whenever the current binary bit is 1, you multiply that power into answer.
// At every iteration the exponent is divided by 2. After k iterations, the exponent becomes n/2 k . We stop when it reaches 1, so 2k≈n, giving k=O(logn).

// The iterative version combines these ideas by:
// odd exponent → save current x in answer
// always → square x
// always → halve exponent
// That is the heart of the algorithm.
    double myPow(double x, int n) {
        // Edge / Corner Cases
        if (n == 0 || x == 1)
            return 1.0;
        if (x == 0)
            return 0.0;
        if (n == 1)
            return x;
        if (x == -1 && n % 2 == 0)
            return 1.0;
        if (x == -1 && n % 2 != 0)
            return -1.0;

        double answer = 1;

        int binaryForm = n;

        // if negative power comes
        if (n < 0) {
            x = 1 / x;
            binaryForm = -binaryForm;
        }

        while (binaryForm > 0) {
            // if current exponent is odd,save one extra factor of x
            // if odd power comes,
            if (binaryForm % 2 == 1) {
                answer *= x;
            }
            // square number
            // prepare the next power x^2
            x = x * x;
            // halve the power or exponent
            binaryForm /= 2;
        }

        return answer;
    }
};
int main(){

}