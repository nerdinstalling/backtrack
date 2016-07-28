#include <iostream>
#define N 4

using namespace std;

bool solvemazeutil(int maze[N][N],int x,int y,int sol[N][N]);

void printsolution(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << sol[i][j];
        }
        cout << endl;
    }
}

bool is_safe(int maze[N][N],int x,int y){
    if(x >=0 && x <N && y >=0 && y < N && maze[x][y] ==1)
        return true;
    return false;
}
bool solvemaze(int maze[N][N]){
    int sol[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    if(solvemazeutil(maze,0,0,sol)== false){
        cout << "solution doesnot exists" << endl;
        return false;
    }
    printsolution(sol);
    return true;
}
// A RECURSIVE UTILITY FUNCTON TO SOLVE MAZE PROBLEM

bool solvemazeutil(int maze[N][N],int x,int y,int sol[N][N]){
    /* if (x,y is goal) return true */
    if (x == N-1 && y == N-1){
        sol[x][y] = 1;
        return true;
    }
    if (is_safe(maze,x,y) == true){

        sol[x][y] = 1;

        if (solvemazeutil(maze,x+1,y,sol)== true){
            return true;
        }
        if (solvemazeutil(maze,x,y+1,sol) == true)
            return true;

        sol[x][y] = 0;

        return false;
    }
    return false;
}
int main(){
    int maze[N][N] = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    solvemaze(maze);
    return 0;
}











