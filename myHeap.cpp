#include <iostream>
#include <algorithm> // swap

using namespace std;

class Myheap{
private:
    const int size = 100;
    int h_size = 0;
    int* array;
public:
    Myheap(){
        array = new int[size];
    }
    
    Myheap(int *a, int s) : size(2 * s){
        array = new int[size];
        h_size = s;
        for(int i = 0; i < s; i++)
            array[i] = a[i];
        //从最后一个节点的parent开始 p = (h_size - 2) / 2;
        int p = (h_size - 2) / 2;
        for(int i = p; i >= 0; i--)
            maxHeapify(i);
    }
    
    ~Myheap(){
        delete[] array;
    }
    
    void maxHeapify(int k){
        //i的孩子节点 2 * i + 1， 2 * i + 2
        if(k >= h_size) return;
        if((2 * k + 1) >= h_size) return;
        int ma = 0;
        if(array[k] < array[2 * k + 1])
            ma = 2 * k + 1;
        else ma = k;
        if((2 * k + 2) < h_size && array[ma] < array[2 * k + 2]){
            ma = 2 * k + 2;
        }
        if(ma != k){
            swap(array[k], array[ma]);
            maxHeapify(ma);
        }
    }
    
    void insert(int ele){
        array[h_size] = ele;
        h_size++;
        int cur = h_size - 1;
        int p = (cur - 1 ) / 2;
        while(cur > 0 && array[p] < array[cur])
        {
            swap(array[p], array[cur]);
            cur = p;
            p = (cur - 1 ) / 2;
        }
    }
    
    int getMax(){
        if(h_size > 0)
            return array[0];
        else return -1;
    }
    
    void pop(){
        if(h_size > 0){
            array[0] = array[h_size - 1];
            h_size--;
            maxHeapify(0);
        }
    }
    
    void print(){
        for(int i = 0; i < h_size; i++){
            cout << array[i] << " " ;
        }
    }
    
};

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    Myheap heap(a, 10);
    heap.print();   // 9 8 6 7 4 5 2 0 3 1
    heap.insert(12);
    heap.print();  // 12 9 6 7 8 5 2 0 3 1 4
    cout << heap.getMax() << endl;
    heap.pop();
    heap.print();  //9 8 6 7 4 5 2 0 3 1 4
    return 0;
}
