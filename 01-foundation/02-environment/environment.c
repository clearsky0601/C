/*
 * C语言开发环境检测程序
 * 
 * 功能：
 * 1. 检测编译器信息
 * 2. 显示C标准支持情况
 * 3. 检查系统基本信息
 * 4. 验证标准库功能
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("=== C语言开发环境检测 ===\n\n");
    
    // 1. 编译器信息
    printf("1. 编译器信息：\n");
    #ifdef __clang__
        printf("   编译器: Clang\n");
        printf("   版本: %s\n", __clang_version__);
    #elif defined(__GNUC__)
        printf("   编译器: GCC\n");
        printf("   版本: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #else
        printf("   编译器: 未知\n");
    #endif
    
    // 2. C标准支持
    printf("\n2. C标准支持：\n");
    #if __STDC_VERSION__ >= 201710L
        printf("   支持C17/C18标准\n");
    #elif __STDC_VERSION__ >= 201112L
        printf("   支持C11标准\n");
    #elif __STDC_VERSION__ >= 199901L
        printf("   支持C99标准\n");
    #elif __STDC_VERSION__ >= 199409L
        printf("   支持C95标准\n");
    #else
        printf("   支持C89/C90标准\n");
    #endif
    
    // 3. 系统信息
    printf("\n3. 系统信息：\n");
    #ifdef __APPLE__
        printf("   操作系统: macOS\n");
    #elif defined(__linux__)
        printf("   操作系统: Linux\n");
    #elif defined(_WIN32)
        printf("   操作系统: Windows\n");
    #else
        printf("   操作系统: 未知\n");
    #endif
    
    #ifdef __x86_64__
        printf("   架构: x86_64\n");
    #elif defined(__aarch64__) || defined(__arm64__)
        printf("   架构: ARM64 (Apple Silicon)\n");
    #else
        printf("   架构: 其他\n");
    #endif
    
    // 4. 基本功能测试
    printf("\n4. 基本功能测试：\n");
    
    // 时间函数测试
    time_t current_time = time(NULL);
    printf("   当前时间: %s", ctime(&current_time));
    
    // 内存分配测试
    int *test_ptr = malloc(sizeof(int));
    if (test_ptr != NULL) {
        *test_ptr = 42;
        printf("   内存分配: 成功 (测试值: %d)\n", *test_ptr);
        free(test_ptr);
    } else {
        printf("   内存分配: 失败\n");
    }
    
    printf("\n=== 环境检测完成 ===\n");
    printf("如果所有测试都通过，说明你的C语言开发环境配置正确！\n");
    
    return 0;
}
