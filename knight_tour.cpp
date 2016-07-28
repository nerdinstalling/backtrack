#include<iostream>
#define N 8
using namespace std;
int solvektutil(int x,int y,int movei,int sol[N][N],int x_move[N],int y_move[N]);

int is_safe(int x,int y,int sol[N][N]){
    if(x>=0 && x < N && y>=0 && y < N && sol[N][N] == -1)
        return 1;
    return 0;
}
void printsolution(int sol[N][N])
{
    for(int x =0; x<N; x++){
        for(int y=0;y<N;y++){
            cout << sol[x][y];
        }
        cout << endl;
    }
}
bool solvekt()
{
    int sol[N][N];
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            sol[x][y]=-1;
        }
    }
    int x_move[8] = {2,1,-1,-2,-2,-1,1,2};
    int y_move[8] = {1,2,2,1,-1,-2,-2,-1};

    sol[0][0] = 0;

    if(solvektutil(0,0,1,sol,x_move,y_move)== false)
    {
        cout << "solution does not exists";
        return false;
    }
    else
        printsolution(sol);
    return true;
}
int solvektutil(int x,int y,int movei,int sol[N][N],int x_move[N],int y_move[N])
{
    int k, next_x,next_y;
    if(movei == N*N)
        return true;
    for (k=0;k<8;k++){

        next_x = x + x_move[k];
        next_y = y + y_move[k];

        if (is_safe(next_x,next_y,sol)){
            sol [next_x][next_y] = movei;

            if(solvektutil(next_x,next_y,movei+1,sol,x_move,y_move)== true){
                return true;
            }
            else
                sol[next_x][next_y]= -1;
        }
    }
    return false;
}
int main(){
    solvekt();

    return 0;
}


