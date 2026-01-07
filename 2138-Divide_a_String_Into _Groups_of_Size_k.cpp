vector<string> divideString(string s, int k, char fill) {
    int i = 0;
    vector<string> ans;
    while(i<s.size()){
    string j= "";
    int c = k;
        while(c>0){
            if(i<s.size()){
                j+=s[i];
                i++;
                c--;
            }
            if(i==s.size()&&c>0){
                j+=fill;
                c--;
            }
        }
        ans.push_back(j);
    }
    return ans;
}
