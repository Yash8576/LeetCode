class Allocator {
public:
    vector<int> mem;
    Allocator(int n) {
        mem.assign(n, 0);
    }
    
    int allocate(int size, int mID) {
        int n = mem.size();
        if (size > n) return -1;
        for (int i = 0; i <= n - size; ) {
            int j = 0;
            while (j < size && mem[i + j] == 0) {
                j++;
            }
            if (j == size) {
                for (int k = 0; k < size; k++) {
                    mem[i + k] = mID;
                }
                return i;
            }
            i += j + 1;
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int count = 0;
        for (int &unit : mem) {
            if (unit == mID) {
                unit = 0;
                count++;
            }
        }
        return count;
    }
};