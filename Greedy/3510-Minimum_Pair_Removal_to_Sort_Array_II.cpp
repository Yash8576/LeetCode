typedef long long ll;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums_) {
        int n = nums_.size();
        if (n < 2) return 0;

        vector<ll> nums(n);
        for (int i = 0; i < n; i++) nums[i] = nums_[i];

        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            l[i] = i - 1;
            r[i] = i + 1;
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

        ll inv = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) inv++;
            pq.push({nums[i] + nums[i + 1], i});
        }

        vector<bool> active(n, true);

        int ans = 0;

        while (inv > 0) {
            while (true) {
                if (pq.empty()) break; 

                pair<ll, int> top = pq.top();
                pq.pop();
                
                ll s = top.first;
                int i = top.second;
                
                if (active[i] && r[i] < n && (nums[i] + nums[r[i]] == s)) {
                    int j = r[i];
                    int k = r[j];
                    int h = l[i];

                    if (h >= 0 && nums[h] > nums[i]) inv--;
                    if (nums[i] > nums[j]) inv--;
                    if (k < n && nums[j] > nums[k]) inv--;

                    nums[i] = nums[i] + nums[j];
                    
                    r[i] = k;
                    if (k < n) l[k] = i;
                    active[j] = false;

                    if (h >= 0 && nums[h] > nums[i]) inv++;
                    if (k < n && nums[i] > nums[k]) inv++;

                    if (h >= 0) {
                        pq.push({nums[h] + nums[i], h});
                    }
                    if (k < n) {
                        pq.push({nums[i] + nums[k], i});
                    }

                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};