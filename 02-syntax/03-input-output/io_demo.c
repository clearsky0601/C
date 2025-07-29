/*
 * C语言输入输出演示程序
 * 
 * 功能：
 * 1. 演示printf的各种格式化输出
 * 2. 展示scanf的输入功能
 * 3. 演示字符输入输出
 * 4. 展示输入验证技巧
 */

#include <stdio.h>
#include <string.h>

int main() {
    printf("=== C语言输入输出演示 ===\n\n");
    
    // 1. printf格式化输出演示
    printf("1. printf格式化输出：\n");
    int num = 42;
    float pi = 3.14159f;
    char ch = 'A';
    char str[] = "Hello";
    
    printf("   整数: %d, %i, %u\n", num, num, (unsigned)num);
    printf("   进制: 十进制%d, 八进制%o, 十六进制%x, %X\n", num, num, num, num);
    printf("   浮点: %f, %e, %g\n", pi, pi, pi);
    printf("   字符: %c (ASCII: %d)\n", ch, ch);
    printf("   字符串: %s\n", str);
    printf("   指针: %p\n", (void*)&num);
    
    // 2. 格式修饰符演示
    printf("\n2. 格式修饰符：\n");
    printf("   宽度控制: '%5d' '%10s'\n", num, str);
    printf("   左对齐: '%-5d' '%-10s'\n", num, str);
    printf("   零填充: '%05d'\n", num);
    printf("   精度控制: '%.2f' '%.4f'\n", pi, pi);
    printf("   显示符号: '%+d' '%+.2f'\n", num, pi);
    
    // 3. 字符输入输出演示
    printf("\n3. 字符输入输出演示：\n");
    printf("   请输入一个字符: ");
    char input_char = getchar();
    printf("   你输入的字符是: ");
    putchar(input_char);
    printf(" (ASCII: %d)\n", input_char);
    
    // 清理输入缓冲区中的换行符
    while (getchar() != '\n');
    
    // 4. 基本输入演示
    printf("\n4. 基本输入演示：\n");
    int age;
    float height;
    char name[50];
    
    printf("   请输入你的年龄: ");
    if (scanf("%d", &age) == 1) {
        printf("   年龄: %d岁\n", age);
    } else {
        printf("   输入错误！\n");
        return 1;
    }
    
    printf("   请输入你的身高(米): ");
    if (scanf("%f", &height) == 1) {
        printf("   身高: %.2f米\n", height);
    } else {
        printf("   输入错误！\n");
        return 1;
    }
    
    // 清理缓冲区
    while (getchar() != '\n');
    
    printf("   请输入你的姓名: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // 移除fgets读取的换行符
        name[strcspn(name, "\n")] = 0;
        printf("   姓名: %s\n", name);
    }
    
    // 5. 综合信息显示
    printf("\n5. 个人信息卡：\n");
    printf("   ================================\n");
    printf("   | 姓名: %-20s |\n", name);
    printf("   | 年龄: %-20d |\n", age);
    printf("   | 身高: %-18.2f米 |\n", height);
    printf("   ================================\n");
    
    // 6. 数值格式化展示
    printf("\n6. 数值格式化展示：\n");
    double big_num = 1234567.89;
    printf("   大数字: %.2f\n", big_num);
    printf("   科学记数法: %e\n", big_num);
    printf("   自动格式: %g\n", big_num);
    
    // 7. 表格输出示例
    printf("\n7. 表格输出示例：\n");
    printf("   +--------+--------+--------+\n");
    printf("   | %-6s | %-6s | %-6s |\n", "项目", "数值", "百分比");
    printf("   +--------+--------+--------+\n");
    printf("   | %-6s | %6d | %5.1f%% |\n", "A", 85, 85.0);
    printf("   | %-6s | %6d | %5.1f%% |\n", "B", 92, 92.0);
    printf("   | %-6s | %6d | %5.1f%% |\n", "C", 78, 78.0);
    printf("   +--------+--------+--------+\n");
    
    return 0;
}
