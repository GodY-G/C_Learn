# 计算机考研C语言复习
- now:
    [前六周作业](http://47.115.215.212:8080/00_%E5%89%8D%E8%A8%80/)

## 📖 项目简介
本项目是一个C语言算法学习仓库。
核心思想：少量持续 > 大量突击。

## 🗂️ 仓库目录结构
**本仓库严格对应 王道六周作业（OJ平台）​ 与 LeetCode 408题单（80题）。**
```text
C/
├── week01/                
├── week02/                 
├── week03/                
├── week04/                 
├── week05/                 
├── week06/                 
│
├── leetcode_408/           # 力扣408专项题单（80题）
│
├── daily_notes/            # 力扣每日一题（笔记）
└── README.md               # 本文件
```

🎯 学习目标（Checklist）
```text
周次	主题	OJ状态	重点难点
Week 1​	环境配置 & 基础语法	⏳ 进行中	printf/scanf格式控制
Week 2​	分支与循环	⏳ 未开始	多层循环、边界条件
Week 3​	数组与字符串	⏳ 未开始	字符数组、字符串处理函数
Week 4​	函数与递归	⏳ 未开始	递归出口、栈帧变化
Week 5​	指针	⏳ 未开始	核心难点：指针与数组的关系
Week 6​	结构体与链表	⏳ 未开始	动态内存分配 (malloc/free)
```

## 🛠️ 环境说明
```text
平台	编译器	说明
macOS​	Clang (Apple clang)​	系统自带，终端使用 gcc或 clang
Windows​	MinGW-w64 (GCC)​	推荐使用 VS Code + MinGW 或 CLion
标准​	C99​	编译参数统一为：gcc -std=c99 -o output source.c
```

## 编译与运行示例
```text
# Mac / Linux
gcc week01/homework.c -o homework
./homework

# Windows (MinGW)
gcc week01/homework.c -o homework.exe
homework.exe
```
## 🤝 如何参与（如果你想一起学）
Fork 本仓库
创建你的学习分支 (git checkout -b my-study)
提交代码 (git commit -m "Day XX: 学习内容")
推送分支 (git push origin my-study)
提交 Pull Request


==⭐ 如果这个仓库对你有帮助，点个 Star 支持一下吧！​ ⭐==