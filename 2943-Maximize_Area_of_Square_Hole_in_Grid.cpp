class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int maxH = 1;
        if (!hBars.empty()) {
            int current = 1;
            for (size_t i = 1; i < hBars.size(); ++i) {
                if (hBars[i] == hBars[i-1] + 1) {
                    current++;
                    maxH = max(maxH, current);
                } else {
                    current = 1;
                }
            }
        }
        
        int maxV = 1;
        if (!vBars.empty()) {
            int current = 1;
            for (size_t i = 1; i < vBars.size(); ++i) {
                if (vBars[i] == vBars[i-1] + 1) {
                    current++;
                    maxV = max(maxV, current);
                } else {
                    current = 1;
                }
            }
        }
        
        int k = min(maxH, maxV);
        return (k + 1) * (k + 1);
    }
};