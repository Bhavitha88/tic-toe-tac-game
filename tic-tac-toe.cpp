#include<iostream>
#include<vector>
using namespace std;
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string n1,n2;
char token = 'X';

void createGrid(bool tie){
    
      
    cout << "   |   |   "<<endl;
    cout << "   |   |   "<<endl; 
    cout <<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<endl;
    cout << "___|___|___"<<endl;
    cout << "   |   |   "<<endl;
    cout << "   |   |   "<<endl;
    cout <<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<endl;
    cout << "___|___|___"<<endl;
    cout << "   |   |   "<<endl;
    cout << "   |   |   "<<endl;
    cout <<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<endl;
    cout << "   |   |   "<<endl;
   
 }
 bool gameOver(bool tie){
   for(int i = 0; i < 3; i++){
    if((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i])){
        return true;
    }
   }  
   if(space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0]){
    return true;
   }
   for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        if(space[i][j] != 'X' && space[i][j] != '0'){
            return false;
        }
    }
   }
   tie = true;
   return false;
 }
 void Game(bool tie){
    int digit;
    if(token == 'X'){
        cout << n1 <<" Please enter ";
        cin >> digit;
    }
    if(token == '0'){
        cout << n2 <<" Please enter ";
        cin >> digit;
    }
    int row = (digit-1)/3;
    int col = (digit-1)%3;
    if(digit > 9){
        cout << "Invalid !!!"<<endl;
    }
    if(token == 'X' && space[row][col] != 'X' && space[row][col] != '0'){
        space[row][col] = 'X';
        token = '0';
    }
    else if(token == '0' && space[row][col] != 'X' && space[row][col] != '0'){
        space[row][col] = '0';
        token = 'X';
    }
    else{
        cout << "There is no empty space"<<endl;
        Game(tie);
    }
 }
 int main(){
    bool tie = false;
    cout << "Enter the name of the first player : \n";
    getline(cin,n1);
    cout << "Enter the name of the second player : \n";
    getline(cin,n2);
    cout << n1 << " is player1 so he/she will play first \n";
    cout << n2 << " is player1 so he/she will play second \n";
    while(!gameOver(tie)){
        createGrid(tie);
        Game(tie);
        gameOver(tie);
    }
    if(token == 'X' && tie == false){
       cout << n2 <<" Wins !!!"<<endl;
    }
    else if(token == '0' && tie == false){
       cout << n1 <<" Wins !!!"<<endl;
    }
    else{
        cout << "It's a tie!"<<endl;
    }
 }