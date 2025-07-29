/*
 * 学生成绩管理系统 - 核心功能实现
 */

#include "../include/student.h"

// 初始化系统
void init_system(StudentSystem *system) {
    system->count = 0;
    memset(system->students, 0, sizeof(system->students));
}

// 保存到文件
void save_to_file(StudentSystem *system) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("无法打开文件进行保存！\n");
        return;
    }
    
    fwrite(&system->count, sizeof(int), 1, fp);
    fwrite(system->students, sizeof(Student), system->count, fp);
    fclose(fp);
}

// 从文件加载
void load_from_file(StudentSystem *system) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        printf("数据文件不存在，将创建新的数据文件。\n");
        return;
    }
    
    fread(&system->count, sizeof(int), 1, fp);
    fread(system->students, sizeof(Student), system->count, fp);
    fclose(fp);
    
    printf("成功加载 %d 个学生的数据。\n", system->count);
}

// 添加学生
int add_student(StudentSystem *system, Student *student) {
    if (system->count >= MAX_STUDENTS) {
        printf("学生数量已达上限！\n");
        return 0;
    }
    
    // 检查学号是否重复
    if (find_student_by_id(system, student->id) != NULL) {
        printf("学号已存在！\n");
        return 0;
    }
    
    if (!validate_student_data(student)) {
        return 0;
    }
    
    system->students[system->count] = *student;
    system->count++;
    return 1;
}

// 删除学生
int delete_student(StudentSystem *system, int id) {
    for (int i = 0; i < system->count; i++) {
        if (system->students[i].id == id) {
            // 移动后面的学生向前
            for (int j = i; j < system->count - 1; j++) {
                system->students[j] = system->students[j + 1];
            }
            system->count--;
            return 1;
        }
    }
    return 0;
}

// 按学号查找学生
Student* find_student_by_id(StudentSystem *system, int id) {
    for (int i = 0; i < system->count; i++) {
        if (system->students[i].id == id) {
            return &system->students[i];
        }
    }
    return NULL;
}

// 按姓名查找学生
Student* find_student_by_name(StudentSystem *system, const char *name) {
    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->students[i].name, name) == 0) {
            return &system->students[i];
        }
    }
    return NULL;
}

// 计算平均分
void calculate_average(Student *student) {
    if (student->total_subjects == 0) {
        student->average = 0.0;
        return;
    }
    
    float sum = 0.0;
    for (int i = 0; i < student->total_subjects; i++) {
        sum += student->scores[i];
    }
    student->average = sum / student->total_subjects;
}

// 添加成绩
void add_score(Student *student, Subject subject, float score) {
    if (subject >= 0 && subject < MAX_SUBJECTS && score >= 0 && score <= 100) {
        student->scores[subject] = score;
        if (student->total_subjects <= subject) {
            student->total_subjects = subject + 1;
        }
        calculate_average(student);
    }
}

// 打印单个学生信息
void print_student(Student *student) {
    printf("学号: %d\n", student->id);
    printf("姓名: %s\n", student->name);
    printf("年龄: %d\n", student->age);
    printf("班级: %s\n", student->class_name);
    printf("成绩: ");
    for (int i = 0; i < student->total_subjects; i++) {
        printf("%s:%.1f ", get_subject_name(i), student->scores[i]);
    }
    printf("\n平均分: %.2f\n", student->average);
    printf("------------------------\n");
}

// 打印所有学生
void print_all_students(StudentSystem *system) {
    if (system->count == 0) {
        printf("暂无学生数据。\n");
        return;
    }
    
    printf("共有 %d 个学生:\n\n", system->count);
    for (int i = 0; i < system->count; i++) {
        printf("第 %d 个学生:\n", i + 1);
        print_student(&system->students[i]);
    }
}

// 按平均分排序
void sort_by_average(StudentSystem *system) {
    for (int i = 0; i < system->count - 1; i++) {
        for (int j = 0; j < system->count - 1 - i; j++) {
            if (system->students[j].average < system->students[j + 1].average) {
                Student temp = system->students[j];
                system->students[j] = system->students[j + 1];
                system->students[j + 1] = temp;
            }
        }
    }
}

// 按学号排序
void sort_by_id(StudentSystem *system) {
    for (int i = 0; i < system->count - 1; i++) {
        for (int j = 0; j < system->count - 1 - i; j++) {
            if (system->students[j].id > system->students[j + 1].id) {
                Student temp = system->students[j];
                system->students[j] = system->students[j + 1];
                system->students[j + 1] = temp;
            }
        }
    }
}

// 统计信息
void print_statistics(StudentSystem *system) {
    if (system->count == 0) {
        printf("暂无数据可统计。\n");
        return;
    }
    
    float total_avg = 0.0;
    float max_avg = system->students[0].average;
    float min_avg = system->students[0].average;
    
    for (int i = 0; i < system->count; i++) {
        total_avg += system->students[i].average;
        if (system->students[i].average > max_avg) {
            max_avg = system->students[i].average;
        }
        if (system->students[i].average < min_avg) {
            min_avg = system->students[i].average;
        }
    }
    
    printf("学生总数: %d\n", system->count);
    printf("平均分最高: %.2f\n", max_avg);
    printf("平均分最低: %.2f\n", min_avg);
    printf("全班平均分: %.2f\n", total_avg / system->count);
}

// 按姓名搜索
void search_by_name(StudentSystem *system, const char *name) {
    int found = 0;
    for (int i = 0; i < system->count; i++) {
        if (strstr(system->students[i].name, name) != NULL) {
            if (!found) {
                printf("找到以下学生:\n");
                found = 1;
            }
            print_student(&system->students[i]);
        }
    }
    
    if (!found) {
        printf("未找到包含 '%s' 的学生姓名。\n", name);
    }
}

// 获取科目名称
const char* get_subject_name(Subject subject) {
    const char* names[] = {"数学", "英语", "物理", "化学", "生物"};
    if (subject >= 0 && subject < MAX_SUBJECTS) {
        return names[subject];
    }
    return "未知";
}

// 验证学生数据
int validate_student_data(Student *student) {
    if (student->id <= 0) {
        printf("学号必须大于0！\n");
        return 0;
    }
    
    if (strlen(student->name) == 0) {
        printf("姓名不能为空！\n");
        return 0;
    }
    
    if (student->age < 0 || student->age > 150) {
        printf("年龄必须在0-150之间！\n");
        return 0;
    }
    
    return 1;
}

// 清理输入缓冲区
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
