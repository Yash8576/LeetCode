class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        list<long long> lst(nums.begin(), nums.end());
        
        list<long long>::iterator it = lst.begin();
        int idx = 0;
        while(it != lst.end()){
            list<long long>::iterator next_it = it;
            next_it++;
            if(next_it != lst.end()){
                pq.push({*it + *next_it, idx});
                idx++;
            }
            it++;
        }
        
        int operations = 0;
        
        while(!pq.empty()){
            bool sorted = true;
            list<long long>::iterator prev = lst.begin();
            list<long long>::iterator curr = prev;
            curr++;
            while(curr != lst.end()){
                if(*curr < *prev){
                    sorted = false;
                    break;
                }
                prev = curr;
                curr++;
            }
            if(sorted) break;
            
            while(!pq.empty()){
                pair<long long, int> top = pq.top();
                long long sum = top.first;
                int pair_idx = top.second;
                pq.pop();
                
                list<long long>::iterator it = lst.begin();
                int curr_idx = 0;
                while(it != lst.end() && curr_idx < pair_idx){
                    it++;
                    curr_idx++;
                }
                
                if(it == lst.end()) continue;
                list<long long>::iterator next_it = it;
                next_it++;
                if(next_it == lst.end()) continue;
                
                if(*it + *next_it == sum){
                    long long new_val = *it + *next_it;
                    *it = new_val;
                    lst.erase(next_it);
                    operations++;
                    
                    pq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>();
                    list<long long>::iterator temp_it = lst.begin();
                    int temp_idx = 0;
                    while(temp_it != lst.end()){
                        list<long long>::iterator temp_next = temp_it;
                        temp_next++;
                        if(temp_next != lst.end()){
                            pq.push({*temp_it + *temp_next, temp_idx});
                            temp_idx++;
                        }
                        temp_it++;
                    }
                    break;
                }
            }
        }
        
        return operations;
    }
};