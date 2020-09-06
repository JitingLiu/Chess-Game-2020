/*Player.h ���ļ�ΪPlayer���ͷ�ļ�*/

#pragma once
#include <iostream>
#include <string>
#include "Chess.h"

using namespace std;

class Player{
private:
	int id;	//���id��ϵͳ����
	string playerName;	//����ǳ�
	string passwd;	//����˺�����
	string email;	//�������
	int grade;	//��ҷ���
	Chess chessRecord;	//��¼���һ����
public:
	Player();//Ĭ�Ϲ��캯��
	Player(string name, string word, string mail); //���캯����ע����
	Player(int, string, string, string, int, Chess); //���캯��,��д�ļ���
	Player(const Player& player); //��������
    ~Player(){}	//��������

	bool change_playerName(string playername);//�޸��ǳ�
	bool change_passwd(string passwd2);	 //�޸�����
	bool change_email(string mail);	 //�޸�����
	
	int get_id();	//�������id
	string get_playerName(); //��������ǳ�
	string get_passwd();	 //��������˺�����
	string get_email();		 //�����������
	int get_grade();		 //������ҷ���
    Chess& get_chessRecord(); //���ؼ�¼�����̶���
};
