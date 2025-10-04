#include "types_demo.h"

static void say_hi(void) { 
    printf("hello from void function\n"); 
}

void helper_print(void *data, size_t size) {
    unsigned char *bytes = (unsigned char*)data;
    printf("bytes:");
    for (size_t i = 0; i < size; ++i) printf(" %02x", bytes[i]);
    printf("\n");
}

void demo_void_examples(void) {
    /* void 函数（无返回） */
    say_hi();

    /* void* 通用指针示例 */
    double dv = 3.14159;
    void *vp = &dv;
    printf("double value via cast: %f\n", *(double*)vp);
    helper_print(vp, sizeof(dv));
}

