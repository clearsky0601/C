# 指针基础学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = pointers
SOURCE = pointers.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行指针基础演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 指针算术演示
pointer-math: $(TARGET)
	@echo "指针算术运算演示："
	@echo "================================"
	./$(TARGET) | grep -A 10 "指针算术运算"
	@echo "================================"

# 内存地址演示
memory: $(TARGET)
	@echo "内存地址演示："
	@echo "================================"
	./$(TARGET) | grep -E "(地址|指针.*值)"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all          - 编译程序"
	@echo "  run          - 运行完整演示"
	@echo "  pointer-math - 显示指针算术"
	@echo "  memory       - 显示内存地址"
	@echo "  clean        - 清理文件"

.PHONY: all run pointer-math memory clean help
