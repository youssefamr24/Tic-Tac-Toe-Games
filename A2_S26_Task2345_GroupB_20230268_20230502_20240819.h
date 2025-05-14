#ifndef UNTITLED2_TIC_TAC_TOE_GAMES_H
#define UNTITLED2_TIC_TAC_TOE_GAMES_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include "BoardGame_Classes.h"
#include "3x3X_O.h"
#include "MinMaxPlayer.h"
using namespace std;
string rev(string s);
template <typename T>
class ultimate_board : public Board<T> {
protected:
    X_O_Board<T>boards[10];
public:
    ultimate_board();
    bool is_win();
    T is_winne(int x,int y);
    bool is_draw();
    void display_board();
    bool update_board(int x, int y, T mark);
    bool game_is_over() ;
};
template <typename T>
class ultimate_player : public Player <char>{
public:
    ultimate_player(string name, T symbol);
    void getmove(int& x, int& y);
};
template <typename T>
class ultimate_Rplayer : public X_O_Random_Player <char>{
public:
    ultimate_Rplayer(T symbol) ;
    void getmove(int& x, int& y);
};
template <typename T>
class Pyramid_board : public Board<T>{
public:
    Pyramid_board ();
    void display_board() override;
    virtual bool update_board(int x, int y, T symbol) override;
    virtual bool is_win() override;
    virtual bool is_draw() override;
    virtual bool game_is_over() override;
};
template <typename T>
class Pyramid_player : public Player<T>{
public:
    Pyramid_player(string name, T symbol) ;
    void getmove(int& x, int& y);
};
template <typename T>
class Pyramid_Random_Player : public RandomPlayer<T>{
protected:
    vector<pair<int, int>> spots = {{0, 2}, {1, 1}, {1, 2}, {1, 3}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}};
public:
    Pyramid_Random_Player(T symbol);
    void getmove(int& x, int& y) override;
};
extern vector<pair<int,int>> spots ;
template <typename T>
class Pyramid_X_O_MinMax_Player : public Player<T> {
public:
    Pyramid_X_O_MinMax_Player(T symbol);
    void getmove(int& x, int& y);
private:
    pair<int, int> getBestMove();
};
template <typename T>
class word_X_O_board : public Board<T>{
protected:
    vector<string>words;
public:
    word_X_O_board();
    bool update_board(int x, int y, T mark);
    bool is_win();
    void display_board();
    bool is_draw();
    bool game_is_over();
};
template <typename T>
class word_X_O_player : public Player<T>{
public:
    word_X_O_player(string name);
    void getmove(int& x, int& y);
};
template <typename T>
class word_X_O_aplayer : public RandomPlayer<T>{
public:
    word_X_O_aplayer();
    void getmove(int& x, int& y) override ;
};
template <typename T>
class word_X_O_AI_player : public RandomPlayer<T>{
protected:
    vector<char>letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
public:
    word_X_O_AI_player();
    void getmove(int& x, int& y);
private:
    pair<int, int> getBestMove();
};
template <typename T>
class FXF_X_O_board : public Board<T>{
public:
    FXF_X_O_board();
    bool update_board(int x, int y, T mark);
    bool is_valid(int x, int y , T mark);
    void remove_cell(int x , int y);
    bool is_win();
    bool is_draw();
    bool game_is_over();
    void display_board();
};
template <typename T>
class FBF_player : public Player <T>{
public:
    FBF_player(string name, T symbol);
    void getmove(int& x, int& y);
};
template <typename T>
class FBF_Rplayer : public RandomPlayer <T>{
protected:
    vector<pair<int,int>>moves={{0,1},{0,-1},{1,0},{-1,0}};
public:
    FBF_Rplayer(T symbol) ;
    void getmove(int& x, int& y);
};
template <typename T>
class Numerical_TicTacToe_Board : public Board<T> {
public:
    Numerical_TicTacToe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};
