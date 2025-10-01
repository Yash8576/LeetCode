int hIndex(vector<int>& citations) {
        int index =1;
        int ans = 0;
        for(int i=0;i<citations.size();i++){
            int count = 0;
            int oldindex = index;
            for(int j=0;j<citations.size();j++){
                if(citations[j]>=index) count++;
                if(count>=index){
                    ans = index;
                    index++;
                    break;
                }
            }
            if(oldindex==index) break;
        }
        return ans;
    }
