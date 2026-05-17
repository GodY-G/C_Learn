
//解法一：新建数组
void rotate(int* nums, int numsSize, int k) {
    
    int *temp = (int*)malloc(sizeof(int) * numsSize);
    
    for(int i = 0; i < numsSize;++i){
        int j = (i + k) % numsSize;
        temp[j] = nums[i];
    }
    for(int i = 0;i < numsSize;++i){
        nums[i] = temp[i];
    }
}
//解法二：三次反转法
void reverse(int* nums, int left, int right) {
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;  // 防止 k > numsSize

    reverse(nums, 0, numsSize - k - 1); // 前半部分
    reverse(nums, numsSize - k, numsSize - 1); // 后半部分
    reverse(nums, 0, numsSize - 1); // 整体
}