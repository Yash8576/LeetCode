class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int x = 0; x < nums[i]; x++) {
                if ((x | (x + 1)) == nums[i]) {
                    ans[i] = x;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};