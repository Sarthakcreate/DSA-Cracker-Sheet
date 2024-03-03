//User function template for C++

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        if (k > 0 && k <= r - l + 1) {
            // Partition the array around last element and get the position of pivot
            int pos = partition(arr, l, r);
            // If pivot position is same as k
            if (pos - l == k - 1)
                return arr[pos];
            // If pivot position is more, recur for the left subarray
            if (pos - l > k - 1)
                return kthSmallest(arr, l, pos - 1, k);
            // Else recur for the right subarray
            return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
        }
        // If k is invalid
        return -1;
    }
private:
    int partition(int arr[], int l, int r) {
        int pivot = arr[r]; // Pivot is the last element
        int i = l - 1; // Index of smaller element
        for (int j = l; j <= r - 1; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;
                // Swap arr[i] and arr[j]
                swap(arr[i], arr[j]);
            }
        }
        // Swap arr[i+1] and arr[r]
        swap(arr[i + 1], arr[r]);
        return i + 1;
    }
};
