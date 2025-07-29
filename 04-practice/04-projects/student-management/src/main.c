/*
 * 学生成绩管理系统 - 主程序
 * 
 * 这是一个综合性的C语言项目，演示了：
 * - 结构体和数组的使用
 * - 文件操作和数据持久化
 * - 函数模块化设计
 * - 用户交互界面
 */

#include "../include/student.h"

int main() {
    printf("=== 学生成绩管理系统 ===\n");
    printf("欢迎使用学生成绩管理系统！\n\n");
    
    // 运行主系统
    run_system();
    
    printf("\n感谢使用学生成绩管理系统！\n");
    return 0;
}

// 显示主菜单
void show_menu(void) {
    printf("\n=== 主菜单 ===\n");
    printf("1. 添加学生\n");
    printf("2. 删除学生\n");
    printf("3. 修改学生信息\n");
    printf("4. 查找学生\n");
    printf("5. 显示所有学生\n");
    printf("6. 按平均分排序\n");
    printf("7. 按学号排序\n");
    printf("8. 统计信息\n");
    printf("9. 保存数据\n");
    printf("0. 退出系统\n");
    printf("请选择操作 (0-9): ");
}

// 运行主系统
void run_system(void) {
    StudentSystem system;
    init_system(&system);
    load_from_file(&system);
    
    int choice;
    Student temp_student;
    int id;
    char name[MAX_NAME_LEN];
    
    do {
        show_menu();
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch (choice) {
            case 1: // 添加学生
                printf("\n=== 添加学生 ===\n");
                printf("学号: ");
                scanf("%d", &temp_student.id);
                clear_input_buffer();
                
                printf("姓名: ");
                fgets(temp_student.name, MAX_NAME_LEN, stdin);
                temp_student.name[strcspn(temp_student.name, "\n")] = 0;
                
                printf("年龄: ");
                scanf("%d", &temp_student.age);
                clear_input_buffer();
                
                printf("班级: ");
                fgets(temp_student.class_name, MAX_NAME_LEN, stdin);
                temp_student.class_name[strcspn(temp_student.class_name, "\n")] = 0;
                
                // 初始化成绩
                temp_student.total_subjects = 0;
                for (int i = 0; i < MAX_SUBJECTS; i++) {
                    temp_student.scores[i] = 0.0;
                }
                temp_student.average = 0.0;
                
                if (add_student(&system, &temp_student)) {
                    printf("学生添加成功！\n");
                } else {
                    printf("学生添加失败！\n");
                }
                break;
                
            case 2: // 删除学生
                printf("\n=== 删除学生 ===\n");
                printf("请输入要删除的学号: ");
                scanf("%d", &id);
                clear_input_buffer();
                
                if (delete_student(&system, id)) {
                    printf("学生删除成功！\n");
                } else {
                    printf("未找到该学号的学生！\n");
                }
                break;
                
            case 3: // 修改学生信息
                printf("\n=== 修改学生信息 ===\n");
                printf("请输入要修改的学号: ");
                scanf("%d", &id);
                clear_input_buffer();
                
                Student *found = find_student_by_id(&system, id);
                if (found != NULL) {
                    printf("当前学生信息:\n");
                    print_student(found);
                    
                    printf("\n请输入新的信息:\n");
                    printf("姓名 [%s]: ", found->name);
                    fgets(temp_student.name, MAX_NAME_LEN, stdin);
                    if (temp_student.name[0] != '\n') {
                        temp_student.name[strcspn(temp_student.name, "\n")] = 0;
                        strcpy(found->name, temp_student.name);
                    }
                    
                    printf("年龄 [%d]: ", found->age);
                    char input[10];
                    fgets(input, sizeof(input), stdin);
                    if (input[0] != '\n') {
                        found->age = atoi(input);
                    }
                    
                    printf("学生信息修改成功！\n");
                } else {
                    printf("未找到该学号的学生！\n");
                }
                break;
                
            case 4: // 查找学生
                printf("\n=== 查找学生 ===\n");
                printf("1. 按学号查找\n");
                printf("2. 按姓名查找\n");
                printf("请选择查找方式: ");
                int search_type;
                scanf("%d", &search_type);
                clear_input_buffer();
                
                if (search_type == 1) {
                    printf("请输入学号: ");
                    scanf("%d", &id);
                    clear_input_buffer();
                    
                    Student *student = find_student_by_id(&system, id);
                    if (student != NULL) {
                        printf("找到学生:\n");
                        print_student(student);
                    } else {
                        printf("未找到该学号的学生！\n");
                    }
                } else if (search_type == 2) {
                    printf("请输入姓名: ");
                    fgets(name, MAX_NAME_LEN, stdin);
                    name[strcspn(name, "\n")] = 0;
                    search_by_name(&system, name);
                }
                break;
                
            case 5: // 显示所有学生
                printf("\n=== 所有学生信息 ===\n");
                print_all_students(&system);
                break;
                
            case 6: // 按平均分排序
                printf("\n=== 按平均分排序 ===\n");
                sort_by_average(&system);
                print_all_students(&system);
                break;
                
            case 7: // 按学号排序
                printf("\n=== 按学号排序 ===\n");
                sort_by_id(&system);
                print_all_students(&system);
                break;
                
            case 8: // 统计信息
                printf("\n=== 统计信息 ===\n");
                print_statistics(&system);
                break;
                
            case 9: // 保存数据
                printf("\n=== 保存数据 ===\n");
                save_to_file(&system);
                printf("数据保存成功！\n");
                break;
                
            case 0: // 退出
                printf("\n正在保存数据...\n");
                save_to_file(&system);
                printf("数据已保存，系统退出。\n");
                break;
                
            default:
                printf("无效的选择，请重新输入！\n");
                break;
        }
        
        if (choice != 0) {
            printf("\n按回车键继续...");
            getchar();
        }
        
    } while (choice != 0);
}
