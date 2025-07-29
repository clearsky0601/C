/*
 * C语言控制结构演示程序
 * 
 * 功能：
 * 1. 演示if-else条件语句
 * 2. 展示switch-case语句
 * 3. 演示嵌套控制结构
 * 4. 展示条件运算符的使用
 */

#include <stdio.h>

int main() {
    printf("=== C语言控制结构演示 ===\n\n");
    
    // 1. 基本if语句演示
    printf("1. 基本if语句：\n");
    int score = 85;
    printf("   学生成绩: %d\n", score);
    
    if (score >= 90) {
        printf("   等级: 优秀\n");
    } else if (score >= 80) {
        printf("   等级: 良好\n");
    } else if (score >= 70) {
        printf("   等级: 中等\n");
    } else if (score >= 60) {
        printf("   等级: 及格\n");
    } else {
        printf("   等级: 不及格\n");
    }
    
    // 2. switch语句演示
    printf("\n2. switch语句：\n");
    char grade = 'B';
    printf("   等级: %c\n", grade);
    
    switch (grade) {
        case 'A':
        case 'a':
            printf("   评价: 优秀！继续保持！\n");
            break;
        case 'B':
        case 'b':
            printf("   评价: 良好！还有进步空间！\n");
            break;
        case 'C':
        case 'c':
            printf("   评价: 中等，需要努力！\n");
            break;
        case 'D':
        case 'd':
            printf("   评价: 及格，要加油了！\n");
            break;
        case 'F':
        case 'f':
            printf("   评价: 不及格，需要重修！\n");
            break;
        default:
            printf("   评价: 无效等级！\n");
            break;
    }
    
    // 3. 嵌套if语句演示
    printf("\n3. 嵌套if语句：\n");
    int age = 20;
    int has_license = 1;  // 1表示有驾照，0表示没有
    
    printf("   年龄: %d, 有驾照: %s\n", age, has_license ? "是" : "否");
    
    if (age >= 18) {
        printf("   年龄符合要求\n");
        if (has_license) {
            printf("   可以开车！\n");
        } else {
            printf("   需要先考驾照\n");
        }
    } else {
        printf("   年龄不够，不能开车\n");
    }
    
    // 4. 逻辑运算符演示
    printf("\n4. 逻辑运算符：\n");
    int x = 5, y = 10, z = 15;
    printf("   x = %d, y = %d, z = %d\n", x, y, z);
    
    if (x < y && y < z) {
        printf("   x < y < z: 真\n");
    }
    
    if (x > 0 || y < 0) {
        printf("   x > 0 或 y < 0: 真\n");
    }
    
    if (!(x > y)) {
        printf("   x 不大于 y: 真\n");
    }
    
    // 5. 条件运算符演示
    printf("\n5. 条件运算符：\n");
    int a = 15, b = 25;
    printf("   a = %d, b = %d\n", a, b);
    
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    printf("   最大值: %d\n", max);
    printf("   最小值: %d\n", min);
    
    // 嵌套条件运算符
    char *result = (a > b) ? "a更大" : (a < b) ? "b更大" : "相等";
    printf("   比较结果: %s\n", result);
    
    // 6. 复杂条件判断演示
    printf("\n6. 复杂条件判断：\n");
    int year = 2024;
    printf("   年份: %d\n", year);
    
    // 判断闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("   %d年是闰年\n", year);
    } else {
        printf("   %d年不是闰年\n", year);
    }
    
    // 7. switch的fall-through特性演示
    printf("\n7. switch的fall-through特性：\n");
    int month = 3;
    printf("   月份: %d\n", month);
    
    switch (month) {
        case 12:
        case 1:
        case 2:
            printf("   季节: 冬季\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("   季节: 春季\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("   季节: 夏季\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("   季节: 秋季\n");
            break;
        default:
            printf("   无效月份\n");
            break;
    }
    
    // 8. 短路求值演示
    printf("\n8. 短路求值：\n");
    int num = 0;
    printf("   num = %d\n", num);
    
    // && 短路：如果第一个条件为假，不会执行第二个条件
    if (num != 0 && 10 / num > 2) {
        printf("   条件成立\n");
    } else {
        printf("   避免了除零错误（短路求值）\n");
    }
    
    return 0;
}
