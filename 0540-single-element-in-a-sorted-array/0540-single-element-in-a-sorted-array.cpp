class Solution {
public:
    bool check(int n, const vector<int>& v) { return v[2 * n] == v[2 * n + 1]; }
    int singleNonDuplicate(vector<int>& nums) {
        // lets generate number x, ->2*x==2*x+1 is true for 1st half and breaks
        // for 2nd half with the wrong number bing the 1st that breaks

        int ans = -1;
        for (int z = nums.size() / 2; z > 0; z /= 2) {
            while ((ans + z)*2 < nums.size() && check(ans + z, nums)) {
                ans += z;
            }
        }
        return nums[2 * (ans + 1)];
    }
};