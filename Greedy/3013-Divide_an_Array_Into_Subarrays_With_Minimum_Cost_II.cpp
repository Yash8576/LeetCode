class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int m = k - 2; 
        long long ans = -1;
        multiset<int> low, high;
        long long current_low_sum = 0;

        auto balance = [&]() {
            while (low.size() < m && !high.empty()) {
                int val = *high.begin();
                current_low_sum += val;
                low.insert(val);
                high.erase(high.begin());
            }
            while (low.size() > m && !low.empty()) {
                int val = *low.rbegin();
                current_low_sum -= val;
                high.insert(val);
                low.erase(prev(low.end()));
            }
        };

        auto add = [&](int val) {
            if (!low.empty() && val < *low.rbegin()) {
                current_low_sum += val;
                low.insert(val);
            } else {
                high.insert(val);
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);
            if (it != low.end()) {
                current_low_sum -= val;
                low.erase(it);
            } else {
                high.erase(high.find(val));
            }
            balance();
        };
        for (int j = 2; j <= 1 + dist && j < n; j++) {
            add(nums[j]);
        }

        ans = (long long)nums[0] + nums[1] + current_low_sum;

        for (int i = 2; i <= n - (k - 1); i++) {
            remove(nums[i]);
            if (i + dist < n) {
                add(nums[i + dist]);
            }
            
            long long current_total = (long long)nums[0] + nums[i] + current_low_sum;
            if (ans == -1 || current_total < ans) {
                ans = current_total;
            }
        }

        return ans;
    }
};