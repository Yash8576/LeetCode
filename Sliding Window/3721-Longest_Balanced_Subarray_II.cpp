// class Solution {
// public:
//     int longestBalanced(vector<int>& nums) {
//         int n = nums.size();
//         int maxLen = 0;
        
//         // Try all possible subarrays
//         for (int i = 0; i < n; i++) {
//             unordered_set<int> evenSet;
//             unordered_set<int> oddSet;
            
//             for (int j = i; j < n; j++) {
//                 // Add current element to appropriate set
//                 if (nums[j] % 2 == 0) {
//                     evenSet.insert(nums[j]);
//                 } else {
//                     oddSet.insert(nums[j]);
//                 }
                
//                 // Check if balanced
//                 if (evenSet.size() == oddSet.size()) {
//                     maxLen = max(maxLen, j - i + 1);
//                 }
//             }
//         }
        
//         return maxLen;
//     }
// };
class Solution {
    vector<int> tree_min, tree_max, tree_lazy;
    int n;

    void push(int node) {
        if (tree_lazy[node] != 0) {
            tree_lazy[2 * node] += tree_lazy[node];
            tree_min[2 * node] += tree_lazy[node];
            tree_max[2 * node] += tree_lazy[node];
            
            tree_lazy[2 * node + 1] += tree_lazy[node];
            tree_min[2 * node + 1] += tree_lazy[node];
            tree_max[2 * node + 1] += tree_lazy[node];
            
            tree_lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            tree_lazy[node] += val;
            tree_min[node] += val;
            tree_max[node] += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree_min[node] = min(tree_min[2 * node], tree_min[2 * node + 1]);
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start || tree_min[node] > 0 || tree_max[node] < 0) return -1;
        if (start == end) return start;
        push(node);
        int mid = (start + end) / 2;
        int res = query(2 * node + 1, mid + 1, end, l, r);
        if (res != -1) return res;
        return query(2 * node, start, mid, l, r);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        tree_min.assign(4 * n, 0);
        tree_max.assign(4 * n, 0);
        tree_lazy.assign(4 * n, 0);

        vector<int> next_occ(n);
        vector<int> last(100001, n);
        
        for (int i = n - 1; i >= 0; --i) {
            next_occ[i] = last[nums[i]];
            last[nums[i]] = i;
        }

        for (int i = 0; i < 100001; ++i) {
            if (last[i] != n) {
                int val = (i % 2 != 0) ? 1 : -1;
                update(1, 0, n - 1, last[i], n - 1, val);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int r = query(1, 0, n - 1, i, n - 1);
            if (r != -1) {
                ans = max(ans, r - i + 1);
            }
            if (i < n - 1) {
                int val = nums[i];
                int sign = (val % 2 != 0) ? 1 : -1;
                update(1, 0, n - 1, i, next_occ[i] - 1, -sign);
            }
        }
        return ans;
    }
};