class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto s: strs){
            string orgStr = s;
            sort(s.begin(), s.end());
            m[s].push_back(orgStr);
        }

        vector<vector<string>> anagrams;
        for(auto [key, vecOfStr]: m){
            anagrams.push_back(vecOfStr);
        }

        return anagrams;
    }
};