# 动态内存管理学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
DEBUG_FLAGS = -fsanitize=address -fno-omit-frame-pointer
TARGET = memory
SOURCE = memory.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 调试版本（使用AddressSanitizer）
debug: $(SOURCE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET)_debug $(SOURCE)
	@echo "调试版本编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行内存管理演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 运行调试版本
run-debug: debug
	@echo "运行调试版本（AddressSanitizer）："
	@echo "================================"
	./$(TARGET)_debug
	@echo "================================"

# 内存检查（如果有valgrind）
valgrind: $(TARGET)
	@echo "使用Valgrind检查内存："
	@echo "================================"
	@if command -v valgrind >/dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET); \
	else \
		echo "Valgrind未安装，跳过内存检查"; \
		echo "在macOS上可以使用: brew install valgrind"; \
	fi
	@echo "================================"

# 性能测试
performance: $(TARGET)
	@echo "内存分配性能测试："
	@echo "================================"
	@time ./$(TARGET)
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET) $(TARGET)_debug
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all         - 编译程序"
	@echo "  debug       - 编译调试版本"
	@echo "  run         - 运行演示"
	@echo "  run-debug   - 运行调试版本"
	@echo "  valgrind    - 使用Valgrind检查"
	@echo "  performance - 性能测试"
	@echo "  clean       - 清理文件"

.PHONY: all debug run run-debug valgrind performance clean help
