# 数据类型学习 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = data_types
SOURCE = data_types.c

# 默认目标
all: $(TARGET)

# 编译程序
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！"

# 运行程序
run: $(TARGET)
	@echo "运行数据类型演示："
	@echo "================================"
	./$(TARGET)
	@echo "================================"

# 类型大小测试
test: $(TARGET)
	@echo "系统类型大小信息："
	@echo "================================"
	./$(TARGET) | grep "大小:"
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
	@echo "  test  - 显示类型大小"
	@echo "  clean - 清理文件"

.PHONY: all run test clean help
