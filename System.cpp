/*System.cpp ���ļ�ΪSystem���ʵ��*/

#include <iostream>
#include <fstream>
#include <string>
#include <list> //STL����
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
		exit(-1);	//�ļ���ʧ�ܣ��˳���
	}

	while (!infile.eof())
	{
		string name, word, mail;
		int id, grade;
		char chessBoard[N][N];

		infile >> id >> name >> word >> mail >> grade; //���ļ��ж�ȡ��Ϣ

		for (int i = 0; i < N ; ++i)
		{
			for (int j = 0; j < N ; ++j)
			{
				infile >> chessBoard[i][j];//��������Ϣ
				//cout << chessBoard[i][j];
				infile.get(); //���ո�
			}
			infile.get(); //������
		}

		Chess* chess = new Chess(chessBoard); //Player��һ����Ա�����̶���
		Player* player = new Player(id, name, word, mail, grade, *chess);

		playerList.push_back(*player);//��ӵ�����β��
		if (infile.peek() == EOF)
			break; //��ֹĩβ������

	}

	infile.close();

}

void System::write_file()
{
	fstream outfile("playerInfo.txt", ios::out);
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(-1);	//�ļ���ʧ�ܣ��˳���
	}

	list<Player>::iterator iter = playerList.begin();
	while ( iter != playerList.end())
	{
		int id = (*iter).get_id(); //id
		string name = (*iter).get_playerName(); //�ǳ�
		string word = (*iter).get_passwd(); //����
		string mail = (*iter).get_email(); //����
		int grade = (*iter).get_grade(); //����

		outfile << id << '\n' << name << '\n' << word << '\n' << mail << '\n' << grade << '\n'; 
		//���ļ���д����Ϣ

		for (int i = 0; i < N ; ++i)
		{
			for (int j = 0; j < N ; ++j)
			{
				outfile << (*iter).get_chessRecord().get_coordinate(i,j) << ' '; //д������Ϣ
			}
			outfile << '\n';
		}
		iter++; //ָ����һ�����	

	}

	outfile.close();

}

list<Player>::iterator System::find_player(string name) //�����ǳƲ������
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
	//û�ҵ����������һ�����
	//���򣬷��ص�ǰ���
	return iter; 

}

bool System::register_player(string name, string passwd,string mail)
{
	list<Player>::iterator iter = find_player(name);
	if (iter == playerList.end())
	{
		Player *player = new Player(name, passwd, mail);
		playerList.push_back(*player);//���������ĩβ
		return true;
	}
	else {
		return false; //��ע��
	}
	

}

bool System::log_in(string name, string word)
{
	list<Player>::iterator iter = find_player(name);
	if (iter != playerList.end() && word == (*iter).get_passwd())	
	{
		//ȷ������,����������ȷ
		this->iter = iter; //�޸�Ϊ��ǰ���
		return true;	
	}
	else
	{
		//�˺Ż��������
		return false;
	}
}

string System::forget_passwd(string name, string mail)
{
	list<Player>::iterator iter = find_player(name);
	if (iter != playerList.end() && mail == (*iter).get_email())
	{
		//ȷ������,����������ȷ
		return (*iter).get_passwd();
	}
	else
	{
		//�˺Ų����ڻ��������
		return ""; 
	}
}

bool System::delete_player(string name, string word) //ע�����
{
	list<Player>::iterator iter = find_player(name);
	if (iter != playerList.end() && word == (*iter).get_passwd())
	{
		//ȷ������,����������ȷ
		playerList.erase(iter);//ɾ�����
		return true;
	}
	else
	{
		//ע��ʧ��
		return false;
	}
}

bool System::change_Info(string info, int cmd) //�޸ĸ�����Ϣ
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