#include <iostream>
#include <chrono>
#include <stack>

using namespace std;
using namespace std::chrono;

//recursive partitioning
int partitionR(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = t;
    return (i + 1);
}

// Recursive quick sort
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionR(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
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
            
            auto startTimeR = high_resolution_clock::now();
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSortRecursive(arr, 0, n - 1);
            auto endTimeR = high_resolution_clock::now();
            auto durationR = duration_cast<microseconds>(endTimeR - startTimeR);
            tTimeR += durationR;
        }
        auto aTimeR = tTimeR.count() / iterations;
        cout << "Average time for "<<size<<" elements - reccursive : " << aTimeR << " microseconds"<<endl;
    }
}
