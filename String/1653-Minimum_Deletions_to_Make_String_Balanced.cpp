class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> prefixB(n + 1, 0);
        vector<int> suffixA(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            prefixB[i] = prefixB[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            suffixA[i] = suffixA[i + 1] + (s[i] == 'a' ? 1 : 0);
        }
        
        int minDeletions = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            int deletions = prefixB[i] + suffixA[i];
            if (deletions < minDeletions) {
                minDeletions = deletions;
            }
        }
        
        return minDeletions;
    }
};