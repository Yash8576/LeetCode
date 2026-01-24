class Solution {
public:
    int maxarray(vector<int>& arr){
        stack<int> st;
        int maxArea = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int height = arr[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int height = arr[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int area = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    heights[j] = (i > 0) ? heights[j] + 1 : 1;
                } else {
                    heights[j] = 0;
                }
            }
            area = max(area, maxarray(heights));
        }
        return area;
    }
};