#include <stdlib.h>

// Node for the Doubly Linked List
typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

// Entry for the Hash Table (Handles collisions with chaining)
typedef struct HashEntry {
    int key;
    Node* node;
    struct HashEntry* next;
} HashEntry;

typedef struct {
    int capacity;
    int size;
    int hashSize;
    Node *head, *tail; // Dummy nodes for the list
    HashEntry** table; // Array of HashEntry pointers
} LRUCache;

// --- Helper Functions ---

Node* createNode(int key, int value) {
    Node* node = malloc(sizeof(Node));
    node->key = key; node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void addToHead(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

// Hash Function
int getHash(int key, int hashSize) {
    return abs(key) % hashSize;
}

// Find entry in Hash Table
HashEntry* findEntry(LRUCache* obj, int key) {
    int h = getHash(key, obj->hashSize);
    HashEntry* entry = obj->table[h];
    while (entry) {
        if (entry->key == key) return entry;
        entry = entry->next;
    }
    return NULL;
}

// --- Main Cache Functions ---

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->hashSize = capacity * 2; // Keep load factor low
    obj->table = calloc(obj->hashSize, sizeof(HashEntry*));
    
    obj->head = createNode(-1, -1);
    obj->tail = createNode(-1, -1);
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    HashEntry* entry = findEntry(obj, key);
    if (!entry) return -1;
    
    // Move to head (Most Recently Used)
    removeNode(entry->node);
    addToHead(obj, entry->node);
    return entry->node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    HashEntry* entry = findEntry(obj, key);
    
    if (entry) {
        // Update existing key
        entry->node->value = value;
        removeNode(entry->node);
        addToHead(obj, entry->node);
    } else {
        // Add new key
        if (obj->size == obj->capacity) {
            // Evict LRU (node before dummy tail)
            Node* lru = obj->tail->prev;
            int h = getHash(lru->key, obj->hashSize);
            HashEntry **curr = &obj->table[h];
            while (*curr && (*curr)->key != lru->key) curr = &((*curr)->next);
            HashEntry* toFree = *curr;
            *curr = (*curr)->next; // Remove from hash chain
            free(toFree);
            removeNode(lru);
            free(lru);
            obj->size--;
        }
        
        Node* newNode = createNode(key, value);
        addToHead(obj, newNode);
        
        // Insert into Hash Table
        int h = getHash(key, obj->hashSize);
        HashEntry* newEntry = malloc(sizeof(HashEntry));
        newEntry->key = key;
        newEntry->node = newNode;
        newEntry->next = obj->table[h];
        obj->table[h] = newEntry;
        obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    for (int i = 0; i < obj->hashSize; i++) {
        HashEntry* entry = obj->table[i];
        while (entry) {
            HashEntry* tmp = entry;
            entry = entry->next;
            free(tmp);
        }
    }
    Node* curr = obj->head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(obj->table);
    free(obj);
}
