void moveZeroes(vector<int>& nums) {
    int k = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i>k && nums[i] != 0){
            swap(nums[i], nums[k]);
            k++;
        }
        else if(nums[i] ==0){
            continue;
        }
        else{
            k++;
        }
    }
}
