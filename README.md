# c++五子棋项目(Qt界面)

**详细说明请见中文博客：<https://blog.csdn.net/weixin_45157679/article/details/108405709>**

## 一、项目简介
### 1.1 项目内容
利用C++的知识和QT以及一些自行拓展的新知识，实现双人对战及AI模式的五子棋游戏，尝试设计启发式算法，实现AI模式的五子棋游戏。

主要功能：

（1）用户注册、登录和找回密码

（2）双人模式五子棋对战

（3）AI模式五子棋游戏

### 1.2电子文档名及文件列表
文件夹名：Chess_Game_2020

文件名说明：Chess_Game_2020.pro 

项目主程序：

Chess.h / Chess.cpp 五子棋“后端”处理模块设计，包括双人对战和AI对战

Player.h / Player.cpp 用户基础操作（如根据用户名返回密码等）

System.h / System.cpp 系统操作，如注册用户、登录

Gamewindow.h / Gamewindow.cpp 五子棋游戏界面设计

Mainwindow.h / Mainwindow.cpp / Mainwindow.ui 主界面设计

dialog_login.h / dialog_login.cpp / dialog_login.ui 登录对话窗口设计（在此输入用户名及密码）

### 1.3 运行步骤
编译执行环境：Qt 5.9

注意：除了界面设计外，都是在vscode2019中调试好再在Qt中新建的工程，由于字符编码方式不同，需要**按照Qt的“System”编码重新载入（如果是在Qt编辑器下查看）**

运行步骤：项目设计为可视化界面，直接点击按钮执行即可。

**可行步骤简述为**：登录→ 输入用户名及密码（测试过程中可以用Kenny，密码是123456）→（提示登录成功）个人中心 → 选择进入游戏 → 选择游戏模式（双人模式或与AI对战）