template <typename T>
class Numerical_TicTacToe_Player : public Player<T> {
public:
    vector<int> available_numbers;
    Numerical_TicTacToe_Player(string name, T symbol);
    T getsymbol();
    string getname();
    void getmove(int& x, int& y);
    void setBoard(Numerical_TicTacToe_Board<T>* board) {
        this->boardPtr = board;
    }
};
template <typename T>
class Numerical_TicTacToe_Random_Player : public RandomPlayer<T> {
public:
    vector<int> available_numbers;
    Numerical_TicTacToe_Random_Player(T symbol);
    void getmove(int& x, int& y);
    void setBoard(Numerical_TicTacToe_Board<T>* board) {
        this->boardPtr = board;
    }
};
template <typename T>
class Numerical_TicTacToe_AI_Player : public RandomPlayer<T>{
public:
    vector<int> available_numbers;
    Numerical_TicTacToe_AI_Player(T symbol);
    void getmove(int& x, int& y);
private:
    pair<int, int> getBestMove();
};
template <typename T>
class Four_in_A_Row_Board : public Board<T> {
public:
    Four_in_A_Row_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Four_in_A_Row_Player : public Player<T> {
public:
    Four_in_A_Row_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class Four_in_A_Row_Random_Player : public Player<T> {
public:
    Four_in_A_Row_Random_Player(T symbol);
    void getmove(int& x, int& y);
};
template <typename T>
class reverse_x_oBoard :public Board<T> {
public:
    reverse_x_oBoard();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

};
template <typename T>
class reverse_x_oPlayer : public Player<T> {
public:
    reverse_x_oPlayer(string name, T symbol);
    void getmove(int& x, int& y);

};
template <typename T>
class reverse_x_oRandom_Player : public RandomPlayer<T> {
public:
    reverse_x_oRandom_Player(string name, T symbol);
    void getmove(int& x, int& y);
};
template <typename T>
class FIVEttc : public Board<T>
{
public:
    FIVEttc() ;
    bool update_board(int x, int y, T mark)override;
    void display_board()override ;
    bool is_win() override ;
    bool is_draw() override ;
    bool game_is_over()override ;
};

template <typename T>
class game_player :public Player<T> {
public:
    game_player(string name, T sympol);
    void getmove(int& x, int& y) ;
};

template <typename T>
class game_random : public RandomPlayer<T> {
public:
    // Constructor
    game_random(T symbol);
    void getmove(int& x, int& y);
};
class menu{
public:
    menu();
private:
    void wordxo();
    void pyramidxo();
    void four_by_four ();
    void ultimate();
    void Numerical_TicTacToe();
    void connect_four();
    void reverse_tic_tac_toe();
    void five_tic_tac_toe();
};


//--------------------------------------- IMPLEMENTATION
int  x1  ,w1 ;
vector<pair<int,int>>ind = {{0,0},{0,1},{0,2},{0,3},{3,0},{3,1},{3,2},{3,3}};
string rev(string s){
    string g = s;
    reverse(g.begin(),g.end());
    return g;
}
template <typename T>
ultimate_board<T>::ultimate_board(){
    this->rows = this->columns = 9;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
}
template <typename T>
bool ultimate_board<T>::is_win(){
    return boards[9].is_win();
}
template <typename T>
T ultimate_board<T>::is_winne(int x,int y){
    for (int i = x; i < x + 3; i++) {
        if (this->board[i][y] == this->board[i][y + 1] &&
            this->board[i][y + 1] == this->board[i][y + 2] &&
            this->board[i][y] != ' ') {
            return this->board[i][y];
        }
    }
    for (int j = y; j < y + 3; j++) {
        if (this->board[x][j] == this->board[x + 1][j] &&
            this->board[x + 1][j] == this->board[x + 2][j] &&
            this->board[x][j] != ' ') {
            return this->board[x][j];
        }
    }
    if (this->board[x][y] == this->board[x+1][y+1] && this->board[x+1][y+1] == this->board[x+2][y+2] && this->board[x][y] != ' '){
        return this->board[x][x];
    }
    if (this->board[x][y+2] == this->board[x+1][y+1] && this->board[x+1][y+1] == this->board[x+2][y] && this->board[x][y+2] != ' ') {
        return this->board[x][x+2];
    }
    return ' ';
}
template <typename T>
bool ultimate_board<T>::is_draw(){
    return (this->n_moves == 81 && !is_win());
}
template <typename T>
void ultimate_board<T>::display_board() {
    cout << endl;
    cout << endl << string (27,'*') << " *  " << string (25,'*') << "   *  " << string (25,'*') << "   *  ";
    for (int i = 0; i < this->rows; i++) {
        cout << "\n* ";
        for (int j = 0; j < this->columns; j++) {
            int sub_board_index = (i / 3) * 3 + (j / 3);
            if (boards[sub_board_index].is_win()) {
                char winner = is_winne(i - i % 3, j - j % 3);
                boards[9].update_board(sub_board_index / 3, sub_board_index % 3, winner);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        this->board[i - i % 3 + x][j - j % 3 + y] = winner;
                    }
                }
            }
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " *";
            if (j % 3 == 2) {
                cout << "    ";
            }
        }
        if(i%3 == 2){
            cout << endl << string (27,'*') << " *  " << string (25,'*') << "   *  " << string (25,'*') << "   *  ";
        }
        else{
            cout << endl << string (85,'-');
        }
    }
    cout << endl;
    boards[9].display_board();
    cout << endl;
}
template <typename T>
bool ultimate_board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == ' '|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            int sub_board_index = (x / 3) * 3 + (y / 3);
            this->n_moves++;
            this->board[x][y] = toupper(mark);
            this->boards[sub_board_index].update_board(x%3,y%3,mark);
        }
        return true;
    }
    return false;
}
template <typename T>
bool ultimate_board<T>:: game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
ultimate_player<T>::ultimate_player(string name, T symbol) : Player<T>(name, symbol){}
template <typename T>

