bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    dp[s.size()] = true;
    for(int i=s.size()-1;i>=0;i--){
        for(auto j:wordDict){
            if(i+j.size() <= s.size() && s.substr(i, j.size()) == j){
                if(dp[i+j.size()]){
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[0];
}
