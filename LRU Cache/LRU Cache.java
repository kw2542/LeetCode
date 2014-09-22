public class LRUCache {
    class Node {
        Node prev = null;
        Node next = null;
        int key = 0;
        int value = 0;
        Node (int key, int value) {
            this.key = key;
            this.value = value;
        }
    }
    private int capacity;
    private Node head;
    private Node tail;
    private HashMap<Integer, Node> map;
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
        map = new HashMap<>(capacity);
    }
    
    public int get(int key) {
        Node node = map.get(key);
        if (node != null) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            tail.prev.next = node;
            node.prev = tail.prev;
            node.next = tail;
            tail.prev = node;
            return node.value;
        } else return -1;
    }
    
    public void set(int key, int value) {
        Node node = map.get(key);
        if (node != null) {
            node.value = value;
            node.prev.next = node.next;
            node.next.prev = node.prev;
            tail.prev.next = node;
            node.prev = tail.prev;
            node.next = tail;
            tail.prev = node;
        } else {
            if (map.size() < capacity) {
                Node newNode = new Node(key, value);
                tail.prev.next = newNode;
                newNode.prev = tail.prev;
                newNode.next = tail;
                tail.prev = newNode;
                map.put(key, newNode);
            } else {
                map.remove(head.next.key);
                head.next = head.next.next;
                head.next.prev = head;
                Node newNode = new Node(key, value);
                tail.prev.next = newNode;
                newNode.prev = tail.prev;
                newNode.next = tail;
                tail.prev = newNode;
                map.put(key, newNode);
            }
        }
    }
}