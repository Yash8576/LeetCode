bool wordBreak(string s, vector<string>& wordDict) {
    map<string, vector<vector<int>>> mpp;
    vector<string> dict;
    for(int i=0;i<wordDict.size();i++){
        dict.push_back(wordDict[i]);
    }
    while(!dict.isempty()){
        string word = dict.back();
        vector<vector<int>> arr;
        int start = 0;
        for(int i=0;i<s.size();i++){
            bool iswordstarted = false;
            if(!iswordstarted && s[i] == word[0]){
                start = i;
                iswordstarted = true;
            }
            else if(iswordstarted && ){
                
            }
        }
    }
}
