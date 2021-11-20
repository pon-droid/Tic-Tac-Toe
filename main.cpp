#include <iostream>
#define B 3



void board_init(char board[B][B]){
    for(int x = 0; x < B; x++){
        for(int y = 0; y < B; y++){
            board[x][y] = 32;
        }
    }
}

void print_board(char board[B][B]){
   std::cout << "   " << 0 << " | " << 1 << " | " << 2 << std::endl;
   std::cout << 0 << " |" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << std::endl;
   std::cout << 1 << " |" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << std::endl;
   std::cout << 2 << " |" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << std::endl;




}

int main()
{
    char board[B][B];
    board_init(board);
    board[1][2] = 88;
    board[2][1] = 79;
    print_board(board);

    return 0;
}
