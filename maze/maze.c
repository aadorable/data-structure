#include <stdio.h>
#include "../seqstack/seqstack.h"

#define MAZE_ROW 6
#define MAZE_COL 6

typedef struct Maze{
    int map[MAZE_ROW][MAZE_COL];
}Maze;

void MazePrint(Maze* maze){
    if(maze == NULL){
        return;
    }
    size_t i = 0;
    for(; i<MAZE_ROW; ++i){
        size_t j = 0;
        for(; j<MAZE_COL; ++j){
            printf("%d ",maze->map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void MazeInit(Maze* maze){
    if(maze == NULL){
        return;
    }
    int map[MAZE_ROW][MAZE_COL] = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };
    size_t i = 0; 
    for(; i<MAZE_ROW; ++i){
        size_t j = 0;
        for(; j<MAZE_COL; ++j){
            maze->map[i][j] = map[i][j];
        }
    }
}

int CanStay(Maze* maze,Point cur){
    if(maze == NULL){
        return 0;
    }
    //1.点在地图上
    if(cur.row < 0 || cur.row >= MAZE_ROW
       || cur.col < 0 || cur.col >= MAZE_COL){
        return 0;
    }
    //2.当前点对应值为1
    if(maze->map[cur.row][cur.col] == 1){
        return 1;
    }
    return 0;
}

void Mark(Maze* maze, Point cur){
    if(maze == NULL){
        return;
    }
    maze->map[cur.row][cur.col] = 2;
}

int IsExit(Point cur, Point entry){
    //1.点在地图边缘
    //2.不是入口点
    if(cur.row == 0 || cur.col == 0
       ||cur.row == MAZE_ROW - 1 || cur.col == MAZE_COL - 1){
        //在边缘上
        if(cur.row == entry.row && cur.col == entry.col){
            //是入口点
            return 0;
        }
        return 1;
    }
    return 0;
}

void _HasPath(Maze* maze,Point cur, Point entry){
    if(maze == NULL){
        return;
    }
    //1.判断该点是否可以落脚(点在地图上；位置的值是1)
    if(!CanStay(maze,cur)){
        return;
    }
    //2.标记走过的点
    Mark(maze,cur);
    //3.判定当前点是否是出口(落在边缘上；不是入口点)
    if(IsExit(cur, entry)){
        printf("找到了路径！\n");
        return;
    }
    //4.顺时针递归探测周围的点是否可以落脚
    Point up = cur;
    up.row -= 1;
    _HasPath(maze, up, entry);

    Point right = cur;
    right.col += 1;
    _HasPath(maze, right, entry);

    Point down = cur;
    down.row += 1;
    _HasPath(maze, down, entry);

    Point left = cur;
    left.col -= 1;
    _HasPath(maze, left, entry);

    //5.如果四个方向都探测完，直接返回
    return;
}

//使用递归的方法查找是否存在一条路径
void HasPath(Maze* maze,Point entry){
    if(maze == NULL){
        return;
    }
    Point cur = entry;
    _HasPath(maze, cur, entry);
}

//使用非递归方法查找是否存在一条路径
void HasPathByLoop(Maze* maze, Point entry){
    if(maze == NULL){
        return;
    }
    //1.判定入口点是否能落脚，如果不能，表示非法输入
    if(!CanStay(maze, entry)){
        return;      //入口点是非法点
    }
    //2.标记入口点走过了，将入口点入栈
    Mark(maze, entry);
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack, entry);
    //3.进入循环，取栈顶元素为当前点
    Point cur;
    while(SeqStackTop(&stack, &cur)){
        //4.判定当前点是否是出口（如果是出口，说明找到路径）
        if(IsExit(cur, entry)){
            printf("找到路径！\n");
            return;
        }
        //5.按照一定顺序判断当前点的四个邻接点是否能落脚
        Point up = cur;
        up.row -= 1;
        if(CanStay(maze, up)){
            //6.如果某个邻接点可以落脚，标记这个邻接点，并且把邻接点入栈，并且直接进入下一次循环
            Mark(maze, up);
            SeqStackPush(&stack, up);
            continue;
        }
        Point right = cur;
        right.col += 1;
        if(CanStay(maze, right)){
            Mark(maze, right);
            SeqStackPush(&stack, right);
            continue;
        }
        Point down = cur;
        down.row += 1;
        if(CanStay(maze, down)){
            Mark(maze, down);
            SeqStackPush(&stack, down);
            continue;
        }
        Point left = cur;
        left.col -= 1;
        if(CanStay(maze, left)){
            Mark(maze, left);
            SeqStackPush(&stack, left);
            continue;
        }
        //7.四个方向都探测完毕，把当前点出栈
        SeqStackPop(&stack);
    }
    return;
}

////////////////////////////////////////////////////////////////////////////////
//以下是测试代码
////////////////////////////////////////////////////////////////////////////////

#define TEST_HEADER printf("\n=======%s========\n",__FUNCTION__)

void Test1(){
    TEST_HEADER;
    Maze maze;
    MazeInit(&maze);
    MazePrint(&maze);
}

void Test2(){
    TEST_HEADER;
    Maze maze;
    MazeInit(&maze);
    Point entry = {0,1};
    HasPath(&maze, entry);
    MazePrint(&maze);
}

void Test3(){
    TEST_HEADER;
    Maze maze;
    MazeInit(&maze);
    Point entry = {0, 1};
    HasPathByLoop(&maze, entry);
    MazePrint(&maze);
}

int main(){
    Test1();
    Test2();
    Test3();
    return 0;
}








