class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for (auto interval : intervals) {
            
            // If ans is empty OR no overlap
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            }
            else {
                // Overlap: merge the intervals
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};