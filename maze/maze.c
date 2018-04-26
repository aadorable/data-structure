#include <stdio.h>
#include "seqstack.h"

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

void MazeInitMultiExit(Maze* maze){
    if(maze == NULL){
        return;
    }
    int map[MAZE_ROW][MAZE_COL] = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0},
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

void MazeInitMultiExitWithCycle(Maze* maze){
    if(maze == NULL){
        return;
    }
    int map[MAZE_ROW][MAZE_COL] = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0},
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

void _GetShortPath(Maze* maze, Point cur, Point entry, SeqStack* short_path, SeqStack* cur_path){
    //1.判断当前点是否能落脚
    if(!CanStay(maze, cur)){
        return;
    }
    //2.标记当前点，把当前点push到cur_path
    Mark(maze, cur);
    SeqStackPush(cur_path, cur);
    //3.判断当前点是否是出口，如果是出口
    if(IsExit(cur, entry)){
        //   a)比较当前点的 cur_path 和 short_path 的长短
        SeqStackDebugPrintPoint(cur_path, "找到一条路径！");
        if(SeqStackSize(cur_path) < SeqStackSize(short_path) || SeqStackSize(short_path) == 0){
           //   b)如果 cur_path 比 short_path 小，或者 short_path 为空，就用 cur_path 替换 short_path
           SeqStackAssign(cur_path, short_path);
           printf("当前路径是一条比较短的路径\n");
        }   
        //   c)让 cur_path 出栈，同时返回上一层栈帧
        SeqStackPop(cur_path);
        return;
    }
    //4.按照一定顺序，递归的调用该函数完成邻接点的判定
    Point up = cur;
    up.row -= 1;
    _GetShortPath(maze, up, entry, short_path, cur_path);

    Point right = cur;
    right.col += 1;
    _GetShortPath(maze, right, entry, short_path, cur_path);

    Point down = cur;
    down.row += 1;
    _GetShortPath(maze, down, entry, short_path, cur_path);

    Point left = cur;
    left.col -= 1;
    _GetShortPath(maze, left, entry, short_path, cur_path);
    //5.回溯到上一个位置，先将 cur_path 出栈，然后return
    SeqStackPop(cur_path);
    return;
}

void GetShortPath(Maze* maze,Point entry){
    SeqStack short_path;     //保存最短路径
    SeqStack cur_path;      //当前找到的路径是哪个
    SeqStackInit(&short_path);
    SeqStackInit(&cur_path);
    _GetShortPath(maze, entry, entry, &short_path, &cur_path);
    SeqStackDebugPrintPoint(&short_path, "最短路径是：");
}

int CanStayWithCycle(Maze* maze, Point cur, Point pre){
    //1.判定当前点是否在地图上，如果不在，就不能落脚
    if(cur.row < 0 || cur.row >= MAZE_ROW || cur.col < 0 || cur.col >= MAZE_COL){
        return 0;
    }
    //2.判定当前点的值是否为1，是1则一定能落脚
    int cur_value = maze->map[cur.row][cur.col];
    if(cur_value == 1){
        return 1;
    }
    //3.判定当前点的值和前一个点的值得大小
    //  满足 cur_value -1 > pre_value 时才能落脚
    if(pre.row >= 0 && pre.row < MAZE_ROW && pre.col >= 0 && pre.col < MAZE_COL){
        //判定pre合法
        int pre_value = maze->map[pre.row][pre.col];
        if(cur_value - 1 > pre_value){
            return 1;
        }
    }
    return 0;
}

void MarkWithCycle(Maze* maze, Point cur, Point pre){
    if(pre.row < 0 || pre.row >= MAZE_ROW || pre.col < 0 || pre.col >= MAZE_COL){
        //pre不合法
        maze->map[cur.row][cur.col] = 2;
        return;
    }
    int pre_value = maze->map[pre.row][pre.col];
    maze->map[cur.row][cur.col] = pre_value + 1;
}

void _GetShortPathWithCycle(Maze* maze, Point cur, Point pre, Point entry, SeqStack* short_path, SeqStack* cur_path){
    //1.判断当前点是否能落脚(判定落脚方式有变化)
    if(!CanStayWithCycle(maze, cur, pre)){
        return;
    }
    //2.如果能落脚，就标记当前点(标记方式也有变化)，把当前点入栈
    MarkWithCycle(maze, cur, pre);
    SeqStackPush(cur_path, cur);
    //3.判断当前点是否是出口，如果是出口
    if(IsExit(cur, entry)){
        //   a)比较当前点的 cur_path 和 short_path 的长短
        SeqStackDebugPrintPoint(cur_path, "找到一条路径:");
        if(SeqStackSize(cur_path) < SeqStackSize(short_path) || SeqStackSize(short_path) == 0){
           //   b)如果 cur_path 比 short_path 小，或者 short_path 为空，就用 cur_path 替换 short_path
            SeqStackAssign(cur_path, short_path);
        }
        //   c)让 cur_path 出栈，并回溯
        SeqStackPop(cur_path);
        return;
    }
    //4.如果不是出口，以当前点为基准，探测四个方向，递归调用该函数
    Point up = cur;
    up.row -= 1;
    _GetShortPathWithCycle(maze, up, cur, entry, short_path, cur_path);

    Point right = cur;
    right.col += 1;
    _GetShortPathWithCycle(maze, right, cur, entry, short_path, cur_path);

    Point down = cur;
    down.row += 1;
    _GetShortPathWithCycle(maze, down, cur, entry, short_path, cur_path);

    Point left = cur;
    left.col -= 1;
    _GetShortPathWithCycle(maze, left, cur, entry, short_path, cur_path);
    //5.四个方向都探测完了，出栈，并回溯
    SeqStackPop(cur_path);
    return;
}

void GetShortPathWithCycle(Maze* maze,Point entry){
    SeqStack short_path;     //保存最短路径
    SeqStack cur_path;      //当前找到的路径是哪个
    SeqStackInit(&short_path);
    SeqStackInit(&cur_path);
    Point pre = {-1, -1};
    _GetShortPathWithCycle(maze, entry, pre, entry, &short_path, &cur_path);
    SeqStackDebugPrintPoint(&short_path, "最短路径是：");
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

void Test4(){
    TEST_HEADER;
    Maze maze;
    MazeInitMultiExit(&maze);
    Point entry = {0, 1};
    GetShortPath(&maze, entry);
    MazePrint(&maze);
}

void Test5(){
    TEST_HEADER;
    Maze maze;
    MazeInitMultiExitWithCycle(&maze);
    Point entry = {0, 1};
    GetShortPathWithCycle(&maze, entry);
    MazePrint(&maze);
}

int main(){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}

