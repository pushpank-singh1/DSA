class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int min = nums1[0];

        if(min % 2 == 1){
            return true;
        }

        for(int i : nums1){
            if(i%2 == 1){
                return false;
            }
        }
        return true;
    }
};