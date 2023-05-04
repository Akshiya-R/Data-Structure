#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int largest = root;
  int left = 2*root+1;
  int right = 2*root+2;

    // If root is less than left child
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If current largest is smaller than right child
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If root not equal current largest
    if (largest != root) {
        swap(arr[root], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
  
   
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{   
   
   int size_of_array;
   cout << "Enter the size of the array: ";
   cin>>size_of_array;
   int heap_arr[size_of_array];
   cout << "Enter the numbers: ";

    //store input from user to array
    for (int i = 0; i < size_of_array; ++i) {
        cin >> heap_arr[i];
    }
    cout<<"\n";
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);

   // the array input which I used.
   //heap_arr[] = {4,17,3,12,9,6};
   //heap_arr[] = {10, 15, 20, 25, 30};
   //heap_arr[] = {2, 7, 3, 11, 6, 5, 1, 8};
   //heap_arr[] = {4, 6, 12, 15, 9, 8, 2, 11};
}