class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
    int maxLength = 0, left = 0, right = 0;
    std::unordered_set<char> charSet;

    while (right < n) {
        if (charSet.find(s[right]) == charSet.end()) {
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
            ++right;
        } else {
            charSet.erase(s[left]);
            ++left;
        }
    }

    return maxLength;
    }
};