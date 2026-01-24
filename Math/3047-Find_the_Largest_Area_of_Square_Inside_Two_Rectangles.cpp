class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int max_side = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // compute intersection
                int blx = max(bottomLeft[i][0], bottomLeft[j][0]);
                int bly = max(bottomLeft[i][1], bottomLeft[j][1]);
                int trx = min(topRight[i][0], topRight[j][0]);
                int tr_y = min(topRight[i][1], topRight[j][1]);
                if(blx < trx && bly < tr_y){
                    int width = trx - blx;
                    int height = tr_y - bly;
                    int side = min(width, height);
                    if(side > max_side){
                        max_side = side;
                    }
                }
            }
        }
        return (long long)max_side * max_side;
    }
};