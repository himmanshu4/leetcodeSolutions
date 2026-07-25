class Solution {
public:
    void solve(const map<int, int>::iterator lastIt, vector<vector<int>>& ans,
               vector<int>& tmpAns, map<int, int>::iterator it) {
        cout<<it->first<<" "<<it->second<<"\n";
        if (it == lastIt) {
            ans.push_back(tmpAns);
            return;
        }
        auto nextIt = it;
        nextIt++;
        solve(lastIt, ans, tmpAns, nextIt);
        for (int i = 0; i < it->second; i++) {
            tmpAns.push_back(it->first);
            solve(lastIt, ans, tmpAns, nextIt);
        }
        for (int i = 0; i < it->second; i++) {
            tmpAns.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        vector<int> tmpAns;
        solve(m.end(), ans, tmpAns, m.begin());
        return ans;
    }
};