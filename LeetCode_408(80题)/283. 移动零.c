void moveZeroes(int* nums, int numsSize) {
    int j = 0;  // j 指向下一个非零元素应该放置的位置
    
    // 1️⃣ 遍历数组，将非零元素移动到前面
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];  // 将非零元素放到 j 位置
            j++;                  // j 前进一位
        }
    }
    
    // 2️⃣ 将 j 之后的所有位置设为 0
    for (int i = j; i < numsSize; i++) {
        nums[i] = 0;
    }
}