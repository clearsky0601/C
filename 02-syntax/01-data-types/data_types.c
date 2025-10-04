/*
 * C语言数据类型演示程序
 * 
 * 功能：
 * 1. 展示各种基本数据类型
 * 2. 演示变量声明和初始化
 * 3. 显示类型大小和范围
 * 4. 演示类型转换
 */

#include <stdio.h>
#include <limits.h>  // 整数类型的限制
#include <float.h>   // 浮点类型的限制

// 全局常量定义
#define PI 3.14159
const int GLOBAL_CONST = 100;

// 全局变量
int global_var = 42;

int main() {
    printf("=== C语言数据类型演示 ===\n\n");
    
    // 1. 整数类型演示
    printf("1. 整数类型：\n");
    char c = 'A';
    short s = 1000;
    int i = 50000;
    long l = 1000000L;
    long long ll = 1000000000LL;
    
    printf("   char c = '%c' (值: %d, 大小: %zu字节)\n", c, c, sizeof(c));
    printf("   short s = %d (大小: %zu字节)\n", s, sizeof(s));
    printf("   int i = %d (大小: %zu字节)\n", i, sizeof(i));
    printf("   long l = %ld (大小: %zu字节)\n", l, sizeof(l));
    printf("   long long ll = %lld (大小: %zu字节)\n", ll, sizeof(ll));
    
    // 2. 无符号整数类型
    printf("\n2. 无符号整数类型：\n");
    unsigned char uc = 255;
    unsigned int ui = 4000000000U;
    
    printf("   unsigned char uc = %u (大小: %zu字节)\n", uc, sizeof(uc));
    printf("   unsigned int ui = %u (大小: %zu字节)\n", ui, sizeof(ui));
    
    // 3. 浮点类型演示
    printf("\n3. 浮点类型：\n");
    float f = 3.14159f; // 单精度浮点数
    double d = 3.141592653589793; // 双精度浮点数
    long double ld = 3.141592653589793238L;
    
    printf("   float f = %.6f (大小: %zu字节)\n", f, sizeof(f));
    printf("   double d = %.15f (大小: %zu字节)\n", d, sizeof(d));
    printf("   long double ld = %.18Lf (大小: %zu字节)\n", ld, sizeof(ld));
    
    // 4. 类型范围演示
    printf("\n4. 类型范围：\n");
    printf("   int 范围: %d 到 %d\n", INT_MIN, INT_MAX);
    printf("   unsigned int 范围: 0 到 %u\n", UINT_MAX);
    printf("   float 精度: %d位有效数字\n", FLT_DIG);
    printf("   double 精度: %d位有效数字\n", DBL_DIG);
    
    // 5. 常量演示
    printf("\n5. 常量：\n");
    printf("   宏定义常量 PI = %.5f\n", PI);
    printf("   const常量 GLOBAL_CONST = %d\n", GLOBAL_CONST);
    printf("   全局变量 global_var = %d\n", global_var);
    
    // 6. 类型转换演示
    printf("\n6. 类型转换：\n");
    int int_val = 10;
    float float_val = 3.7f;
    
    printf("   隐式转换: int %d + float %.1f = %.1f\n", 
           int_val, float_val, int_val + float_val);
    printf("   显式转换: (int)%.1f = %d\n", float_val, (int)float_val);
    printf("   字符转换: 'A' = %d, %d = '%c'\n", 'A', 65, 65);
    
    // 7. 局部变量作用域演示
    printf("\n7. 变量作用域：\n");
    {
        int local_var = 999;  // 块作用域变量
        printf("   块内局部变量: %d\n", local_var);
    }
    // local_var 在这里不可访问
    
    printf("   全局变量在函数内: %d\n", global_var);
    
    return 0;
}
