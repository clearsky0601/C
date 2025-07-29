# 学生成绩管理系统 - Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRCDIR = src
INCDIR = include
OBJDIR = obj
TARGET = student_management

# 源文件和目标文件
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# 默认目标
all: $(TARGET)

# 创建目标目录
$(OBJDIR):
	mkdir -p $(OBJDIR)

# 编译目标文件
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# 链接生成可执行文件
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "编译完成！可执行文件：$(TARGET)"

# 运行程序
run: $(TARGET)
	@echo "启动学生成绩管理系统："
	@echo "================================"
	./$(TARGET)

# 调试运行
debug: $(TARGET)
	@echo "调试模式运行："
	@echo "================================"
	gdb ./$(TARGET)

# 创建示例数据
sample-data: $(TARGET)
	@echo "创建示例数据..."
	@echo "1\n1001\n张三\n20\n计算机1班\n9\n0" | ./$(TARGET) > /dev/null
	@echo "1\n1002\n李四\n21\n计算机1班\n9\n0" | ./$(TARGET) > /dev/null
	@echo "示例数据创建完成"

# 清理生成的文件
clean:
	rm -rf $(OBJDIR) $(TARGET) students.dat
	@echo "清理完成！"

# 只清理可执行文件和目标文件
clean-build:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "构建文件已清理！"

# 检查代码风格
check:
	@echo "检查代码风格..."
	@for file in $(SOURCES); do \
		echo "检查 $$file"; \
		grep -n "TODO\|FIXME\|XXX" $$file || true; \
	done

# 统计代码行数
count:
	@echo "代码统计："
	@echo "源文件："
	@wc -l $(SOURCES)
	@echo "头文件："
	@wc -l $(INCDIR)/*.h
	@echo "总计："
	@cat $(SOURCES) $(INCDIR)/*.h | wc -l

# 安装（复制到系统目录）
install: $(TARGET)
	@echo "安装程序到 /usr/local/bin/"
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "安装完成！"

# 卸载
uninstall:
	@echo "卸载程序..."
	@sudo rm -f /usr/local/bin/$(TARGET)
	@echo "卸载完成！"

# 打包发布
package: clean all
	@echo "创建发布包..."
	@mkdir -p release
	@cp $(TARGET) release/
	@cp README.md release/ 2>/dev/null || echo "README.md not found"
	@tar -czf student_management_v1.0.tar.gz release/
	@rm -rf release/
	@echo "发布包已创建：student_management_v1.0.tar.gz"

# 帮助信息
help:
	@echo "学生成绩管理系统 - 构建帮助"
	@echo "================================"
	@echo "可用目标："
	@echo "  all          - 编译程序（默认）"
	@echo "  run          - 编译并运行程序"
	@echo "  debug        - 调试模式运行"
	@echo "  sample-data  - 创建示例数据"
	@echo "  clean        - 清理所有生成文件"
	@echo "  clean-build  - 只清理构建文件"
	@echo "  check        - 检查代码"
	@echo "  count        - 统计代码行数"
	@echo "  install      - 安装到系统"
	@echo "  uninstall    - 从系统卸载"
	@echo "  package      - 创建发布包"
	@echo "  help         - 显示此帮助"

# 声明伪目标
.PHONY: all run debug sample-data clean clean-build check count install uninstall package help
