/*
名称：贪吃蛇
编写时间：2021年10月14日
作者：王洋
学号：2019201524
Copyright 2021  Wang Yang, Inc. All rights reserved.
*/
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=100;

struct Point{//点类，包含横纵坐标
    int x,y;
    bool operator == (const Point &p)const{
        return x==p.x&&y==p.y;
    }
};

int random(int MIN,int MAX){//随机生成一个[MIN,MAX]之间的整数
    return rand()%(MAX-MIN+1)+MIN;
}

char mp[maxn][maxn];//记录地图上所有位置的符号

void print(int y,int x,char ch){// 输出字符ch到控制台的(x,y)坐标处
	COORD pos={(short)x,(short)y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
    CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible=FALSE;
	cursor.dwSize=sizeof(cursor);
	SetConsoleCursorInfo(hOut,&cursor);
    putchar(ch);
    mp[y][x]=ch;//更新地图
}

char dir;//当前前进方向
Point head,tail,food;//蛇头、蛇尾、食物的坐标
Point pre[maxn][maxn];//每个蛇身的前一个蛇身的位置
int growth;//当前还需要增长的长度

void greater_food(){//生成新的食物
    vector<Point> vec;//不定长数组储存所有没被蛇占用的点
    vec.clear();
    rep(i,1,15){
        rep(j,1,15){
            if(mp[i][j]=='.'){
                vec.push_back(Point{i,j});
            }
        }
    }
    food=vec[random(0,(int)vec.size()-1)];//在所有空位置随机出一个放置食物
    print(food.x,food.y,'@');
}

void init(){//初始化地图、蛇和食物
    system("cls");
    rep(i,1,15){
        rep(j,1,15){
            print(i,j,'.');
            pre[i][j]={0,0};
        }
    }
    dir='d';
    head={8,8};
    tail={8,5};
    rep(j,5,7)pre[8][j]={8,j+1};
    rep(j,5,7)print(8,j,'o');
    print(8,8,'#');
    growth=0;
    greater_food();
}

int main(){
    while(1){
        game:
        init();//初始化
        while(1){
            char ch;
            while(ch=_getch()){
                if((ch=='w'&&dir=='s')||(ch=='s'&&dir=='w')||(ch=='a'&&dir=='d')||(ch=='d'&&dir=='a'))continue;//如果输入和当前方向相反，忽略
                else if(ch=='w'||ch=='s'||ch=='a'||ch=='d'){
                    dir=ch;//采用输入为新的方向
                    break;
                }
            }
            if(dir=='w'){
                if(!growth){//如果没有待增长的长度
                    print(tail.x,tail.y,'.');//将当前蛇尾位置变为空
                    Point tmp=tail;
                    tail=pre[tail.x][tail.y];//当前蛇尾的前一个蛇身为新的蛇尾
                    pre[tmp.x][tmp.y]={0,0};
                }
                else growth--;//有待增长的长度，蛇尾不动即可
                pre[head.x][head.y]={head.x-1,head.y};
                print(head.x,head.y,'o');
                head.x--;//蛇头向对应位置移动一位
                print(head.x,head.y,'#');
            }
            if(dir=='s'){
                if(!growth){
                    print(tail.x,tail.y,'.');
                    Point tmp=tail;
                    tail=pre[tail.x][tail.y];
                    pre[tmp.x][tmp.y]={0,0};
                }
                else growth--;
                pre[head.x][head.y]={head.x+1,head.y};
                print(head.x,head.y,'o');
                head.x++;
                print(head.x,head.y,'#');
            }
            if(dir=='a'){
                if(!growth){
                    print(tail.x,tail.y,'.');
                    Point tmp=tail;
                    tail=pre[tail.x][tail.y];
                    pre[tmp.x][tmp.y]={0,0};
                }
                else growth--;
                pre[head.x][head.y]={head.x,head.y-1};
                print(head.x,head.y,'o');
                head.y--;
                print(head.x,head.y,'#');
            }
            if(dir=='d'){
                if(!growth){
                    print(tail.x,tail.y,'.');
                    Point tmp=tail;
                    tail=pre[tail.x][tail.y];
                    pre[tmp.x][tmp.y]={0,0};
                }
                else growth--;
                pre[head.x][head.y]={head.x,head.y+1};
                print(head.x,head.y,'o');
                head.y++;
                print(head.x,head.y,'#');
            }
            if(head.x<1||head.x>15||head.y<1||head.y>15||!(pre[head.x][head.y]==Point{0,0})){//如果蛇头超出地图范围或蛇头撞到蛇身
                GG:
                print(8,20,'G');printf("ame Over!");
                Sleep(5000);
                goto game;//开始下一局游戏
            }
            if(head==food){//蛇头吃到了食物
                greater_food();//生成新的食物
                growth+=3;//待增长长度+3
            }
        }
    }
    return 0;
}