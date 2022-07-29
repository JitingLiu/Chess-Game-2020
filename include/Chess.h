#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Chess.h" //vector definition using struct position

using namespace std;

#define N 15	//15*15的棋盘

extern const char chessBoardFlag;  //棋盘标志
extern const char chessFlag1;      // 玩家1
extern const char chessFlag2;      // 玩家2的棋子标志

typedef struct Position {	//坐标
    int row;	//行
    int col;	//列
}Position;

extern vector<Position> vec1;      //存 player1 的下棋信息
extern vector<Position> vec2;      //存 player2 的下棋信息
extern vector<Position> vec3;      //存 player1 + player2 的下棋信息
extern vector<Position> vec_blank; //存未下棋的位置
extern vector<Position> vec_all;   //棋盘的所有位置

class Chess{
private:
	char chessBoard[N][N];	//棋盘
public:
	Chess();	//默认构造函数
	Chess(char chessBoard[][N]); //构造函数
	Chess(const Chess& chess);	//拷贝构造函数
    ~Chess(){} //
	void Init_chessboard();	//棋盘初始化函数
	void take_step(Position& pos, int player, char flag); //走一步
	int judge_postition(const Position& pos); //判断坐标的合法性
	int judge_victory(Position pos, char flag); //判断是否有玩家获胜
	char get_coordinate(int, int); //返回(x,y)的信息

	void init_vector(); //容器初始化
    void AI_chess(Position& pos, char flag); //AI走
	int alpha_beta(int h, int player, int alpha, int beta); //alpha-beta剪枝
	void order(); //离最后落子的邻居位置最有可能是最优点
	bool has_neightnor(vector<Position>::iterator vter); // 判断点 pt 是否有邻居点
	long int evaluate(int); //评估函数, 主要是评估当前棋局的得分
	bool match_vector(vector<int>& temp, vector<int>& shape); //括号是否匹配
	int cal_score(int m, int n, int x_direct, int y_direct, vector<Position>& enemy_list,
		vector<Position>& my_list); //每个方向上的分值计算
};

