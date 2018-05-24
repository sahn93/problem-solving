class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> *m;
    list<pair<int, int>> *vals;
    int cap;
    // A deque a map
    LRUCache(int capacity) {
        m = new unordered_map<int, list<pair<int, int>>::iterator>;
        vals = new list<pair<int, int>>;
        cap = capacity;
    }
    
    int get(int key) {
        int res;
        if (m->count(key) > 0) {
            auto it = (*m)[key];
            vals->splice(vals->begin(), *vals, it);
            return vals->front().second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m->find(key) != m->end()) {
            auto it = (*m)[key];
            vals->splice(vals->begin(), *vals, it);
            vals->front().second = value;
        } else {
            if (vals->size() == cap) {
                int key = vals->back().first;
                m->erase(key);
                vals->pop_back();
            }
            vals->push_front(make_pair(key, value));
            (*m)[key] = vals->begin();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
