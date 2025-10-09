void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> sr;
    unordered_set<int> sc;
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                sr.insert(i);
                sc.insert(j);
            }
        }
    }
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            if(sr.count(i) || sc.count(j)) matrix[i][j] = 0;
        }
    }
}
