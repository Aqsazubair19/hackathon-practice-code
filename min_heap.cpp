#include<iostream>
using namespace std;


class MinHeap{
    public:
    int arr[100];
    int size=0;
    int capacity = 100;
  
    void insert(int val){
        if(size == capacity){
            cout<<"heap is full "<<endl;
            return;
        }

        arr[size] = val;
        size++;

        int i = size -1;
        int parent = (i-1)/2;

        while(i !=0 && arr[parent]>arr[i] ){
            swap(arr[i],arr[parent]);
            i= parent;
            parent = (i-1)/2;

        }
    }

    max_heapify(int i){
        int smallest = i;
        int left = i*2 +1;
        int right = (i*2)+2;

        if(left <size && arr[smallest]>arr[left]){
            smallest= left;
        }
        if(right <size && arr[smallest]>arr[right]){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[smallest], arr[i]);
            max_heapify(smallest);
        }
    }

    void deletemin(){
        if(size == 0){
            cout<<"heap is empty"<<endl;
            return;
        }

        if(size == 1){
            size--;
            return;
        }

        arr[0] = arr[size-1];
        size--;
        max_heapify(0);
    }

    void print_heap_arr(){
        for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    MinHeap heap;
    heap.insert(10);
    heap.insert(15);
    heap.insert(21);
    heap.insert(30);
    heap.insert(18);
    heap.insert(19);

    

    cout<<"heap elements: ";
    heap.print_heap_arr();

    heap.deletemin();
     cout<<"heap elements after delete min: ";
    heap.print_heap_arr();

    return 0;
}
