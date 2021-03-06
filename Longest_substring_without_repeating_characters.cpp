/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ans(256,-1);
        int left = 0, right = 0, len = 0, n = s.size();
        while(right<n){
            if(ans[s[right]] != -1)
                left = max(left,ans[s[right]]+1);
            ans[s[right]] = right;
            len = max(len, right - left +1);
            right++;
        }
        return len;
    }
};
