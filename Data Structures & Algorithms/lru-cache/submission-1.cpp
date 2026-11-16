// por linked list
class LRUCache {
public:
    struct Node {
        Node  *prev, *next;
        int key, value;
    };
    int capacity;
    unordered_map<int, Node*> cache;
    Node * head = new Node(nullptr, nullptr, 0, 0);
    Node * tail = new Node(nullptr, nullptr, 0, 0);
    void add(Node * cur) {
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
    }   
    void rem(Node * cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        // free(cur);
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        tail->prev = head;
        head->next = tail;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        Node * cur = cache[key];
        int value = cur->value;
        rem(cur);
        Node * newer = new Node(nullptr, nullptr, key, value);
        add(newer);
        cache[key] = newer;
        return value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node * cur = cache[key];
            rem(cur);
        }
        Node * newer = new Node(nullptr,nullptr,key,value);
        add(newer);
        cache[key] = newer;
        if (cache.size() > capacity) {
            Node * lru = tail->prev;
            cache.erase(lru->key);
            rem(lru);
        }
    }
};
