int lengthOfLastWord(char* s) {
    int len = 0;                     // 1️⃣ 记录最后一个单词的长度
    int i = strlen(s) - 1;           // 2️⃣ 从字符串最后一个字符开始

    // 3️⃣ 跳过字符串末尾的空格
    while (i >= 0 && s[i] == ' ') {
        i--;                         // 向前移动
    }

    // 4️⃣ 统计最后一个单词的长度
    while (i >= 0 && s[i] != ' ') {
        len++;                       // 长度+1
        i--;                         // 向前移动
    }

    return len;                     // 5️⃣ 返回长度
}