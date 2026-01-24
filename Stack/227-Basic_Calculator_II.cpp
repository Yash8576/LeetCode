int calculate(string s){
    stack<int> nums;
    char op = '+';
    int current_num = 0;
    for(int i = 0; i<s.size(); i++){
        char c = s[i];
        if(isdigit(c)){
            current_num = current_num*10 + (c-'0');
        }    
        if(!isdigit(c) && c != ' ' || i == s.size()-1){
            if(op == '+'){
                nums.push(current_num);
            }
            if(op == '-'){
                nums.push(-current_num);
            }
            if(op == '*'){
                int prev = nums.top();
                nums.pop();
                nums.push(prev*current_num);
            }
            if(op == '/'){
                int prev = nums.top();
                nums.pop();
                nums.push(prev/current_num);
            }
            op = c;
            current_num = 0;
        }
    }
    int result = 0;
    while(!nums.empty()){
        result+=nums.top();
        nums.pop();
    }
    return result;
}
