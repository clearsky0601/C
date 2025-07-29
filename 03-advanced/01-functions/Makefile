# 函数学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = functions
SOURCE = functions.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行函数演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 测试递归函数
test: $(TARGET)
	@echo "递归函数测试："
	@echo "================================"
	./$(TARGET) | grep -A 5 "递归函数"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all   - 编译程序"
	@echo "  run   - 运行演示"
	@echo "  test  - 测试递归函数"
	@echo "  clean - 清理文件"

.PHONY: all run test clean help
