class TrieNode {
private:
    TrieNode* links[26];
    bool isEnd;
public:
    TrieNode() {
        for(int i = 0 ; i < 26 ; i++) links[i] = nullptr;
        isEnd = false;
    }

    bool contains(char ch) {
        return links[ch-'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch-'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch-'a'] = node;
    }

    void setEnd(bool e=true) {
        isEnd = e;
    }

    bool isEndOfWord() {
        return isEnd;
    }
    
};

class Trie {
private:
    TrieNode* root;
    TrieNode* searchPfx(string pfx) {
        TrieNode* node = root;
        for(auto ch: pfx) {
            if(!node->contains(ch)) {
                return nullptr;
            }
            node = node->get(ch);
        }
        return node;
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(auto ch: word) {
            if(!node->contains(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = searchPfx(word);
        return node != nullptr && node->isEndOfWord();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = searchPfx(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
