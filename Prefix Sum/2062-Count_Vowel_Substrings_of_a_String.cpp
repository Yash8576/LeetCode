class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = word.size();
        int count = 0;
        int i = 0;
        while (i < n) {
            if (vowels.find(word[i]) == vowels.end()) {
                i++;
                continue;
            }
            int j = i;
            while (j < n && vowels.find(word[j]) != vowels.end()) j++;
            for (int left = i; left < j; left++) {
                unordered_set<char> seen;  
                for (int right = left; right < j; right++) {
                    seen.insert(word[right]);  
                    if (seen.size() == 5) {
                        count += (j - right);   
                        break;
                    }
                }
            }
            i = j;
        }
        return count;
    }
};