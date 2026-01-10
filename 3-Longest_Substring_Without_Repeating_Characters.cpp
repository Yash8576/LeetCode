class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int size = 0;
        while(j<s.size()){
            if(mpp.find(s[j]) == mpp.end()){
                mpp[s[j]]++;
                size = max(size, (int)mpp.size());
                j++;
            }
            else{
                if(i<s.size()){
                    mpp.erase(s[i]);
                    i++;    
                }
                else break;
            }
        }
        return size;
    }
};