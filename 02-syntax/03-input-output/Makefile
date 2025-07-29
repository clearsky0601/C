# 输入输出学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = io_demo
SOURCE = io_demo.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序（非交互式演示）
run: $(TARGET)
	@echo "运行输入输出演示（自动输入）："
	@echo "================================"
	@echo -e "X\n25\n1.75\nJohn Doe" | ./$(TARGET)
	@echo "================================"

# 交互式运行
interactive: $(TARGET)
	@echo "交互式运行（请根据提示输入）："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 格式化输出测试
format-test: $(TARGET)
	@echo "格式化输出测试："
	@echo "================================"
	@echo -e "A\n0\n0\nTest" | ./$(TARGET) | grep -A 20 "printf格式化输出"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all         - 编译程序"
	@echo "  run         - 自动输入演示"
	@echo "  interactive - 交互式运行"
	@echo "  format-test - 格式化测试"
	@echo "  clean       - 清理文件"

.PHONY: all run interactive format-test clean help
