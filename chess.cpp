#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Board{

    public:
        Board() {
            cout << "Initializing board..." << endl;
            displayBoard();
        }


        void displayBoard() {    
            cout<<"\n"<<"- - - - - - - - - - - -  - - - -"<<endl; 
            for (auto &row : board) {
                cout <<"| ";
                for (auto &cell : row) {
                    cout << cell << " "<<"| ";
                }
                cout << endl;
                cout<<"- - - - - - - - - - - -  - - - -"; 
                cout << endl;
                }
        }

        void changeplace(char piece, int prev[2], int next[2]){
            board[prev[0]][prev[1]] = ' ';
            board[next[0]][next[1]] = piece;
        }

    // private:
        // uppercaase for blackones 
        vector <vector<char>> board = {
                {'R', 'K', 'B', 'Q', 'k', 'B', 'K', 'R'},
                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                {'r', 'k', 'b', 'q', 'k', 'b', 'k', 'r'},
            };
};

class Piece {
    public:
        char getName(){
            return name;
        }
        vector<short int> getPosition(){
            return posiiton;
        }
        
        void setPosition(short int pos[2]){
            if(pos[0] < 8 && pos[0] >= 0 && pos[1] < 8 && pos[1] >= 0 ){
                posiiton[0] = pos[0];
                posiiton[1] = pos[1];
            }
            else
                cout<< "invalid position" ;
        };

        virtual bool isValidMove(char color, short int posPrev[2], short int posNext[2], Board &board){
            if(color == 'w' )
                cout<< "Hello";
                return true;
        };

    private:
        char colur; // b-black; w-white
        char name = ' ';
        vector<short int> posiiton = {0, 0} ;
};

class Pawn : public Piece{
    public:
        bool isValidMove(char color, short int posPrev[2], short int posNext[2], Board &board) override{
            char opponentColour = (color = 'w') ? 'b' : 'w';


            if(board.board[posNext[0]][posNext[1]] == ' ' ){
                if(color=='b' && posNext[1] ==posPrev[1] + 1)
                    return true;
                if(color=='w' && posNext[1] == posPrev[1] -1 )
                    return true;
            }
            else{
                if(color=='b' && opponentColour == board.board[posNext[1]][posPrev[2]] && posNext[1] == posPrev[1] + 1)
                    return true;
                if(color=='w' && opponentColour == board.board[posNext[1]][posPrev[2]] && posNext[1] == posPrev[1] - 1)
                    return true;
            }
            
            return false;
            
        };
};

int main(){
    Board Board;

    return 0;
}
