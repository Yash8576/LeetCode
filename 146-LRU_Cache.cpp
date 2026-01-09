class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){}
    };

    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int capacity;
    int size;

    void addToHead(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveNodeToHead(Node* node){
        removeNode(node);
        addToHead(node);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveNodeToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            moveNodeToHead(node);
            return;
        }
        else if(size < capacity){
            Node* node = new Node(key, value);
            cache[key] = node;
            size++;
            addToHead(node);
        }
        else {
            Node* lru = tail->prev;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
        }
    }
};