class LRUCache {
struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key, int val): key(key), val(val), next(nullptr), prev(nullptr) {}
};

public:
    Node* head = nullptr;
    Node* tail = nullptr;
    map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // accessed! so move to the back please
        if(mp.find(key) == mp.end()) return -1;
        auto el_to_move = mp[key];
        if(el_to_move == tail) {
            return mp[key]->val;
        }
        if(el_to_move == head) {
            head = head->next;
            head->prev = nullptr;
            el_to_move->next = nullptr;
            tail->next = el_to_move;
            el_to_move->prev = tail;
            tail = el_to_move;
            return mp[key]->val;
        }
        
        if(el_to_move->prev != nullptr) el_to_move->prev->next = el_to_move->next;
        if(el_to_move->next != nullptr) el_to_move->next->prev = el_to_move->prev;
        tail->next = el_to_move;
        el_to_move->prev = tail;
        el_to_move->next = nullptr;
        tail = el_to_move;
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            mp[key]->val = value;
            return;
        }
        if(mp.size() == 0) {
            // init!
            head = new Node(key, value);
            tail = head;
            mp[key] = head;
            return;
        }

        // add to the thing
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

        if(mp.size() > cap) {
            // delete!
            // Node* oldhead = head;
            mp.erase(head->key);
            head = head->next;
            head->prev = nullptr;
            // delete oldhead;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
