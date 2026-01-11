class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        int leftmax = 0;
        int rightmax = 0;
        int water = 0;
        while(low<high){
            if(height[low]<height[high]){
                if(height[low]>=leftmax){
                    leftmax = height[low];
                }
                else water += (leftmax-height[low]);
                low++;
            }
            else{
                if(height[high]>=rightmax){
                    rightmax = height[high];
                }
                else water += (rightmax-height[high]);
                high--;
            }
        }
        return water;
    }
};