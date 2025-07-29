# 字符串处理

## 学习目标
- 理解C语言中字符串的表示方法
- 掌握字符串的基本操作
- 学会使用标准字符串函数
- 了解字符串与指针的关系

## 知识要点

### 字符串基础

#### 1. 字符串表示
```c
char str1[] = "Hello";           // 字符数组
char str2[10] = "World";         // 固定大小数组
char *str3 = "C Programming";    // 字符串指针
```

#### 2. 字符串特点
- 以'\0'（空字符）结尾
- 字符数组的特殊形式
- 字符串长度不包括'\0'

#### 3. 字符串字面量
- 存储在只读内存区域
- 多个相同字面量可能共享内存
- 不应该修改字符串字面量

### 字符串操作

#### 1. 字符串长度
```c
#include <string.h>
int len = strlen(str);
```

#### 2. 字符串复制
```c
strcpy(dest, src);      // 复制字符串
strncpy(dest, src, n);  // 复制n个字符
```

#### 3. 字符串连接
```c
strcat(dest, src);      // 连接字符串
strncat(dest, src, n);  // 连接n个字符
```

#### 4. 字符串比较
```c
int result = strcmp(str1, str2);    // 比较字符串
int result = strncmp(str1, str2, n); // 比较前n个字符
```

### 字符串查找

#### 1. 查找字符
```c
char *ptr = strchr(str, 'c');    // 查找字符
char *ptr = strrchr(str, 'c');   // 反向查找字符
```

#### 2. 查找子串
```c
char *ptr = strstr(str, "sub");  // 查找子字符串
```

### 字符串转换

#### 1. 大小写转换
```c
#include <ctype.h>
char c = toupper('a');  // 转大写
char c = tolower('A');  // 转小写
```

#### 2. 数字转换
```c
#include <stdlib.h>
int num = atoi("123");        // 字符串转整数
double d = atof("3.14");      // 字符串转浮点数
```

### 字符串输入输出

#### 1. 输入函数
```c
gets(str);              // 不安全，已废弃
fgets(str, size, stdin); // 安全的输入
scanf("%s", str);       // 读取单词
```

#### 2. 输出函数
```c
printf("%s", str);      // 格式化输出
puts(str);              // 输出并换行
```

### 字符串安全

#### 1. 缓冲区溢出
- 确保目标缓冲区足够大
- 使用安全的函数版本
- 检查字符串长度

#### 2. 安全函数
```c
strncpy(dest, src, sizeof(dest)-1);
strncat(dest, src, sizeof(dest)-strlen(dest)-1);
```

## 代码说明
本目录包含字符串处理的完整演示，展示各种字符串操作和安全实践。

## 编译运行
```bash
make
make run
make search    # 字符串查找演示
```

## 练习建议
1. 实现自己的字符串函数
2. 练习字符串解析和处理
3. 编写字符串验证函数
4. 实现简单的文本处理工具

## 常见错误
1. **缓冲区溢出**：目标数组太小
2. **未终止字符串**：忘记'\0'结尾
3. **修改字符串字面量**：试图修改常量字符串
4. **内存泄漏**：动态分配的字符串未释放

## 下一步学习
完成本节后，请继续学习：
- 05-structures：结构体与联合体