void ultimate_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 8) separated by spaces: ";
    cin >> x >> y;
}
template <typename T>
ultimate_Rplayer<T>::ultimate_Rplayer(T symbol) : X_O_Random_Player<T>(symbol){
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
template <typename T>
void ultimate_Rplayer<T>:: getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}
template <typename T>
Pyramid_board<T>::Pyramid_board (){
    this->rows = 3;
    this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];  // Allocate proper size
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}
template <typename T>
void Pyramid_board<T>::display_board(){
    for (int i = 0; i < 3; i++) {
        cout << string((2-i)*11,' ');
        for (int j = 0; j < 5; j++) {
            if(i==0 && j==2){
                cout <<"[ (" << i << "," << j << ")"<<setw(2) << this->board[i][j] << " ]";
            }
            else if(i==1 && (j==1 || j==2 || j==3)){
                cout <<"[ (" << i << "," << j << ")"<<setw(2) <<this->board[i][j] << " ]";
            }
            else if(i==2){
                cout <<"[ (" << i << "," << j << ")"<<setw(2) <<this->board[i][j] << " ]";
            }
        }
        cout << endl;
    }
    cout << endl;
}
template <typename T>
bool Pyramid_board<T>:: update_board(int x, int y, T symbol) {
    if(this->n_moves<9){
        if (symbol == 0){
            this->n_moves--;
            this->board[x][y] = 0;
            return true;
        }
        if(x==0 && y==2 && this->board[x][y]==0){
            this->board[x][y]=symbol;
            this->n_moves+=1;
            return true;
        }
        else if(x==2 && y<5 && y > -1 && this->board[x][y]==0){
            this->board[x][y]=symbol;
            this->n_moves+=1;
            return true;
        }
        else if(x==1 && y > 0 && y < 4 && this->board[x][y]==0){
            this->board[x][y]=symbol;
            this->n_moves+=1;
            return true;
        }
    }
    return false;
}
template <typename T>
bool Pyramid_board<T>:: is_win() {
    if(this->board[0][2] == this->board[1][2] && this->board[0][2] == this->board[2][2] && this->board[0][2] != 0){
        return true;
    }
    else if(this->board[1][1] == this->board[1][2] && this->board[1][1] == this->board[1][3] && this->board[1][1] != 0){
        return true;
    }
    else if(this->board[0][2] == this->board[1][1] && this->board[0][2] == this->board[2][0] && this->board[0][2] != 0){
        return true;
    }
    else if(this->board[0][2] == this->board[1][3] && this->board[0][2] == this->board[2][4] && this->board[0][2] != 0){
        return true;
    }
    else{
        for(auto j = 0 ; j < 3 ;j++){
            if(this->board[2][j] == this->board[2][j+1] && this->board[2][j] == this->board[2][j+2] && this->board[2][j] != 0){
                return true;
            }
        }
        return false;
    }
}
template <typename T>
bool Pyramid_board<T>:: is_draw(){
    if(this->n_moves==9){
        return true;
    }
    return false;
}
template <typename T>
bool Pyramid_board<T>:: game_is_over(){
    return is_draw() || is_win();
}
template <typename T>
Pyramid_player<T>::Pyramid_player(string name, T symbol) : Player<T>(name, symbol) {}
template <typename T>
void Pyramid_player<T>:: getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}
template <typename T>
Pyramid_Random_Player<T>::Pyramid_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void Pyramid_Random_Player<T>:: getmove(int& x, int& y){
    int i = rand()%spots.size();
    x = spots[i].first;
    y = spots[i].second;
    spots.erase(spots.begin()+i);
}
vector<pair<int,int>> spots = {{0,2},{1,1} , {1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{2,4}};
template <typename T>
Pyramid_X_O_MinMax_Player<T> :: Pyramid_X_O_MinMax_Player(T symbol): Player<T>(symbol) {
    this->name = "AI Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void Pyramid_X_O_MinMax_Player<T> :: getmove(int& x, int& y){
    pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;
}
template <typename T>
pair<int, int> Pyramid_X_O_MinMax_Player<T> ::  getBestMove() {
    if(spots.size() == 1){
        return {spots[0].first,spots[0].second};
    }
    int i , j ;
    pair<int,int> values;
    T opponentSymbol = (this->symbol == 'X') ? 'O' : 'X';
    for(auto k = 0 ; k < spots.size();k++){
        i = spots[k].first ; j = spots[k].second;
        if (this->boardPtr->update_board(i, j, this->symbol)) {
            if (this->boardPtr->is_win()) {
                this->boardPtr->update_board(i, j, 0); // Undo move
                for(auto k = 0 ; k < spots.size() ;k++){
                    if(i == spots[k].first && j == spots[k].second){
                        spots.erase(spots.begin()+k);
                    }
                }
                return {i, j}; // Winning move found
            }
            this->boardPtr->update_board(i, j, 0);
        }
    }
    for(auto k = 0 ; k < spots.size();k++){
        i = spots[k].first ; j = spots[k].second;
        if (this->boardPtr->update_board(i, j, opponentSymbol)) {
            if (this->boardPtr->is_win()) {
                this->boardPtr->update_board(i, j, 0); // Undo move
                for(auto k = 0 ; k < spots.size() ;k++){
                    if(i == spots[k].first && j == spots[k].second){
                        spots.erase(spots.begin()+k);
                    }
                }
                return {i, j}; // Block opponent's winning move
            }
            this->boardPtr->update_board(i, j, 0); // Undo move
        }
    }
    int index = rand()%spots.size();
    values = spots[index];
    spots.erase(spots.begin()+index);
    return {values.first,values.second};
}
template <typename T>
word_X_O_board<T> :: word_X_O_board(){
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    string filename = "dic.txt";
    ifstream file(filename);
    string word;
    while (file >> word) {
        this->words.push_back(word);
    }
    file.close();
}
template <typename T>
bool word_X_O_board<T> :: update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        return true;
    }
    return false;
}
template <typename T>
bool word_X_O_board<T> :: is_win(){
    for (int i = 0; i < this->rows; i++) {
        for(auto j : this->words){
            if (string(1, this->board[i][0]) + string(1,this->board[i][1]) + string(1,this->board[i][2]) == j ||
                string(1, this->board[0][i]) + string(1,this->board[1][i]) + string(1,this->board[2][i]) == j ||
                string(1, this->board[i][0]) + string(1,this->board[i][1]) + string(1,this->board[i][2]) == rev(j) ||
                string(1, this->board[0][i]) + string(1,this->board[1][i]) + string(1,this->board[2][i]) == rev(j)) {
                return true;
            }
            if (string(1, this->board[0][0]) + string(1,this->board[1][1]) + string(1,this->board[2][2]) == j ||
                string(1, this->board[0][2]) + string(1,this->board[1][1]) + string(1,this->board[2][0]) == j ||
                string(1, this->board[0][0]) + string(1,this->board[1][1]) + string(1,this->board[2][2]) == rev(j) ||
                string(1, this->board[0][2]) + string(1,this->board[1][1]) + string(1,this->board[2][0]) == rev(j)){
                return true;
            }
        }
    }
    return false;
}
template <typename T>
void word_X_O_board<T> :: display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
template <typename T>
bool word_X_O_board<T> :: is_draw() {
    return (this->n_moves == 9 && !is_win());
}
template <typename T>
bool word_X_O_board<T> :: game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
word_X_O_player<T>::word_X_O_player(string name) : Player<T>(name, ' ') {}
template <typename T>
void word_X_O_player<T>:: getmove(int& x, int& y){
    char c;
    cout << "enter char :\n";
    cin >> c;
    this->symbol = toupper(c);
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}
template <typename T>
word_X_O_aplayer<T> :: word_X_O_aplayer() : RandomPlayer<T>(' ') {
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void word_X_O_aplayer<T> :: getmove(int& x, int& y){
    vector<char>letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    this->symbol = letters[rand()%letters.size()];
    x = rand() % 3;
    y = rand() % 3;
}
template <typename T>
word_X_O_AI_player<T>::word_X_O_AI_player() : RandomPlayer<T>(' ') {
    this->name = "AI Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void word_X_O_AI_player<T>:: getmove(int& x, int& y){
    pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;
}
template <typename T>
pair<int, int> word_X_O_AI_player<T>:: getBestMove() {
    for(auto i = 0 ; i < 3 ; i++){
        for(auto j = 0 ; j < 3 ; j++){
            for(auto l : letters) {
                if (this->boardPtr->update_board(i, j, l)) {
                    if (this->boardPtr->is_win()) {
                        this->boardPtr->update_board(i, j, 0); // Undo move
                        this->symbol = l;
                        return {i, j}; // Winning move found
                    }
                    this->boardPtr->update_board(i, j, 0);
                }
            }
        }
    }
    int index = rand()%letters.size();
    this->symbol=letters[index];
    return {rand()%3,rand()%3};
}
template <typename T>
FXF_X_O_board<T> :: FXF_X_O_board(){
    this->rows = this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            if(i == 0){
                j%2 == 0 ? this->board[i][j] = 'O' : this->board[i][j] = 'X';
            }
            else if(i == 3){
                j%2 == 0 ? this->board[i][j] = 'X' : this->board[i][j] = 'O';
            }
            else{
                this->board[i][j] = 0;
            }
        }
    }
    this->n_moves = 0;
}
template <typename T>
bool FXF_X_O_board<T> :: update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            if(!is_valid(x1,w1,mark)){
                return false;
            }
            else{
                this->n_moves++;
                this->board[x][y] = toupper(mark);
                for(auto i= 0 ; i < ind.size();i++){
                    if(ind[i].first == x1 && ind[i].second==w1){
                        ind[i].first = x;
                        ind[i].second = y;
                        break;
                    }
                }
                remove_cell(x1,w1);
            }
        }
        return true;
    }
    return false;
}
template <typename T>
bool FXF_X_O_board<T> :: is_valid(int x, int y , T mark){
    if(this->board[x][y]==mark){
        return true;
    }
    return false;
}
template <typename T>
void FXF_X_O_board<T> :: remove_cell(int x , int y){
    this->board[x][y] = 0;
}
template <typename T>
bool FXF_X_O_board<T> :: is_win(){
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0) ||
            (this->board[i][1] == this->board[i][2] && this->board[i][1] == this->board[i][3] && this->board[i][1] != 0) ||
            (this->board[1][i] == this->board[2][i] && this->board[1][i] == this->board[3][i] && this->board[1][i] != 0)) {
            return true;
        }
    }
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][3] == this->board[1][2] && this->board[1][2] == this->board[2][1] && this->board[0][3] != 0) ||
        (this->board[1][1] == this->board[2][2] && this->board[1][1] == this->board[3][3] && this->board[1][1] != 0) ||
        (this->board[1][2] == this->board[2][1] && this->board[1][2] == this->board[3][0] && this->board[1][2] != 0) ||
        (this->board[0][1] == this->board[1][2] && this->board[1][2] == this->board[2][3] && this->board[0][1] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0) ||
        (this->board[1][0] == this->board[2][1] && this->board[1][0] == this->board[3][2] && this->board[1][0] != 0) ||
        (this->board[1][3] == this->board[2][2] && this->board[1][3] == this->board[3][1] && this->board[1][3] != 0)) {
        return true;
    }
    return false;
}
template <typename T>
bool FXF_X_O_board<T> :: is_draw(){
    return false;
}
template <typename T>
bool FXF_X_O_board<T> :: game_is_over() {
    return is_win();
}
template <typename T>
void FXF_X_O_board<T> :: display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
template <typename T>
FBF_player<T> :: FBF_player(string name, T symbol) : Player<T>(name, symbol){}
template <typename T>
void FBF_player<T> :: getmove(int& x, int& y) {
    cout << "enter the index of the cell you want to use separate by space\n";
    cin >> x1 >> w1;
    cout << "enter the index of the cell you want to move to\n";
    cin >> x >> y;
    while(abs(x-x1) + abs(y-w1) != 1){
        cout << "not valid\n";
        cout << "enter the index of the cell you want to use separate by space\n";
        cin >> x1 >> w1;
        cout << "enter the index of the cell you want to move to\n";
        cin >> x >> y;
    }
}
template <typename T>
FBF_Rplayer<T> :: FBF_Rplayer(T symbol) : RandomPlayer<T>(symbol){
    this->dimension = 4;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void FBF_Rplayer<T> :: getmove(int& x, int& y) {
    int i,ii ;
    i = rand()%ind.size();
    x1 = ind[i].first;
    w1 = ind[i].second;
    ii = rand()%moves.size();
    x = moves[ii].first;
    y = moves[ii].second;
    x+=x1;
    y+=w1;
}
template <typename T>
Numerical_TicTacToe_Board<T>::Numerical_TicTacToe_Board() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0; // Initialize with 0
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Numerical_TicTacToe_Board<T>::update_board(int x, int y, T num) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| num == 0)) {
        if (num == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = num;
        }
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Numerical_TicTacToe_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>
bool Numerical_TicTacToe_Board<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0 &&
            this->board[i][0] + this->board[i][1] + this->board[i][2] == 15) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < this->columns; i++) {
        if (this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0 &&
            this->board[0][i] + this->board[1][i] + this->board[2][i] == 15) {
            return true;
        }
    }

    // Check main diagonal
    if (this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0 &&
        this->board[0][0] + this->board[1][1] + this->board[2][2] == 15) {
        return true;
    }

    // Check anti-diagonal
    if (this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0 &&
        this->board[0][2] + this->board[1][1] + this->board[2][0] == 15) {
        return true;
    }

    return false;
}


