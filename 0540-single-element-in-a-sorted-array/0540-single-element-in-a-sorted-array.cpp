class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int ans = 0;
        for(int val: A){
            ans = ans ^ val;
        }
        return ans;
    }
};