/*Player.cpp 此文件为Player类的实现*/

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

static int ID = 0;	//玩家系统编号，默认从0开始

Player::Player():id(0),playerName(""), passwd(""), email(""), grade(0)
{
	id = ID;
	++ID;
}

Player::Player(string name, string word, string mail)//构造函数，注册用
	: playerName(name), passwd(word), email(mail), grade(0)
{
	id = ID;
	++ID;
}

Player::Player(int id, string name, string word, string mail, int Grade, Chess chess)
	: id(id),playerName(name), passwd(word), email(mail), grade(Grade),chessRecord(chess)
{
	//初始化列表
}

//拷贝构造参数要有const不然会报错
Player::Player(const Player& player)//拷贝构造
{
	//访问限制标号是针对类而不是针对一个类的不同对象
	id = player.id;
	playerName = player.playerName;
	passwd = player.passwd;
	email = player.email;
	grade = player.grade;
	this->chessRecord = player.chessRecord;

}

bool Player::change_playerName(string playername) //修改昵称
{	
	playerName = playername;
	return true;
}

bool Player::change_passwd(string passwd2)	 //修改密码
{
	passwd = passwd2;
	return true;
}

bool Player::change_email(string mail)	 //修改邮箱
{
	email = mail;
	return true;
}

int Player::get_id()	//返回玩家id
{
	return id;
}

string Player::get_playerName()
{
	return playerName;
}

string Player::get_passwd()	 //返回玩家账号密码
{
	return passwd;
}

string Player::get_email()
{
	return email;
}

int Player::get_grade()
{
	return grade;
}

Chess& Player::get_chessRecord() //返回记录，棋盘对象
{
	return chessRecord;
}
