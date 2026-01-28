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
    
    vector<string> prefix(const string& word) {
        /**
         * Return a list of all words in the trie that start with the given prefix.
         */
        // === YOUR CODE HERE ===
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return {};
            }
            node = node->children[ch];
        }
        return collectWords(node, word);
    }
    
    vector<string> trie(vector<string>& words, string prefix) {
        // === DO NOT MODIFY ===
        create_trie(words);
        return this->prefix(prefix);
    }
};