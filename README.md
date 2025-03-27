# Longest Palindromic Substring

## 📌 Problem Statement
Given a string `s`, return the longest palindromic substring in `s`.

A **palindrome** is a string that reads the same forward and backward. For example, "racecar" and "abba" are palindromes.

---

## 💡 Algorithm Explanation (Expand Around Center)
We use the **Expand Around Center** approach, which iterates over the string and expands outward to check for palindromes.

### **🔹 How It Works?**
1. Each character (and each pair of adjacent characters) is treated as a potential center of a palindrome.
2. Expand outwards while the characters match.
3. Keep track of the **longest palindrome found**.

### **🔹 Function Explanation**
#### **1️⃣ expandAroundCenter() Function**
This function expands around a given center and updates the longest palindrome found.
```cpp
void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen) {
    // Expand while the characters match and are within bounds
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        // If the current palindrome is longer than the previously recorded one, update
        if (right - left + 1 > maxLen) {
            start = left;  // Update start index of the longest palindrome
            maxLen = right - left + 1;  // Update maximum length found
        }
        left--;  // Move left pointer outward
        right++; // Move right pointer outward
    }
}
```
- **Parameters:**
  - `s`: The input string.
  - `left, right`: The center indices of the palindrome.
  - `start, maxLen`: Variables that store the start index and maximum length of the longest palindrome found.
- **Process:**
  - Expand outward as long as `s[left] == s[right]`.
  - If a longer palindrome is found, update `start` and `maxLen`.
  - Continue expanding until a mismatch is found.

#### **2️⃣ longestPalindrome() Function**
This function iterates through the string and finds the longest palindromic substring.
```cpp
string longestPalindrome(string &s) {
    int n = s.size();
    if (n == 0) return ""; // Handle empty string case

    int start = 0, maxLen = 1; // Initialize variables

    for (int i = 0; i < n; i++) {
        expandAroundCenter(s, i, i, start, maxLen);     // Odd-length palindrome
        expandAroundCenter(s, i, i + 1, start, maxLen); // Even-length palindrome
    }

    return s.substr(start, maxLen); // Extract and return the longest palindrome
}
```
- **Process:**
  - Iterate over each index `i` as a potential center.
  - Call `expandAroundCenter()` twice:
    1. Once for odd-length palindromes (`i, i` as center).
    2. Once for even-length palindromes (`i, i+1` as center).
  - The longest palindrome found is extracted using `s.substr(start, maxLen)`.

### **🔹 Visualization**
Consider the input string:

```
    "forgeeksskeegfor"
```

#### **Step-by-step expansion:**
1. Start at 'g', expand to "geeksskeeg" ✅
2. Check all centers, update max length if a longer palindrome is found.
3. The longest palindrome is **"geeksskeeg"**.

---

## **⏳ Complexity Analysis**
- **Time Complexity**: `O(n^2)` (Each character is a center, and we expand around it)
- **Space Complexity**: `O(1)` (No extra space used)

---

## **🖥️ C++ Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to expand around center and update the longest palindrome found
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
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}
```



## **🔗 References**
- [LeetCode Problem](https://leetcode.com/problems/longest-palindromic-substring/)


