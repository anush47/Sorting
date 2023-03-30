#include <iostream>

using namespace std;

double getMedian(int* arr,int length){
    //return the mid value if the number of elements are odd
    if (length % 2 != 0){
        return (arr[length/2]);
    }
    //return the average value of the two middle numbers if no of elements are even
    else{
        int i = length/2;
        double md = (arr[i-1]+arr[i])/(double)2;
        return (md);
    }
}

void insertNumber(int* arr,int length){
    int no = arr[length - 1];
    //sort the last element of the array
    for (int i = length - 1; i >= 0; i--) {
        if (arr[i] >= no){
            arr[i+1] = arr[i];
            arr[i] = no;
        }
    }
    //get median
    double md = getMedian(arr,length);
    
    //print the output
    cout<<"[";
    for (int i = 0; i < length; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"]";
    
    cout<<" - median: "<<md<<endl;
}

int main()
{
    //input the array legth
    int length;
    cin>>length;
    //input array elements
    int arr[length];
    for (int i = 0; i < length; i++) {
        cin>>arr[i];
    }
    //add numbers to running median
    for (int i = 0; i < length; i++) {
        int arr_dum[i+1];
        for (int j = 0; j < i+1;j++) {
            arr_dum[j] = arr[j];
        }
        int length = sizeof(arr_dum) / sizeof(int);
        insertNumber(arr_dum,length);
        
        //sort the array until given number
        for (int j = 0; j < i+1;j++) {
            arr[j] = arr_dum[j];
        }
    }
    return 0;
}
