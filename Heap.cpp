#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> 
using namespace std;

enum HeapTypes {
    Min_Heap,
    Max_Heap
};

class Heap {
    public:
        int size = 0;
        HeapTypes type;
        vector<int> heap;

    Heap(HeapTypes type) {
        this->type = type;
        cout << "HEAP !!";
    }

    void insert(int value) {
        heap.push_back(value);
        size++;
        heapify();
    }

    void printHeap(){
        vector<int> temp = heap;
        cout << "Your Heap:" << endl;
        for(auto i: temp){
            cout << temp[i] << endl;
        }
    }

    // void del(int val){
    //     int id = find(heap.begin(), heap.end(), val);
    //     heap.

    // }

    private:

    int getLeftChildIndex(int parentIndex){ return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex){ return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex){ return (childIndex-1) / 2; }

    void heapify(){ // we will heapify each time we insert a value
        int index = size - 1;
        if(type == HeapTypes::Min_Heap){
            while(index != 0 && heap[getParentIndex(index)] > heap[index]){
                swapValuesWithIndices(getParentIndex(index), index);
                index = getParentIndex(index);
            }
        }
        else {
            while(index != 0 && heap[getParentIndex(index)] < heap[index]){
                swapValuesWithIndices(getParentIndex(index), index);
                index = getParentIndex(index);
            }
        }
    }

    void swapValuesWithIndices(int f_index, int l_index){
        int temp = heap[f_index];
        heap[f_index] = heap[l_index];
        heap[l_index] = temp;
    }
};

int main(){
    Heap h(HeapTypes::Min_Heap);
    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(17);
    h.insert(8); 
    h.printHeap();
}
