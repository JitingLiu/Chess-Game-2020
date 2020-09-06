/*Player.h 此文件为Player类的头文件*/

#pragma once
#include <iostream>
#include <string>
#include "Chess.h"

using namespace std;

class Player{
private:
	int id;	//玩家id，系统分配
	string playerName;	//玩家昵称
	string passwd;	//玩家账号密码
	string email;	//玩家邮箱
	int grade;	//玩家分数
	Chess chessRecord;	//记录最后一盘棋
public:
	Player();//默认构造函数
	Player(string name, string word, string mail); //构造函数，注册用
	Player(int, string, string, string, int, Chess); //构造函数,读写文件用
	Player(const Player& player); //拷贝构造
    ~Player(){}	//析构函数

	bool change_playerName(string playername);//修改昵称
	bool change_passwd(string passwd2);	 //修改密码
	bool change_email(string mail);	 //修改邮箱
	
	int get_id();	//返回玩家id
	string get_playerName(); //返回玩家昵称
	string get_passwd();	 //返回玩家账号密码
	string get_email();		 //返回玩家邮箱
	int get_grade();		 //返回玩家分数
    Chess& get_chessRecord(); //返回记录，棋盘对象
};
