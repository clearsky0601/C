/*
 * C语言函数演示程序
 * 
 * 功能：
 * 1. 演示函数的定义和调用
 * 2. 展示参数传递机制
 * 3. 演示递归函数
 * 4. 展示函数指针的使用
 */

#include <stdio.h>

// 函数声明（原型）
int add(int a, int b);
int subtract(int a, int b);
void print_separator(void);
void swap_by_value(int a, int b);
void swap_by_reference(int *a, int *b);
int factorial(int n);
int fibonacci(int n);
void counter(void);
int calculate(int a, int b, int (*operation)(int, int));

// 全局变量
int global_var = 100;

int main() {
    printf("=== C语言函数演示 ===\n\n");
    
    // 1. 基本函数调用
    printf("1. 基本函数调用：\n");
    int x = 10, y = 5;
    printf("   %d + %d = %d\n", x, y, add(x, y));
    printf("   %d - %d = %d\n", x, y, subtract(x, y));
    
    print_separator();
    
    // 2. 值传递演示
    printf("2. 值传递演示：\n");
    printf("   交换前: x = %d, y = %d\n", x, y);
    swap_by_value(x, y);
    printf("   交换后: x = %d, y = %d (值未改变)\n", x, y);
    
    print_separator();
    
    // 3. 地址传递演示
    printf("3. 地址传递演示：\n");
    printf("   交换前: x = %d, y = %d\n", x, y);
    swap_by_reference(&x, &y);
    printf("   交换后: x = %d, y = %d (值已改变)\n", x, y);
    
    print_separator();
    
    // 4. 递归函数演示
    printf("4. 递归函数演示：\n");
    int n = 5;
    printf("   %d! = %d\n", n, factorial(n));
    printf("   斐波那契数列第%d项 = %d\n", n, fibonacci(n));
    
    print_separator();
    
    // 5. 静态变量演示
    printf("5. 静态变量演示：\n");
    printf("   调用counter函数3次：\n");
    for (int i = 0; i < 3; i++) {
        printf("   ");
        counter();
    }
    
    print_separator();
    
    // 6. 函数指针演示
    printf("6. 函数指针演示：\n");
    int a = 20, b = 8;
    printf("   使用函数指针计算：\n");
    printf("   %d + %d = %d\n", a, b, calculate(a, b, add));
    printf("   %d - %d = %d\n", a, b, calculate(a, b, subtract));
    
    print_separator();
    
    // 7. 作用域演示
    printf("7. 作用域演示：\n");
    printf("   全局变量: %d\n", global_var);
    {
        int local_var = 50;  // 局部变量
        printf("   局部变量: %d\n", local_var);
        global_var = 200;    // 修改全局变量
    }
    printf("   修改后的全局变量: %d\n", global_var);
    
    return 0;
}

// 函数定义

// 加法函数
int add(int a, int b) {
    return a + b;
}

// 减法函数
int subtract(int a, int b) {
    return a - b;
}

// 打印分隔线
void print_separator(void) {
    printf("\n");
}

// 值传递的交换函数（不会真正交换）
void swap_by_value(int a, int b) {
    printf("   函数内交换: a = %d, b = %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("   函数内交换后: a = %d, b = %d\n", a, b);
}

// 地址传递的交换函数（真正交换）
void swap_by_reference(int *a, int *b) {
    printf("   函数内交换: *a = %d, *b = %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("   函数内交换后: *a = %d, *b = %d\n", *a, *b);
}

// 递归计算阶乘
int factorial(int n) {
    if (n <= 1) {
        return 1;  // 终止条件
    }
    return n * factorial(n - 1);  // 递归调用
}

// 递归计算斐波那契数
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // 终止条件
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // 递归调用
}

// 使用静态变量的计数器
void counter(void) {
    static int count = 0;  // 静态变量，保持状态
    count++;
    printf("调用次数: %d\n", count);
}

// 使用函数指针的计算器
int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);  // 调用传入的函数
}
