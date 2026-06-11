#include<iostream>
#include<string>
#define ll int
using namespace std;
string board[3][3];
void initializeboard(){
    for(ll i{};i<3;++i){
        for(ll j{};j<3;++j){
            ll x=3*i+j+1;
            board[i][j]=to_string(x);
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
ll turnchange(string symbol){
    ll x=0;cin>>x;
    if(x>9 || x<1){
        cout<<"Invalid input, Cell does not exist!"<<endl;
        return 0;
    }
    ll i=(x-1)/3,j=(x-1)%3;
    if(board[i][j]=="X" || board[i][j]=="O"){
        cout<<"Invalid input, Cell occupied"<<endl;
        return 0;
    }else{
        board[i][j]=symbol;
        return 1;
    }
    
}
ll computer_turnchange(string symbol){
    string str;
    if(symbol=="X") str="O";
    else if(symbol=="O") str="X";
    for(ll run=1;run<=9;++run){
        ll i=(run-1)/3;
        ll j=(run-1)%3;
        if(board[i][j]!="X" && board[i][j]!="O"){
            board[i][j]=str;
            return 1;
        }
    }
    return 0;
}
string playerturn(){
    cout<<"Please choose a symbol"<<endl;
    cout<<"X for first turn or O for second turn"<<endl;
    string str;cin>>str;
    while(str!="X" && str!="O"){
        cout<<"Invalid input, Symbol cannot be Identified!"<<endl<<"Re-enter: "<<endl;
        cin>>str;
    }
    return str;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    initializeboard();
    string symbol=playerturn();
    printboard();
    ll board_updated=turnchange(symbol);
    while(!board_updated)board_updated=turnchange(symbol);
    printboard();
    ll computer_board_updated=computer_turnchange(symbol);
    while(computer_turnchange(symbol)){
        printboard();
        board_updated=turnchange(symbol);
        while(!board_updated)board_updated=turnchange(symbol);
        printboard();
        computer_board_updated=computer_turnchange(symbol);
    }
    return 0;
}