#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i+1; j < n; j++ ){
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool swapped = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j+1] < arr[j]){
                swapped = true;
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if(!swapped) break;
    }
    //Average and Worst TC = O(N2);
    //Best TC = O(N) - already sorted array
}

void insertion_sort(int arr[], int n){
    //takes an element and places it in its correct position
    for(int i = 0; i < n ; i++){
        int j = i;
        while( j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    //Average and Worst TC = O(N2);
    //Best TC = O(N) - already sorted array
}

void merge(int arr[], int low, int mid, int high){
    int temp[1000];
    int left = low;
    int right = mid + 1;
    int k = low; // index for temp array
    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[k] = arr[left];
            left++;
        }
        else{
            temp[k] = arr[right];
            right++; 
        }
        k++;
    } 

    while(left <= mid){
        temp[k] = arr[left];
        left++;
        k++;
    }
    
    while(right <= high){
        temp[k] = arr[right];
        right++;
        k++;
    }
    
    // Copy merged result back to original array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i];
    }
}


void merge_sort(int arr[], int low, int high){
    //the best soring algorithm - Divide and Merge
    if(low >= high) return;
    int mid = (low + high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i]<=pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high){
    //divide and conquer algorithm
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        quick_sort(arr, low, partitionIndex - 1);
        quick_sort(arr, partitionIndex + 1, high);
    }
}

int main(){
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;
    //insertion_sort(arr, n);
    quick_sort(arr, 0, n-1); //merge_sort(arr, 0, n-1);
    cout << "Sorted Array is --> ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}