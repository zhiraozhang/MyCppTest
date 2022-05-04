# windows简单配置wsl & vscode &C++开发环境

[toc]

## wsl的安装
1. 打开功能，启用wsl系统
2. 去microsoft store搜索linux
3. 选一个喜欢的下载，我选的是debian

## wsl安装后配置
1. 换源
2. 安装必要软件`sudo apt install vim g++ gdb cmake'

## vscode安装后配置

## 【可选】clang

## 【可选】lldb

坑：lldb无法在wsl1上使用

## 【可选】ninja

wsl安装ninja:

``sudo apt install ninja-build``

vscode修改build改为ninja:

`ctrl+,`之后搜索generator改为Ninja![1646545561557.png](image/environment/ninja.png)



## 参考文章：[VS Code + clang + lldb - sinferwu - 博客园 (cnblogs.com)](https://www.cnblogs.com/sinferwu/p/15353427.html)
