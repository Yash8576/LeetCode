bool canCross(vector<int>& stones) {
    if(stones.size()>1 && stones[1]!=1) return false;
    unordered_map<int, unordered_set<int>> dp;
    for(auto i:stones){
        dp[i] = {};
    }
    dp[0].insert(0);
    for(int i=0; i<stones.size();i++){
        int cp = stones[i];
        for(int kp:dp[cp]){
            for(int kn = kp-1; kn<=kp+1;kn++){
                if(kn<=0) continue;
                int np = cp+kn;
                if(dp.count(np)){
                    dp[np].insert(kn);
                }
            }
        }
    }
    return !dp[stones.back()].empty();
}
