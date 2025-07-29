# 字符串处理学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = strings
SOURCE = strings.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行字符串处理演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 字符串查找演示
search: $(TARGET)
	@echo "字符串查找演示："
	@echo "================================"
	./$(TARGET) | grep -A 10 "字符串查找"
	@echo "================================"

# 字符串转换演示
convert: $(TARGET)
	@echo "字符串转换演示："
	@echo "================================"
	./$(TARGET) | grep -A 15 "字符串转换"
	@echo "================================"

# 清理
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 帮助
help:
	@echo "可用目标："
	@echo "  all     - 编译程序"
	@echo "  run     - 运行完整演示"
	@echo "  search  - 显示查找功能"
	@echo "  convert - 显示转换功能"
	@echo "  clean   - 清理文件"

.PHONY: all run search convert clean help
