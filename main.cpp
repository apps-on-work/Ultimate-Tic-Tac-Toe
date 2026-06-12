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
void computer_turnchange(char symbol){
    for(ll position=1;position<=9;++position){
        ll i=(position-1)/3,j=(position-1)%3;
        if(board[i][j]!='X' && board[i][j]!='O'){
            board[i][j]=symbol;break;
        }
    }
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
char winner(){
    for(ll i{};i<3;++i){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return board[i][0];
        }
    }
    for(ll i{};i<3;++i){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return board[0][i];
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return board[0][0];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return board[0][2];
    }
    for(ll position=1;position<=9;++position){
        ll i=(position-1)/3,j=(position-1)%3;
        if(board[i][j]!='X' && board[i][j]!='O') return 'U';
    }
    return 'D';
}
int main()
{
    initializeboard();
    printboard();
    char symbol=choose_symbol();
    char computer_symbol;
    if(symbol=='X')computer_symbol='O';
    else if(symbol=='O')computer_symbol='X';
    if(computer_symbol=='X'){
        computer_turnchange(computer_symbol);
        cout<<"Computer's turn: "<<endl;
        printboard();
    }
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
        cout<<"Your turn: "<<endl;
        printboard();
        char checkwinner=winner();
        if(checkwinner=='D'){
            cout<<"-----------"<<endl;
            cout<<"----DRAW---"<<endl;
            cout<<"-----------"<<endl;
            break;
        }else if(checkwinner==symbol){
            cout<<"-----------"<<endl;
            cout<<"-YOU WIN!!-"<<endl;
            cout<<"--PERFECT--"<<endl;
            cout<<"-----------"<<endl;
            break;
        }else if(checkwinner==computer_symbol){
            cout<<"-----------"<<endl;
            cout<<"-YOU LOSE!-"<<endl;
            cout<<"--GARBAGE--"<<endl;
            cout<<"-----------"<<endl;
            break;
        }
        computer_turnchange(computer_symbol);
        cout<<"Computer's turn: "<<endl;
        printboard();
        checkwinner=winner();
        if(checkwinner=='D'){
            cout<<"-----------"<<endl;
            cout<<"----DRAW---"<<endl;
            cout<<"-----------"<<endl;
            break;
        }else if(checkwinner==symbol){
            cout<<"-----------"<<endl;
            cout<<"-YOU WIN!!-"<<endl;
            cout<<"--PERFECT--"<<endl;
            cout<<"-----------"<<endl;
            break;
        }else if(checkwinner==computer_symbol){
            cout<<"-----------"<<endl;
            cout<<"-YOU LOSE!-"<<endl;
            cout<<"--GARBAGE--"<<endl;
            cout<<"-----------"<<endl;
            break;
        }
    }
    return 0;
}