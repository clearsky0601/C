# Makefile基础教程

## 学习目标
- 理解Makefile的作用和重要性
- 掌握Makefile的基本语法和规则
- 学会编写实用的Makefile
- 了解常用的make命令和选项

## 知识要点

### 什么是Makefile？
Makefile是一个构建脚本，用于：
- **自动化编译**：避免手动输入复杂的编译命令
- **依赖管理**：只重新编译修改过的文件
- **项目管理**：统一的构建、测试、清理流程
- **跨平台**：在不同系统上使用相同的构建方式

### Makefile基本语法

#### 1. 规则结构
```makefile
目标: 依赖文件
	命令（必须用Tab缩进）
```

#### 2. 变量定义
```makefile
CC = gcc                    # 编译器
CFLAGS = -Wall -std=c99    # 编译选项
TARGET = program           # 目标文件名
```
这个配置翻译成人话就是:：用 gcc 编译器按照 C99 标准编译代码，并打开所有警告信息，最终生成的可执行文件叫做 program。

#### 3. 自动变量
- `$@`：目标文件名
- `$<`：第一个依赖文件
- `$^`：所有依赖文件
- `$?`：比目标新的依赖文件

#### 4. 伪目标
```makefile
.PHONY: clean all run
```

### 常用模式

#### 1. 简单程序
```makefile
program: main.c
	gcc -o program main.c
```

#### 2. 多文件项目
```makefile
program: main.o utils.o
	gcc -o program main.o utils.o

main.o: main.c
	gcc -c main.c

utils.o: utils.c
	gcc -c utils.c
```

#### 3. 使用变量
```makefile
CC = gcc
CFLAGS = -Wall -std=c99
OBJECTS = main.o utils.o
TARGET = program

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
```

## 代码说明
本目录包含多个Makefile示例，从简单到复杂，展示不同的使用场景。

## 编译运行
```bash
make              # 使用默认目标
make simple       # 运行简单示例
make advanced     # 运行高级示例
make clean        # 清理文件
```

## 练习建议
1. 修改示例程序，观察make的行为
2. 尝试添加新的目标和规则
3. 学习使用make的调试选项：`make -n`（干运行）
4. 理解依赖关系：修改文件后观察重新编译的过程

## 常见错误
1. **缩进错误**：命令行必须用Tab，不能用空格
2. **依赖错误**：忘记列出头文件依赖
3. **路径问题**：相对路径和绝对路径的使用
4. **变量未定义**：使用了未定义的变量

## 下一步学习
完成本节后，你已经掌握了C语言的基础准备知识，可以继续学习：
- 02-syntax：C语言核心语法
