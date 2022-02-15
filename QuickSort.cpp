class Solution
{
public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low >= high)
            return;
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Your code here
        int pivot = arr[high];
        int pindex = low;
        for (int i = low; i <= high - 1; i++)
        {
            if (arr[i] <= pivot)
            {
                swap(arr[i], arr[pindex]);
                pindex++;
            }
        }
        swap(arr[high], arr[pindex]);
        return pindex;
    }
};