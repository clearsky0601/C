# 开发环境检测 - Makefile
# 演示不同的编译选项和配置

# 编译器设置
CC = gcc
# 基本编译选项
CFLAGS = -Wall -Wextra -std=c99
# 调试选项
DEBUG_FLAGS = -g -DDEBUG
# 优化选项
RELEASE_FLAGS = -O2 -DNDEBUG
# 目标文件
TARGET = environment
SOURCE = environment.c

# 默认目标：编译调试版本
all: debug

# 调试版本
debug: $(SOURCE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成（调试版本）！"

# 发布版本
release: $(SOURCE)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成（发布版本）！"

# 运行程序
run: debug
	@echo "运行环境检测程序："
	@echo "========================================"
	./$(TARGET)
	@echo "========================================"

# 测试不同编译器
test: test-gcc test-clang

test-gcc: $(SOURCE)
	@echo "使用GCC编译："
	gcc $(CFLAGS) -o $(TARGET)_gcc $(SOURCE)
	./$(TARGET)_gcc
	@echo ""

test-clang: $(SOURCE)
	@echo "使用Clang编译："
	clang $(CFLAGS) -o $(TARGET)_clang $(SOURCE)
	./$(TARGET)_clang
	@echo ""

# 显示编译器信息
compiler-info:
	@echo "=== 编译器信息 ==="
	@echo "GCC版本："
	@gcc --version | head -1
	@echo ""
	@echo "Clang版本："
	@clang --version | head -1
	@echo ""

# 清理生成的文件
clean:
	rm -f $(TARGET) $(TARGET)_gcc $(TARGET)_clang
	@echo "清理完成！"

# 帮助信息
help:
	@echo "可用的make目标："
	@echo "  all           - 编译调试版本（默认）"
	@echo "  debug         - 编译调试版本"
	@echo "  release       - 编译发布版本"
	@echo "  run           - 编译并运行程序"
	@echo "  test          - 测试不同编译器"
	@echo "  compiler-info - 显示编译器信息"
	@echo "  clean         - 删除生成的文件"
	@echo "  help          - 显示此帮助信息"

.PHONY: all debug release run test test-gcc test-clang compiler-info clean help
