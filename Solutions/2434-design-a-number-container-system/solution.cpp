class NumberContainers {
public:
    unordered_map<int, set<int>> mp1;
    unordered_map<int, int> mp2;
    NumberContainers() {}
    void change(int index, int number) {
        if(mp2.find(index) != mp2.end()) {
            if(mp2[index] == number) return;
            // delete the number
            int num = mp2[index];
            mp1[num].erase(index);
            if(mp1[num].empty()) mp1.erase(num);
        }
        mp2[index] = number;
        mp1[number].insert(index);
    }
    
    int find(int number) {
        if(mp1.find(number) != mp1.end()) return *mp1[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
