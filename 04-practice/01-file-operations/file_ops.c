/*
 * C语言文件操作演示程序
 * 
 * 功能：
 * 1. 演示文件的创建、读取、写入
 * 2. 展示不同的文件操作模式
 * 3. 演示文件定位和状态检查
 * 4. 实现实用的文件处理功能
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 函数声明
void create_sample_file(void);
void read_file_demo(void);
void write_file_demo(void);
void append_file_demo(void);
void binary_file_demo(void);
void file_position_demo(void);
void copy_file(const char *source, const char *dest);
void count_file_stats(const char *filename);

int main() {
    printf("=== C语言文件操作演示 ===\n\n");
    
    // 1. 创建示例文件
    printf("1. 创建示例文件：\n");
    create_sample_file();
    
    // 2. 文件读取演示
    printf("\n2. 文件读取演示：\n");
    read_file_demo();
    
    // 3. 文件写入演示
    printf("\n3. 文件写入演示：\n");
    write_file_demo();
    
    // 4. 文件追加演示
    printf("\n4. 文件追加演示：\n");
    append_file_demo();
    
    // 5. 二进制文件演示
    printf("\n5. 二进制文件演示：\n");
    binary_file_demo();
    
    // 6. 文件定位演示
    printf("\n6. 文件定位演示：\n");
    file_position_demo();
    
    // 7. 文件复制演示
    printf("\n7. 文件复制演示：\n");
    copy_file("sample.txt", "copy.txt");
    
    // 8. 文件统计演示
    printf("\n8. 文件统计演示：\n");
    count_file_stats("sample.txt");
    
    printf("\n=== 文件操作演示完成 ===\n");
    return 0;
}

// 创建示例文件
void create_sample_file(void) {
    FILE *fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        perror("   无法创建示例文件");
        return;
    }
    
    fprintf(fp, "这是第一行文本\n");
    fprintf(fp, "这是第二行文本\n");
    fprintf(fp, "这是第三行文本\n");
    fprintf(fp, "数字: 123, 浮点数: 3.14\n");
    fprintf(fp, "最后一行\n");
    
    fclose(fp);
    printf("   示例文件 'sample.txt' 创建成功\n");
}

// 文件读取演示
void read_file_demo(void) {
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        perror("   无法打开文件进行读取");
        return;
    }
    
    printf("   逐行读取文件内容:\n");
    char line[256];
    int line_num = 1;
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("     第%d行: %s", line_num++, line);
    }
    
    if (feof(fp)) {
        printf("   文件读取完成\n");
    } else if (ferror(fp)) {
        printf("   文件读取出错\n");
    }
    
    fclose(fp);
}

// 文件写入演示
void write_file_demo(void) {
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("   无法创建输出文件");
        return;
    }
    
    // 获取当前时间
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    
    fprintf(fp, "文件创建时间: %s", time_str);
    fprintf(fp, "这是写入的第一行\n");
    fprintf(fp, "数字: %d, 浮点数: %.2f\n", 42, 3.14159);
    
    // 使用fputs写入字符串
    fputs("使用fputs写入的行\n", fp);
    
    // 使用fputc写入字符
    fputs("字符序列: ", fp);
    for (char c = 'A'; c <= 'E'; c++) {
        fputc(c, fp);
    }
    fputc('\n', fp);
    
    fclose(fp);
    printf("   输出文件 'output.txt' 创建成功\n");
}

// 文件追加演示
void append_file_demo(void) {
    FILE *fp = fopen("output.txt", "a");
    if (fp == NULL) {
        perror("   无法打开文件进行追加");
        return;
    }
    
    fprintf(fp, "\n--- 追加的内容 ---\n");
    fprintf(fp, "这是追加的第一行\n");
    fprintf(fp, "这是追加的第二行\n");
    
    fclose(fp);
    printf("   内容已追加到 'output.txt'\n");
}

// 二进制文件演示
void binary_file_demo(void) {
    // 写入二进制数据
    FILE *fp = fopen("data.bin", "wb");
    if (fp == NULL) {
        perror("   无法创建二进制文件");
        return;
    }
    
    int numbers[] = {10, 20, 30, 40, 50};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);
    
    size_t written = fwrite(numbers, sizeof(int), count, fp);
    fclose(fp);
    
    printf("   写入 %zu 个整数到二进制文件\n", written);
    
    // 读取二进制数据
    fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        perror("   无法打开二进制文件");
        return;
    }
    
    int read_numbers[5];
    size_t read_count = fread(read_numbers, sizeof(int), count, fp);
    fclose(fp);
    
    printf("   从二进制文件读取 %zu 个整数: ", read_count);
    for (size_t i = 0; i < read_count; i++) {
        printf("%d ", read_numbers[i]);
    }
    printf("\n");
}

// 文件定位演示
void file_position_demo(void) {
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        perror("   无法打开文件");
        return;
    }
    
    printf("   文件定位演示:\n");
    
    // 读取第一个字符
    int c = fgetc(fp);
    printf("     第一个字符: '%c', 位置: %ld\n", c, ftell(fp));
    
    // 移动到文件中间
    fseek(fp, 10, SEEK_SET);
    printf("     移动到位置10, 当前位置: %ld\n", ftell(fp));
    
    // 读取当前字符
    c = fgetc(fp);
    printf("     位置10的字符: '%c'\n", c);
    
    // 移动到文件末尾
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    printf("     文件大小: %ld 字节\n", file_size);
    
    // 回到文件开头
    rewind(fp);
    printf("     回到文件开头, 位置: %ld\n", ftell(fp));
    
    fclose(fp);
}

// 文件复制功能
void copy_file(const char *source, const char *dest) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("   无法打开源文件");
        return;
    }
    
    FILE *dst = fopen(dest, "wb");
    if (dst == NULL) {
        perror("   无法创建目标文件");
        fclose(src);
        return;
    }
    
    char buffer[1024];
    size_t bytes;
    size_t total_bytes = 0;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
        total_bytes += bytes;
    }
    
    fclose(src);
    fclose(dst);
    
    printf("   文件复制完成: %s -> %s (%zu 字节)\n", source, dest, total_bytes);
}

// 文件统计功能
void count_file_stats(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("   无法打开文件进行统计");
        return;
    }
    
    int lines = 0, words = 0, chars = 0;
    int in_word = 0;
    int c;
    
    while ((c = fgetc(fp)) != EOF) {
        chars++;
        
        if (c == '\n') {
            lines++;
        }
        
        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    
    fclose(fp);
    
    printf("   文件 '%s' 统计:\n", filename);
    printf("     行数: %d\n", lines);
    printf("     单词数: %d\n", words);
    printf("     字符数: %d\n", chars);
}
