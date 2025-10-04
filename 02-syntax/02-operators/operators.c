/*
 * C语言运算符演示程序
 * 
 * 功能：
 * 1. 演示各种运算符的使用
 * 2. 展示运算符优先级
 * 3. 比较前缀和后缀运算符
 * 4. 演示位运算操作
 */

#include <stdio.h>

int main() {
    printf("=== C语言运算符演示 ===\n\n");
    
    // 1. 算术运算符
    printf("1. 算术运算符：\n");
    int a = 15, b = 4;
    printf("   a = %d, b = %d\n", a, b);
    printf("   a + b = %d\n", a + b);
    printf("   a - b = %d\n", a - b);
    printf("   a * b = %d\n", a * b);
    printf("   a / b = %d (整数除法)\n", a / b);
    printf("   a %% b = %d (取模)\n", a % b);
    printf("   (double)a / b = %.2f (浮点除法)\n", (double)a / b);
    
    // 2. 关系运算符
    printf("\n2. 关系运算符：\n");
    printf("   a < b: %d\n", a < b);
    printf("   a > b: %d\n", a > b);
    printf("   a <= b: %d\n", a <= b);
    printf("   a >= b: %d\n", a >= b);
    printf("   a == b: %d\n", a == b);
    printf("   a != b: %d\n", a != b);
    
    // 3. 逻辑运算符
    printf("\n3. 逻辑运算符：\n");
    int x = 1, y = 0;
    printf("   x = %d, y = %d\n", x, y);
    printf("   x && y: %d\n", x && y);
    printf("   x || y: %d\n", x || y);
    printf("   !x: %d\n", !x);
    printf("   !y: %d\n", !y);
    
    // 4. 自增自减运算符
    printf("\n4. 自增自减运算符：\n");
    int i = 5, j = 5;
    printf("   初始值: i = %d, j = %d\n", i, j);
    printf("   ++i = %d (前缀自增)\n", ++i);
    printf("   j++ = %d (后缀自增)\n", j++);
    printf("   现在: i = %d, j = %d\n", i, j);
    
    // 5. 赋值运算符
    printf("\n5. 赋值运算符：\n");
    int num = 10;
    printf("   初始值: num = %d\n", num);
    num += 5;  printf("   num += 5: %d\n", num);
    num -= 3;  printf("   num -= 3: %d\n", num);
    num *= 2;  printf("   num *= 2: %d\n", num);
    num /= 4;  printf("   num /= 4: %d\n", num);
    num %= 3;  printf("   num %%= 3: %d\n", num);
    
    // 6. 位运算符
    printf("\n6. 位运算符：\n");
    unsigned char p = 12;  // 二进制: 00001100
    unsigned char q = 10;  // 二进制: 00001010
    printf("   p = %d (二进制: ", p);
    for(int bit = 7; bit >= 0; bit--) {
        printf("%d", (p >> bit) & 1);
    }
    printf(")\n");
    printf("   q = %d (二进制: ", q);
    for(int bit = 7; bit >= 0; bit--) {
        printf("%d", (q >> bit) & 1);
    }
    printf(")\n");
    
    printf("   p & q = %d (按位与)\n", p & q);
    printf("   p | q = %d (按位或)\n", p | q);
    printf("   p ^ q = %d (按位异或)\n", p ^ q);
    printf("   ~p = %d (按位取反)\n", (unsigned char)~p);
    printf("   p << 1 = %d (左移1位)\n", p << 1);
    printf("   p >> 1 = %d (右移1位)\n", p >> 1);
    
    // 7. 条件运算符。也叫三目运算符。
    printf("\n7. 条件运算符：\n");
    int max = (a > b) ? a : b;
    printf("   max = (a > b) ? a : b = %d\n", max);
    
    // 8. sizeof运算符
    printf("\n8. sizeof运算符：\n");
    printf("   sizeof(int) = %zu\n", sizeof(int));
    printf("   sizeof(a) = %zu\n", sizeof(a));
    printf("   sizeof(3.14) = %zu\n", sizeof(3.14));
    
    // 9. 运算符优先级演示
    printf("\n9. 运算符优先级：\n");
    int result1 = 2 + 3 * 4;        // 乘法优先级高于加法
    int result2 = (2 + 3) * 4;      // 括号改变优先级
    printf("   2 + 3 * 4 = %d\n", result1);
    printf("   (2 + 3) * 4 = %d\n", result2);
    
    // 10. 逗号运算符
    printf("\n10. 逗号运算符：\n");
    int m, n;
    int result = (m = 3, n = 4, m + n);  // 逗号运算符从左到右求值
    printf("    (m = 3, n = 4, m + n) = %d\n", result);
    
    return 0;
}
