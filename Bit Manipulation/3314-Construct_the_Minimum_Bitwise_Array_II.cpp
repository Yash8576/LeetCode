class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int low = 0, high = 30;
            int best = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                long long d = 1LL << mid;
                if(d > nums[i]){
                    high = mid - 1;
                    continue;
                }
                long long xx = nums[i] - d;
                long long mask = (1LL << (mid + 1)) - 1;
                if((xx & mask) == (d - 1)){
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if(best != -1){
                long long d = 1LL << best;
                ans[i] = nums[i] - d;
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};