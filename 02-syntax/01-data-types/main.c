#include "types_demo.h"

int main(void) {
    printf("=== C 数据类型 演示 (data_types_demo) ===\n\n");

    printf("--- 基本类型 (basics) ---\n");
    demo_basics();
    printf("\n");

    printf("--- 构造类型 (constructs) ---\n");
    demo_constructs();
    printf("\n");

    printf("--- 指针类型 (pointers) ---\n");
    demo_pointers();
    printf("\n");

    printf("--- 空类型 (void) ---\n");
    demo_void_examples();
    printf("\n");

    return 0;
}
