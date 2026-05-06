#include <string.h>
#include <stdbool.h>
//暴力解法：双重循环，时间复杂度O(n^2)，空间复杂度O(1)
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
//哈希表 计数排序
bool isAnagram(char* s, char* t) {
    int hash1[26];
    int hash2[26];

    int len1 = strlen(s);
    int len2 = strlen(t);
    for(int i = 0;i < 26;++i){
        hash1[i] = 0;
        hash2[i] = 0;
    }

    if(len1 != len2){
        return false;
    }

    for(int i = 0;i < len1;++i){
        hash1[s[i] - 'a']++;
        hash2[t[i] - 'a']++;
    }

    for(int i = 0;i < 26;++i){
        if(hash1[i] != hash2[i]){
            return false;
        }
    }
    return true;
}