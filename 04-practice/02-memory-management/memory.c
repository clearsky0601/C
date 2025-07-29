/*
 * C语言动态内存管理演示程序
 * 
 * 功能：
 * 1. 演示malloc、calloc、realloc、free的使用
 * 2. 展示动态数组和字符串的管理
 * 3. 演示常见的内存错误和避免方法
 * 4. 实现简单的内存管理工具
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 简单的内存统计结构
typedef struct {
    size_t total_allocated;
    size_t total_freed;
    int allocation_count;
    int free_count;
} MemoryStats;

// 全局内存统计
MemoryStats g_memory_stats = {0, 0, 0, 0};

// 函数声明
void* safe_malloc(size_t size);
void safe_free(void **ptr);
void print_memory_stats(void);
void demonstrate_basic_allocation(void);
void demonstrate_array_allocation(void);
void demonstrate_string_allocation(void);
void demonstrate_realloc(void);
void demonstrate_common_errors(void);
int* create_dynamic_array(int size, int initial_value);
char* create_dynamic_string(const char *source);

int main() {
    printf("=== C语言动态内存管理演示 ===\n\n");
    
    // 1. 基本内存分配演示
    printf("1. 基本内存分配演示：\n");
    demonstrate_basic_allocation();
    
    // 2. 动态数组演示
    printf("\n2. 动态数组演示：\n");
    demonstrate_array_allocation();
    
    // 3. 动态字符串演示
    printf("\n3. 动态字符串演示：\n");
    demonstrate_string_allocation();
    
    // 4. realloc演示
    printf("\n4. realloc演示：\n");
    demonstrate_realloc();
    
    // 5. 常见错误演示（注释掉的危险代码）
    printf("\n5. 常见错误和避免方法：\n");
    demonstrate_common_errors();
    
    // 6. 内存统计
    printf("\n6. 内存使用统计：\n");
    print_memory_stats();
    
    printf("\n=== 内存管理演示完成 ===\n");
    return 0;
}

// 安全的malloc包装函数
void* safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        g_memory_stats.total_allocated += size;
        g_memory_stats.allocation_count++;
        printf("   [内存] 分配 %zu 字节，地址: %p\n", size, ptr);
    } else {
        printf("   [错误] 内存分配失败！\n");
    }
    return ptr;
}

// 安全的free包装函数
void safe_free(void **ptr) {
    if (ptr != NULL && *ptr != NULL) {
        printf("   [内存] 释放地址: %p\n", *ptr);
        free(*ptr);
        *ptr = NULL;  // 避免悬空指针
        g_memory_stats.free_count++;
    }
}

// 打印内存统计信息
void print_memory_stats(void) {
    printf("   总分配次数: %d\n", g_memory_stats.allocation_count);
    printf("   总释放次数: %d\n", g_memory_stats.free_count);
    printf("   总分配字节: %zu\n", g_memory_stats.total_allocated);
    
    if (g_memory_stats.allocation_count != g_memory_stats.free_count) {
        printf("   [警告] 可能存在内存泄漏！\n");
    } else {
        printf("   [正常] 内存分配和释放平衡\n");
    }
}

// 基本内存分配演示
void demonstrate_basic_allocation(void) {
    // malloc演示
    int *int_ptr = (int*)safe_malloc(sizeof(int));
    if (int_ptr != NULL) {
        *int_ptr = 42;
        printf("   malloc分配的整数: %d\n", *int_ptr);
        safe_free((void**)&int_ptr);
    }
    
    // calloc演示
    int *zero_array = (int*)calloc(5, sizeof(int));
    if (zero_array != NULL) {
        printf("   calloc分配的数组 (自动初始化为0): ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", zero_array[i]);
        }
        printf("\n");
        safe_free((void**)&zero_array);
    }
}

// 动态数组演示
void demonstrate_array_allocation(void) {
    int size = 10;
    int *dynamic_array = create_dynamic_array(size, 5);
    
    if (dynamic_array != NULL) {
        printf("   动态数组内容: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", dynamic_array[i]);
        }
        printf("\n");
        
        // 修改数组内容
        for (int i = 0; i < size; i++) {
            dynamic_array[i] = i * i;
        }
        
        printf("   修改后的数组: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", dynamic_array[i]);
        }
        printf("\n");
        
        safe_free((void**)&dynamic_array);
    }
}

// 动态字符串演示
void demonstrate_string_allocation(void) {
    const char *original = "Hello, Dynamic Memory!";
    char *dynamic_string = create_dynamic_string(original);
    
    if (dynamic_string != NULL) {
        printf("   原字符串: %s\n", original);
        printf("   复制的字符串: %s\n", dynamic_string);
        printf("   字符串长度: %zu\n", strlen(dynamic_string));
        
        // 修改字符串
        strcat(dynamic_string, " - Modified");
        printf("   修改后: %s\n", dynamic_string);
        
        safe_free((void**)&dynamic_string);
    }
}

// realloc演示
void demonstrate_realloc(void) {
    int initial_size = 5;
    int *array = (int*)safe_malloc(sizeof(int) * initial_size);
    
    if (array != NULL) {
        // 初始化数组
        for (int i = 0; i < initial_size; i++) {
            array[i] = i + 1;
        }
        
        printf("   初始数组 (%d个元素): ", initial_size);
        for (int i = 0; i < initial_size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        
        // 扩展数组
        int new_size = 10;
        int *new_array = (int*)realloc(array, sizeof(int) * new_size);
        
        if (new_array != NULL) {
            array = new_array;  // 更新指针
            printf("   [内存] realloc扩展到 %d 个元素\n", new_size);
            
            // 初始化新元素
            for (int i = initial_size; i < new_size; i++) {
                array[i] = i + 1;
            }
            
            printf("   扩展后数组: ");
            for (int i = 0; i < new_size; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            
            safe_free((void**)&array);
        } else {
            printf("   [错误] realloc失败！\n");
            safe_free((void**)&array);  // 释放原内存
        }
    }
}

// 常见错误演示和避免方法
void demonstrate_common_errors(void) {
    printf("   常见内存错误和避免方法:\n");
    
    // 1. 检查分配结果
    printf("     1. 总是检查分配结果:\n");
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("       内存分配失败，程序应该处理这种情况\n");
        return;
    } else {
        printf("       内存分配成功，可以安全使用\n");
        *ptr = 100;
        printf("       设置值: %d\n", *ptr);
        safe_free((void**)&ptr);
    }
    
    // 2. 避免悬空指针
    printf("     2. 避免悬空指针:\n");
    char *str = (char*)malloc(20);
    if (str != NULL) {
        strcpy(str, "Test");
        printf("       释放前: %s\n", str);
        safe_free((void**)&str);  // 自动设置为NULL
        
        if (str == NULL) {
            printf("       释放后指针已设为NULL，避免悬空指针\n");
        }
    }
    
    // 3. 避免内存泄漏的示例
    printf("     3. 避免内存泄漏:\n");
    for (int i = 0; i < 3; i++) {
        int *temp = (int*)safe_malloc(sizeof(int));
        if (temp != NULL) {
            *temp = i;
            printf("       循环 %d: 分配并立即释放\n", i);
            safe_free((void**)&temp);
        }
    }
}

// 创建动态数组的工具函数
int* create_dynamic_array(int size, int initial_value) {
    int *array = (int*)safe_malloc(sizeof(int) * size);
    if (array != NULL) {
        for (int i = 0; i < size; i++) {
            array[i] = initial_value;
        }
    }
    return array;
}

// 创建动态字符串的工具函数
char* create_dynamic_string(const char *source) {
    if (source == NULL) return NULL;
    
    size_t len = strlen(source);
    char *new_string = (char*)safe_malloc(len + 50);  // 额外空间用于修改
    
    if (new_string != NULL) {
        strcpy(new_string, source);
    }
    
    return new_string;
}
