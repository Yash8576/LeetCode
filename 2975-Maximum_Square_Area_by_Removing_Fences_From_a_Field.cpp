class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1000000007;
        vector<long long> hlines = {1};
        for (int i = 0; i < hFences.size(); i++) {
            hlines.push_back(hFences[i]);
        }
        hlines.push_back(m);
        sort(hlines.begin(), hlines.end());
        vector<long long> rowh;
        for (int i = 1; i < hlines.size(); i++) {
            rowh.push_back(hlines[i] - hlines[i - 1]);
        }
        vector<long long> vlines = {1};
        for (int i = 0; i < vFences.size(); i++) {
            vlines.push_back(vFences[i]);
        }
        vlines.push_back(n);
        sort(vlines.begin(), vlines.end());
        vector<long long> colw;
        for (int i = 1; i < vlines.size(); i++) {
            colw.push_back(vlines[i] - vlines[i - 1]);
        }
        unordered_set<long long> rowsums;
        for (int i = 0; i < rowh.size(); i++) {
            long long sum = 0;
            for (int j = i; j < rowh.size(); j++) {
                sum += rowh[j];
                rowsums.insert(sum);
            }
        }
        unordered_set<long long> colsums;
        for (int i = 0; i < colw.size(); i++) {
            long long sum = 0;
            for (int j = i; j < colw.size(); j++) {
                sum += colw[j];
                colsums.insert(sum);
            }
        }
        long long maxs = -1;
        for (auto s : colsums) {
            if (rowsums.count(s)) {
                maxs = max(maxs, s);
            }
        }
        if (maxs == -1) return -1;
        long long area = maxs * maxs % MOD;
        return (int)area;
    }
};