# C语言历史学习 - Makefile
# 这是一个简单的Makefile，用于编译和运行C程序

# 编译器设置
CC = gcc
# 编译选项：启用所有警告，使用C99标准
CFLAGS = -Wall -Wextra -std=c99
# 目标可执行文件名
TARGET = history
# 源文件
SOURCE = history.c

# 默认目标：编译程序
all: $(TARGET)

# 编译规则：从源文件生成可执行文件
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo "编译完成！可执行文件：$(TARGET)"

# 运行程序
run: $(TARGET)
	@echo "运行程序："
	@echo "----------------------------------------"
	./$(TARGET)
	@echo "----------------------------------------"

# 清理生成的文件
clean:
	rm -f $(TARGET)
	@echo "清理完成！"

# 显示帮助信息
help:
	@echo "可用的make目标："
	@echo "  all    - 编译程序（默认）"
	@echo "  run    - 编译并运行程序"
	@echo "  clean  - 删除生成的可执行文件"
	@echo "  help   - 显示此帮助信息"

# 声明伪目标（这些目标不对应实际文件）
.PHONY: all run clean help
