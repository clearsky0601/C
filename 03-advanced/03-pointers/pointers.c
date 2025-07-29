/*
 * C语言指针基础演示程序
 * 
 * 功能：
 * 1. 演示指针的基本概念和操作
 * 2. 展示指针与数组的关系
 * 3. 演示指针算术运算
 * 4. 展示指针作为函数参数
 */

#include <stdio.h>
#include <stdlib.h>

// 函数声明
void swap_values(int *a, int *b);
void print_array_with_pointer(int *arr, int size);
int* find_max_element(int *arr, int size);
void demonstrate_pointer_arithmetic(int *arr, int size);

int main() {
    printf("=== C语言指针基础演示 ===\n\n");
    
    // 1. 指针基础概念
    printf("1. 指针基础概念：\n");
    int x = 42;
    int *ptr = &x;  // ptr指向x的地址
    
    printf("   变量x的值: %d\n", x);
    printf("   变量x的地址: %p\n", (void*)&x);
    printf("   指针ptr的值(地址): %p\n", (void*)ptr);
    printf("   通过指针访问的值: %d\n", *ptr);
    
    // 通过指针修改值
    *ptr = 100;
    printf("   通过指针修改后x的值: %d\n", x);
    
    // 2. 指针与变量的关系
    printf("\n2. 指针与变量的关系：\n");
    int a = 10, b = 20;
    printf("   交换前: a = %d, b = %d\n", a, b);
    swap_values(&a, &b);
    printf("   交换后: a = %d, b = %d\n", a, b);
    
    // 3. 指针与数组
    printf("\n3. 指针与数组：\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int *arr_ptr = numbers;  // 数组名就是指向第一个元素的指针
    
    printf("   数组地址: %p\n", (void*)numbers);
    printf("   指针地址: %p\n", (void*)arr_ptr);
    printf("   第一个元素地址: %p\n", (void*)&numbers[0]);
    
    // 不同的数组访问方式
    printf("   数组访问方式比较:\n");
    for (int i = 0; i < 5; i++) {
        printf("     numbers[%d] = %d, *(numbers+%d) = %d, arr_ptr[%d] = %d\n",
               i, numbers[i], i, *(numbers + i), i, arr_ptr[i]);
    }
    
    // 4. 指针算术运算
    printf("\n4. 指针算术运算：\n");
    demonstrate_pointer_arithmetic(numbers, 5);
    
    // 5. 使用指针遍历数组
    printf("\n5. 使用指针遍历数组：\n");
    printf("   使用指针打印数组: ");
    print_array_with_pointer(numbers, 5);
    
    // 6. 查找数组中的最大元素
    printf("\n6. 查找最大元素：\n");
    int *max_ptr = find_max_element(numbers, 5);
    printf("   最大元素的值: %d\n", *max_ptr);
    printf("   最大元素的地址: %p\n", (void*)max_ptr);
    printf("   最大元素的索引: %ld\n", max_ptr - numbers);
    
    // 7. 多级指针
    printf("\n7. 多级指针：\n");
    int value = 99;
    int *ptr1 = &value;
    int **ptr2 = &ptr1;  // 指向指针的指针
    
    printf("   value = %d\n", value);
    printf("   *ptr1 = %d\n", *ptr1);
    printf("   **ptr2 = %d\n", **ptr2);
    printf("   ptr1地址 = %p, ptr2指向的地址 = %p\n", (void*)ptr1, (void*)*ptr2);
    
    // 通过二级指针修改值
    **ptr2 = 200;
    printf("   通过**ptr2修改后value = %d\n", value);
    
    // 8. 空指针和安全检查
    printf("\n8. 空指针和安全检查：\n");
    int *null_ptr = NULL;
    printf("   null_ptr的值: %p\n", (void*)null_ptr);
    
    if (null_ptr == NULL) {
        printf("   null_ptr是空指针，不能解引用\n");
    }
    
    // 安全的指针使用
    int *safe_ptr = malloc(sizeof(int));
    if (safe_ptr != NULL) {
        *safe_ptr = 123;
        printf("   动态分配的内存值: %d\n", *safe_ptr);
        free(safe_ptr);  // 释放内存
        safe_ptr = NULL; // 避免悬空指针
        printf("   内存已释放，指针已置空\n");
    }
    
    // 9. 指针大小
    printf("\n9. 指针大小：\n");
    printf("   int指针大小: %zu字节\n", sizeof(int*));
    printf("   char指针大小: %zu字节\n", sizeof(char*));
    printf("   double指针大小: %zu字节\n", sizeof(double*));
    printf("   void指针大小: %zu字节\n", sizeof(void*));
    
    return 0;
}

// 函数定义

// 交换两个整数的值
void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 使用指针打印数组
void print_array_with_pointer(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));  // 等价于arr[i]
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// 查找数组中最大元素的地址
int* find_max_element(int *arr, int size) {
    int *max_ptr = arr;  // 指向第一个元素
    
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *max_ptr) {
            max_ptr = arr + i;  // 更新指针位置
        }
    }
    
    return max_ptr;
}

// 演示指针算术运算
void demonstrate_pointer_arithmetic(int *arr, int size) {
    printf("   指针算术运算演示:\n");
    int *ptr = arr;  // 指向数组开始
    
    printf("     初始位置: ptr指向arr[0], 值 = %d, 地址 = %p\n", 
           *ptr, (void*)ptr);
    
    ptr++;  // 移动到下一个元素
    printf("     ptr++后: ptr指向arr[1], 值 = %d, 地址 = %p\n", 
           *ptr, (void*)ptr);
    
    ptr += 2;  // 向前移动2个位置
    printf("     ptr+=2后: ptr指向arr[3], 值 = %d, 地址 = %p\n", 
           *ptr, (void*)ptr);
    
    ptr--;  // 向后移动1个位置
    printf("     ptr--后: ptr指向arr[2], 值 = %d, 地址 = %p\n", 
           *ptr, (void*)ptr);
    
    // 指针相减
    int *end_ptr = arr + size - 1;
    printf("     指针相减: end_ptr - arr = %ld (数组长度-1)\n", 
           end_ptr - arr);
}
