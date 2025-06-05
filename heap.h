#ifndef HEAP_H
#define HEAP_H

#define INITIAL_CAPACITY 1

class HeapNode {
private:
    int priority;
    int ID;
public:
    HeapNode() {};
    HeapNode(int id, int PRI);

    void setPRI(int p) { priority = p; }
    int getPRI() const { return priority; }

    void setID(int id) { ID = id; }
    int getID() const { return ID; }
};

class Heap {
private:
    HeapNode* array;
    size_t capacity;
    size_t size;

    void heapify(int i);
    void deleteNode(int i);
    void resize();
    void swapNodes(int i, int j);

public:
    Heap();
    ~Heap();

    void insert(int id, int PRI);
    HeapNode extractMax();
    void printHeap() const;
    void updateNode(int id, int newPRI);
};

#endif // !HEAP_H