/*
 * 多文件项目主程序 - 用于演示高级Makefile
 * 
 * 这个程序演示：
 * 1. 多文件项目结构
 * 2. 头文件的使用
 * 3. 函数的分离和调用
 */

#include <stdio.h>
#include "utils.h"

int main() {
    printf("=== Makefile高级示例 ===\n\n");
    
    // 测试数学工具函数
    printf("1. 数学工具测试：\n");
    int a = 15, b = 25;
    printf("   %d + %d = %d\n", a, b, add(a, b));
    printf("   %d - %d = %d\n", a, b, subtract(a, b));
    printf("   %d * %d = %d\n", a, b, multiply(a, b));
    
    if (b != 0) {
        printf("   %d / %d = %.2f\n", a, b, divide(a, b));
    }
    
    // 测试字符串工具函数
    printf("\n2. 字符串工具测试：\n");
    char str[] = "Hello, Makefile!";
    printf("   原字符串: %s\n", str);
    printf("   字符串长度: %d\n", string_length(str));
    
    // 转换为大写
    to_uppercase(str);
    printf("   转为大写: %s\n", str);
    
    // 测试数组工具函数
    printf("\n3. 数组工具测试：\n");
    int numbers[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("   原数组: ");
    print_array(numbers, size);
    
    printf("   最大值: %d\n", find_max(numbers, size));
    printf("   最小值: %d\n", find_min(numbers, size));
    printf("   平均值: %.2f\n", calculate_average(numbers, size));
    
    printf("\n=== 程序结束 ===\n");
    return 0;
}
