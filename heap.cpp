#include "heap.h"
#include <iostream>
Heap::Heap(int capacity, int ary) {
    this->capacity = capacity;
    this->data = new int[capacity];
    this->size = 0;
    this->ary = ary;
}
//algorytm porządkowania kopca
void Heap::heapify_to_bottom(int i){
    int smallest=i;
    int left = ary * (i + 1) - ary + 2 - 1;
    int right = left + ary - 1;
    for (int j = left; j <= right; ++j) {
        if (j < size && data[j] < data[smallest]) {
            smallest=j;
        } 
    }
    if(smallest!=i){
        std::swap(data[i],data[smallest]);
        heapify_to_bottom(smallest);
    }
}
void Heap::heapify_to_top(int i) {
    int parent = (i + 1 + ary - 2) / ary - 1;
    if (parent < 0)
        return;
    int smallest=parent;
    int left = ary * (parent + 1) - ary + 2 - 1;
    int right = left + ary - 1;
    for (int j = left; j <= right; ++j) {
        if (j < size && data[j] < data[smallest]) {
            smallest=j;
        }
    }
    if (smallest != parent) {
        std::swap(data[parent],data[smallest]);
        heapify_to_top(parent);
    }
}
//tworzenie kopca
Heap *Heap::create_heap(int* data, int size, int capacity, int ary){
    Heap *heap = new Heap(capacity, ary);
    heap->data = data;
    heap->size = size;
    int in=(size/ary)-1;
    for(int i=in;i>=0;i--){
        heap->heapify_to_bottom(i);
    }
    return heap;
}
//wyświetlanie w formie kopca
void Heap::display_heap(){
    std::cout<<"Kopiec"<<std::endl;
    int count=0;
    int power = 1;
    while (count < size) {
        int c=0, spaces = 1; //todo
        for(int j=count;c<power;j++){
            if(j<size){
                for (int k = 0; k < spaces; ++k) {
                    std::cout<<" ";
                }
                std::cout<<data[j];
                c++;
                count++;
            }
            else break;
        }
        std::cout<<std::endl;
        power *= ary;
    }
}
//wyświetlanie w formie tablicy
void Heap::display_array(){
std::cout<<"Tablica"<<std::endl;
    for (int i=0; i<size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}
//wstawianie elementu do kopca
void Heap::insert_element(int element){
    size=size+1;
    data[size-1]=element;
    heapify_to_top(size - 1);
}
//usuwanie szczytowego elementu kopca
void Heap::delete_heap_peak(){
    int element=data[size-1];
    data[0]=element;
    size=size-1;
    heapify_to_bottom(0);
}
