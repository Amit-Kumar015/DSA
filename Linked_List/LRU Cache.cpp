// https://leetcode.com/problems/lru-cache/description/

class Node{
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v): key(k), value(v), prev(nullptr),
         next(nullptr){}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node){
        Node* temp = right->prev;
        temp->next = node;
        node->prev = temp;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if(cache.size() > cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete(lru);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */