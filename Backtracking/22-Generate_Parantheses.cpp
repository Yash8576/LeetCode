void backtrack(vector<string>& s, string current_string, int open_count, int close_count, int max_pairs){
    if(current_string.size() == max_pairs*2){
        s.push_back(current_string);
        return;
    }
    if(open_count<max_pairs){
        backtrack(s, current_string+"(", open_count+1, close_count, max_pairs);
    }
    if(close_count<open_count){
        backtrack(s, current_string+")", open_count, close_count+1, max_pairs);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(ans, "", 0, 0, n);
    return ans;
}

