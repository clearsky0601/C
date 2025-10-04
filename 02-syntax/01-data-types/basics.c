#include "types_demo.h"
#include <limits.h>
#include <float.h>
#include <stdbool.h>


/**
 * @file basics.c
 * @brief C 语言基础数据类型演示代码。
 *
 * 本文件包含如下内容：
 * - 常见数据类型（char, int, unsigned int, short, long, float, double, _Bool）的声明与初始化。
 * - 使用 printf 输出各类型的值及其所占字节数。
 * - 展示各类型的取值范围（limits）。
 * - 演示符号与无符号类型的溢出行为。
 *
 * 适用场景：
 * - C 语言初学者学习数据类型的声明、初始化和基本操作。
 * - 参考各类型的取值范围和内存占用。
 *
 * 用法：
 * - 调用 demo_basics() 函数即可运行所有演示代码。
 *
 * @author [你的名字]
 * @date [日期]
 */

void demo_basics(void) {
    //1. ===定义与初始化===
    char c = 'A';
    int i = -42;
    unsigned int u = 42u;
    short s = 123;
    long l = 1234567890L;
    // 声明一个浮点型变量 f，并赋值为 3.14。
    // 在数值 3.14 后面加上 'f'，表示这是一个 float 类型的常量。
    // 如果不加 'f'，3.14 默认会被当作 double 类型，赋值给 float 时可能会有类型转换警告或精度损失。
    // 加 'f' 可以确保常量类型与变量类型一致，避免不必要的类型转换。
    float f = 3.14f;
    double d = 2.718281828;
    _Bool b = 1; // C99: boolean-like type


    //2.  ====输出各个数据类型的值和大小====
    printf("Basic data types and their sizes:\n");

    // 输出 char 类型的值和大小
    printf("char: %c (size=%zu)\n", c, sizeof(c)); // %z 是长度修饰符，u 表示无符号十进制整数

    // 输出 int 类型的值和大小
    printf("int: %d (size=%zu)\n", i, sizeof(i));

    // 输出 unsigned int 类型的值和大小
    printf("unsigned int: %u (size=%zu)\n", u, sizeof(u));

    // 输出 short 类型的值和大小
    printf("short: %d (size=%zu)\n", s, sizeof(s));

    // 输出 long 类型的值和大小
    printf("long: %ld (size=%zu)\n", l, sizeof(l));

    // 输出 float 类型的值和大小，DBL_DIG 表示 double 类型的有效数字位数
    printf("float: %f (size=%zu, DBL_DIG=%d)\n", f, sizeof(f), DBL_DIG);

    // 输出 double 类型的值和大小，DBL_DIG 同上
    printf("double: %f (size=%zu, DBL_DIG=%d)\n", d, sizeof(d), DBL_DIG);

    // 输出 _Bool 类型的值和大小
    printf("_Bool: %d (size=%zu)\n", b, sizeof(b));

    // 3.=== 输出各种类型的取值范围和示例 ===
    printf("\nLimits and examples:\n");
    
    // 以下宏均来自标准头文件 <limits.h> 和 <float.h>，用于表示各数据类型的取值范围。
    // 它们不是变量，而是由编译器在编译时定义的常量宏，无需手动定义。
    // 只需包含对应头文件即可直接使用。

    printf("CHAR_MIN=%d CHAR_MAX=%d\n", CHAR_MIN, CHAR_MAX); // char 类型的最小值和最大值 (<limits.h>)
    printf("INT_MIN=%d INT_MAX=%d\n", INT_MIN, INT_MAX);     // int 类型的最小值和最大值 (<limits.h>)
    printf("UINT_MAX=%u\n", UINT_MAX);                       // unsigned int 类型的最大值 (<limits.h>)
    printf("FLT_MAX=%e DBL_MAX=%e\n", FLT_MAX, DBL_MAX);     // float 和 double 类型的最大值 (<float.h>, 科学计数法输出)



    /* 示例：符号与无符号的意外行为 */
    unsigned int zero = 0u; // 后面的 'u' 表示这是一个 unsigned int 类型的常量，避免类型不匹配或隐式转换
    printf("zero - 1 (unsigned underflow) = %u\n", zero - 1u);

    /* 溢出示例（未定义行为）——仅演示，不推荐在实际代码中依赖此行为 */
    int big = INT_MAX;
    printf("INT_MAX = %d, INT_MAX + 1 (可能溢出) = %d\n", big, big + 1);
}
