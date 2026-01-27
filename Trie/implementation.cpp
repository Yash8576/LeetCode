class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class Solution {
private:
    TrieNode* root;
    
public:
    void create_trie(vector<string>& words) {
        // === DO NOT MODIFY ===
        root = new TrieNode();
        for (const string& word : words) {
            insert(word);
        }
    }
    
    void insert(const string& word) {
        // === DO NOT MODIFY ===
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    
    bool search(const string& word) {
        TrieNode* node = root;
        for(char ch : word){
            if(node->children.find(ch) == node->children.end()){
                return false;
            }
            else node = node->children[ch];
        }
        return node->isEndOfWord;
    }
    
    void deleteWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return;
            }
            node = node->children[ch];
        }
        node->isEndOfWord = false;
        return;
    }
    
    vector<bool> trie(vector<string>& initialWords, vector<vector<string>>& commands) {
        // === DO NOT MODIFY ===
        create_trie(initialWords);
        
        vector<bool> output;
        for (const auto& command : commands) {
            if (command[0] == "search") {
                output.push_back(search(command[1]));
            } else if (command[0] == "delete") {
                deleteWord(command[1]);
            }
        }
        return output;
    }
};