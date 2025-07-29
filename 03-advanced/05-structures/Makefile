# 结构体与联合体学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = structures
SOURCE = structures.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行结构体与联合体演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 内存对齐演示
memory: $(TARGET)
	@echo "内存对齐演示："
	@echo "================================"
	./$(TARGET) | grep -A 15 "内存对齐演示"
	@echo "================================"

# 联合体演示
union: $(TARGET)
	@echo "联合体演示："
	@echo "================================"
	./$(TARGET) | grep -A 10 "联合体演示"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all    - 编译程序"
	@echo "  run    - 运行完整演示"
	@echo "  memory - 显示内存对齐"
	@echo "  union  - 显示联合体"
	@echo "  clean  - 清理文件"

.PHONY: all run memory union clean help
