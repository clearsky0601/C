# 文件操作学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = file_ops
SOURCE = file_ops.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行文件操作演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 测试文件操作
test-files: $(TARGET)
	@echo "测试文件操作："
	@echo "================================"
	./$(TARGET)
	@echo ""
	@echo "生成的文件列表："
	@ls -la *.txt *.bin 2>/dev/null || echo "没有找到生成的文件"
	@echo "================================"

# 查看生成的文件内容
show-files: $(TARGET) run
	@echo "查看生成的文件内容："
	@echo "================================"
	@echo "--- sample.txt ---"
	@cat sample.txt 2>/dev/null || echo "文件不存在"
	@echo ""
	@echo "--- output.txt ---"
	@cat output.txt 2>/dev/null || echo "文件不存在"
	@echo ""
	@echo "--- copy.txt ---"
	@cat copy.txt 2>/dev/null || echo "文件不存在"
	@echo "================================"

# 清理生成的文件
clean:
	rm -f $(TARGET) *.txt *.bin
	@echo "清理完成！"

# 只清理可执行文件，保留测试文件
clean-exe:
	rm -f $(TARGET)
	@echo "可执行文件已清理！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all        - 编译程序"
	@echo "  run        - 运行演示"
	@echo "  test-files - 测试并显示文件"
	@echo "  show-files - 查看生成的文件内容"
	@echo "  clean      - 清理所有文件"
	@echo "  clean-exe  - 只清理可执行文件"

.PHONY: all run test-files show-files clean clean-exe help
