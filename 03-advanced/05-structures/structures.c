/*
 * C语言结构体与联合体演示程序
 * 
 * 功能：
 * 1. 演示结构体的定义和使用
 * 2. 展示联合体的概念和应用
 * 3. 演示嵌套结构体和结构体数组
 * 4. 展示内存对齐和优化
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 基本结构体定义
struct Point {
    int x;
    int y;
};

// 使用typedef简化类型名
typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

// 嵌套结构体
typedef struct {
    struct Point top_left;
    struct Point bottom_right;
} Rectangle;

// 联合体定义
union Data {
    int i;
    float f;
    char str[20];
};

// 位域结构体
struct Flags {
    unsigned int is_active : 1;
    unsigned int is_visible : 1;
    unsigned int priority : 4;
    unsigned int reserved : 2;
};

// 内存对齐演示结构体
struct Aligned {
    char c;      // 1字节
    int i;       // 4字节
    short s;     // 2字节
};

struct Optimized {
    int i;       // 4字节
    short s;     // 2字节
    char c;      // 1字节
};

// 函数声明
void print_point(struct Point p);
void print_employee(Employee emp);
double calculate_area(Rectangle rect);
void demonstrate_union(void);
void demonstrate_memory_alignment(void);

int main() {
    printf("=== C语言结构体与联合体演示 ===\n\n");
    
    // 1. 基本结构体使用
    printf("1. 基本结构体使用：\n");
    struct Point p1 = {10, 20};
    struct Point p2;
    p2.x = 30;
    p2.y = 40;
    
    printf("   点p1: ");
    print_point(p1);
    printf("   点p2: ");
    print_point(p2);
    
    // 结构体赋值
    struct Point p3 = p1;  // 整体赋值
    printf("   点p3 (复制p1): ");
    print_point(p3);
    
    // 2. typedef结构体
    printf("\n2. typedef结构体：\n");
    Employee emp1 = {"Alice Johnson", 28, 55000.0};
    Employee emp2;
    
    strcpy(emp2.name, "Bob Smith");
    emp2.age = 35;
    emp2.salary = 65000.0;
    
    printf("   员工1: ");
    print_employee(emp1);
    printf("   员工2: ");
    print_employee(emp2);
    
    // 3. 结构体指针
    printf("\n3. 结构体指针：\n");
    Employee *emp_ptr = &emp1;
    printf("   通过指针访问: %s, 年龄 %d\n", emp_ptr->name, emp_ptr->age);
    
    // 修改结构体成员
    emp_ptr->salary = 60000.0;
    printf("   修改薪资后: ");
    print_employee(*emp_ptr);
    
    // 4. 嵌套结构体
    printf("\n4. 嵌套结构体：\n");
    Rectangle rect = {{0, 0}, {100, 50}};
    
    printf("   矩形左上角: (%d, %d)\n", rect.top_left.x, rect.top_left.y);
    printf("   矩形右下角: (%d, %d)\n", rect.bottom_right.x, rect.bottom_right.y);
    printf("   矩形面积: %.2f\n", calculate_area(rect));
    
    // 5. 结构体数组
    printf("\n5. 结构体数组：\n");
    struct Point points[] = {
        {0, 0}, {10, 10}, {20, 20}, {30, 30}
    };
    int point_count = sizeof(points) / sizeof(points[0]);
    
    printf("   点数组:\n");
    for (int i = 0; i < point_count; i++) {
        printf("     点%d: ", i);
        print_point(points[i]);
    }
    
    // 6. 员工数组
    printf("\n6. 员工数组：\n");
    Employee employees[] = {
        {"Charlie Brown", 25, 45000.0},
        {"Diana Prince", 30, 70000.0},
        {"Edward Norton", 40, 80000.0}
    };
    int emp_count = sizeof(employees) / sizeof(employees[0]);
    
    printf("   员工列表:\n");
    for (int i = 0; i < emp_count; i++) {
        printf("     %d. ", i + 1);
        print_employee(employees[i]);
    }
    
    // 计算平均薪资
    float total_salary = 0;
    for (int i = 0; i < emp_count; i++) {
        total_salary += employees[i].salary;
    }
    printf("   平均薪资: %.2f\n", total_salary / emp_count);
    
    // 7. 联合体演示
    printf("\n7. 联合体演示：\n");
    demonstrate_union();
    
    // 8. 位域演示
    printf("\n8. 位域演示：\n");
    struct Flags flag = {1, 0, 5, 0};
    
    printf("   标志状态:\n");
    printf("     活跃: %s\n", flag.is_active ? "是" : "否");
    printf("     可见: %s\n", flag.is_visible ? "是" : "否");
    printf("     优先级: %d\n", flag.priority);
    printf("   位域结构体大小: %zu字节\n", sizeof(struct Flags));
    
    // 9. 内存对齐演示
    printf("\n9. 内存对齐演示：\n");
    demonstrate_memory_alignment();
    
    // 10. 动态分配结构体
    printf("\n10. 动态分配结构体：\n");
    Employee *dynamic_emp = malloc(sizeof(Employee));
    if (dynamic_emp != NULL) {
        strcpy(dynamic_emp->name, "Frank Miller");
        dynamic_emp->age = 45;
        dynamic_emp->salary = 90000.0;
        
        printf("    动态员工: ");
        print_employee(*dynamic_emp);
        
        free(dynamic_emp);
        printf("    内存已释放\n");
    }
    
    return 0;
}

// 函数定义

// 打印点坐标
void print_point(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

// 打印员工信息
void print_employee(Employee emp) {
    printf("%s, %d岁, 薪资: %.2f\n", emp.name, emp.age, emp.salary);
}

// 计算矩形面积
double calculate_area(Rectangle rect) {
    int width = rect.bottom_right.x - rect.top_left.x;
    int height = rect.bottom_right.y - rect.top_left.y;
    return (double)(width * height);
}

// 联合体演示
void demonstrate_union(void) {
    union Data data;
    
    printf("   联合体大小: %zu字节\n", sizeof(union Data));
    
    // 存储整数
    data.i = 42;
    printf("   存储整数: %d\n", data.i);
    printf("   此时浮点值: %f (无意义)\n", data.f);
    
    // 存储浮点数
    data.f = 3.14f;
    printf("   存储浮点: %.2f\n", data.f);
    printf("   此时整数值: %d (无意义)\n", data.i);
    
    // 存储字符串
    strcpy(data.str, "Hello");
    printf("   存储字符串: %s\n", data.str);
    printf("   此时整数值: %d (无意义)\n", data.i);
}

// 内存对齐演示
void demonstrate_memory_alignment(void) {
    printf("   结构体大小比较:\n");
    printf("     struct Aligned (char, int, short): %zu字节\n", sizeof(struct Aligned));
    printf("     struct Optimized (int, short, char): %zu字节\n", sizeof(struct Optimized));
    
    struct Aligned aligned;
    printf("   struct Aligned 成员地址:\n");
    printf("     c的地址: %p (偏移: %zu)\n", (void*)&aligned.c, (char*)&aligned.c - (char*)&aligned);
    printf("     i的地址: %p (偏移: %zu)\n", (void*)&aligned.i, (char*)&aligned.i - (char*)&aligned);
    printf("     s的地址: %p (偏移: %zu)\n", (void*)&aligned.s, (char*)&aligned.s - (char*)&aligned);
    
    struct Optimized optimized;
    printf("   struct Optimized 成员地址:\n");
    printf("     i的地址: %p (偏移: %zu)\n", (void*)&optimized.i, (char*)&optimized.i - (char*)&optimized);
    printf("     s的地址: %p (偏移: %zu)\n", (void*)&optimized.s, (char*)&optimized.s - (char*)&optimized);
    printf("     c的地址: %p (偏移: %zu)\n", (void*)&optimized.c, (char*)&optimized.c - (char*)&optimized);
}
