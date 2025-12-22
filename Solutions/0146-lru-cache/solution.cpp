struct Node {
    Node* next;
    Node* prev;
    int val; 
    int key;
};

class LRUCache {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> mp;
    int cap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* curr = mp[key];
        if(curr == tail) return curr->val;
        // what if curr is head?!
        if(curr->prev != nullptr) curr->prev->next = curr->next;
        if(curr->next != nullptr) curr->next->prev = curr->prev;
        if(curr == head) head = head ->next;
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
        return curr->val;
    }
    
    void put(int key, int value) {
        // do we have to move when update?!
        if(get(key) != -1) {
            mp[key]->val = value;
            return;
        }
        Node* curr = new Node();
        mp[key] = curr;
        curr->val = value;
        curr->key = key;
        if(head == nullptr) {
            head = curr;
            tail = curr;
            return;
        }
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
        if(mp.size() > cap) {
            // evict!
            mp.erase(head->key);
            head = head->next;
            head->prev = nullptr;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
