#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

void merge(pair<int, int> arr[], long long mins[], long long maxs[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    pair<int, int> leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    long long controle[n2] = {0};
    while (i < n1 && j < n2) {
        if (leftArr[i].first < rightArr[j].first) {
            arr[k] = leftArr[i];
            mins[leftArr[i].second] += n2-j;
            controle[j]++;
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    for (int m = 0; m < n2; m++) {
        if (m > 0) {
            controle[m] += controle[m-1];
        }
    }

    for (int m = 0; m < n2; m++) {
        maxs[rightArr[m].second] += controle[m];
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
}

void mergeSort(pair<int, int> arr[], long long mins[], long long maxs[], int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        mergeSort(arr, mins, maxs, left, mid);
        mergeSort(arr, mins, maxs, mid + 1, right);

        merge(arr, mins, maxs, left, mid, right);
    }
}

pair<int, int> ind[100000] = {{-1, -1}};

long long mins[100000] = {0};
long long maxs[100000] = {0};

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i<n; i++) {
        scanf("%d", &(ind[i].first));
        ind[i].second = i;
    }

    mergeSort(ind, mins, maxs, 0, n-1);

    long long result = 0;

    for (int i = 0; i < n; i++) {
        result += mins[i]*maxs[i];
    }

    printf("%lld\n", result);

    return 0;
}
