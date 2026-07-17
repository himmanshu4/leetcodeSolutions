class Solution {
public:
    void setFreq(int x,vector<int>&arr) {
        arr[x]=-arr[x];

    }
    int findDuplicate(vector<int>& nums) {
        vector<int> &arr=nums;
        for (int& x : nums) {
            if(arr[abs(x)]<0){
                return abs(x);
            }
            setFreq(abs(x),arr);
        }
        return 0;
    }
};