class MyHashMap {
private:
    struct ListNode {
        int key;
        int value;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    
    vector<ListNode*> buckets;
    const int numBuckets = 10000; // A suitable number of buckets
    
    // Hash function to map a key to an index in the vector
    int hash(int key) {
        return key % numBuckets;
    }
    
    // Helper function to find a node with the given key in a linked list
    ListNode* find(ListNode* head, int key) {
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

public:
    MyHashMap() {
        buckets.resize(numBuckets, nullptr);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        if (buckets[index] == nullptr) {
            buckets[index] = new ListNode(key, value);
        } else {
            ListNode* prev = nullptr;
            ListNode* curr = buckets[index];
            while (curr != nullptr) {
                if (curr->key == key) {
                    curr->value = value; // Update the existing key's value
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            prev->next = new ListNode(key, value);
        }
    }
    
    int get(int key) {
        int index = hash(key);
        ListNode* node = find(buckets[index], key);
        return (node != nullptr) ? node->value : -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        ListNode* prev = nullptr;
        ListNode* curr = buckets[index];
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    buckets[index] = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    ~MyHashMap() {
        for (int i = 0; i < numBuckets; ++i) {
            ListNode* curr = buckets[i];
            while (curr != nullptr) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }
};