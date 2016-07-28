#include<iostream>
#define V 4

using namespace std;

void printsolution(int color[]);

bool is_safe(int v,bool graph[V][V],int color[],int c){
    for (int i=0; i<V; i++){
        if(graph[v][i] && c == color[i])
            return false;
        return true;
    }
}
/* A RECURSIVE UTILITY FUNCTION TO SOLVE M COLORING PROBLEMM */

bool graphcoloringutil(bool graph[V][V],int m,int color[],int v){
    if(v==V)
        return true;

    for(int c = 1; c<=m;c++){

        if(is_safe(v, graph, color, c))
        {
            color[V] = c;

            if(graphcoloringutil(graph, m,color, v+1)== true)
                return true;

            color[V] = 0;
        }
    }
    return false;
}
bool graphcoloring(bool graph[V][V],int m){
    int *color = new int[V];
    for(int i=0;i<V;i++)
        color[i]=0;

    if(graphcoloringutil(graph,m,color,0)== false)
    {
        cout << "solution doesnot exist" << endl;
        return false;
    }
    printsolution(color);
    return true;
}
void printsolution(int color[]){
    cout << "Solution Exists: Following ae Assingment color \n";
    for(int i=0;i<V;i++){
        cout << color[i];
    }
    cout << endl;
}
int main(){
    bool graph[V][V] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int m =3;

    graphcoloring (graph,m);
    return 0;
}














