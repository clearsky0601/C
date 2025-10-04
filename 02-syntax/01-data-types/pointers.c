#include "types_demo.h"

static int add_impl(int a, int b) { return a + b; }

void demo_pointers(void) {
    int value = 2025;
    int *p = &value;
    // 输出变量的值、变量地址、指针的值（即指向的地址）以及指针指向的值
    printf("value=%d, &value=%p, p=%p, *p=%d\n", value, (void*)&value, (void*)p, *p);

    /* 指针算术 */
    int arr[3] = {10, 20, 30};
    int *pa = arr; // 指向数组首元素
    printf("arr elements via pointer:");
    for (int i = 0; i < 3; ++i) {
        printf(" %d", *(pa + i));
    }
    printf("\n");

    /* 指向函数的指针 */
    int (*fn)(int, int) = &add_impl;
    printf("function pointer add(2,3) = %d\n", fn(2,3));

    /* 指向 void 的指针 (通用指针) */
    void *vp = &value;
    printf("void* 通用指针地址=%p\n", vp);
}