// Return true if 9 moves are done and no winner
template <typename T>
bool Numerical_TicTacToe_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

//Return true if the game is over
template <typename T>
bool Numerical_TicTacToe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

///================================================

// Implementations of Player functions and methods
template <typename T>
Numerical_TicTacToe_Player<T>::Numerical_TicTacToe_Player(string name, T symbol)
        : Player<T>(name, symbol) {
    if (symbol == 1) {
        available_numbers = {1, 3, 5, 7, 9}; // First player gets odd numbers
    } else if (symbol == 2) {
        available_numbers = {2, 4, 6, 8};    // Second player gets even numbers
    }

}
// Getter for player's name
template <typename T>
string Numerical_TicTacToe_Player<T>::getname() {
    return this->name;
}

// Getter for player's symbol
template <typename T>
T Numerical_TicTacToe_Player<T>::getsymbol() {
    return this->symbol;
}

// To get the move and the number for the player
template <typename T>
void Numerical_TicTacToe_Player<T>::getmove(int& x, int& y) {
    cout << "\n" << this->name << ", your available numbers: ";
    for (int n : available_numbers) cout << n << " ";
    cout << endl;

    cout << "\nPlease enter your move (x and y coordinates) separated by a space: ";
    cin >> x >> y;

    int num;
    cout << "Please enter the number you want to place from your available numbers: ";
    cin >> num;

    // Validate the chosen number
    auto it = find(available_numbers.begin(), available_numbers.end(), num);
    if (it != available_numbers.end()) {
        this->symbol = num; // Assign the chosen number as the current player's symbol
        available_numbers.erase(it); // Remove the number from the player's available numbers
    } else {
        cout << "Invalid number! Please choose a number from your available numbers.\n";
        getmove(x, y); // Retry the move
    }
}


