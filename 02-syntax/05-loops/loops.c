/*
 * C语言循环结构演示程序
 * 
 * 功能：
 * 1. 演示for循环的各种用法
 * 2. 展示while和do-while循环
 * 3. 演示break和continue语句
 * 4. 展示嵌套循环的应用
 */

#include <stdio.h>

int main() {
    printf("=== C语言循环结构演示 ===\n\n");
    
    // 1. 基本for循环
    printf("1. 基本for循环：\n");
    printf("   数字1到5: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 2. 倒序for循环
    printf("\n2. 倒序for循环：\n");
    printf("   数字5到1: ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 3. 步长不为1的for循环
    printf("\n3. 步长为2的for循环：\n");
    printf("   偶数2到10: ");
    for (int i = 2; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 4. while循环演示
    printf("\n4. while循环：\n");
    printf("   2的幂次: ");
    int power = 1;
    int count = 0;
    while (count < 6) {
        printf("%d ", power);
        power *= 2;
        count++;
    }
    printf("\n");
    
    // 5. do-while循环演示
    printf("\n5. do-while循环：\n");
    printf("   至少执行一次: ");
    int num = 10;
    do {
        printf("%d ", num);
        num--;
    } while (num > 10);  // 条件为假，但至少执行一次
    printf("(条件为假，但执行了一次)\n");
    
    // 6. break语句演示
    printf("\n6. break语句：\n");
    printf("   寻找第一个大于50的平方数: ");
    for (int i = 1; i <= 10; i++) {
        int square = i * i;
        if (square > 50) {
            printf("%d^2 = %d\n", i, square);
            break;  // 找到后立即退出循环
        }
    }
    
    // 7. continue语句演示
    printf("\n7. continue语句：\n");
    printf("   1到10中的奇数: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // 跳过偶数
        }
        printf("%d ", i);
    }
    printf("\n");
    
    // 8. 嵌套循环 - 乘法表
    printf("\n8. 嵌套循环 - 乘法表（部分）：\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("   %d × %d = %2d", i, j, i * j);
        }
        printf("\n");
    }
    
    // 9. 嵌套循环 - 图案绘制
    printf("\n9. 图案绘制：\n");
    printf("   直角三角形：\n");
    for (int i = 1; i <= 5; i++) {
        printf("   ");
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    printf("\n   等腰三角形：\n");
    for (int i = 1; i <= 4; i++) {
        // 打印空格
        for (int j = 1; j <= 4 - i; j++) {
            printf(" ");
        }
        // 打印星号
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // 10. 数学计算 - 阶乘
    printf("\n10. 数学计算 - 阶乘：\n");
    int n = 5;
    long factorial = 1;
    printf("    %d! = ", n);
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%d", i);
        if (i < n) printf(" × ");
    }
    printf(" = %ld\n", factorial);
    
    // 11. 数学计算 - 斐波那契数列
    printf("\n11. 斐波那契数列（前10项）：\n");
    printf("    ");
    int fib1 = 0, fib2 = 1;
    printf("%d %d ", fib1, fib2);
    for (int i = 2; i < 10; i++) {
        int next = fib1 + fib2;
        printf("%d ", next);
        fib1 = fib2;
        fib2 = next;
    }
    printf("\n");
    
    // 12. 循环中的多重控制
    printf("\n12. 多重控制示例：\n");
    printf("    寻找1到20中能被3整除但不能被6整除的数: ");
    for (int i = 1; i <= 20; i++) {
        if (i % 3 != 0) {
            continue;  // 不能被3整除，跳过
        }
        if (i % 6 == 0) {
            continue;  // 能被6整除，跳过
        }
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
