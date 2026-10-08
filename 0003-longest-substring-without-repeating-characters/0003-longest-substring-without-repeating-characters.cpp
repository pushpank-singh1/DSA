class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int maxLen = 0;

        //check for right in aage ki string, if found repeating then move the left to the next char of the org char of repeating char
        for (int right = 0; right < s.length(); right++) {
            if (mp.find(s[right]) != mp.end() &&
                mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }

            mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};