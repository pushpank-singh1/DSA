class Solution {
public:
    void getAllCombinations(vector<int>& arr, int idx, int tar,vector<vector<int>>& ans, vector<int>& combin){
        //base case
        if(tar == 0){
            ans.push_back(combin);
            return;
        }
        
        for(int i=idx; i<arr.size(); i++){
            //skipping duplicates
            if(i > idx && arr[i] == arr[i-1]){
                continue;
            }
            if(arr[i] > tar){
                break;
            }

            combin.push_back(arr[i]);
            //single
            getAllCombinations(arr, i+1, tar-arr[i], ans, combin);

            combin.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(arr, 0, tar, ans, combin);
        return ans;
    }
};