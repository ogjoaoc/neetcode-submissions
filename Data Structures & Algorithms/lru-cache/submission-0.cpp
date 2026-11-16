class LRUCache {
public:
    int capacity;
    list<pair<int, int>> List;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        auto it = cache[key];
        int value = it->second;
        List.erase(it);
        List.push_front({key, value});
        cache[key] = begin(List);
        return value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            auto it = cache[key];
            List.erase(it);
        }
        List.push_front({key, value});
        cache[key] = begin(List);
        if (cache.size() > capacity) {
            int lru = List.back().first;
            List.pop_back();
            cache.erase(lru);
        }
    }
};
