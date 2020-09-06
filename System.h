#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list> //STL����
#include "Player.h"
#include "Chess.h"

#define CMD_NAME 1
#define CMD_PASSWD 2
#define CMD_EMAIL 3

class System{
private:
	list<Player> playerList; //�������
	list<Player>::iterator iter; //��ǰ���
public:
	void read_file(); //���ļ��ж�ȡ��Ϣ
	void write_file(); //���ļ���д����Ϣ

	list<Player>::iterator find_player(string name); //�����ǳƲ������
	//����ֵ�ǵ����������Ϊend(),��ôû�ҵ�
	bool register_player(string, string, string);	//ע���û�
	bool log_in(string name, string word);			//��¼����
	string forget_passwd(string name, string mail); //�һ�����
	bool delete_player(string name, string word);	//ע�����

	bool change_Info(string info, int cmd); //�޸ĸ�����Ϣ
	//���а�

};

