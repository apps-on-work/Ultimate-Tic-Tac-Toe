#include <iostream>
#define ll long long
using namespace std;
char board[3][3];
void clearboard(){
    for(ll i{};i<3;++i){
        for(ll j{};j<3;++j){
            board[i][j]=' ';
        }
    }
}
void rintboard(){
    cout<<"---------"<<endl;
    for(ll i{};i<3;++i){
        cout<<" "<<board[i][0]<<" "<<"|"<<" "<<board[i][1]<<" "<<"|"<<" "<<board[i][2]<<" "<<endl;
        cout<<"---------"<<endl;
    }
}
int main()
{
    cout << "Tic Tac Toe\n";
    clearboard();
    rintboard();
    return 0;
}