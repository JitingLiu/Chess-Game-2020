/*Chess.h ���ļ�ΪChess���d����*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Chess.h" //vector definition using struct position

using namespace std;

#define N 15	//15*15������

extern const char chessBoardFlag;  //���̱�־
extern const char chessFlag1;      //���1����Ե����ӱ�־
extern const char chessFlag2;      //���2�����ӱ�־

typedef struct Position {	//����
    int row;	//��
    int col;	//��
}Position;

extern vector<Position> vec1;      //�� player1 ��������Ϣ
extern vector<Position> vec2;      //�� player2 ��������Ϣ
extern vector<Position> vec3;      //�� player1 + player2 ��������Ϣ
extern vector<Position> vec_blank; //��δ�����λ��
extern vector<Position> vec_all;   //���̵�����λ��

class Chess{
private:
	char chessBoard[N][N];	//����
public:
	Chess();	//Ĭ�Ϲ��캯��
	Chess(char chessBoard[][N]); //���캯��
	Chess(const Chess& chess);	//�������캯��
    ~Chess(){} //
	void Init_chessboard();	//���̳�ʼ������
	void take_step(Position& pos, int player, char flag); //��һ��
	int judge_postition(const Position& pos); //�ж�����ĺϷ���
	int judge_victory(Position pos, char flag); //�ж��Ƿ�����һ�ʤ
	char get_coordinate(int, int); //����(x,y)����Ϣ

	void init_vector(); //������ʼ��
	void AI_chess(Position& pos, char flag); //������
	int alpha_beta(int h, int player, int alpha, int beta); //alpha-beta��֦
	void order(); //��������ӵ��ھ�λ�����п��������ŵ�
	bool has_neightnor(vector<Position>::iterator vter); // �жϵ� pt �Ƿ����ھӵ�
	long int evaluate(int); //��������, ��Ҫ��������ǰ��ֵĵ÷�
	bool match_vector(vector<int>& temp, vector<int>& shape); //�����Ƿ�ƥ��
	int cal_score(int m, int n, int x_direct, int y_direct, vector<Position>& enemy_list,
		vector<Position>& my_list); //ÿ�������ϵķ�ֵ����
};

