void sortColors(int* nums, int numsSize) {
    int red = 0;
    int white = 0;
    int blue = 0;
    
    for(int i = 0; i < numsSize;++i){
        if(nums[i] == 0) red++;
        if(nums[i] == 1) white++;
        if(nums[i] == 2) blue++;
    }
    
    for(int i = 0;i < numsSize;++i){
        if(red > 0){
            nums[i] = 0;
            red--;
        }
        else if(red == 0 && white  > 0){
            nums[i] = 1;
            white --;
        }
        else if(red == 0 && white == 0 && blue > 0){
            nums[i] = 2;
            blue--;
        }
    }
    

}

//解法二 双指针
void sortColors(int* nums, int numsSize) {
    int left = 0;           // 1️⃣ 指向下一个0的位置
    int right = numsSize - 1; // 2️⃣ 指向下一个2的位置
    int i = 0;              // 3️⃣ 当前遍历指针
    
    while (i <= right) {    // 4️⃣ 遍历直到i超过right
        if (nums[i] == 0) {
            // 5️⃣ 遇到0：和left位置交换
            int temp = nums[i];
            nums[i] = nums[left];
            nums[left] = temp;
            left++;          // left右移
            i++;             // i右移
        }
        else if (nums[i] == 1) {
            // 6️⃣ 遇到1：不交换，直接跳过
            i++;             // i右移
        }
        else { // nums[i] == 2
            // 7️⃣ 遇到2：和right位置交换
            int temp = nums[i];
            nums[i] = nums[right];
            nums[right] = temp;
            right--;         // right左移
            // ⚠️ 注意：i不动！因为换过来的数还没检查
        }
    }
}