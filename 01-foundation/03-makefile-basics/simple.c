/*
 * 简单的C程序 - 用于演示Makefile基础
 * 
 * 这是一个简单的计算器程序，演示：
 * 1. 基本的输入输出
 * 2. 简单的数学运算
 * 3. 单文件程序的编译
 */

#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;
    
    printf("=== 简单计算器 ===\n");
    printf("请输入第一个数字: ");
    scanf("%lf", &num1);
    
    printf("请输入运算符 (+, -, *, /): ");
    scanf(" %c", &operator);  // 注意空格，用于跳过前面的换行符
    
    printf("请输入第二个数字: ");
    scanf("%lf", &num2);
    
    // 根据运算符进行计算
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("错误：除数不能为零！\n");
                return 1;
            }
            break;
        default:
            printf("错误：不支持的运算符 '%c'\n", operator);
            return 1;
    }
    
    return 0;
}