template <typename T>
Numerical_TicTacToe_Random_Player<T>::Numerical_TicTacToe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {

    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    if (symbol == 1) {
        available_numbers = {1, 3, 5, 7, 9}; // First player gets odd numbers
    } else if (symbol == 2) {
        available_numbers = {2, 4, 6, 8};    // Second player gets even numbers
    }

}
template <typename T>
void Numerical_TicTacToe_Random_Player<T>::getmove(int& x, int& y) {
//    int random_number;
    x = rand() % 3;
    y = rand() % 3;

    int index = rand()%available_numbers.size();
    this->symbol=available_numbers[index];

    // Remove the chosen number from available numbers
    available_numbers.erase(available_numbers.begin()+index);
}
template <typename T>
Numerical_TicTacToe_AI_Player<T>::Numerical_TicTacToe_AI_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "AI Computer Player";
    srand(static_cast<unsigned int>(time(0)));
    if (symbol == 1) {
        available_numbers = {1, 3, 5, 7, 9}; // First player gets odd numbers
    } else if (symbol == 2) {
        available_numbers = {2, 4, 6, 8};    // Second player gets even numbers
    }

}
template <typename T>
void Numerical_TicTacToe_AI_Player<T>:: getmove(int& x, int& y){
    pair<int, int> bestMove = getBestMove();
    x = bestMove.first;
    y = bestMove.second;
}
template <typename T>
pair<int, int> Numerical_TicTacToe_AI_Player<T>:: getBestMove() {
    for(auto i = 0 ; i < 3 ; i++){
        for(auto j = 0 ; j < 3 ; j++){
            for(auto l : available_numbers) {
                if (this->boardPtr->update_board(i, j, l)) {
                    if (this->boardPtr->is_win()) {
                        this->boardPtr->update_board(i, j, 0); // Undo move
                        this->symbol = l;
                        return {i, j}; // Winning move found
                    }
                    this->boardPtr->update_board(i, j, 0);
                }
            }
        }
    }
    int index = rand()%available_numbers.size();
    this->symbol=available_numbers[index];
    available_numbers.erase(available_numbers.begin()+index);
    return {rand()%3,rand()%3};
}
template <typename T>
Four_in_A_Row_Board<T>::Four_in_A_Row_Board() {
    this->rows = 6;
    this->columns = 7;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0; // Initialize with empty cells
        }
    }
    this->n_moves = 0;
}

