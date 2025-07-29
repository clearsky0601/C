/*
 * 学生成绩管理系统 - 头文件
 * 
 * 定义学生数据结构和函数接口
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 常量定义
#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define DATA_FILE "students.dat"

// 学科枚举
typedef enum {
    MATH = 0,
    ENGLISH,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY
} Subject;

// 学生结构体
typedef struct {
    int id;                           // 学号
    char name[MAX_NAME_LEN];         // 姓名
    int age;                         // 年龄
    char class_name[MAX_NAME_LEN];   // 班级
    float scores[MAX_SUBJECTS];      // 各科成绩
    float average;                   // 平均分
    int total_subjects;              // 科目数量
} Student;

// 学生管理系统结构体
typedef struct {
    Student students[MAX_STUDENTS];
    int count;                       // 当前学生数量
} StudentSystem;

// 函数声明

// 系统管理
void init_system(StudentSystem *system);
void save_to_file(StudentSystem *system);
void load_from_file(StudentSystem *system);

// 学生操作
int add_student(StudentSystem *system, Student *student);
int delete_student(StudentSystem *system, int id);
int update_student(StudentSystem *system, int id, Student *new_data);
Student* find_student_by_id(StudentSystem *system, int id);
Student* find_student_by_name(StudentSystem *system, const char *name);

// 成绩操作
void calculate_average(Student *student);
void add_score(Student *student, Subject subject, float score);

// 统计功能
void print_all_students(StudentSystem *system);
void print_student(Student *student);
void sort_by_average(StudentSystem *system);
void sort_by_id(StudentSystem *system);
void print_statistics(StudentSystem *system);

// 查询功能
void search_by_name(StudentSystem *system, const char *name);
void search_by_class(StudentSystem *system, const char *class_name);
void list_top_students(StudentSystem *system, int count);

// 工具函数
const char* get_subject_name(Subject subject);
int validate_student_data(Student *student);
void clear_input_buffer(void);

// 用户界面
void show_menu(void);
void run_system(void);

#endif // STUDENT_H
