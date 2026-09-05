class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0){
            return -1;
        }

        //prefixMax = maximum from nums[0] to nums[i]
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        //suffixMin = minimum from nums[i] to nums[n-1]
        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            int instabillity = prefixMax[i] - suffixMin[i];

            if(instabillity <= k){
                return i;
            }
        }

        return -1;
    }
};