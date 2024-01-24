#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (arr[j] <= x) { 
            SWAP(arr[i], arr[j],int); 
            i++; 
        } 
    } 
    SWAP(arr[i], arr[r],int); 
    return i; 
} 

int quickSelect(int* arr, int* left, int* right, int k){
    if (left == right)
        return *left;
    int* pivot = left + (right - left) / 2;
    pivot = partition(arr, left, right, pivot);
    if (k == pivot - left)
        return *pivot;
    else if (k < pivot - left)
        return quickSelect(arr, left, pivot - 1, k);
    else
        return quickSelect(arr, pivot + 1, right, k - (pivot - left + 1));
}