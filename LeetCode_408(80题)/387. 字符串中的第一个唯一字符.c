#include <string.h>
//暴力解法：双重循环，时间复杂度O(n^2)，空间复杂度O(1)
int firstUniqChar(char* s) {
    int n = strlen(s);  // 获取字符串长度
    
    // 外层：遍历每个字符
    for (int i = 0; i < n; i++) {
        int isUnique = 1;  // 假设当前字符是唯一的
        
        // 内层：检查是否有重复字符
        for (int j = 0; j < n; j++) {
            // 跳过自身，检查其他位置是否有相同字符
            if (i != j && s[i] == s[j]) {
                isUnique = 0;  // 找到重复，不是唯一的
                break;         // 跳出内层循环
            }
        }
        
        // 如果当前字符是唯一的，返回它的索引
        if (isUnique) {
            return i;
        }
    }
    
    return -1;  // 没有找到唯一字符
}
//优化解法：使用哈希表记录字符出现次数，时间复杂度O(n)，空间复杂度O(1)（因为字符集有限）
int firstUniqChar(char* s) {
    int count[26] = {0};  // 假设输入只包含小写字母，使用一个大小为26的数组来记录每个字符的出现次数
    int n = strlen(s);  // 获取字符串长度   

    // 第一次遍历：统计每个字符的出现次数
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;  // 将字符转换为索引并增加计数
    }

    // 第二次遍历：找到第一个出现次数为1的字符
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;  // 返回第一个唯一字符的索引
        }
    }

    return -1;  // 没有找到唯一字符
}