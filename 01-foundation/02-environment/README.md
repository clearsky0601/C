# 开发环境搭建

## 学习目标
- 了解C语言开发所需的工具链
- 验证编译器安装和配置
- 学习基本的编译命令和选项

## 知识要点


### Windows上的C语言开发环境

#### 1\. 编译器选择 (Compiler Selection)

  * **MinGW (Minimalist GNU for Windows)**：
      * 提供一套将 **GNU Compiler Collection (GCC)** 移植到 Windows 上的工具。
      * 常用于编译生成原生 Windows 可执行文件。
  * **MinGW-w64**：
      * **推荐**：它是 MinGW 的一个更现代的分支，支持 32 位和 64 位 (x64) Windows 系统。
      * 例如，**MSYS2** 是一种流行的 MinGW-w64 发行版，它提供了一个类似 **Linux** 的命令行环境和包管理器。
  * **Visual Studio (MSVC)**：
      * 微软官方提供的编译器和集成开发环境 (IDE)。
      * 适用于需要与 Windows API 深度集成或使用微软生态系统的项目。

#### 2\. 开发工具 (Development Tools)

  * **集成开发环境 (IDE) / 编辑器 (Editor)**：
      * **Visual Studio Code (VS Code)**：轻量级，通过安装 C/C++ 扩展包和配置 MinGW-w64，是主流选择。
      * **Visual Studio Community Edition**：功能强大的完整 IDE，尤其适合大型项目。
      * **CLion**：跨平台 C/C++ IDE (商业软件)。
  * **调试器 (Debugger)**：
      * **GDB (GNU Debugger)**：通常与 MinGW/MinGW-w64 一起安装和使用。
      * **Windows Debugger (WinDbg)** 或 Visual Studio 自带的调试器。
  * **命令行工具 (Command Line)**：
      * **Windows Terminal** 或 **PowerShell**：现代化的终端工具。
      * **MSYS2 Shell**：如果您使用 MSYS2，它提供一个 **Bash** 环境，使操作体验更接近 **Ubuntu**。


### Linux 上的 C 语言开发环境

#### 1\. 编译器选择 (Compiler Selection)

  * **GCC (GNU Compiler Collection)**：
      * **默认和推荐**：Linux 系统上标准的 C/C++ 编译器。
      * 通过 `build-essential` 元包安装，该包包含 GCC 和其他必需的开发工具。
  * **Clang/LLVM**：
      * 另一个流行的开源编译器，在某些优化和错误诊断方面表现优秀。

#### 2\. 开发工具 (Development Tools)

  * **包管理器 (Package Manager)**：
      * **apt**：Ubuntu/Debian 系统的标准包管理器，用于安装所有开发工具。
        ```bash
        # Install GCC and essential development tools
        sudo apt update
        sudo apt install build-essential
        ```
  * **文本编辑器 (Text Editor) / IDE**：
      * **Vim / Emacs**：经典且强大的终端编辑器，是 Linux 上的高效开发工具。
      * **VS Code**：轻量级且跨平台，是现代 Linux 桌面的流行选择。
      * **Code::Blocks / Eclipse CDT**：专用的 C/C++ IDE。
  * **调试器 (Debugger)**：
      * **GDB (GNU Debugger)**：标准的命令行调试器。
      * **Valgrind**：用于内存错误检测和性能分析的强大工具。
  * **构建系统 (Build System)**：
      * **Make / CMake**：用于自动化编译过程的工具，是管理大型 C 项目的标准方式。

### macOS 上的 C 语言开发环境

#### 1\. 编译器选择 (Compiler Selection)

  - **Clang**：macOS默认编译器，Apple维护
  - **GCC**：GNU编译器集合，可通过**Homebrew**安装
  - **推荐**：使用系统自带的 **Clang**，兼容性最好

#### 2\. 开发工具 (Development Tools)

  - **Xcode Command Line Tools**：包含编译器和基本工具
      * 安装命令：`xcode-select --install`
  - **文本编辑器**：**VS Code**、**Vim**、**Emacs**等
  - **调试器**：**lldb**（LLVM 调试器）

#### 3\. 包管理器（可选）

  - **Homebrew**：用于安装额外的开发工具（如特定版本的 GCC、Python 库或实用程序）
  - **MacPorts**：另一个包管理选择

### 编译器验证

#### 检查编译器版本
```bash
gcc --version    # 查看GCC版本（实际可能是clang）
clang --version  # 查看Clang版本
```

#### 编译器特性
- **C标准支持**：C89, C99, C11, C17
- **优化选项**：-O0, -O1, -O2, -O3
- **调试信息**：-g选项
- **警告控制**：-Wall, -Wextra

## 代码说明
本目录包含一个环境检测程序，用于验证编译器功能和系统信息。

## 编译运行
```bash
make
make run
make test    # 运行环境测试
```

## 练习建议
1. 运行环境检测程序，查看你的系统信息
2. 尝试不同的编译选项，观察差异
3. 学习使用调试器lldb的基本命令

## 常见问题
1. **找不到编译器**：安装Xcode Command Line Tools
2. **权限问题**：确保有执行权限
3. **路径问题**：检查PATH环境变量

## 下一步学习
完成本节后，请继续学习：
- 03-makefile-basics：深入学习Makefile
