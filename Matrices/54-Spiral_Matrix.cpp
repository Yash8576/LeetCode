class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i =0;
        int j = 0;
        vector<int> ans;
        int d = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(i<matrix.size() && j<matrix[0].size() && matrix[i][j] != 101){
            ans.push_back(matrix[i][j]);
            matrix[i][j] = 101;
            if(i+dir[d%4][0] >= matrix.size()|| j+dir[d%4][1] >= matrix[0].size() || matrix[i+dir[d%4][0]][j+dir[d%4][1]] == 101){
                d++;
            }
            i+=dir[d%4][0];
            j+=dir[d%4][1]; 
        }
        return ans;
    }
};