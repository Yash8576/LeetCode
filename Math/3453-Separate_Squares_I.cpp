class Solution {
public:
    double areaAtY(vector<vector<int>>& squares, double y) {
        double area = 0.0;

        for (int i = 0; i < squares.size(); i++) {
            double bottom = squares[i][1];
            double len = squares[i][2];
            double top = bottom + len;

            if (y <= bottom) {
                continue;
            } 
            else if (y >= top) {
                area += len * len;
            } 
            else {
                area += len * (y - bottom);
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double miny = 1e18;
        double maxy = -1e18;
        double totalArea = 0.0;

        for (int i = 0; i < squares.size(); i++) {
            miny = min(miny, (double)squares[i][1]);
            maxy = max(maxy, (double)squares[i][1] + squares[i][2]);
            totalArea += (double)squares[i][2] * squares[i][2];
        }

        double reqArea = totalArea / 2.0;

        while (maxy - miny > 1e-6) {
            double mid = (miny + maxy) / 2.0;

            if (areaAtY(squares, mid) < reqArea) {
                miny = mid;
            } else {
                maxy = mid;
            }
        }

        return miny;
    }
};
