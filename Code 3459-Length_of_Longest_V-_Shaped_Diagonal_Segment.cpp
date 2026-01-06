int lenOfVDiagonal(vector<vector<int>>& grid){
    static int dp[501][501][4][2];
    memset(dp, 0, sizeof(dp));
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    for(int d = 0; d<4; d++){
        int istart = (dir[d][0]==1)?n-1:0;
        int iend = (dir[d][0] == 1)?-1:n;
        int istep = (dir[d][0] == 1)?-1:1;

        int jstart = (dir[d][1]==1)?m-1:0;
        int jend = (dir[d][1] == 1)?-1:m;
        int jstep = (dir[d][1] == 1)?-1:1;
        for(int i = istart; i!=iend; i+=istep){
            for(int j = jstart; j!=jend; j+=jstep){
                for(int t = 0; t<2; t++){
                    int target = (t==1?2:0);
                    if(grid[i][j]!=target) continue;
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if(ni>=0 && nj>=0 && ni<n &&nj<m) dp[i][j][d][t] = 1+dp[ni][nj][d][1-t];
                    else dp[i][j][d][t] = 1;
                }
            }
        }
    }
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] != 1) continue;
            res = max(res, 1);
            for(int d = 0; d<4;d++){
                int dx = dir[d][0], dy = dir[d][1];
                int ni = i+dx, nj = j+dy;
                if(ni<0||nj<0||ni>=n||nj>=m) continue;
                int maxstraight = dp[ni][nj][d][1];
                res = max(res, 1+maxstraight);
                for(int len = 1; len<=maxstraight; len++){
                    int endi = i+dx*len, endj = j+dy*len;
                    int nd = (d+1)%4;
                    int ti = endi + dir[nd][0], tj = endj + dir[nd][1];
                    if (ti < 0 || tj < 0 || ti >= n || tj >= m) continue;
                    int next_t = (len%2==1?0:1);
                    res = max(res, 1+len+dp[ti][tj][nd][next_t]);
                }
            }
        }
    }
    return res;
}
//At every index find the max len diagonally in all the directions (maxlen) now at some point in one of that maxlen diagonal(len1 until that point)(this is in between 1 to maxlen cause we cannot rotate at first index itself)

//now from this point rotate 90degree Clockwise and see if we there is a digonal in that direction of lenght(lets say len2) noiw the total becomes 1+len1+len2 now try to max this out by comparing all the possible values .
