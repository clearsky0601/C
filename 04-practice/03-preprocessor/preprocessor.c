/*
 * C语言预处理器演示程序
 * 
 * 功能：
 * 1. 演示各种预处理器指令
 * 2. 展示宏定义和条件编译
 * 3. 演示预定义宏的使用
 * 4. 展示预处理器的高级技巧
 */

#include <stdio.h>
#include <stdlib.h>

// 简单宏定义
#define PI 3.14159
#define MAX_SIZE 100
#define PROGRAM_NAME "预处理器演示"

// 函数式宏
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))

// 多行宏
#define SWAP(a,b) do { \
    typeof(a) temp = a; \
    a = b; \
    b = temp; \
} while(0)

// 字符串化宏
#define STR(x) #x
#define XSTR(x) STR(x)

// 连接宏
#define CONCAT(a,b) a##b

// 调试宏
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) \
        printf("[DEBUG %s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) // 空宏
#endif

// 日志宏
#define LOG_INFO(msg) \
    printf("[INFO] %s - %s:%d - %s\n", __TIME__, __FILE__, __LINE__, msg)

#define LOG_ERROR(msg) \
    printf("[ERROR] %s - %s:%d - %s\n", __TIME__, __FILE__, __LINE__, msg)

// 条件编译示例
#define VERSION 2

#if VERSION >= 2
    #define FEATURE_ADVANCED 1
    #define VERSION_STRING "v2.0+"
#else
    #define FEATURE_ADVANCED 0
    #define VERSION_STRING "v1.x"
#endif

// 平台检测
#ifdef __APPLE__
    #define PLATFORM "macOS"
#elif defined(__linux__)
    #define PLATFORM "Linux"
#elif defined(_WIN32)
    #define PLATFORM "Windows"
#else
    #define PLATFORM "Unknown"
#endif

// 编译器检测
#ifdef __clang__
    #define COMPILER "Clang " __clang_version__
#elif defined(__GNUC__)
    #define COMPILER "GCC " XSTR(__GNUC__) "." XSTR(__GNUC_MINOR__)
#else
    #define COMPILER "Unknown"
#endif

// 函数声明
void demonstrate_simple_macros(void);
void demonstrate_function_macros(void);
void demonstrate_conditional_compilation(void);
void demonstrate_predefined_macros(void);
void demonstrate_advanced_techniques(void);

int main() {
    printf("=== %s ===\n\n", PROGRAM_NAME);
    
    // 1. 简单宏演示
    printf("1. 简单宏演示：\n");
    demonstrate_simple_macros();
    
    // 2. 函数式宏演示
    printf("\n2. 函数式宏演示：\n");
    demonstrate_function_macros();
    
    // 3. 条件编译演示
    printf("\n3. 条件编译演示：\n");
    demonstrate_conditional_compilation();
    
    // 4. 预定义宏演示
    printf("\n4. 预定义宏演示：\n");
    demonstrate_predefined_macros();
    
    // 5. 高级技巧演示
    printf("\n5. 高级技巧演示：\n");
    demonstrate_advanced_techniques();
    
    printf("\n=== 预处理器演示完成 ===\n");
    return 0;
}

// 简单宏演示
void demonstrate_simple_macros(void) {
    printf("   PI = %f\n", PI);
    printf("   MAX_SIZE = %d\n", MAX_SIZE);
    printf("   程序名称: %s\n", PROGRAM_NAME);
    
    // 使用宏定义的数组
    int array[MAX_SIZE];
    printf("   使用MAX_SIZE定义的数组大小: %zu\n", sizeof(array)/sizeof(array[0]));
    
    // 计算圆的面积
    double radius = 5.0;
    double area = PI * radius * radius;
    printf("   半径%.1f的圆面积: %.2f\n", radius, area);
}

// 函数式宏演示
void demonstrate_function_macros(void) {
    int a = 10, b = 20;
    printf("   a = %d, b = %d\n", a, b);
    printf("   MAX(a, b) = %d\n", MAX(a, b));
    printf("   MIN(a, b) = %d\n", MIN(a, b));
    
    int x = -5;
    printf("   x = %d\n", x);
    printf("   SQUARE(x) = %d\n", SQUARE(x));
    printf("   ABS(x) = %d\n", ABS(x));
    
    // 交换变量
    printf("   交换前: a = %d, b = %d\n", a, b);
    SWAP(a, b);
    printf("   交换后: a = %d, b = %d\n", a, b);
    
    // 演示宏的副作用问题
    int i = 5;
    printf("   i = %d\n", i);
    printf("   SQUARE(++i) = %d (注意副作用！)\n", SQUARE(++i));
    printf("   现在 i = %d\n", i);
}

// 条件编译演示
void demonstrate_conditional_compilation(void) {
    printf("   程序版本: %s\n", VERSION_STRING);
    printf("   版本号: %d\n", VERSION);
    
#if FEATURE_ADVANCED
    printf("   高级功能: 已启用\n");
    printf("   这是高级功能的代码\n");
#else
    printf("   高级功能: 未启用\n");
#endif
    
    printf("   运行平台: %s\n", PLATFORM);
    printf("   编译器: %s\n", COMPILER);
    
    // 调试信息
    DEBUG_PRINT("这是调试信息");
    DEBUG_PRINT("变量值: %d", 42);
    
    // 日志信息
    LOG_INFO("程序正常运行");
    LOG_ERROR("这是一个错误示例");
}

// 预定义宏演示
void demonstrate_predefined_macros(void) {
    printf("   当前文件: %s\n", __FILE__);
    printf("   当前行号: %d\n", __LINE__);
    printf("   编译日期: %s\n", __DATE__);
    printf("   编译时间: %s\n", __TIME__);
    printf("   当前函数: %s\n", __FUNCTION__);
    
    // C标准版本
#ifdef __STDC_VERSION__
    printf("   C标准版本: %ld\n", __STDC_VERSION__);
#endif
    
    // 编译器特定信息
#ifdef __clang__
    printf("   Clang版本: %s\n", __clang_version__);
#endif
    
#ifdef __GNUC__
    printf("   GCC版本: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif
}

// 高级技巧演示
void demonstrate_advanced_techniques(void) {
    // 字符串化
    int value = 42;
    printf("   字符串化: " STR(value) " = %d\n", value);
    printf("   宏展开字符串化: PI = " XSTR(PI) "\n");
    
    // 连接符
    int CONCAT(var, 1) = 100;
    int CONCAT(var, 2) = 200;
    printf("   连接符创建的变量: var1 = %d, var2 = %d\n", var1, var2);
    
    // 可变参数宏（如果支持）
#ifdef DEBUG
    DEBUG_PRINT("可变参数宏测试");
    DEBUG_PRINT("数值: %d, 字符串: %s", 123, "test");
#endif
    
    // 条件表达式宏
    int num1 = 15, num2 = 25;
    printf("   条件宏: MAX(%d, %d) = %d\n", num1, num2, MAX(num1, num2));
    
    // 类型安全检查（编译时）
    #define TYPE_CHECK(type, var) \
        ((void)(&(var) == (type*)0))
    
    int test_int = 10;
    TYPE_CHECK(int, test_int);  // 编译时类型检查
    printf("   类型检查通过\n");
    
    // 数组大小宏
    #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
    int test_array[] = {1, 2, 3, 4, 5};
    printf("   数组大小宏: ARRAY_SIZE = %zu\n", ARRAY_SIZE(test_array));
}
