int mySqrt(int x) {
    long long a = x;
    if(x == 1) return 1;
    long long low = 1;
    long long high = x;
    int b = 0;
    int c = 0;
    while(low<=high){
        long long mid = (low+high)/2;
        long long y = mid * mid;
        if(y == x) return mid;
        else if(y < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}