// Update the board if the move is valid
template <typename T>
bool Four_in_A_Row_Board<T>::update_board(int x, int y, T mark) {
    if (y < 0 || y >= this->columns) return false; // Out of bounds
    for (int i = this->rows - 1; i >= 0; --i) {
        if (this->board[i][y] == 0) {
            this->board[i][y] = mark;
            ++this->n_moves;
            return true;
        }
    }
    return false; // Column is full
}

// Display the board
template <typename T>
void Four_in_A_Row_Board<T>::display_board() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";
        for (int j = 0; j < this->columns; j++) {
            cout << (this->board[i][j] == 0 ? '.' : this->board[i][j]) << " | ";
        }
        cout << "\n" << string(this->columns * 4, '-') << "\n";
    }
}


// Check for a win
template <typename T>
bool Four_in_A_Row_Board<T>::is_win() {
    static const int directions[4][2] = {
            {0, 1},
            {1, 0},
            {1, 1},
            {1, -1}
    };

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            T symbol = this->board[i][j];
            if (symbol == 0) continue; // Skip empty cells

            for (int d = 0; d < 4; ++d) {
                int dx = directions[d][0];
                int dy = directions[d][1];
                int count = 1; // Include the current cell

                // Count in the positive direction
                for (int step = 1; step < 4; ++step) {
                    int x = i + step * dx;
                    int y = j + step * dy;
                    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == symbol) {
                        ++count;
                    } else {
                        break;
                    }
                }

                // Count in the negative direction
                for (int step = 1; step < 4; ++step) {
                    int x = i - step * dx;
                    int y = j - step * dy;
                    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == symbol) {
                        ++count;
                    } else {
                        break;
                    }
                }

                // Check if we have 4 or more in a row
                if (count >= 4) return true;
            }
        }
    }

    return false;
}


// Check for a draw
template <typename T>
bool Four_in_A_Row_Board<T>::is_draw() {
    return (this->n_moves == this->rows * this->columns && !is_win());
}

// Check if the game is over
template <typename T>
bool Four_in_A_Row_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//----------------------------------------------------
// Constructor for Four_in_A_Row_Player
template <typename T>
Four_in_A_Row_Player<T>::Four_in_A_Row_Player(string name, T symbol) : Player<T>(name, symbol) {}

// Get the move from the player
template <typename T>
void Four_in_A_Row_Player<T>::getmove(int& x, int& y) {
    cout << "\n" << this->name << ", enter your move (column 0-6): ";
    cin >> y;
    x = -1;
}

//----------------------------------------------------
// Constructor for Four_in_A_Row_Random_Player
template <typename T>
Four_in_A_Row_Random_Player<T>::Four_in_A_Row_Random_Player(T symbol) : Player<T>(symbol) {}


