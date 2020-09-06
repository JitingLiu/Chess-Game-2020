/*Chess.cpp ���ļ�ΪChess���ʵ��*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Chess.h"

#define inf 99999999 //�����ֵ
#define Depth 3      //�������Ϊ3

using namespace std;

//give a definition
const char chessBoardFlag = 'w';  //���̱�־
const char chessFlag1 = 'o';      //���1����Ե����ӱ�־
const char chessFlag2 = 'x';      //���2�����ӱ�־

//definition of vector
vector<Position> vec1 = {};      //�� player1 ��������Ϣ
vector<Position> vec2 = {};      //�� player2 ��������Ϣ
vector<Position> vec3 = {};      //�� player1 + player2 ��������Ϣ
vector<Position> vec_blank = {}; //��δ�����λ��
vector<Position> vec_all = {};   //���̵�����λ��

Chess::Chess()  //���캯��
{
    Init_chessboard();

}

Chess::Chess(char chessBoard[][N]) //�������Ĺ��캯��
{
    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < N ; ++j)
        {
            this->chessBoard[i][j] = chessBoard[i][j];//��ֵ
        }
    }

}

Chess::Chess(const Chess& chess)	//�������캯��
{
    for (int i = 0; i < N ; ++i)
    {
        for (int j = 0; j < N ; ++j)
        {
            this->chessBoard[i][j] = chess.chessBoard[i][j];//��ֵ
        }
    }
}

void Chess::Init_chessboard()    //��ʼ������
{         
    for (int i = 0; i < N ; ++i) 
    {
        for (int j = 0; j < N ; ++j) 
        {
            chessBoard[i][j] = chessBoardFlag;//ÿ��λ�ó�ʼ��Ϊ��
        }
    }

}

void Chess::init_vector() //������ʼ��
{
    //�� vector ��ʼ��
    vec_blank.clear(); //�����
    vec_all.clear();   //�����
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Position pos;
            pos.row = i;
            pos.col = j;
            if (chessBoard[i][j] == chessBoardFlag) //û����
            {
                vec_blank.push_back(pos);
                vec_all.push_back(pos);
            }
            else if (chessBoard[i][j] == chessFlag1) //�����ߵ�λ��
            {    
                vec_all.push_back(pos);
            }
            else if (chessBoard[i][j] == chessFlag2) //����ߵ�λ��
            {
                vec_all.push_back(pos);
            }
        }
    }
}

Position *p = new Position(); //��¼next step
void Chess::AI_chess(Position& pos, char flag) //������
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


//��ֵ�����㷨���� alpha + beta��֦, �ϲ�����ڵ�ͼ�С�ڵ��������, ���ٴ�����
//��һ�������, ��������A����, alpha �൱������A�õ�����õ�ֵ, ��������A��ֵ, �Ӷ��ֵĽǶȿ���Ҫȡ��ֵ.
int Chess::alpha_beta(int player, int h, int alpha, int beta)
//h������ȣ�player=1��ʾ����,player=0��ʾ����
{
    if (vec1.begin() != vec1.end() && vec2.begin() != vec2.end())//����
    {
        vector<Position>::iterator pter1 = vec1.end()-1;
        vector<Position>::iterator pter2 = vec2.end()-1; //�ж�������Ӻ��Ƿ�Ӯ��
        if (h == 1 || judge_victory(*pter1,chessFlag1) || judge_victory(*pter2, chessFlag2))
        {
            //��������� ���ǳ���ʤ��
            return evaluate(player);       
        }
    }
    
    if (vec3.begin() == vec3.end()) //��δ���塣������
    {
        vector<Position>::iterator vter = vec_blank.begin();
        vec_blank.erase(vter + 7 * 15 + 7); //��ɾ����������
        (*p).row = 7; //�ڰ��еڰ��У�ִ��
        (*p).col = 7;
        return 0;
    }

    // vec_blank Ϊ�������ӵļ���  
    order();  //������˳������  ��߼�֦Ч��

    //����ÿһ����ѡ��
    vector<Position>::iterator vter = vec_blank.begin();
    while (vter != vec_blank.end())
    {
        int tempv = vter - vec_blank.begin();
        //���Ҫ������λ��û�����ڵ��ӣ� ��ȥ����  ���ټ���
        if (!has_neightnor(vter))
        {
            vter++;
            continue;
        }    

        Position *pos = new Position();
        pos->col = (*vter).col;
        pos->row = (*vter).row;
        //�ж��Ƿ�Ϊai����
        if (player){
            vec1.push_back(*pos);
            vec_blank.erase(vter);
        }
        else{
            vec2.push_back(*pos);
            vec_blank.erase(vter); //�ӿհ׼�¼ɾ��
        }
        vec3.push_back(*pos);

        //���ص���һ��ڵ�ʱ��������������෴��(��Ϊ���ص�ֵ�൱�����ڶ��ֵ�ѡ���¶��ֶԵ�ǰ���̵���������
        //����Ϊ���Ķ�����, Ҫ�ѷ���ȡ��
        //alpha������Ϊ��ǰ����£���ǰ���ֿ��Եõ������ֵ����ǰ���ֵõ����ֵ == ���ֲ�Ը����ܵ����ֵ
        //��Ϊ������Ҫ�������
        int value = -alpha_beta(!player, h - 1, -beta, -alpha);

        vector<Position>::iterator vter1 = vec1.end() - 1;
        vector<Position>::iterator vter2 = vec2.end() - 1;
        vector<Position>::iterator vter3 = vec3.end() - 1;
        vter = vec_blank.insert(vec_blank.begin() + tempv, *pos); 
        //�ӿհ׼�¼ԭ��λ�ò���
        //���ղ������Ƴ�
        if (player)  {   //�ǵ���
            vec1.erase(vter1);
        }     
        else{   //�����
            vec2.erase(vter2);
        }
        vec3.erase(vter3);
        //vec3.erase(vter); ��ôд���У�������Χ

        delete pos;

        if (value > alpha)
        {
            //��depth == DEPTHʱ, ������ѭ���ڲ��ϵ���, �ܻ��ڿ��Ǻ����������������ҵ���õ����ӷ�ʽ;
            if (h == Depth) //�ҵ�·����
            {
                p->row = (*vter).row;
                p->col = (*vter).col;
            }
               
            //alpha + beta��֦��
            //����ǰvalue > beta ʱ�൱�� ���ֵ� value < -alpha, ���ֿ϶����ῼ�����ѡ��
            if (value >= beta)
            {
                //��Ϊ��ǰ depth�� ����Ҫ������ѡ��, return ֮��ֱ�ӷ����ϲ�, �ϲ㽫����ֵȡ��ֵ
                //��Ϊ�����øú���ʱalpah > - beta, �ض������ϲ����ʱ, value < alpha, �ﵽ��֦Ŀ��
                return beta;
            }

            alpha = value; //����alphaֵ

        }
        vter++;

    }

    return alpha;

}


//��������ӵ��ھ�λ�����п��������ŵ�
void Chess::order()
{
    // vec3.end()-1 ��ʾ vec3 �����һ������
    
    vector<Position>::iterator last_pt = vec3.end()-1; //ʵʱ���
    //��������Ӹ��������Ƿ��п������ӵĵ�
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            //�� i = j = 0 �Ǳ�ʾ�������, ��Ϊ���丽�������������� i = j = 0;
            if ( (i == 0 && j == 0) || (*last_pt).row + i < 0  || (*last_pt).row + i > 14||
            (*last_pt).col + j < 0 || (*last_pt).col + j > 14)
            {
                continue;
            }            
            vector<Position>::iterator vter = vec_blank.begin();
            for (; vter < vec_blank.end(); vter++) {
                if (chessBoard[(*last_pt).row + i][(*last_pt).col + j] != chessBoardFlag)
                {
                    break; //��λ�ò��ǿ�
                }
                //��������ӵ㸽���п�ѡ��ʱ, �ȴ�ɾ��, Ȼ��Ӻ�ѡ���б��ײ�����
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

bool Chess::has_neightnor(vector<Position>::iterator pter) // �жϵ� *vter �Ƿ����ھӵ�
{
    vector<Position>::iterator vter = vec3.begin();
    if (vter == vec3.end())
    {
        return false; //�����δ��ʼ��һ��û���ھӵ�
    }
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            //�� i = j = 0 �Ǳ�ʾ�������, ��Ϊ���丽�������������� i = j = 0;
            if ((i == 0 && j == 0) || (*pter).row + i < 0 || (*pter).row + i > 14 ||
                (*pter).col + j < 0 || (*pter).col + j > 14){
                continue;
            }
            vter = vec3.begin(); //ѭ��ǰ����
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

//���͵���������, ��ʾ�����Ϊ��ͬ��״ʱ�ĵ÷�
vector<int> shape_score[15] = { {50, 0, 1, 1, 0, 0},
                                {50, 0, 0, 1, 1, 0,},
                                {200, 1, 1, 0, 1, 0},
                                {500, 0, 0, 1, 1, 1},
                                {500, 1, 1, 1, 0, 0},
                                {5000, 0, 1, 1, 1, 0},
                                {5000, 0, 1, 0, 1, 1, 0},
                                {5000, 0, 1, 1, 0, 1, 0},
                                {5000, 1, 1, 1, 0, 1},
                                {5000, 1, 1, 0, 1, 1},
                                {5000, 1, 0, 1, 1, 1},
                                {5000, 1, 1, 1, 1, 0},
                                {5000, 0, 1, 1, 1, 1},
                                {50000, 0, 1, 1, 1, 1, 0},
                                {inf, 1, 1, 1, 1, 1} };

int ratio = 1.2;  // ������ϵ��   ����1 �����ͣ�  С��1 ������

long int Chess::evaluate(int player) //��������, ��Ҫ��������ǰ��ֵĵ÷�
{
    //evaluate Ϊ����ʽ�����ۺ�����alpha + beta�������൱���ڼ���˫����ͬһ���ۺ�����������²���Ч
    long int total_score = 0;
    vector<Position> my_list;//�ٶ���ʼֵ
    vector<Position> enemy_list;

    if (player) { //��AI��
        my_list = vec1;
        enemy_list = vec2;
    }
    else {
        my_list = vec2;
        enemy_list = vec1;
    }

    //���Լ��ĵ÷�
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

    //����˵ĵ÷֣� ����ȥ
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


    //�������� ��ȥ �з�����
    total_score = my_score - (int)(enemy_score * ratio * 0.3);

    return total_score;

}



int Chess::cal_score(int m, int n, int x_direct, int y_direct, vector<Position>& enemy_list,
    vector<Position>& my_list) //ÿ�������ϵķ�ֵ����
{
    int max_score = 0; //���û��ƥ���ģ�ͷ��ؿ�ֵ
        
    //�����ӵ� ���ҷ�����ѭ�����ҵ÷���״
    for (int i = -5; i < 1; ++i)
    {
        vector<int> temp{}; //��ʱ����
        for (int j = 0; j < 6; ++j)
        {
            if (m + (i + j) * x_direct < 0 || m + (i + j) * x_direct >14 ||
                n + (i + j) * y_direct < 0 || n + (i + j) * y_direct > 14)//���������ж�
            {
                continue; //��һ���������⣬
            }
            vector<Position>::iterator pter1 = enemy_list.begin();
            vector<Position>::iterator pter2 = my_list.begin();
            while (pter1 != enemy_list.end() || pter2 != my_list.end())
            {
                
                if (m + (i + j) * x_direct == (*pter1).row && n + (i + j) * y_direct == (*pter1).col) {
                    //˵����λ���ǵз�����
                    temp.push_back(2);
                    break; // �˳�����һ��ѭ��
                }
                else if (m + (i + j) * x_direct == (*pter2).row && n + (i + j) * y_direct == (*pter2).col) {
                    //˵����λ�����ҷ�����
                    temp.push_back(1);
                    break;
                }
                
                if (pter1 == enemy_list.end()-1){
                    if (pter2 == my_list.end()-1) {
                        //˵����λ����˫����û������
                        temp.push_back(0);
                        break; //��Ϊ�գ������˳�ѭ��
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
            continue; //�ղ�����������ü��������
        }

        vector<int> tmp_shap5 = { temp[0], temp[1], temp[2], temp[3], temp[4] }; //��¼����������
        vector<int> tmp_shap6 = { temp[0], temp[1], temp[2], temp[3], temp[4] }; //��¼�����������
        if (temp.size() == 6)
        {
            tmp_shap6.push_back(temp[5]);//��ֹԽ��
        }
        
        for (int k = 0; k < 15; k++)
        {
            if (match_vector(tmp_shap5, shape_score[k]) || match_vector(tmp_shap6, shape_score[k])) {
                //ģ�ͼ�¼���������������Ϊ6������ͷ���ִ�
                if (shape_score[k][0] > max_score)
                {
                    max_score = shape_score[k][0]; //����
                }          
                    
            }
   
        }
        if (max_score == inf) {
            //�жϳ���Ӯ�ˣ����Խ�����
            break;
        }
    }

    return  max_score;

}
    
bool Chess::match_vector(vector<int>& temp, vector<int>& shape)
{
    vector<int>::iterator iter1 = temp.begin();
    vector<int>::iterator iter2 = shape.begin() + 1; //��һ��λ���Ƿ���
    while (iter1 != temp.end() && iter2 != shape.end()) 
        //ֻҪ��һ����ͷ�Ͳ��жϣ�ģ�ͼ�¼��5������������Ϊ6������ͷ���ִ�
    {
        if (*iter1 != *iter2)
            return false; //ģ�Ͳ�ƥ��
        else{ //����
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

int Chess::judge_postition(const Position& pos) //�ж�����ĺϷ���
{       
    //��������
    if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < N) {
        //����λ��Ϊ�գ�û�����ӣ�
        if (chessBoard[pos.row][pos.col] == chessBoardFlag) {
            return 1;      //�Ϸ�
        }
    }
    return 0;       //�Ƿ�
}

int Chess::judge_victory(Position pos, char flag)  //�ж��Ƿ�����һ�ʤ
{     
    int begin = 0;
    int end = 0;

    //�ж����Ƿ���������
    (pos.col - 4) >= 0 ? begin = (pos.col - 4) : begin = 0;//��ǰ̽4��λ��
    (pos.col + 4) >= N ? end = N - 1: end = (pos.col + 4);//����̽4��λ��
    for (int i = pos.row, j = begin; j + 4 <= end; ++j) 
    {
        if (chessBoard[i][j] == flag && chessBoard[i][j + 1] == flag &&
            chessBoard[i][j + 2] == flag && chessBoard[i][j + 3] == flag &&
            chessBoard[i][j + 4] == flag)//��������Χ�Ƿ������������
            return 1;

    }

    //�ж����Ƿ���������
    (pos.row - 4) >= 0 ? begin = (pos.row - 4) : begin = 0;
    (pos.row + 4) >= N ? end = N - 1: end = (pos.row + 4);
    for (int j = pos.col, i = begin; i + 4 <= end; ++i) {
        if (chessBoard[i][j] == flag && chessBoard[i + 1][j] == flag &&
            chessBoard[i + 2][j] == flag && chessBoard[i + 3][j] == flag &&
            chessBoard[i + 4][j] == flag)//��������Χ�Ƿ������������
            return 1;

    }

    //�ж����Խ����Ƿ���������
    int length = 0;    //��Գ���
    int start = 0;
    int finish = 0;
    pos.row > pos.col ? length = pos.col : length = pos.row; //ѡ��һ����С��ֵ���޽�
    if (length > 4) 
    {
        length = 4;
    }
    begin = pos.row - length;       //��������ʼλ��
    start = pos.col - length;       //��������ʼλ��

    pos.row > pos.col ? length = N - pos.row - 1 : length = N - pos.col - 1;
    if (length > 4) 
    {
        length = 4;
    }
    end = pos.row + length;         //���������λ��
    finish = pos.col + length;      //���������λ��

    for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish); ++i, ++j) 
    {
        if (chessBoard[i][j] == flag && chessBoard[i + 1][j + 1] == flag &&
            chessBoard[i + 2][j + 2] == flag && chessBoard[i + 3][j + 3] == flag &&
            chessBoard[i + 4][j + 4] == flag)
            return 1;
    }
    //�жϸ��Խ����Ƿ���������
    pos.row > (N - pos.col - 1) ? length = N - pos.col - 1 : length = pos.row;
    if (length > 4)
    {
        length = 4;
    }
    begin = pos.row - length;       //��������ʼλ��
    start = pos.col + length;       //��������ʼλ��

    (N - pos.row -1) > pos.col ? length = pos.col : length = N - pos.row - 1;
    if (length > 4) 
    {
        length = 4;
    }
    end = pos.row + length;         //���������λ��
    finish = pos.col - length;      //���������λ��

    for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish); ++i, --j) 
    {
        if (chessBoard[i][j] == flag && chessBoard[i + 1][j - 1] == flag &&
            chessBoard[i + 2][j - 2] == flag && chessBoard[i + 3][j - 3] == flag &&
            chessBoard[i + 4][j - 4] == flag)
            return 1;
    }
    
    //�������δ��ʼ
    for (int x = 0; x < N; ++x) 
    {
        for (int y = 0; y < N; ++y) 
        {
            if (chessBoard[x][y] == chessBoardFlag) 
            {
                return 0;       //δ����
            }
        }
    }
    return -1;      //�;�

}


char Chess::get_coordinate(int x, int y) //����(x,y)����Ϣ
{
    return chessBoard[x][y];

}
