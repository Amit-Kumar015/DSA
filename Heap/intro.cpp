#include <iostream>
#include <queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
    
        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;

            arr[index] = val;

            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            for (int i = 1; i <= size; i++)
            {
                cout<<arr[i]<<" ";
            }cout<<endl;
        }

        void deleteFromHeap(){
            if(size == 0){
                cout<<"nothing to delete"<<endl;
                return;
            }

            // put last element into first index
            arr[1] = arr[size];
            size = size - 1;

            // take root to its correct pos
            int i = 1;
            while(i<size){
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;

                if(leftIndex < size && arr[leftIndex] > arr[i]){
                    swap(arr[leftIndex], arr[i]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[rightIndex] > arr[i]){
                    swap(arr[rightIndex], arr[i]);
                    i = rightIndex;
                }
                else{
                    return;
                }
            }
        }

    };
    
    void heapify(int arr[], int size, int index){
        int largest = index;

        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;

        if(leftIndex < size && arr[largest] < arr[leftIndex]){
            largest = leftIndex;
        }
        
        if(rightIndex < size && arr[largest] < arr[rightIndex]){
            largest = rightIndex;
        }

        if(largest != index){
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }

    int main(){
    heap h;

    h.insert(20);
    h.insert(40);
    h.insert(25);
    h.insert(50);
    h.insert(30);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[5] = {-1, 20, 30, 15, 50};
    int n = 5;

    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    cout<<"printing the array"<<endl;
    for (int i = 1; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    // max heap
    priority_queue<int> pq;

    // min heap
    priority_queue<int , vector<int>, greater<int>> pq;

    return 0;
}