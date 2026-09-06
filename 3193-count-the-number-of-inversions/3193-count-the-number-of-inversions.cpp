class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;

        // req[i] = required inversion count for prefix ending at i
        vector<int> req(n, -1);

        for (auto& r : requirements) {
            int end = r[0];
            int cnt = r[1];

            // If conflicting requirements exist
            if (req[end] != -1 && req[end] != cnt) {
                return 0;
            }

            req[end] = cnt;
        }

        // Maximum inversion count is limited by requirements.
        // LeetCode constraints usually have cnt <= 400.
        int maxInv = 0;

        for (auto& r : requirements) {
            maxInv = max(maxInv, r[1]);
        }

        vector<vector<long long>> dp(n, vector<long long>(maxInv + 1, 0));

        // A permutation of length 1 has 0 inversions
        dp[0][0] = 1;

        if (req[0] != -1 && req[0] != 0) {
            return 0;
        }

        for (int i = 1; i < n; i++) {

            for (int inv = 0; inv <= maxInv; inv++) {

                // Add the new element in different positions.
                // It can create 0 to i new inversions.
                for (int add = 0; add <= i && add <= inv; add++) {
                    dp[i][inv] =
                        (dp[i][inv] + dp[i - 1][inv - add]) % MOD;
                }
            }

            // If there is a requirement for this prefix,
            // keep only that inversion count.
            if (req[i] != -1) {
                for (int inv = 0; inv <= maxInv; inv++) {
                    if (inv != req[i]) {
                        dp[i][inv] = 0;
                    }
                }
            }
        }

        long long ans = 0;

        for (int inv = 0; inv <= maxInv; inv++) {
            ans = (ans + dp[n - 1][inv]) % MOD;
        }

        return ans;
    }
};