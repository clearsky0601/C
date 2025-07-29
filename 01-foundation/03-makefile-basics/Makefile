# Makefile基础教程 - 完整示例
# 这个Makefile展示了从简单到复杂的各种用法

# ============================================================================
# 变量定义部分
# ============================================================================

# 编译器和编译选项
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
RELEASE_FLAGS = -O2 -DNDEBUG

# 项目文件
SIMPLE_SRC = simple.c
SIMPLE_TARGET = simple_calc

ADVANCED_SRC = main.c utils.c
ADVANCED_OBJS = main.o utils.o
ADVANCED_TARGET = advanced_demo

# 头文件依赖
HEADERS = utils.h

# ============================================================================
# 默认目标
# ============================================================================

# 默认构建所有目标
all: simple advanced

# ============================================================================
# 简单示例：单文件程序
# ============================================================================

# 方法1：直接编译
simple: $(SIMPLE_SRC)
	@echo "编译简单示例..."
	$(CC) $(CFLAGS) -o $(SIMPLE_TARGET) $(SIMPLE_SRC)
	@echo "简单示例编译完成！"

# ============================================================================
# 高级示例：多文件项目
# ============================================================================

# 方法2：分步编译（推荐）
advanced: $(ADVANCED_TARGET)

# 链接目标文件生成可执行文件
$(ADVANCED_TARGET): $(ADVANCED_OBJS)
	@echo "链接生成可执行文件..."
	$(CC) $(CFLAGS) -o $(ADVANCED_TARGET) $(ADVANCED_OBJS)
	@echo "高级示例编译完成！"

# 编译main.c为目标文件
main.o: main.c $(HEADERS)
	@echo "编译 main.c..."
	$(CC) $(CFLAGS) -c main.c

# 编译utils.c为目标文件
utils.o: utils.c $(HEADERS)
	@echo "编译 utils.c..."
	$(CC) $(CFLAGS) -c utils.c

# ============================================================================
# 运行目标
# ============================================================================

# 运行简单示例
run-simple: simple
	@echo "运行简单计算器："
	@echo "================================"
	./$(SIMPLE_TARGET)
	@echo "================================"

# 运行高级示例
run-advanced: advanced
	@echo "运行高级示例："
	@echo "================================"
	./$(ADVANCED_TARGET)
	@echo "================================"

# 运行所有示例
run: run-simple run-advanced

# ============================================================================
# 发布版本
# ============================================================================

# 编译优化版本
release: CFLAGS += $(RELEASE_FLAGS)
release: clean all
	@echo "发布版本编译完成！"

# ============================================================================
# 调试和测试
# ============================================================================

# 显示变量值（调试用）
debug-vars:
	@echo "CC = $(CC)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "SIMPLE_SRC = $(SIMPLE_SRC)"
	@echo "ADVANCED_SRC = $(ADVANCED_SRC)"
	@echo "ADVANCED_OBJS = $(ADVANCED_OBJS)"

# 检查语法（不生成文件）
check:
	$(CC) $(CFLAGS) -fsyntax-only $(SIMPLE_SRC)
	$(CC) $(CFLAGS) -fsyntax-only $(ADVANCED_SRC)
	@echo "语法检查通过！"

# ============================================================================
# 清理目标
# ============================================================================

# 清理所有生成的文件
clean:
	rm -f $(SIMPLE_TARGET) $(ADVANCED_TARGET) $(ADVANCED_OBJS)
	@echo "清理完成！"

# 深度清理（包括备份文件等）
distclean: clean
	rm -f *~ *.bak *.tmp
	@echo "深度清理完成！"

# ============================================================================
# 帮助信息
# ============================================================================

help:
	@echo "Makefile基础教程 - 可用目标："
	@echo ""
	@echo "构建目标："
	@echo "  all          - 编译所有示例（默认）"
	@echo "  simple       - 编译简单示例"
	@echo "  advanced     - 编译高级示例"
	@echo "  release      - 编译优化版本"
	@echo ""
	@echo "运行目标："
	@echo "  run          - 运行所有示例"
	@echo "  run-simple   - 运行简单示例"
	@echo "  run-advanced - 运行高级示例"
	@echo ""
	@echo "调试目标："
	@echo "  debug-vars   - 显示Makefile变量"
	@echo "  check        - 语法检查"
	@echo ""
	@echo "清理目标："
	@echo "  clean        - 删除生成的文件"
	@echo "  distclean    - 深度清理"
	@echo ""
	@echo "其他："
	@echo "  help         - 显示此帮助信息"

# ============================================================================
# 伪目标声明
# ============================================================================

.PHONY: all simple advanced run run-simple run-advanced release debug-vars check clean distclean help
