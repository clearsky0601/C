# 循环结构学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = loops
SOURCE = loops.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行循环结构演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 只显示图案
patterns: $(TARGET)
	@echo "图案绘制演示："
	@echo "================================"
	./$(TARGET) | grep -A 20 "图案绘制"
	@echo "================================"

# 数学计算演示
math: $(TARGET)
	@echo "数学计算演示："
	@echo "================================"
	./$(TARGET) | grep -A 5 "阶乘\|斐波那契"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all      - 编译程序"
	@echo "  run      - 运行完整演示"
	@echo "  patterns - 显示图案绘制"
	@echo "  math     - 显示数学计算"
	@echo "  clean    - 清理文件"

.PHONY: all run patterns math clean help
