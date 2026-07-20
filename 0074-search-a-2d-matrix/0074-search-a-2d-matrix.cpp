class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // finding the row
        auto row = upper_bound(matrix.begin(), matrix.end(), target,
                               [](auto& target, const auto& element) {
                                   return target < element[0];
                               });
        if (row == matrix.begin()) {
            return false;
        }
        row--;
        auto elem = lower_bound(row->begin(), row->end(), target);
        if (elem == row->end()) {
            return false;
        }
        return *elem == target;
    }
};