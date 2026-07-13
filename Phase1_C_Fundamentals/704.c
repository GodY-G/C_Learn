int search(int* nums, int numsSize, int target) {
    int i = 0, j = numsSize - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (nums[mid] < target)
            i = mid + 1;
        else if (nums[mid] == target)
            return mid;
        else
            j = mid - 1;
    }
    return -1;
}