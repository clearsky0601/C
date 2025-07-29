# 预处理器

## 学习目标
- 掌握预处理器指令的使用
- 理解宏定义和条件编译
- 学会文件包含和头文件保护
- 了解预处理器的高级技巧

## 知识要点

### 预处理器指令

#### 1. 文件包含
```c
#include <stdio.h>     // 系统头文件
#include "myheader.h"  // 用户头文件
```

#### 2. 宏定义
```c
#define PI 3.14159
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```

#### 3. 条件编译
```c
#ifdef DEBUG
    // 调试代码
#endif

#ifndef HEADER_H
#define HEADER_H
    // 头文件内容
#endif
```

### 宏定义

#### 1. 简单宏
```c
#define SIZE 100
#define MESSAGE "Hello World"
```

#### 2. 函数式宏
```c
#define SQUARE(x) ((x) * (x))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
```

#### 3. 多行宏
```c
#define SWAP(a,b) do { \
    typeof(a) temp = a; \
    a = b; \
    b = temp; \
} while(0)
```

### 条件编译

#### 1. 基本条件
```c
#if defined(WINDOWS)
    // Windows特定代码
#elif defined(LINUX)
    // Linux特定代码
#else
    // 其他系统代码
#endif
```

#### 2. 版本控制
```c
#if VERSION >= 2
    // 新版本功能
#endif
```

### 预定义宏

#### 1. 标准宏
- `__FILE__`：当前文件名
- `__LINE__`：当前行号
- `__DATE__`：编译日期
- `__TIME__`：编译时间
- `__FUNCTION__`：当前函数名

#### 2. 编译器宏
- `__GNUC__`：GCC编译器
- `__clang__`：Clang编译器
- `_MSC_VER`：MSVC编译器

### 头文件保护

#### 1. 传统方法
```c
#ifndef HEADER_H
#define HEADER_H
// 头文件内容
#endif
```

#### 2. pragma once
```c
#pragma once
// 头文件内容
```

### 高级技巧

#### 1. 字符串化
```c
#define STR(x) #x
#define XSTR(x) STR(x)
```

#### 2. 连接符
```c
#define CONCAT(a,b) a##b
```

#### 3. 可变参数宏
```c
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
```

## 代码说明
本目录包含预处理器的完整演示，展示各种预处理技术和应用。

## 编译运行
```bash
make
make run
make debug    # 调试版本
```

## 练习建议
1. 创建自己的头文件库
2. 实现条件编译的配置系统
3. 编写调试宏和日志宏
4. 实现跨平台兼容性宏

## 常见错误
1. **宏参数问题**：忘记使用括号保护参数
2. **副作用**：宏参数被多次求值
3. **头文件重复包含**：缺少头文件保护
4. **宏命名冲突**：与标准库宏冲突

## 下一步学习
完成本节后，请继续学习：
- 04-projects：综合练习项目
