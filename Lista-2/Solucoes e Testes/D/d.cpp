#include <cstdio>
#include <cstdlib>

long long merge(int arr[], int left, int mid, int right, int d) {
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
        if (leftArr[i] <= rightArr[j]+d) {
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

long long mergeSort(int arr[], int left, int right, int d) {
    long long count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, left, mid, d);
        count += mergeSort(arr, mid + 1, right, d);

        count += merge(arr, left, mid, right, d);
    }

    return count;
}

int ind1[100000] = {-1};
int dif[100000] = {-1};

int main() {

    int n, d;
    scanf("%d %d", &n, &d);

    for (int i = 0; i<n; i++) {
        scanf("%d", &ind1[i]);
    }
    int temp;
    for (int i = 0; i<n; i++) {
        scanf("%d", &temp);
        dif[i] = ind1[i]-temp;
    }

    long long count = mergeSort(dif, 0, n-1, d);
    
    printf("%lld\n", count);

    return 0;
}