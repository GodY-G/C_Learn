int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    
    // 1️⃣ 使用128大小的数组，覆盖所有ASCII字符
    int lastPos[128];
    for (int i = 0; i < 128; i++) {
        lastPos[i] = -1;  // 初始化为-1
    }
    
    int left = 0;          // 窗口左边界
    int maxLen = 0;       // 最大长度
    
    // 2️⃣ 滑动窗口
    for (int right = 0; right < len; right++) {
        unsigned char ch = s[right];  // 转换为无符号，确保索引非负
        int idx = ch;                  // 直接使用ASCII值作为索引
        
        // 3️⃣ 如果字符已出现且在当前窗口内，移动左指针
        if (lastPos[idx] != -1 && lastPos[idx] >= left) {
            left = lastPos[idx] + 1;
        }
        
        // 4️⃣ 更新字符最后出现的位置
        lastPos[idx] = right;
        
        // 5️⃣ 计算当前窗口长度并更新最大值
        int currLen = right - left + 1;
        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }
    
    return maxLen;
}