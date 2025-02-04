struct Node{
    unordered_map<char,Node*>links;
    bool isEnd=false;
    bool contains(char ch)
    {
        return links.find(ch)!=links.end();
    }
    void put(char ch , Node* node)
    {
        links[ch]=node;
    }
    Node* get(char ch)
    {
        return links[ch];
    }

};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word)
    {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++)
        {
            if(!node->contains(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->isEnd=true;
    }
    bool findHelper(string word,int index,Node* node)
    {
        if(index==word.size())
        {
            return node->isEnd;
        }
        if(word[index]=='.')
        {
            for(auto &child: node->links)
            {
                if(findHelper(word,index+1,child.second))return true;
            }
            return false;
        }
        else
        {
            if(!node->contains(word[index])) return false;
            return findHelper(word,index+1,node->get(word[index]));
        }
    }
    bool find(string word,int index)
    {
        Node* node=root;
        return findHelper(word,index,node);
    }
};
class WordDictionary {
public:
    Trie trie;
    Node* node;
    WordDictionary() {
        node=new Node();
    }
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        
        return trie.find(word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
