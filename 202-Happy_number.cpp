int get_next(int n) {
    int total_sum = 0;
    while (n > 0) {
        int digit = n % 10;
        total_sum += digit * digit;
        n /= 10;
    }
    return total_sum;
}
bool isHappy(int n) {
    if (n == 1) return true;
    int slow = n;
    int fast = get_next(n);
    while (fast != 1 && slow != fast) {
        slow = get_next(slow);
        fast = get_next(get_next(fast));
    }
    return fast == 1;
}
