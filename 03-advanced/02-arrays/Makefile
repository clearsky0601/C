# 数组操作学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = arrays
SOURCE = arrays.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行数组操作演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 排序算法演示
sort: $(TARGET)
	@echo "排序算法演示："
	@echo "================================"
	./$(TARGET) | grep -A 10 "数组算法演示"
	@echo "================================"

# 矩阵操作演示
matrix: $(TARGET)
	@echo "矩阵操作演示："
	@echo "================================"
	./$(TARGET) | grep -A 15 "二维数组演示"
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
	@echo "  sort   - 显示排序算法"
	@echo "  matrix - 显示矩阵操作"
	@echo "  clean  - 清理文件"

.PHONY: all run sort matrix clean help
