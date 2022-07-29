/*Chess.cpp 此文件为Chess类的实现*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./include/Chess.h"

#define inf 99999999 //无穷大值
#define Depth 3      //搜索深度为3

using namespace std;

//give a definition
const char chessBoardFlag = 'w';  // 棋盘标志
const char chessFlag1 = 'o';      // 玩家1
const char chessFlag2 = 'x';      // 玩家2的棋子标志

//definition of vector
vector<Position> vec1 = {};      //存 player1 的下棋信息
vector<Position> vec2 = {};      //存 player2 的下棋信息
vector<Position> vec3 = {};      //存 player1 + player2 的下棋信息
vector<Position> vec_blank = {}; //存未下棋的位置
vector<Position> vec_all = {};   //棋盘的所有位置

Chess::Chess()  //构造函数
{
    Init_chessboard();

}

Chess::Chess(char chessBoard[][N]) //带参数的构造函数
{
    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < N ; ++j)
        {
            this->chessBoard[i][j] = chessBoard[i][j];//赋值
        }
    }

}

Chess::Chess(const Chess& chess)	//拷贝构造函数
{
    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < N ; ++j)
        {
            this->chessBoard[i][j] = chess.chessBoard[i][j];//赋值
        }
    }
}

void Chess::Init_chessboard()    //初始化棋盘
{
    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < N ; ++j)
        {
            chessBoard[i][j] = chessBoardFlag;//每个位置初始化为空
        }
    }

}

void Chess::init_vector() //容器初始化
{
    //对 vector 初始化
    vec_blank.clear(); //先清空
    vec_all.clear();   //先清空
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Position pos;
            pos.row = i;
            pos.col = j;
            if (chessBoard[i][j] == chessBoardFlag) //没人走
            {
                vec_blank.push_back(pos);
                vec_all.push_back(pos);
            }
            else if (chessBoard[i][j] == chessFlag1) //AI走的位置
            {
                vec_all.push_back(pos);
            }
            else if (chessBoard[i][j] == chessFlag2) //玩家走的位置
            {
                vec_all.push_back(pos);
            }
        }
    }
}

Position *p = new Position(); //记录next step
void Chess::AI_chess(Position& pos, char flag) //AI走
{
    init_vector();
    alpha_beta(1, Depth, -inf, inf);
    if (judge_postition(*p))
    {
        chessBoard[p->row][p->col] = chessFlag1;
        pos.row = p->row;
        pos.col = p->col;
    }

}


//负值极大算法搜索 alpha + beta剪枝, 合并极大节点和极小节点两种情况, 减少代码量
//在一盘棋局中, 若到棋手A走棋, alpha 相当于棋手A得到的最好的值, 对于棋手A的值, 从对手的角度看就要取负值.
int Chess::alpha_beta(int player, int h, int alpha, int beta)
//h搜索深度，player=1表示AI,player=0表示人类
{
    if (vec1.begin() != vec1.end() && vec2.begin() != vec2.end())//不空
    {
        vector<Position>::iterator pter1 = vec1.end()-1;
        vector<Position>::iterator pter2 = vec2.end()-1; //判断最新添加后是否赢棋
        if (h == 1 || judge_victory(*pter1,chessFlag1) || judge_victory(*pter2, chessFlag2))
        {
            //若到达深度 或是出现胜负
            return evaluate(player);
        }
    }

    if (vec3.begin() == vec3.end()) //尚未下棋。居中坐
    {
        vector<Position>::iterator vter = vec_blank.begin();
        vec_blank.erase(vter + 7 * 15 + 7); //先删除居中棋子
        (*p).row = 7; //第八行第八列，执先
        (*p).col = 7;
        return 0;
    }

    // vec_blank 为可以落子的集合
    order();  //按搜索顺序排序  提高剪枝效率

    //遍历每一个候选步
    vector<Position>::iterator vter = vec_blank.begin();
    while (vter != vec_blank.end())
    {
        int tempv = vter - vec_blank.begin();
        //如果要评估的位置没有相邻的子， 则不去评估  减少计算
        if (!has_neightnor(vter))
        {
            vter++;
            continue;
        }

        Position *pos = new Position();
        pos->col = (*vter).col;
        pos->row = (*vter).row;
        //判断是否为ai走棋
        if (player){
            vec1.push_back(*pos);
            vec_blank.erase(vter);
        }
        else{
            vec2.push_back(*pos);
            vec_blank.erase(vter); //从空白记录删除
        }
        vec3.push_back(*pos);

        //返回到上一层节点时，会给出分数的相反数(因为返回的值相当于是在对手的选择下对手对当前棋盘的评估分数
        //而作为他的对立方, 要把分数取反
        //alpha可以视为当前情况下，当前棋手可以得到的最好值，当前棋手得到最好值 == 对手不愿意接受的最差值
        //因为对手需要不断提高
        int value = -alpha_beta(!player, h - 1, -beta, -alpha);

        vector<Position>::iterator vter1 = vec1.end() - 1;
        vector<Position>::iterator vter2 = vec2.end() - 1;
        vector<Position>::iterator vter3 = vec3.end() - 1;
        vter = vec_blank.insert(vec_blank.begin() + tempv, *pos);
        //从空白记录原先位置插入
        //将刚才走棋移除
        if (player)  {   //是AI
            vec1.erase(vter1);
        }
        else{   //是玩家
            vec2.erase(vter2);
        }
        vec3.erase(vter3);
        //vec3.erase(vter); 这么写不行，超出范围

        delete pos;

        if (value > alpha)
        {
            //当depth == DEPTH时, 由于在循环内不断迭代, 总会在考虑后三步棋的情况下逐渐找到最好的走子方式;
            if (h == Depth) //找到路径了
            {
                p->row = (*vter).row;
                p->col = (*vter).col;
            }

            //alpha + beta剪枝点
            //当当前value > beta 时相当于 对手的 value < -alpha, 对手肯定不会考虑这个选择
            if (value >= beta)
            {
                //因为当前 depth中 仍需要遍历候选点, return 之后直接返回上层, 上层将返回值取负值
                //因为当调用该函数时alpah > - beta, 必定返回上层迭代时, value < alpha, 达到剪枝目的
                return beta;
            }

            alpha = value; //更新alpha值

        }
        vter++;

    }

    return alpha;

}


//离最后落子的邻居位置最有可能是最优点
void Chess::order()
{
    // vec3.end()-1 表示 vec3 中最后一个落子

    vector<Position>::iterator last_pt = vec3.end()-1; //实时添加
    //在最后落子附近搜索是否有可以落子的点
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            //当 i = j = 0 是表示最后落子, 因为在其附近搜索所以舍弃 i = j = 0;
            if ( (i == 0 && j == 0) || (*last_pt).row + i < 0  || (*last_pt).row + i > 14||
            (*last_pt).col + j < 0 || (*last_pt).col + j > 14)
            {
                continue;
            }
            vector<Position>::iterator vter = vec_blank.begin();
            for (; vter < vec_blank.end(); vter++) {
                if (chessBoard[(*last_pt).row + i][(*last_pt).col + j] != chessBoardFlag)
                {
                    break; //该位置不是空
                }
                //当最后落子点附近有可选点时, 先从删除, 然后从候选点列表首部插入
                if (((*last_pt).row + i)== (*vter).row && ((*last_pt).col + j) == (*vter).col)
                {
                    vec_blank.erase(vter);
                    Position* pos = new Position ();
                    (*pos).row = (*last_pt).row + i;
                    (*pos).col = (*last_pt).row + j;
                    vec_blank.insert(vec_blank.begin(), *pos);
                    break;
                }
            }
        }
    }
}

bool Chess::has_neightnor(vector<Position>::iterator pter) // 判断点 *vter 是否有邻居点
{
    vector<Position>::iterator vter = vec3.begin();
    if (vter == vec3.end())
    {
        return false; //棋局尚未开始，一定没有邻居点
    }
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            //当 i = j = 0 是表示最后落子, 因为在其附近搜索所以舍弃 i = j = 0;
            if ((i == 0 && j == 0) || (*pter).row + i < 0 || (*pter).row + i > 14 ||
                (*pter).col + j < 0 || (*pter).col + j > 14){
                continue;
            }
            vter = vec3.begin(); //循环前重置
            while (vter != vec3.end())
            {
                if (((*pter).row + i) == (*vter).row && ((*pter).col + j) == (*vter).col){
                    return true;
                }
                vter++;
            }

        }
    }
    return false;

}

//棋型的评估分数, 表示当棋局为不同形状时的得分
vector<int> shape_score[15] = { {50, 0, 1, 1, 0, 0},
                                {50, 0, 0, 1, 1, 0,},
                                {500, 1, 1, 0, 1, 0},
                                {500, 0, 0, 1, 1, 1},
                                {500, 1, 1, 1, 0, 0},
                                {500, 0, 1, 1, 1, 0},
                                {500, 0, 1, 0, 1, 1, 0},
                                {500, 0, 1, 1, 0, 1, 0},
                                {50000, 1, 1, 1, 0, 1},
                                {50000, 1, 1, 0, 1, 1},
                                {50000, 1, 0, 1, 1, 1},
                                {50000, 1, 1, 1, 1, 0},
                                {50000, 0, 1, 1, 1, 1},
                                {50000, 0, 1, 1, 1, 1, 0},
                                {inf, 1, 1, 1, 1, 1} };

int ratio = 3;  // 进攻的系数   大于1 防守型，  小于1 进攻型

long int Chess::evaluate(int player) //评估函数, 主要是评估当前棋局的得分
{
    //evaluate 为启发式的评价函数，alpha + beta搜索是相当于在假设双方在同一评价函数函数情况下才有效
    long int total_score = 0;
    vector<Position> my_list;//假定初始值
    vector<Position> enemy_list;

    if (player) { //是AI方
        my_list = vec1;
        enemy_list = vec2;
    }
    else {
        my_list = vec2;
        enemy_list = vec1;
    }

    //算自己的得分
    long int my_score = 0;

    vector<Position>::iterator pter = my_list.begin();
    for(; pter != my_list.end(); ++pter)
    {
        int m = (*pter).row;
        int n = (*pter).col;
        my_score += cal_score(m, n, 0, 1, enemy_list, my_list);
        my_score += cal_score(m, n, 1, 0, enemy_list, my_list);
        my_score += cal_score(m, n, 1, 1, enemy_list, my_list);
        my_score += cal_score(m, n, -1, 1, enemy_list, my_list);
    }

    //算敌人的得分， 并减去
    long int enemy_score = 0;

    pter = enemy_list.begin();
    for (; pter != enemy_list.end(); ++pter)
    {
        int m = (*pter).row;
        int n = (*pter).col;
        enemy_score += cal_score(m, n, 0, 1, my_list, enemy_list);
        enemy_score += cal_score(m, n, 1, 0, my_list, enemy_list);
        enemy_score += cal_score(m, n, 1, 1, my_list, enemy_list);
        enemy_score += cal_score(m, n, -1, 1, my_list, enemy_list);
    }


    //本方分数 减去 敌方分数
    total_score = my_score - (int)(enemy_score * ratio);

    return total_score;

}



int Chess::cal_score(int m, int n, int x_direct, int y_direct, vector<Position>& enemy_list,
    vector<Position>& my_list) //每个方向上的分值计算
{
    int max_score = 0; //如果没有匹配的模型返回空值

    //在落子点 左右方向上循环查找得分形状
    for (int i = -5; i < 1; ++i)
    {
        vector<int> temp{}; //临时变量
        for (int j = 0; j < 6; ++j)
        {
            if (m + (i + j) * x_direct < 0 || m + (i + j) * x_direct >14 ||
                n + (i + j) * y_direct < 0 || n + (i + j) * y_direct > 14)//在棋盘内判断
            {
                continue; //有一个在棋盘外，
            }
            vector<Position>::iterator pter1 = enemy_list.begin();
            vector<Position>::iterator pter2 = my_list.begin();
            while (pter1 != enemy_list.end() || pter2 != my_list.end())
            {

                if (m + (i + j) * x_direct == (*pter1).row && n + (i + j) * y_direct == (*pter1).col) {
                    //说明该位置是敌方棋子
                    temp.push_back(2);
                    break; // 退出，下一轮循环
                }
                else if (m + (i + j) * x_direct == (*pter2).row && n + (i + j) * y_direct == (*pter2).col) {
                    //说明该位置是我方棋子
                    temp.push_back(1);
                    break;
                }

                if (pter1 == enemy_list.end()-1){
                    if (pter2 == my_list.end()-1) {
                        //说明该位置是双方均没有落子
                        temp.push_back(0);
                        break; //均为空，继续退出循环
                    }
                    else {
                        pter2++;
                    }
                }
                else {
                    pter1++;
                    if (pter2 != my_list.end()-1) {
                        pter2++;
                    }
                }
            }
        }
        if (temp.size() < 5)
        {
            continue; //凑不成五个，不用计算分数了
        }

        vector<int> tmp_shap5 = { temp[0], temp[1], temp[2], temp[3], temp[4] }; //记录连五个的情况
        vector<int> tmp_shap6 = { temp[0], temp[1], temp[2], temp[3], temp[4] }; //记录连六个的情况
        if (temp.size() == 6)
        {
            tmp_shap6.push_back(temp[5]);//防止越界
        }

        for (int k = 0; k < 15; k++)
        {
            if (match_vector(tmp_shap5, shape_score[k]) || match_vector(tmp_shap6, shape_score[k])) {
                //模型记录中五个的情况不会成为6个的齐头的字串
                if (shape_score[k][0] > max_score)
                {
                    max_score = shape_score[k][0]; //复制
                }

            }

        }
        if (max_score == inf) {
            //判断出输赢了，可以结束了
            break;
        }
    }

    return  max_score;

}

bool Chess::match_vector(vector<int>& temp, vector<int>& shape)
{
    vector<int>::iterator iter1 = temp.begin();
    vector<int>::iterator iter2 = shape.begin() + 1; //第一个位置是分数
    while (iter1 != temp.end() && iter2 != shape.end())
        //只要有一个到头就不判断，模型记录中5个的情况不会成为6个的齐头的字串
    {
        if (*iter1 != *iter2)
            return false; //模型不匹配
        else{ //继续
            ++iter1;
            ++iter2;
        }
    }
    return true;
}

void Chess::take_step (Position& pos, int player, char flag)
{
    chessBoard[pos.row][pos.col] = flag;
}

int Chess::judge_postition(const Position& pos) //判断坐标的合法性
{
    //在棋盘上
    if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < N) {
        //所在位置为空（没有棋子）
        if (chessBoard[pos.row][pos.col] == chessBoardFlag) {
            return 1;      //合法
        }
    }
    return 0;       //非法
}

int Chess::judge_victory(Position pos, char flag)  //判断是否有玩家获胜
{
    int begin = 0;
    int end = 0;

    //判断行是否满足条件
    (pos.col - 4) >= 0 ? begin = (pos.col - 4) : begin = 0;//往前探4个位置
    (pos.col + 4) >= N ? end = N - 1: end = (pos.col + 4);//往后探4个位置
    for (int i = pos.row, j = begin; j + 4 <= end; ++j)
    {
        if (chessBoard[i][j] == flag && chessBoard[i][j + 1] == flag &&
            chessBoard[i][j + 2] == flag && chessBoard[i][j + 3] == flag &&
            chessBoard[i][j + 4] == flag)//该棋子周围是否出现五子连珠
            return 1;

    }

    //判断列是否满足条件
    (pos.row - 4) >= 0 ? begin = (pos.row - 4) : begin = 0;
    (pos.row + 4) >= N ? end = N - 1: end = (pos.row + 4);
    for (int j = pos.col, i = begin; i + 4 <= end; ++i) {
        if (chessBoard[i][j] == flag && chessBoard[i + 1][j] == flag &&
            chessBoard[i + 2][j] == flag && chessBoard[i + 3][j] == flag &&
            chessBoard[i + 4][j] == flag)//该棋子周围是否出现五子连珠
            return 1;

    }

    //判断主对角线是否满足条件
    int length = 0;    //相对长度
    int start = 0;
    int finish = 0;
    pos.row > pos.col ? length = pos.col : length = pos.row; //选择一个较小的值作限界
    if (length > 4)
    {
        length = 4;
    }
    begin = pos.row - length;       //横坐标起始位置
    start = pos.col - length;       //纵坐标起始位置

    pos.row > pos.col ? length = N - pos.row - 1 : length = N - pos.col - 1;
    if (length > 4)
    {
        length = 4;
    }
    end = pos.row + length;         //横坐标结束位置
    finish = pos.col + length;      //纵坐标结束位置

    for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish); ++i, ++j)
    {
        if (chessBoard[i][j] == flag && chessBoard[i + 1][j + 1] == flag &&
            chessBoard[i + 2][j + 2] == flag && chessBoard[i + 3][j + 3] == flag &&
            chessBoard[i + 4][j + 4] == flag)
            return 1;
    }
    //判断副对角线是否满足条件
    pos.row > (N - pos.col - 1) ? length = N - pos.col - 1 : length = pos.row;
    if (length > 4)
    {
        length = 4;
    }
    begin = pos.row - length;       //横坐标起始位置
    start = pos.col + length;       //纵坐标起始位置

    (N - pos.row -1) > pos.col ? length = pos.col : length = N - pos.row - 1;
    if (length > 4)
    {
        length = 4;
    }
    end = pos.row + length;         //横坐标结束位置
    finish = pos.col - length;      //纵坐标结束位置

    for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish); ++i, --j)
    {
        if (chessBoard[i][j] == flag && chessBoard[i + 1][j - 1] == flag &&
            chessBoard[i + 2][j - 2] == flag && chessBoard[i + 3][j - 3] == flag &&
            chessBoard[i + 4][j - 4] == flag)
            return 1;
    }

    //该棋局尚未开始
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < N; ++y)
        {
            if (chessBoard[x][y] == chessBoardFlag)
            {
                return 0;       //未下棋
            }
        }
    }
    return -1;      //和局

}


char Chess::get_coordinate(int x, int y) //返回(x,y)的信息
{
    return chessBoard[x][y];

}