template <typename T>
void Four_in_A_Row_Random_Player<T>::getmove(int& x, int& y) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 6);
    y = dist(gen); // Random column
    x = -1; // Row is determined by gravity
}
template <typename T>
reverse_x_oBoard<T>::reverse_x_oBoard() {
    this->rows = this->columns = 3;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++){
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool reverse_x_oBoard<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void reverse_x_oBoard<T>::display_board() {
    for (int i = 0; i < this->rows; i++){
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool reverse_x_oBoard<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool reverse_x_oBoard<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool reverse_x_oBoard<T>::game_is_over() {
    return is_win() || is_draw();
}
//--------------------------------------

// Constructor for X_O_Player
template <typename T>
reverse_x_oPlayer<T>::reverse_x_oPlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void reverse_x_oPlayer<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for X_O_Random_Player

template <typename T>
reverse_x_oRandom_Player<T>::reverse_x_oRandom_Player(string Name, T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = Name;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void reverse_x_oRandom_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}
template <typename T>
FIVEttc<T> :: FIVEttc() {
    this->rows = this->columns = 5;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}
template <typename T>
bool FIVEttc<T> :: update_board(int x, int y, T mark)
{
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}
template <typename T>
void FIVEttc<T> :: display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
template <typename T>
bool FIVEttc<T> :: is_win()  {
    int cx = 0, co = 0; // Count for wins of 'X' and 'O'
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            char current = this->board[i][j];
            if (current != 0) {
                // Vertical check
                if (i - 1 >= 0 && i + 1 < this->rows && this->board[i - 1][j] == current && this->board[i + 1][j] == current) {
                    (current == 'X') ? cx++ : co++;
                }
                // Horizontal check
                if (j - 1 >= 0 && j + 1 < this->columns && this->board[i][j - 1] == current && this->board[i][j + 1] == current) {
                    (current == 'X') ? cx++ : co++;
                }
                // Diagonal check
                if (i - 1 >= 0 && i + 1 < this->rows && j - 1 >= 0 && j + 1 < this->columns &&
                    this->board[i - 1][j - 1] == current && this->board[i + 1][j + 1] == current) {
                    (current == 'X') ? cx++ : co++;
                }
                // Diagonal check
                if (i - 1 >= 0 && i + 1 < this->rows && j + 1 < this->columns && j - 1 >= 0 &&
                    this->board[i - 1][j + 1] == current && this->board[i + 1][j - 1] == current) {
                    (current == 'X') ? cx++ : co++;
                }
            }
        }
    }
    // Return true if a player has aligned three marks
    if (this->n_moves == this->rows * this->columns - 1) {
        cout << "x " << cx << endl;
        cout << "o " << co << endl;
        return (cx > co || co > cx); // If there is a winner //
    }
    return false;

}
template <typename T>
bool FIVEttc<T> :: is_draw()  {
    return (this->n_moves == this->rows * this->columns - 1 && !is_win());
}
template <typename T>
bool FIVEttc<T> :: game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
game_player<T> :: game_player(string name, T sympol) : Player<T>(name, sympol) {}
template <typename T>
void game_player<T> :: getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}
template <typename T>
game_random<T> :: game_random(T symbol)
        : RandomPlayer<T>(symbol) {
    this->dimension = 5;  // Set to 5 for a 5x5 board
    this->name = "Random Computer Player";
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));  // Seed random generator
        seeded = true;
    }
}
template <typename T>
void  game_random<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}
menu::menu(){
    cout << "Welcome to FCAI X-O Games. :)\n";
    int choice;
    cout << "Choose X O game type:\n";
    cout << "1. pyramid\n";
    cout << "2. words\n";
    cout << "3. four by four\n";
    cout << "4. ultimate\n";
    cout << "5. Numerical_TicTacToe\n";
    cout << "6. Four_in_A_Row_Board\n";
    cout << "7. reverse tic tac toe\n";
    cout << "8. five tic tac toe\n ";
    cin >> choice;
    switch(choice) {
        case 1:
            menu::pyramidxo();
            break;
        case 2:
            menu::wordxo();
            break;
        case 3 :
            menu::four_by_four();
            break;
        case 4:
            menu::ultimate();
            break;
        case 5 :
            menu::Numerical_TicTacToe();
            break;
        case 6 :
            menu::connect_four();
            break;
        case 7:
            menu :: reverse_tic_tac_toe();
            break;
        case 8:
            menu :: five_tic_tac_toe();
        default:
            cout << "Invalid choice for Exiting the game.\n";
            return;
    }
}

