int firstBadVersion(int n) {
    bool finder = true;
    long low = 1;
    long high = n;
    while(low<=high){
        long mid = (low+high)/2;
        if(isBadVersion(mid)){
            if(isBadVersion(mid-1)){
                high = mid-1;
            }
            else return mid;
        }
        else{
            if(!isBadVersion(mid+1)){
                low = mid+1;
            }
            else return mid+1;
        }
    }
    return high;
}
