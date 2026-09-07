class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        long long dp = 1; // empty subsequence
        
        vector<long long> last(26, 0);
        
        for (char ch : s) {
            int idx = ch - 'a';
            
            long long newDp = (2 * dp) % MOD;
            
            // Remove duplicate subsequences created by this character
            newDp = (newDp - last[idx] + MOD) % MOD;
            
            // Store current dp before updating
            last[idx] = dp;
            
            dp = newDp;
        }
        
        // Exclude the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};