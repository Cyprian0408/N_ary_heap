#ifndef AISDI_LAB3_2_ARY_HEAP_H
#define AISDI_LAB3_2_ARY_HEAP_H

class Heap {
public:
    Heap(int capacity, int ary);
    static Heap *create_heap(int* data, int size, int capacity, int ary);
    virtual void display_heap();
    virtual void display_array();
    virtual void insert_element(int element);
    virtual void delete_heap_peak();
private:
    int capacity;
    int* data;
    int size;
    int ary;
    virtual void heapify_to_bottom(int i);
    virtual void heapify_to_top(int i);
};
#endif //AISDI_LAB3_2_ARY_HEAP_H