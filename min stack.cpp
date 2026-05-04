#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int min;
} Node;

typedef struct {
    Node* data;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 1000; // Starting capacity
    obj->data = (Node*)malloc(sizeof(Node) * obj->capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    // Resize if full
    if (obj->top == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (Node*)realloc(obj->data, sizeof(Node) * obj->capacity);
    }
    
    obj->top++;
    obj->data[obj->top].value = val;
    
    // If it's the first element, it is the min. 
    // Otherwise, compare val with the previous min.
    if (obj->top == 0) {
        obj->data[obj->top].min = val;
    } else {
        int prevMin = obj->data[obj->top - 1].min;
        obj->data[obj->top].min = (val < prevMin) ? val : prevMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top].value;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}
