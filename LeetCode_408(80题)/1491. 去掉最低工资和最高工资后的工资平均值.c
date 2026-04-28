
// 二分查找：在有序数组 [0, right] 中查找第一个大于等于 value 的位置
int binarySearch(int* salary, int value, int right) {
    int l = 0, r = right;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (salary[mid] < value) {
            l = mid + 1;   // 向右搜索
        } else {
            r = mid - 1;   // 向左搜索（包括相等的情况）
        }
    }
    return l; // 插入位置
}

// 二分插入排序
void binarySort(int* salary, int salarySize) {
    for (int i = 1; i < salarySize; ++i) {
        int value = salary[i];
        int pos = binarySearch(salary, value, i - 1); // 在已排序部分查找
        // 后移元素
        for (int j = i; j > pos; --j) {
            salary[j] = salary[j - 1];
        }
        salary[pos] = value;
    }
}

double average(int* salary, int salarySize) {
    if (salarySize <= 2) return 0.0; // 不足两个元素无法去头去尾

    binarySort(salary, salarySize);

    double sum = 0.0;
    // 去掉最小值（索引0）和最大值（索引 salarySize-1）
    for (int i = 1; i < salarySize - 1; ++i) {
        sum += salary[i];
    }
    return sum / (salarySize - 2); // 转为浮点数除法
}

