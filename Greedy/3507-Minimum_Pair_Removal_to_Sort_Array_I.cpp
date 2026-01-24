class Solution {
public:
    bool isNonDecreasing(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<=nums[i+1]) continue;
            else return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        int k = 0;
        int mini = INT_MAX;
        while(!isNonDecreasing(nums)){
            for(int i=0; i<nums.size()-1; i++){
                if((nums[i]+nums[i+1]) < mini){
                    mini = nums[i] + nums[i+1];
                    k = i;
                }
            }
            nums[k] = mini;
            nums.erase(nums.begin() + k + 1);
            k=0;
            mini = INT_MAX;
            count++;
        }
        return count;
    }
};