/*
 * C语言数组操作演示程序
 * 
 * 功能：
 * 1. 演示一维数组的声明和使用
 * 2. 展示多维数组操作
 * 3. 演示数组作为函数参数
 * 4. 实现常用数组算法
 */

#include <stdio.h>
#include <string.h>

// 函数声明
void print_array(int arr[], int size);
void print_matrix(int matrix[][4], int rows);
int find_max(int arr[], int size);
void bubble_sort(int arr[], int size);
void reverse_array(int arr[], int size);

int main() {
    printf("=== C语言数组操作演示 ===\n\n");
    
    // 1. 一维数组基础
    printf("1. 一维数组基础：\n");
    int numbers[5] = {10, 20, 30, 40, 50};
    int scores[] = {85, 92, 78, 96, 88};  // 自动推导大小
    
    printf("   numbers数组: ");
    print_array(numbers, 5);
    printf("   scores数组: ");
    print_array(scores, 5);
    
    // 数组元素访问和修改
    printf("   修改numbers[2]从%d到99\n", numbers[2]);
    numbers[2] = 99;
    printf("   修改后: ");
    print_array(numbers, 5);
    
    // 2. 数组大小和遍历
    printf("\n2. 数组遍历和大小：\n");
    int data[] = {1, 4, 7, 2, 9, 5, 8};
    int size = sizeof(data) / sizeof(data[0]);
    printf("   数组大小: %d个元素\n", size);
    printf("   数组内容: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // 3. 二维数组演示
    printf("\n3. 二维数组演示：\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("   3x4矩阵:\n");
    print_matrix(matrix, 3);
    
    // 访问特定元素
    printf("   matrix[1][2] = %d\n", matrix[1][2]);
    matrix[1][2] = 99;
    printf("   修改matrix[1][2]为99后:\n");
    print_matrix(matrix, 3);
    
    // 4. 字符数组演示
    printf("\n4. 字符数组演示：\n");
    char greeting[] = "Hello, World!";
    char name[50];
    
    printf("   greeting: %s\n", greeting);
    printf("   greeting长度: %zu\n", strlen(greeting));
    
    // 字符数组操作
    strcpy(name, "Alice");
    printf("   name: %s\n", name);
    strcat(name, " Smith");
    printf("   连接后: %s\n", name);
    
    // 5. 数组算法演示
    printf("\n5. 数组算法演示：\n");
    int test_data[] = {64, 34, 25, 12, 22, 11, 90};
    int test_size = sizeof(test_data) / sizeof(test_data[0]);
    
    printf("   原始数组: ");
    print_array(test_data, test_size);
    
    // 查找最大值
    int max_val = find_max(test_data, test_size);
    printf("   最大值: %d\n", max_val);
    
    // 数组排序
    bubble_sort(test_data, test_size);
    printf("   排序后: ");
    print_array(test_data, test_size);
    
    // 数组反转
    reverse_array(test_data, test_size);
    printf("   反转后: ");
    print_array(test_data, test_size);
    
    // 6. 数组初始化方式
    printf("\n6. 数组初始化方式：\n");
    int arr1[5] = {0};           // 全部初始化为0
    int arr2[5] = {1, 2};        // 部分初始化，其余为0
    int arr3[] = {1, 2, 3, 4, 5}; // 自动推导大小
    
    printf("   arr1 (全0): ");
    print_array(arr1, 5);
    printf("   arr2 (部分): ");
    print_array(arr2, 5);
    printf("   arr3 (自动): ");
    print_array(arr3, 5);
    
    // 7. 多维数组的不同访问方式
    printf("\n7. 多维数组访问：\n");
    int cube[2][3][2] = {
        {{1, 2}, {3, 4}, {5, 6}},
        {{7, 8}, {9, 10}, {11, 12}}
    };
    
    printf("   三维数组 cube[2][3][2]:\n");
    for (int i = 0; i < 2; i++) {
        printf("   层 %d:\n", i);
        for (int j = 0; j < 3; j++) {
            printf("     ");
            for (int k = 0; k < 2; k++) {
                printf("%2d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
    
    return 0;
}

// 函数定义

// 打印一维数组
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// 打印二维数组（矩阵）
void print_matrix(int matrix[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("     ");
        for (int j = 0; j < 4; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 查找数组最大值
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 冒泡排序
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 反转数组
void reverse_array(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
