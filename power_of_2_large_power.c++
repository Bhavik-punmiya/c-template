/*
Problem: Project Euler #16 (Programming Version)

Description:
Given an integer `n`, compute 2^n and return the sum of its digits.

Input Format:
- The first line contains an integer `T`, the number of test cases.
- The next `T` lines each contain a single integer `n`.

Output Format:
- For each test case, print the sum of digits of the number 2^n.

Constraints:
- 1 <= T <= 100
- 0 <= n <= 10000

Sample Input:
3
3
4
7

Sample Output:
8
7
11

Explanation:
- 2^3 = 8, sum of digits = 8
- 2^4 = 16, sum of digits = 1 + 6 = 7
- 2^7 = 128, sum of digits = 1 + 2 + 8 = 11

Note:
- Since 2^n grows very large for big `n`, we cannot store the result in standard int/long types.
- We simulate multiplication using a vector to represent big integers.
*/

#include <iostream>
#include <vector>
using namespace std;

// Multiplies a big number (represented as a vector of digits) by 2
void multiplyBy2(vector<int>& number) {
    int carry = 0;
    for (int i = 0; i < number.size(); i++) {
        int product = number[i] * 2 + carry;
        number[i] = product % 10;
        carry = product / 10;
    }
    // Handle remaining carry by appending digits
    while (carry) {
        number.push_back(carry % 10);
        carry /= 10;
    }
}

// Calculates 2^n and returns the sum of its digits
int powerOfTwoDigitSum(int n) {
    vector<int> number = {1}; // Represents the number 1 (i.e., 2^0)
    
    for (int i = 1; i <= n; i++) {
        multiplyBy2(number); // Multiply current number by 2
    }

    // Sum all digits in the number
    int sum = 0;
    for (int digit : number) {
        sum += digit;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << powerOfTwoDigitSum(n) << endl;
    }
    return 0;
}
