CC = clang
CFLAGS = -g -Wall -Wextra -std=c11

SRCS = main.c basics.c constructs.c pointers.c void_examples.c
OBJS = $(SRCS:.c=.o)
TARGET = data_types_demo

all: $(TARGET)

CC = clang
CFLAGS = -g -Wall -Wextra -std=c11

SRCS = main.c basics.c constructs.c pointers.c void_examples.c
OBJS = $(SRCS:.c=.o)
TARGET = data_types_demo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c types_demo.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) data_types data_types.o

help:
	@printf "使用说明: make [target]\n\n"
	@printf "可用目标:\n"
	@printf "  %-10s - 编译并生成 '%s' (默认目标)\n" "all" $(TARGET)
	@printf "  %-10s - 运行演示程序 (需先 make)\n" "run"
	@printf "  %-10s - 清理构建产物 (.o, 可执行文件)\n" "clean"
	@printf "  %-10s - 显示本帮助信息\n\n" "help"
	@printf "说明:\n"
	@printf "  - 使用 clang 编译并以 C11 标准构建，开启 -Wall -Wextra。\n"
	@printf "  - 若需覆盖编译器/选项，在命令行覆盖变量，例如：\n"
	@printf "      make CC=gcc CFLAGS='-O2 -std=c11'\n"
	@printf "  - 源文件列表: %s\n" "$(SRCS)"
	@printf "  - 运行示例: make && ./$(TARGET)\n"

.PHONY: all clean run help
		@printf "  - 运行示例: make && ./$(TARGET)\n"

