# 预处理器学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
DEBUG_FLAGS = -DDEBUG
TARGET = preprocessor
SOURCE = preprocessor.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 调试版本（启用DEBUG宏）
debug: $(SOURCE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET)_debug $(SOURCE)
	@echo "调试版本编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行预处理器演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 运行调试版本
run-debug: debug
	@echo "运行调试版本（启用DEBUG宏）："
	@echo "================================"
	./$(TARGET)_debug
	@echo "================================"

# 查看预处理结果
preprocess: $(SOURCE)
	@echo "查看预处理结果："
	@echo "================================"
	$(CC) -E $(CFLAGS) $(SOURCE) > $(TARGET).i
	@echo "预处理结果已保存到 $(TARGET).i"
	@echo "文件大小: $$(wc -l < $(TARGET).i) 行"
	@echo "================================"

# 查看宏展开（部分）
show-macros: $(SOURCE)
	@echo "显示宏定义："
	@echo "================================"
	@grep -n "^#define" $(SOURCE)
	@echo "================================"

# 不同版本编译
version1: $(SOURCE)
	$(CC) $(CFLAGS) -DVERSION=1 -o $(TARGET)_v1 $(SOURCE)
	@echo "版本1编译完成"

version2: $(SOURCE)
	$(CC) $(CFLAGS) -DVERSION=2 -o $(TARGET)_v2 $(SOURCE)
	@echo "版本2编译完成"

# 比较不同版本
compare-versions: version1 version2
	@echo "比较不同版本的输出："
	@echo "================================"
	@echo "--- 版本1 ---"
	@./$(TARGET)_v1 | grep "版本\|功能"
	@echo ""
	@echo "--- 版本2 ---"
	@./$(TARGET)_v2 | grep "版本\|功能"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET) $(TARGET)_debug $(TARGET)_v1 $(TARGET)_v2 $(TARGET).i
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all              - 编译程序"
	@echo "  debug            - 编译调试版本"
	@echo "  run              - 运行演示"
	@echo "  run-debug        - 运行调试版本"
	@echo "  preprocess       - 查看预处理结果"
	@echo "  show-macros      - 显示宏定义"
	@echo "  version1/version2 - 编译不同版本"
	@echo "  compare-versions - 比较版本差异"
	@echo "  clean            - 清理文件"

.PHONY: all debug run run-debug preprocess show-macros version1 version2 compare-versions clean help
