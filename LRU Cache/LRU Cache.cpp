class LRUCache{
private:
    class Node {
    public:
        int key;
        int value;
        Node *next = nullptr;
        Node *prev = nullptr;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
    Node *head;
    Node *tail;
    int capacity;
    unordered_map<int, Node *> map;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it != map.end()) {
            Node *node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail->prev->next = node;
            node->prev = tail->prev;
            node->next = tail;
            tail->prev= node;
            return node->value;
        } else return -1;
    }
    
    void set(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            Node *node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            tail->prev->next = node;
            node->prev = tail->prev;
            node->next = tail;
            tail->prev= node;
            node->value = value;
        } else {
            if (map.size() < capacity) {
                Node *p = new Node(key, value);
                p->prev = tail->prev;
                p->next = tail;
                tail->prev->next = p;
                tail->prev = p;
                map[key] = p;
            } else {
                map.erase(head->next->key);
                head->next = head->next->next;
                head->next->prev = head;
                Node *p = new Node(key, value);
                p->prev = tail->prev;
                p->next = tail;
                tail->prev->next = p;
                tail->prev = p;
                map[key] = p;
            }
        }
    }
};