class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = n-1;

        while(c >= 0 && r < m){
            if(tar == mat[r][c]){
                return true;
            } else if(tar < mat[r][c]){
                c--;
            } else {
                r++;
            }
        }

        return false;
    }
};