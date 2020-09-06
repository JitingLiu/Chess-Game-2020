/*Player.cpp ���ļ�ΪPlayer���ʵ��*/

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

static int ID = 0;	//���ϵͳ��ţ�Ĭ�ϴ�0��ʼ

Player::Player():id(0),playerName(""), passwd(""), email(""), grade(0)
{
	id = ID;
	++ID;
}

Player::Player(string name, string word, string mail)//���캯����ע����
	: playerName(name), passwd(word), email(mail), grade(0)
{
	id = ID;
	++ID;
}

Player::Player(int id, string name, string word, string mail, int Grade, Chess chess)
	: id(id),playerName(name), passwd(word), email(mail), grade(Grade),chessRecord(chess)
{
	//��ʼ���б�
}

//�����������Ҫ��const��Ȼ�ᱨ��
Player::Player(const Player& player)//��������
{
	//�������Ʊ�����������������һ����Ĳ�ͬ����
	id = player.id;
	playerName = player.playerName;
	passwd = player.passwd;
	email = player.email;
	grade = player.grade;
	this->chessRecord = player.chessRecord;

}

bool Player::change_playerName(string playername) //�޸��ǳ�
{	
	playerName = playername;
	return true;
}

bool Player::change_passwd(string passwd2)	 //�޸�����
{
	passwd = passwd2;
	return true;
}

bool Player::change_email(string mail)	 //�޸�����
{
	email = mail;
	return true;
}

int Player::get_id()	//�������id
{
	return id;
}

string Player::get_playerName()
{
	return playerName;
}

string Player::get_passwd()	 //��������˺�����
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

Chess& Player::get_chessRecord() //���ؼ�¼�����̶���
{
	return chessRecord;
}
