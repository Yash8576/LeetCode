class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1;
        int maxi = INT_MIN;
        while(i<(n/2)){
            maxi = max(maxi, nums[i] + nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};