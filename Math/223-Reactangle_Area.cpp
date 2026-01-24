int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int length1 = ax2-ax1;
    int height1 = ay2-ay1;
    int area1 = length1*height1;
    int length2 = bx2-bx1;
    int height2 = by2-by1;
    int area2 = length2*height2;
    int total_area = area1 + area2;
    int commonheight = 0;
    int commonlenght = 0;
    vector<int> heights = {ay1, ay2, by1, by2};
    sort(heights.begin(), heights.end());
    vector<int> lengths = {ax1, ax2, bx1, bx2};
    sort(lengths.begin(), lengths.end());
    if(heights[1] != ay2 && heights[1] != by2){
        commonheight = heights[2]-heights[1];
    }
    if(lengths[1] != ax2 && lengths[1] != bx2){
        commonlenght = lengths[2]-lengths[1];
    }
    int commonarea = commonheight*commonlenght;
    return total_area-commonarea;
}
