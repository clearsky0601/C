/*
 * 工具函数头文件
 * 
 * 包含各种实用函数的声明：
 * 1. 数学运算函数
 * 2. 字符串处理函数
 * 3. 数组操作函数
 */

#ifndef UTILS_H
#define UTILS_H

// 数学运算函数
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

// 字符串处理函数
int string_length(const char *str);
void to_uppercase(char *str);

// 数组操作函数
void print_array(int arr[], int size);
int find_max(int arr[], int size);
int find_min(int arr[], int size);
double calculate_average(int arr[], int size);

#endif // UTILS_H
