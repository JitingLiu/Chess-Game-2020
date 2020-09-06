#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list> //STL链表
#include "Player.h"
#include "Chess.h"

#define CMD_NAME 1
#define CMD_PASSWD 2
#define CMD_EMAIL 3

class System{
private:
	list<Player> playerList; //玩家链表
	list<Player>::iterator iter; //当前玩家
public:
	void read_file(); //从文件中读取信息
	void write_file(); //向文件中写入信息

	list<Player>::iterator find_player(string name); //根据昵称查找玩家
	//返回值是迭代器，如果为end(),那么没找到
	bool register_player(string, string, string);	//注册用户
	bool log_in(string name, string word);			//登录函数
	string forget_passwd(string name, string mail); //找回密码
	bool delete_player(string name, string word);	//注销玩家

	bool change_Info(string info, int cmd); //修改个人信息
	//排行榜

};

