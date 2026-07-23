class Solution {
    // finds the number of reversals in [l,r).
    void pairReversal(vector<int>& nums, int l, int r, int& count) {
        // pass over 2nd part nums and do a binary search in the 1st array
        if(r-l<=1){
            return;
        }
        int mid = (l + r) / 2;
        pairReversal(nums, l, mid, count);
        pairReversal(nums, mid, r, count);

        auto lIter = nums.begin() + l;
        auto lEnd = nums.begin() + mid;
        auto rIter = nums.begin() + mid;
        auto rEnd = nums.begin() + r;

        while (lIter < lEnd && rIter < rEnd) {

            long long b = *rIter;
            while (lIter < lEnd) {
                long long a = *lIter;
                if (a > 2 * b) {
                    break;
                }
                lIter++;
            }
            int numReversals = lEnd - lIter;
            count += numReversals;
            rIter++;
        }
        sort(nums.begin() + l, nums.begin() + r);
    }

public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        pairReversal(nums, 0, nums.size(), ans);
        return ans;
    }
};