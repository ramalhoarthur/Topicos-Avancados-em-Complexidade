#include <cstdio>
#include <cstdlib>

long long merge(int arr[], int left, int mid, int right) {
    long long count = 0;
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= 3*rightArr[j]) {
            arr[k] = leftArr[i];
            count += n2-j;
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    return count;
}

long long mergeSort(int arr[], int left, int right) {
    long long count = 0;

    if (left < right) {
      
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);

        count += merge(arr, left, mid, right);
    }

    return count;
}

int ind[100000] = {-1};

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i<n; i++) {
        scanf("%d", &ind[i]);
    }

    long long count = mergeSort(ind, 0, n-1);
    long long result = (long long) n*(n-1)/2 - count;

    printf("%lld\n", result);

    return 0;
}