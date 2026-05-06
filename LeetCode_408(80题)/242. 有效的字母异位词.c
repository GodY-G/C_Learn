#include <string.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    // 1️⃣ 长度不同，一定不是异位词
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    // 2️⃣ 创建计数数组，初始化为0
    int count[26] = {0};
    
    // 3️⃣ 遍历第一个字符串，计数+1
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }
    
    // 4️⃣ 遍历第二个字符串，计数-1
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']--;
    }
    
    // 5️⃣ 检查所有计数是否为0
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;  // 计数不为0，不是异位词
        }
    }
    
    return true;  // 所有计数都为0，是异位词
}