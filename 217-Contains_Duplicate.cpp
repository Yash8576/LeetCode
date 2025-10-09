bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> mpp;
    for(int i:nums){
        mpp[i]++;
    }
    for(auto i:mpp){
        if(i.second>1) return true;
    }
    return false;
}
//T.C - O(N) 
//S.C - O(N)

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 0; i<nums.size()-1; i++){
        if(nums[i] == nums[i+1]) return true;
    }
    return false;
}

//T.C - O(NlogN)
//S.C - O(1)
