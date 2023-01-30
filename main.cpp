#include <iostream>
#include "heap.h"
#include <time.h>
#include<chrono>
#include<thread>
#include<cstdlib>
#include"pbPlots.hpp"
#include"supportLib.hpp"
#define MAX 99999
using namespace std::chrono_literals;
int main(){
    bool success;
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageRef=CreateRGBABitmapImageReference();

    int array[MAX]={0,17,21,34,15,2,4,7,1,24};
    int size=10;
    int element=0;
    //Heap *heap_2 = Heap::create_heap(array, size, MAX, 4);
    //heap_2->display_heap();
    //heap_2->display_array();
    //heap_2->insert_element(element);
    //heap_2->display_heap();
    //heap_2->display_array();
    //heap_2->delete_heap_peak();
    //heap_2->display_heap();
    //tworzenie tablicy 100000 losowych liczb z zakresu od 1 do 300000
    int rand_array[100000];
    srand((unsigned) time(NULL));
    for(int i=0;i<100000;i++){
        rand_array[i] = rand()%299999+1;
    }
    int n[]={10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};
    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    double time_taken_by_creation[10], time_taken_by_deletion[10];
    //badanie czasu tworzenia kopca
    for(int j=0;j<10;j++){
        std::ios_base::sync_with_stdio(false);
        start = std::chrono::high_resolution_clock::now();
        Heap *heap_2=Heap::create_heap(rand_array,n[j],MAX,4);
        end = std::chrono::high_resolution_clock::now();
        time_taken_by_creation[j]={double(((std::chrono::duration<double>)(end-start)).count())};
    }
    //badanie czasu usuwania szczytu kopc
    for(int j=0;j<10;j++){
        //tworzenie kopca na podstawie całej tablicy wejściowej
        Heap *heap_2=Heap::create_heap(rand_array,100000,MAX,4);
        std::ios_base::sync_with_stdio(false);
        start = std::chrono::high_resolution_clock::now();
        for(int i=0;i<n[j];i++){        
            heap_2->delete_heap_peak();
        }
        end = std::chrono::high_resolution_clock::now();
        time_taken_by_deletion[j]={double(((std::chrono::duration<double>)(end-start)).count())};
    }
    //tworzenie wektorów umożliwiających stworzenie wykresów 
    std::vector<double> time_c, time_d, num;
    for(int i=0;i<10;i++){
        time_c.push_back(time_taken_by_creation[i]);
    }
    for(int i=0;i<10;i++){
        time_d.push_back(time_taken_by_deletion[i]);
    }
     for(int i=0;i<10;i++){
        num.push_back(n[i]);
    }
    //tworzenie wykresu dla tworzenia kopca
    success=DrawScatterPlot(imageRef, 600, 400, &num, &time_c,errorMessage);
    if(success){
		std::vector<double> *pngdata = ConvertToPNG(imageRef->image);
		WriteToFile(pngdata, "4_ary_heap_creation.png");
		DeleteImage(imageRef->image);
	}else{
		std::cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			std::wcerr << c;
		}
		std::cerr << std::endl;
	}
    //tworzenie wykresu dla usuwania szczytu kopca
    success=DrawScatterPlot(imageRef, 600, 400, &num, &time_d,errorMessage);
    if(success){
		std::vector<double> *pngdata = ConvertToPNG(imageRef->image);
		WriteToFile(pngdata, "4_ary_heap_peak_deletion.png");
		DeleteImage(imageRef->image);
	}else{
		std::cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			std::wcerr << c;
		}
		std::cerr << std::endl;
	}
	success=DrawScatterPlot(imageRef, 600, 400, &num, &time_d,errorMessage);






}