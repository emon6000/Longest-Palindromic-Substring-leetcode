#include <bits/stdc++.h>
using namespace std;

// Function to expand around the center and update the longest palindrome found
void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        if (right - left + 1 > maxLen) {
            start = left;
            maxLen = right - left + 1;
        }
        left--;
        right++;
    }
}

// Function to find the longest palindromic substring
string longestPalindrome(string &s) {
    int n = s.size();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        expandAroundCenter(s, i, i, start, maxLen);     // Odd-length palindrome
        expandAroundCenter(s, i, i + 1, start, maxLen); // Even-length palindrome
    }

    return s.substr(start, maxLen);
}

int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalindrome(s) << endl;
    return 0;
}
