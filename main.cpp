#include<iostream>
#include<string>
#define ll int
using namespace std;
char board[3][3];
void initializeboard(){
    for(ll i{};i<3;++i){
        for(ll j{};j<3;++j){
            ll x=3*i+j+1;
            board[i][j]=x+'0';
        }
    }
}
void printboard(){
    cout<<"-----------"<<endl;
    for(ll i{};i<3;++i){
        cout<<" "<<board[i][0]<<" "<<"|"<<" "<<board[i][1]<<" "<<"|"<<" "<<board[i][2]<<" "<<endl;
        cout<<"-----------"<<endl;
    }
}
bool turnchange(ll position, char symbol){
    if(position>9 || position<1){
        cout<<"Invalid input, Cell does not exist!"<<endl;
        return false;
    }
    ll i=(position-1)/3,j=(position-1)%3;
    if(board[i][j]=='X' || board[i][j]=='O'){
        cout<<"Invalid input, Cell occupied"<<endl;
        return false;
    }
    board[i][j]=symbol;
    return true;
}
bool computer_turnchange(char symbol){
    for(ll position=1;position<=9;++position){
        ll i=(position-1)/3,j=(position-1)%3;
        if(board[i][j]!='X' && board[i][j]!='O'){
            board[i][j]=symbol;
            return true;
        }
    }
    return false;
}
char choose_symbol(){
    char symbol;string str;
    cout<<"Choose a symbol [X] for first turn and [O] for second turn: ";getline(cin, str);symbol=str[0];
    symbol=toupper(symbol);
    while((symbol!='X' && symbol!='O') || str.size()!=1){
        cout<<"Invalid input. Enter X or O: ";getline(cin, str);symbol=str[0];
        symbol=toupper(symbol);
    }
    return symbol;
}
int main()
{
    initializeboard();
    char symbol=choose_symbol();
    char computer_symbol;
    if(symbol=='X')computer_symbol='O';
    else if(symbol=='O')computer_symbol='X';
    printboard();
    while(1){
        ll position=0;bool turn_taken=false;
        while(!turn_taken){
            cout<<"Make you move by putting the cell number [0-9]: ";
            while(!(cin>>position)){
                cout<<"Invalid input, input beyond scope. Re-enter: ";
                cin.clear();cin.ignore(1000000, '\n');
            }
            turn_taken=turnchange(position, symbol);
        }
        printboard();
        if(!computer_turnchange(computer_symbol)) break;
        printboard();
    }
    return 0;
}