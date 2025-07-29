/*
 * C语言字符串处理演示程序
 * 
 * 功能：
 * 1. 演示字符串的不同表示方法
 * 2. 展示标准字符串函数的使用
 * 3. 演示字符串查找和处理
 * 4. 展示字符串安全编程实践
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 自定义字符串函数声明
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);
void to_uppercase(char *str);
void to_lowercase(char *str);
int count_words(const char *str);
void reverse_string(char *str);

int main() {
    printf("=== C语言字符串处理演示 ===\n\n");
    
    // 1. 字符串的不同表示方法
    printf("1. 字符串表示方法：\n");
    char str1[] = "Hello";                    // 字符数组
    char str2[20] = "World";                  // 固定大小数组
    char *str3 = "C Programming";             // 字符串指针
    char str4[] = {'H', 'i', '\0'};          // 字符数组初始化
    
    printf("   str1 (数组): %s, 长度: %zu\n", str1, strlen(str1));
    printf("   str2 (固定): %s, 长度: %zu\n", str2, strlen(str2));
    printf("   str3 (指针): %s, 长度: %zu\n", str3, strlen(str3));
    printf("   str4 (字符): %s, 长度: %zu\n", str4, strlen(str4));
    
    // 2. 基本字符串操作
    printf("\n2. 基本字符串操作：\n");
    char source[] = "Hello, World!";
    char destination[50];
    
    // 字符串复制
    strcpy(destination, source);
    printf("   复制后: %s\n", destination);
    
    // 字符串连接
    strcat(destination, " Welcome to C!");
    printf("   连接后: %s\n", destination);
    
    // 字符串比较
    char str_a[] = "Apple";
    char str_b[] = "Banana";
    int cmp_result = strcmp(str_a, str_b);
    printf("   比较 \"%s\" 和 \"%s\": %d (%s)\n", 
           str_a, str_b, cmp_result, 
           cmp_result < 0 ? "str_a < str_b" : 
           cmp_result > 0 ? "str_a > str_b" : "相等");
    
    // 3. 字符串查找
    printf("\n3. 字符串查找：\n");
    char text[] = "The quick brown fox jumps over the lazy dog";
    
    // 查找字符
    char *char_pos = strchr(text, 'q');
    if (char_pos != NULL) {
        printf("   字符 'q' 在位置: %ld\n", char_pos - text);
    }
    
    // 查找子字符串
    char *substr_pos = strstr(text, "fox");
    if (substr_pos != NULL) {
        printf("   子串 \"fox\" 在位置: %ld\n", substr_pos - text);
    }
    
    // 查找最后出现的字符
    char *last_pos = strrchr(text, 'o');
    if (last_pos != NULL) {
        printf("   最后的 'o' 在位置: %ld\n", last_pos - text);
    }
    
    // 4. 字符串转换
    printf("\n4. 字符串转换：\n");
    char mixed_case[] = "Hello World 123";
    char upper_case[50], lower_case[50];
    
    strcpy(upper_case, mixed_case);
    strcpy(lower_case, mixed_case);
    
    to_uppercase(upper_case);
    to_lowercase(lower_case);
    
    printf("   原字符串: %s\n", mixed_case);
    printf("   大写转换: %s\n", upper_case);
    printf("   小写转换: %s\n", lower_case);
    
    // 5. 数字字符串转换
    printf("\n5. 数字字符串转换：\n");
    char num_str1[] = "12345";
    char num_str2[] = "3.14159";
    char num_str3[] = "100abc";  // 部分数字
    
    int int_val = atoi(num_str1);
    double double_val = atof(num_str2);
    int partial_val = atoi(num_str3);
    
    printf("   \"%s\" -> %d\n", num_str1, int_val);
    printf("   \"%s\" -> %.5f\n", num_str2, double_val);
    printf("   \"%s\" -> %d (部分转换)\n", num_str3, partial_val);
    
    // 6. 自定义字符串函数
    printf("\n6. 自定义字符串函数：\n");
    char test_str[] = "Programming is fun!";
    
    printf("   原字符串: %s\n", test_str);
    printf("   自定义长度函数: %d\n", my_strlen(test_str));
    printf("   单词计数: %d\n", count_words(test_str));
    
    // 字符串反转
    char reverse_test[] = "Hello";
    printf("   反转前: %s\n", reverse_test);
    reverse_string(reverse_test);
    printf("   反转后: %s\n", reverse_test);
    
    // 7. 字符串数组
    printf("\n7. 字符串数组：\n");
    char *languages[] = {"C", "Python", "Java", "JavaScript", "Go"};
    int lang_count = sizeof(languages) / sizeof(languages[0]);
    
    printf("   编程语言列表:\n");
    for (int i = 0; i < lang_count; i++) {
        printf("     %d. %s (长度: %zu)\n", i+1, languages[i], strlen(languages[i]));
    }
    
    // 8. 字符分类
    printf("\n8. 字符分类：\n");
    char sample[] = "Hello123!@#";
    int letters = 0, digits = 0, others = 0;
    
    for (int i = 0; sample[i] != '\0'; i++) {
        if (isalpha(sample[i])) {
            letters++;
        } else if (isdigit(sample[i])) {
            digits++;
        } else {
            others++;
        }
    }
    
    printf("   字符串 \"%s\" 包含:\n", sample);
    printf("     字母: %d个\n", letters);
    printf("     数字: %d个\n", digits);
    printf("     其他: %d个\n", others);
    
    // 9. 安全字符串操作
    printf("\n9. 安全字符串操作：\n");
    char safe_dest[20];
    char long_source[] = "This is a very long string that might overflow";
    
    // 使用安全的复制函数
    strncpy(safe_dest, long_source, sizeof(safe_dest) - 1);
    safe_dest[sizeof(safe_dest) - 1] = '\0';  // 确保字符串终止
    
    printf("   安全复制结果: %s\n", safe_dest);
    printf("   原字符串长度: %zu, 复制长度: %zu\n", 
           strlen(long_source), strlen(safe_dest));
    
    return 0;
}

// 自定义字符串函数实现

// 计算字符串长度
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 字符串复制
void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 转换为大写
void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// 转换为小写
void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// 计算单词数量
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    
    return count;
}

// 反转字符串
void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
