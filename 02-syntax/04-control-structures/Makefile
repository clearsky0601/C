# 控制结构学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = control
SOURCE = control.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行控制结构演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 测试不同条件
test: $(TARGET)
	@echo "控制结构测试："
	@echo "================================"
	./$(TARGET) | grep -E "(等级|季节|条件)"
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
