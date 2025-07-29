# 文件操作

## 学习目标
- 掌握文件的打开、读取、写入和关闭
- 理解文件指针和文件模式
- 学会处理文件错误和异常
- 了解二进制文件和文本文件的区别

## 知识要点

### 文件基础

#### 1. 文件指针
```c
FILE *fp;  // 文件指针
```

#### 2. 文件打开
```c
FILE *fopen(const char *filename, const char *mode);
```

#### 3. 文件模式
- `"r"`：只读模式
- `"w"`：只写模式（覆盖）
- `"a"`：追加模式
- `"r+"`：读写模式
- `"w+"`：读写模式（覆盖）
- `"a+"`：读写模式（追加）

#### 4. 二进制模式
- 在模式后添加`"b"`：如`"rb"`, `"wb"`

### 文件操作函数

#### 1. 字符操作
```c
int fgetc(FILE *fp);        // 读取字符
int fputc(int c, FILE *fp); // 写入字符
```

#### 2. 字符串操作
```c
char *fgets(char *str, int n, FILE *fp);  // 读取字符串
int fputs(const char *str, FILE *fp);     // 写入字符串
```

#### 3. 格式化操作
```c
int fprintf(FILE *fp, const char *format, ...);  // 格式化写入
int fscanf(FILE *fp, const char *format, ...);   // 格式化读取
```

#### 4. 块操作
```c
size_t fread(void *ptr, size_t size, size_t count, FILE *fp);   // 读取块
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *fp); // 写入块
```

### 文件定位

#### 1. 定位函数
```c
int fseek(FILE *fp, long offset, int whence);  // 设置文件位置
long ftell(FILE *fp);                          // 获取当前位置
void rewind(FILE *fp);                         // 回到文件开头
```

#### 2. 定位参数
- `SEEK_SET`：从文件开头
- `SEEK_CUR`：从当前位置
- `SEEK_END`：从文件末尾

### 文件状态

#### 1. 状态检查
```c
int feof(FILE *fp);    // 检查文件结束
int ferror(FILE *fp);  // 检查错误状态
void clearerr(FILE *fp); // 清除错误标志
```

#### 2. 文件关闭
```c
int fclose(FILE *fp);  // 关闭文件
```

### 错误处理

#### 1. 文件打开检查
```c
FILE *fp = fopen("file.txt", "r");
if (fp == NULL) {
    perror("文件打开失败");
    return -1;
}
```

#### 2. 操作结果检查
- 检查返回值
- 使用ferror()检查错误
- 适当的错误处理

### 实际应用

#### 1. 配置文件读取
- 解析配置参数
- 处理注释和空行
- 错误恢复

#### 2. 日志文件写入
- 时间戳记录
- 不同级别的日志
- 文件轮转

#### 3. 数据文件处理
- CSV文件处理
- 二进制数据存储
- 大文件处理

## 代码说明
本目录包含文件操作的完整演示，展示各种文件处理技术和最佳实践。

## 编译运行
```bash
make
make run
make test-files    # 测试文件操作
```

## 练习建议
1. 实现文件复制程序
2. 编写简单的文本编辑器
3. 实现配置文件解析器
4. 创建日志记录系统

## 常见错误
1. **忘记关闭文件**：导致资源泄漏
2. **未检查文件打开**：空指针访问
3. **缓冲区溢出**：读取超长行
4. **权限问题**：文件访问权限不足

## 下一步学习
完成本节后，请继续学习：
- 02-memory-management：动态内存管理
