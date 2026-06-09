#include <iostream>
using namespace std;

// Recursion is a programming technique in which a function calls itself in
// order to solve a problem. It typically involves a base case that stops the
// recursion and a recursive case that breaks the problem into smaller
// subproblems. Recursion can be used to solve problems that can be broken down
// into similar subproblems, such as factorial calculation, Fibonacci sequence
// generation, and tree traversal.
void printNums(int n) { // Recursive function to print numbers from n to 1
  // BASE CASE :
  if (n == 0) {
    return;
  }
  cout << n << " ";
  printNums(n - 1);
}

// Recursive function for factorial
int factorial(int n) {
  // BASE CASE :
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}


// Recursive function for Summation from n to 1
int sum(int n){
  // BASE CASE :
  if(n == 1){
    return 1;
  }

  return n + sum(n-1);//recursive call
}
int main() {
  int n = 5;
  printNums(100);
  cout << endl;
  cout << "Factorial of " << n << " is " << factorial(n) << endl;
  cout << "Sum from " << n << " to 1 is : " << sum(n) << endl;
}