# 运算符学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = operators
SOURCE = operators.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行运算符演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 测试特定运算符
test: $(TARGET)
	@echo "运算符测试："
	@echo "================================"
	./$(TARGET) | grep -E "(算术|位运算|逻辑)"
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
	@echo "  test  - 运行测试"
	@echo "  clean - 清理文件"

.PHONY: all run test clean help
