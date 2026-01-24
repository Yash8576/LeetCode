class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int left = 0;
        int right = min(m, n);
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool canFind = false;
            for (int i = 0; i <= m - mid; ++i) {
                for (int j = 0; j <= n - mid; ++j) {
                    int sum = prefix[i + mid][j + mid] - prefix[i + mid][j] - prefix[i][j + mid] + prefix[i][j];
                    if (sum <= threshold) {
                        canFind = true;
                        break;
                    }
                }
                if (canFind) break;
            }
            if (canFind) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};