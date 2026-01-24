class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==0) return {{""}};
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mpp;
        for(int i = 0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(i);
        }
        for(auto i:mpp){
            vector<string> arr;
            for(int j = 0; j<i.second.size(); j++){
                arr.push_back(strs[i.second[j]]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};