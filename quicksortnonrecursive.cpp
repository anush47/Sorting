#include <iostream>
#include <chrono>
#include <stack>

using namespace std;
using namespace std::chrono;

//non - reccursive partitioning
int Partition(int arr[], int start, int end){
     int pivot = arr[end];
     int index = start;
     for(int i=start;i<end;i++){
         if (arr[i]<pivot){
             int temp = arr[i];
             arr[i]=arr[index];
             arr[index]=temp;
             index++;
         }
     }
     int temp = arr[end];
     arr[end]=arr[index];
     arr[index]=temp;

     return index;
}

void QuicksortNonRecursive(int arr[], int start, int end){
     stack<int> stack;
     stack.push(start);
     stack.push(end);
     while (!stack.empty()) {
         int right = stack.top();
         stack.pop();
         int left = stack.top();
         stack.pop();
         if (left < right) {
             int part = Partition(arr, left, right);
             // Push the left sub-array onto the stack
             stack.push(left);
             stack.push(part - 1);
             // Push the right sub-array onto the stack
             stack.push(part + 1);
             stack.push(right);
         }
     }
}

int main()
{
    int iterations = 5;
    for (int i = 0; i < 5; i++) {
        int size = (i+1)*2000;
        int arr[size];
        auto tTimeR = microseconds(0);
        auto tTimeNR = microseconds(0);
        for (int j = 0; j < iterations; j++) {
            // generate random elements for the array
            for(int i=0;i<size;i++){
               arr[i]=rand()%1000;
            }
            
            auto startTimeNR = high_resolution_clock::now();
            QuicksortNonRecursive(arr,0,size-1);
            auto endTimeNR = high_resolution_clock::now();
            auto durationNR = duration_cast<microseconds>(endTimeNR - startTimeNR);
            tTimeNR += durationNR;
        }
        auto aTimeNR = tTimeNR.count() / iterations;
        cout << "Average time for "<<size<<" elements - non reccursive : " << aTimeNR << " microseconds"<<endl;
    }
}
