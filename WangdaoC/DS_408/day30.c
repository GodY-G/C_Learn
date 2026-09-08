#include<stdio.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];  // 选第一个元素为枢轴
    while (low < high) {
        while (low < high && a[high] >= pivot) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int pivotpos = partition(a, low, high);
        quick_sort(a, low, pivotpos - 1);
        quick_sort(a, pivotpos + 1, high);
    }
}

// O(n²) / O(1)
void insert_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = a[i], j;
        for (j = i - 1; j >= 0 && a[j] > tmp; j--)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}