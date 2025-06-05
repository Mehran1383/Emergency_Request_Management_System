#include <iostream>
#include <stdexcept>

#include "heap.h"

HeapNode::HeapNode(int id, int PRI) 
{
    this->ID = id;
    this->priority = PRI;
}

Heap::Heap()
{
    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
    this->array = new HeapNode[capacity];
}

Heap::~Heap()
{
    if(array != nullptr)
        delete[] array;
}

void Heap::heapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left].getPRI() > array[largest].getPRI())
        largest = left;

    if (right < size && array[right].getPRI() > array[largest].getPRI())
        largest = right;

    if (largest != i) {
        swapNodes(i, largest);
        heapify(largest);
    }
}

void Heap::swapNodes(int i, int j)
{
    HeapNode temp = array[i];

    array[i].setPRI(array[j].getPRI());
    array[i].setID(array[j].getID());

    array[j].setPRI(temp.getPRI());
    array[j].setID(temp.getID());
}

void Heap::insert(int id, int PRI)
{
    HeapNode node(id, PRI);

    if (size >= capacity)
        resize();

    array[size] = node;
    int i = size;
    size++;

    while (i != 0 && array[(i - 1) / 2].getPRI() < array[i].getPRI()) {
        swapNodes(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void Heap::resize()
{
    HeapNode* newArray = new HeapNode[2 * capacity];

    for (int i = 0; i < size; i++)
        newArray[i] = array[i];

    delete[] array;
    array = newArray;
    capacity *= 2;
}

HeapNode Heap::extractMax()
{
    if(size <= 0)
        throw std::underflow_error("Heap underflow");

    HeapNode root = array[0];

    if (size == 1) {
        array[0].setID(0);
        array[0].setPRI(0);
        return root;
    }
    
    size--;
    array[0] = array[size];
    array[size].setID(0);
    array[size].setPRI(0);
    heapify(0);

    return root;
}

void Heap::updateNode(int id, int newPRI)
{
    bool found = false;
    int i = 0;
    for (; i < size; i++) {
        if (array[i].getID() == id) {
            deleteNode(i);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Not such a request with the ID " << id << " found" << std::endl;
        return;
    }
    insert(id, newPRI);
}

void Heap::deleteNode(int i)
{
    if (i >= size) {
        throw std::out_of_range("Invalid index");
    }

    size--;
    array[i] = array[size];
    array[size].setID(0);
    array[size].setPRI(0);
    heapify(i);
}

void Heap::printHeap() const
{
    std::cout << std::endl << "ID" << "    " << "PRI" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i].getID() << "      " << array[i].getPRI() << std::endl;
    }
}

