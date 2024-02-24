class Trie {
public:
    struct Node {
      char nc;
      bool end;
      vector<Node*> list;
      Node(char c) {
        nc = c;
        end = false;
      }
    };

    Node *root;

    Trie() {
      root = new Node('.');
    }
    
    void insert(string word) {
      Node* current = root;
      for(int i = 0 ; i < word.size() ; i++) {
        char current_c = word[i];
        Node* found_node = nullptr;
        for(auto el: current->list) {
          if(el->nc == current_c) {
            found_node = el;
            break;
          }
        }
        if(found_node != nullptr) {
          current = found_node;
        } else {
          Node* newNode = new Node(current_c);
          current->list.push_back(newNode);
          current = newNode;
        }
      }
      current->end = true;
    }
    
    bool search(string word) {
        Node* current = root;
        for(int i = 0 ; i < word.size() ; i++) {
          char current_c = word[i];
          Node* found_node = nullptr;
          for(auto el: current->list) {
            if(el->nc == current_c) {
              found_node = el;
              break;
            }
          }
          if(found_node == nullptr) return false;
          else current = found_node;
        }
        return current->end;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        for(int i = 0 ; i < prefix.size() ; i++) {
          char current_c = prefix[i];
          Node* found_node = nullptr;
          for(auto el: current->list) {
            if(el->nc == current_c) {
              found_node = el;
              break;
            }
          }
          if(found_node == nullptr) return false;
          else current = found_node;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
