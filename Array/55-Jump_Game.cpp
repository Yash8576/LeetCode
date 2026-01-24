bool canJump(vector<int>& nums) {
    if(nums.size()==1) return true;
    int ms = nums[0];
    if(ms>=nums.size()-1) return true;
    for(int i = 1; i<=ms; i++){
        if(i+nums[i]<nums.size()){
            ms = max(ms, i+nums[i]);
            if(ms == nums.size()-1) return true;
        }
        else return true;
    }
    return false;
}