void menu :: wordxo(){
    Player<char>* players[2];
    Board<char>* Pb = new word_X_O_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to FCAI word X-O Game. :)\n";
    int setup;
    // Set up player 1
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. smart AI\n";
    cin >> setup;
    switch(setup) {
        case 1:
            cout << "Enter Player 1 name: ";
            cin >> playerXName;
            players[0] = new word_X_O_player<char>(playerXName);
            break;
        case 2:
            players[0] = new word_X_O_aplayer<char>();
            break;
        case 3:
            players[0] = new word_X_O_AI_player<char>();
            players[0]->setBoard(Pb);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return;
    }
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. smart AI\n";
    cin >> setup;
    switch(setup) {
        case 1:
            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            players[1] = new word_X_O_player<char>(player2Name);
            break;
        case 2:
            players[1] = new word_X_O_aplayer<char>();
            break;
        case 3:
            players[1] = new word_X_O_AI_player<char>();
            players[1]->setBoard(Pb);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return;
    }
    GameManager<char> word_X_O_Gm(Pb, players);
    word_X_O_Gm.run();
    delete Pb;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void menu ::  pyramidxo(){
    Player<char>* players[2];
    Board<char>* Pb = new Pyramid_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to FCAI pyramid X-O Game. :)\n";
    int setup;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. smart AI\n";
    cin >> setup;
    switch(setup) {
        case 1:
            cout << "Enter Player 1 name: ";
            cin >> playerXName;
            players[0] = new Pyramid_player<char>(playerXName,'X');
            break;
        case 2:
            players[0] = new Pyramid_Random_Player<char>('X');
            break;
        case 3:
            players[0] = new Pyramid_X_O_MinMax_Player<char>('X');
            players[0]->setBoard(Pb);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return;
    }
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. smart AI\n";
    cin >> setup;
    switch(setup) {
        case 1:
            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            players[1] = new Pyramid_player<char>(player2Name,'O');
            break;
        case 2:
            players[1] = new Pyramid_Random_Player<char>('O');
            break;
        case 3:
            players[1] = new Pyramid_X_O_MinMax_Player<char>('O');
            players[1]->setBoard(Pb);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return;
    }
    GameManager<char> pyramid_X_O_Gm(Pb, players);
    pyramid_X_O_Gm.run();
    delete Pb;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void menu :: four_by_four (){
    Player<char>* players[2];
    Board<char>* db = new FXF_X_O_board<char>();
    int setup;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> setup;
    string playerXName,player2Name;
    switch(setup) {
        case 1:
            cout << "Enter Player 1 name: ";
            cin >> playerXName;
            players[0] = new FBF_player<char>(playerXName,'X');
            break;
        case 2:
            players[0] = new FBF_Rplayer<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            break;
    }
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> setup;
    switch(setup) {
        case 1:
            cout << "Enter Player 2 name: ";
            cin >> player2Name;
            players[1] = new FBF_player<char>(player2Name,'O');
            break;
        case 2:
            players[1] = new FBF_Rplayer<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            break;
    }
    GameManager<char> four_X_O_Gm(db, players);
    four_X_O_Gm.run();
    delete db;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void menu :: ultimate(){
    int choice;
    Player<char>* players[2];
    Board<char>* B = new ultimate_board<char>();
    B->display_board();
    string playerXName, player2Name;
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            players[0] = new ultimate_player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new ultimate_Rplayer<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            break;
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            players[1] = new ultimate_player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new ultimate_Rplayer<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            break;
    }
    GameManager<char> x_o_game(B, players);
    x_o_game.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void menu :: Numerical_TicTacToe(){
    int choice;
    Player<int>* Players[2];
    Numerical_TicTacToe_Board<int>* B = new Numerical_TicTacToe_Board<int>();
    string p1_name, p2_name;
    cout << "Welcome to FCAI Numerical Tic-Tac-Toe Game. :)\n";
    cout << "Enter Player 1 name: ";
    cin >> p1_name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3.Smart Computer (AI) \n";
    cin >> choice;
    switch (choice) {
        case 1:
            Players[0] = new Numerical_TicTacToe_Player<int>(p1_name, 1);
            break;
        case 2:
            Players[0] = new Numerical_TicTacToe_Random_Player<int>(1);
            break;
        case 3:
            Players[0] = new Numerical_TicTacToe_AI_Player<int>(1);
            Players[0]->setBoard(B);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            break;
    }
    cout << "Enter Player 2 name: ";
    cin >> p2_name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3.Smart Computer (AI) \n";
    cin >> choice;
    switch (choice) {
        case 1:
            Players[1] = new Numerical_TicTacToe_Player<int>(p2_name, 2);
            break;
        case 2:
            Players[1] = new Numerical_TicTacToe_Random_Player<int>(2);
            break;
        case 3:
            Players[1] = new Numerical_TicTacToe_AI_Player<int>(2);
            Players[1]->setBoard(B);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            break;
    }
    GameManager<int> Numerical_TicTacToe_game(B, Players);
    Numerical_TicTacToe_game.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete Players[i];
    }
}
void menu ::connect_four() {
    int choice;
    Player<char>* Players[2];
    Four_in_A_Row_Board<char>* B = new Four_in_A_Row_Board<char>();
    string p1_name, p2_name;
    cout << "Welcome to FCAI Four_in_A_Row (Connect Four) Game. :)\n";
    cout << "Enter Player 1 name: ";
    cin >> p1_name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            Players[0] = new Four_in_A_Row_Player<char>(p1_name, 'X');
            break;
        case 2:
            Players[0] = new Four_in_A_Row_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            break;
    }
    cout << "Enter Player 2 name: ";
    cin >> p2_name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            Players[1] = new Four_in_A_Row_Player<char>(p2_name, 'O');
            break;
        case 2:
            Players[1] = new Four_in_A_Row_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            break;
    }
    GameManager<char> Four_in_A_Row_game(B, Players);
    Four_in_A_Row_game.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete Players[i];
    }
}
void menu ::reverse_tic_tac_toe() {
    int choice;
    Player<char>* players[2];
    reverse_x_oBoard<char>* B = new reverse_x_oBoard<char>();
    string playerXName, player2Name;
    cout << "Welcome to FCAI X-O Game. :)\n";
    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    // cout << "3. Smart Computer (AI)\n";
    cin >> choice;
    //
    switch(choice) {
        case 1:
            players[0] = new reverse_x_oPlayer<char>(player2Name, 'X');
            break;
        case 2:
            players[0] = new reverse_x_oRandom_Player<char>(player2Name, 'X');
            break;

        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            break;
    }

    // Set up player 2


    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    // cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new reverse_x_oPlayer<char>( playerXName, 'O');
            break;
        case 2:
            players[1] = new reverse_x_oRandom_Player<char>( playerXName,'O');
            break;

        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            break;
    }
    GameManager<char> reverse_x_ogame(B ,players);
    reverse_x_ogame.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void menu ::five_tic_tac_toe() {
    int choice;
    Player<char>* players[2];
    //FIVEttc<char>*B=new FIVEttc<char>();
    FIVEttc<char>* B = new FIVEttc<char>();
    string playerXName, player2Name;
    cout << "Welcome to FCAI X-O Game. :)\n";
    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;
    //
    switch (choice) {
        case 1:
            players[0] = new game_player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new game_random<char>('X');
            break;
        case 3:
            players[0] = new X_O_MinMax_Player<char>('X');
            players[0]->setBoard(B);
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            break;
    }

    // Set up player 2


    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[1] = new game_player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new game_random<char>('O');
            break;
        case 3:
            players[1] = new X_O_MinMax_Player<char>('O');
            players[1]->setBoard(B);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            break;
    }

    // Create the game manager and run the game    swap(playerXName,player2Name);
    GameManager<char> game(B, players);

    game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
#endif //UNTITLED2_TIC_TAC_TOE_GAMES_H
