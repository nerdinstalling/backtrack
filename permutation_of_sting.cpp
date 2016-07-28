#include<iostream>
#include<cstring>

using namespace std;

void swap(char *x,char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* Function to print pemutation of string
   This function take 3 parameter
   1.string
   2.starting index of string
   3.ending index of string */

void permute(char *a,int l ,int r){

    if (l==r)
        cout << a << endl;
    else
    {
        for (int i=l;i<=r;i++){
            swap ((a+l),(a+i));
            permute(a,l+1,r);
            swap ((a+l),(a+i));
        }
    }
}

int main(){
    char str[]= "ABC";
    int n = strlen(str);
    permute(str,0,n-1);
    return 0;

}


