string compressedString(string word) {
    string ans;
    int count = 1;
    for(int i=0; i<word.size()-1; i++){
        if(word[i] == word[i+1] && count<9){
            count++;
        }
        else{
            ans+=to_string(count);
            ans+=word[i];    
            count = 1;
        }
    }
    ans+=to_string(count);
    ans+=word[word.size()-1];
    return ans;
}
