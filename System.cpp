/*System.cpp 此文件为System类的实现*/

#include <iostream>
#include <fstream>
#include <string>
#include <list> //STL链表
#include "Player.h"
#include "Chess.h"
#include "System.h"

using namespace std;

void System::read_file()
{
	fstream infile("playerInfo.txt", ios::in);
	if (!infile)
	{
		cout << "open error!" << endl;
		exit(-1);	//文件打开失败，退出！
	}

	while (!infile.eof())
	{
		string name, word, mail;
		int id, grade;
		char chessBoard[N][N];

		infile >> id >> name >> word >> mail >> grade; //从文件中读取信息

		for (int i = 0; i < N ; ++i)
		{
			for (int j = 0; j < N ; ++j)
			{
				infile >> chessBoard[i][j];//读棋盘信息
				//cout << chessBoard[i][j];
				infile.get(); //读空格
			}
			infile.get(); //读换行
		}

		Chess* chess = new Chess(chessBoard); //Player的一个成员是棋盘对象
		Player* player = new Player(id, name, word, mail, grade, *chess);

		playerList.push_back(*player);//添加到链表尾部
		if (infile.peek() == EOF)
			break; //防止末尾读两遍

	}

	infile.close();

}

void System::write_file()
{
	fstream outfile("playerInfo.txt", ios::out);
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(-1);	//文件打开失败，退出！
	}

	list<Player>::iterator iter = playerList.begin();
	while ( iter != playerList.end())
	{
		int id = (*iter).get_id(); //id
		string name = (*iter).get_playerName(); //昵称
		string word = (*iter).get_passwd(); //密码
		string mail = (*iter).get_email(); //邮箱
		int grade = (*iter).get_grade(); //分数

		outfile << id << '\n' << name << '\n' << word << '\n' << mail << '\n' << grade << '\n'; 
		//向文件中写入信息

		for (int i = 0; i < N ; ++i)
		{
			for (int j = 0; j < N ; ++j)
			{
				outfile << (*iter).get_chessRecord().get_coordinate(i,j) << ' '; //写棋盘信息
			}
			outfile << '\n';
		}
		iter++; //指向下一个结点	

	}

	outfile.close();

}

list<Player>::iterator System::find_player(string name) //根据昵称查找玩家
{
	list<Player>::iterator iter = playerList.begin();
	while (iter != playerList.end())
	{
		if (name == (*iter).get_playerName())
		{
			break;
		}
		iter++;
	}
	//没找到，返回最后一个结点
	//否则，返回当前结点
	return iter; 

}

bool System::register_player(string name, string passwd,string mail)
{
	list<Player>::iterator iter = find_player(name);
	if (iter == playerList.end())
	{
		Player *player = new Player(name, passwd, mail);
		playerList.push_back(*player);//添加至链表末尾
		return true;
	}
	else {
		return false; //已注册
	}
	

}

bool System::log_in(string name, string word)
{
	list<Player>::iterator iter = find_player(name);
	if (iter != playerList.end() && word == (*iter).get_passwd())	
	{
		//确有其人,并且密码正确
		this->iter = iter; //修改为当前玩家
		return true;	
	}
	else
	{
		//账号或密码错误！
		return false;
	}
}

string System::forget_passwd(string name, string mail)
{
	list<Player>::iterator iter = find_player(name);
	if (iter != playerList.end() && mail == (*iter).get_email())
	{
		//确有其人,并且密码正确
		return (*iter).get_passwd();
	}
	else
	{
		//账号不存在或邮箱错误！
		return ""; 
	}
}

bool System::delete_player(string name, string word) //注销玩家
{
	list<Player>::iterator iter = find_player(name);
	if (iter != playerList.end() && word == (*iter).get_passwd())
	{
		//确有其人,并且密码正确
		playerList.erase(iter);//删除结点
		return true;
	}
	else
	{
		//注销失败
		return false;
	}
}

bool System::change_Info(string info, int cmd) //修改个人信息
{
	switch (cmd)
	{
		case CMD_NAME:
			return (*iter).change_playerName(info);

		case CMD_PASSWD:
			return (*iter).change_passwd(info);

		case CMD_EMAIL:
			return (*iter).change_email(info);
		
		default:
			return false;
	}


}