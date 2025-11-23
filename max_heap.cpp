#include<iostream>
using namespace std;


class MaxHeap{
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

        while(i !=0 && arr[parent]<arr[i] ){
            swap(arr[i],arr[parent]);
            i= parent;
            parent = (i-1)/2;

        }
    }

    max_heapify(int i){
        int largest = i;
        int left = i*2 +1;
        int right = (i*2)+2;

        if(left <size && arr[largest]<arr[left]){
            largest= left;
        }
        if(right <size && arr[largest]<arr[right]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            max_heapify(largest);
        }
    }
 
    
    int deletemax(){
        if(size == 0){
            cout<<"heap is empty"<<endl;
            return -1;
        }

        if(size == 1){
            size--;
            return -1;
        }

        int max_val = arr[0];
        arr[0] = arr[size-1];
        size--;
        max_heapify(0);
        return max_val;
    }

    void print_heap_arr(){
        for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    
};

int main(){
    MaxHeap heap;
    heap.insert(10);
    heap.insert(15);
    heap.insert(21);
    heap.insert(30);
    heap.insert(18);
    heap.insert(19);

    

    cout<<"heap elements: ";
    heap.print_heap_arr();

    int sort[100];
    int n =heap.size;

    for(int i=0; i<n;i++){
        sort[i]= heap.deletemax();
    }

    cout<<"sorted array in decending order: ";
     for(int j=0; j<n-1;j++){ // end at n-1 because w get extra -1 value d to retun statment
          cout<<sort[j]<<" ";
        }
        cout<<endl;

         cout<<"sorted array in accending order: ";
       for(int j=n-2;j>=0;j--){  //starting from j=n-2 because we got -1 also due to retunr stament 
          cout<<sort[j]<<" ";
        }
        cout<<endl;  

    

//     heap.deletemax();
//      cout<<"heap elements after delete max: ";
//     heap.print_heap_arr();


    return 0;
}
