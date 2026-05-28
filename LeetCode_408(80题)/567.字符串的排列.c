#include <stdbool.h>
#include <string.h>
//滑动窗口
bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // 边界检查
    if (len1 > len2) return false;
    
    // 统计 s1 的字符频率
    int count1[26] = {0};
    for (int i = 0; i < len1; i++) {
        count1[s1[i] - 'a']++;
    }
    
    // 初始化滑动窗口（s2 的前 len1 个字符）
    int count2[26] = {0};
    for (int i = 0; i < len1; i++) {
        count2[s2[i] - 'a']++;
    }
    
    // 比较初始窗口
    bool match = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            match = false;
            break;
        }
    }
    if (match) return true;
    
    // 滑动窗口
    for (int i = len1; i < len2; i++) {
        // 加入新字符
        count2[s2[i] - 'a']++;
        // 移除旧字符（窗口最左边的字符）
        count2[s2[i - len1] - 'a']--;
        
        // 比较频率
        match = true;
        for (int j = 0; j < 26; j++) {
            if (count1[j] != count2[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    
    return false;
}