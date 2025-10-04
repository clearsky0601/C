#include "types_demo.h"

void demo_constructs(void) {
    /* 数组 */
    int arr[5] = {1, 2, 3, 4, 5};
    printf("array arr (length=%zu):", sizeof(arr)/sizeof(arr[0]));
    for (size_t k = 0; k < sizeof(arr)/sizeof(arr[0]); ++k) {
        printf(" %d", arr[k]);
    }
    printf("\n");

    /* 结构体 */
    // 1. 定义结构体类型并声明变量（常规写法）
    struct Point {
        int x;
        int y;
    };
    struct Point p1 = { .x = 10, .y = 20 };
    printf("struct Point p1 {x,y} = {%d, %d} (size=%zu)\n", p1.x, p1.y, sizeof(p1));

    // 2. 定义结构体类型并同时声明变量（复合写法）
    struct Rectangle {
        int width;
        int height;
    } rect = { .width = 30, .height = 40 };
    printf("struct Rectangle rect {width,height} = {%d, %d} (size=%zu)\n", rect.width, rect.height, sizeof(rect));

    // 3. 使用 typedef 简化结构体类型名
    typedef struct {
        char name[16];
        int age;
    } Person;
    Person tom = { "Tom", 25 };
    printf("Person tom {name,age} = {%s, %d} (size=%zu)\n", tom.name, tom.age, sizeof(tom));

    // 4. 匿名结构体变量（只声明变量，不定义类型名）
    struct {
        double lat;
        double lon;
    } location = { 39.9, 116.4 };
    printf("anonymous struct location {lat,lon} = {%.1f, %.1f} (size=%zu)\n", location.lat, location.lon, sizeof(location));

    /* 联合体 */
    union Number {
        int i;
        float f;
        char bytes[4];
    } n;
    n.i = 0x41424344; /* 展示同一内存不同解释 */
    printf("union Number as int=0x%x, as float=%f, bytes=%c%c%c%c (size=%zu)\n",
           n.i, n.f, n.bytes[0], n.bytes[1], n.bytes[2], n.bytes[3], sizeof(n));

    /* 枚举 */
    enum Color { RED, GREEN = 5, BLUE } c = BLUE;
    printf("enum Color: RED=%d GREEN=%d BLUE=%d, selected=%d (size=%zu)\n",
           RED, GREEN, BLUE, c, sizeof(c));
}
