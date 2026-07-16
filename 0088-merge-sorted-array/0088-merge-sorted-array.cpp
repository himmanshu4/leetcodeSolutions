class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto write_itr = nums1.rbegin();
        auto nums1_itr = nums1.rbegin() + n;
        auto nums2_itr = nums2.rbegin();
        while (nums1_itr < nums1.rend() && nums2_itr < nums2.rend()) {

            if (*nums1_itr > *nums2_itr) {
                *write_itr = *nums1_itr;
                nums1_itr++;
            } else {
                *write_itr = *nums2_itr;
                nums2_itr++;
            }
            write_itr++;
        }
        while (nums1_itr < nums1.rend()) {
            *write_itr = *nums1_itr;
            write_itr++;
            nums1_itr++;
        }
        while (nums2_itr < nums2.rend()) {
            *write_itr = *nums2_itr;
            write_itr++;
            nums2_itr++;
        }
    }
};