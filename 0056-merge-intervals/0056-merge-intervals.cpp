class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals={intervals[0]};
        for (const auto& current_interval : intervals) {
            auto& last_interval = merged_intervals.back();
            if (last_interval[1] < current_interval[0]) {
                merged_intervals.push_back(current_interval);
            } else {
                last_interval[1] = max(last_interval[1], current_interval[1]);
            }
        }
        return merged_intervals;
    }
};