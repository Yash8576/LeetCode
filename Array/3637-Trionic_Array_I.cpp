class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int p = -1, q = -1, r = -1;
        bool isIncreasing = true;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) return false;

            if (p == -1) {
                if (nums[i] < nums[i + 1]) continue;
                if (i == 0) return false;
                p = i;
                isIncreasing = false;
            } 
            else if (q == -1) {
                if (nums[i] > nums[i + 1]) continue;
                q = i;
                isIncreasing = true;
            } 
            else if (r == -1) {
                if (nums[i] < nums[i + 1]) continue;
                return false;
            }
        }
        
        r = n - 1;
        return p != -1 && q != -1 && isIncreasing;
    }
};
