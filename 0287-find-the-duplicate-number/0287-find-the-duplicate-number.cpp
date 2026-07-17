class Solution {
public:
    void setFreq(int x,vector<int>&arr) {
        arr[x]=-arr[x];

    }
    int findDuplicate(vector<int>& nums) {
        vector<int> &arr=nums;
        for (const int& x : nums) {
            if(arr[abs(x)]<0){
                return abs(x);
            }
            arr[abs(x)]*=-1;
        }
        return 0;
    }
};