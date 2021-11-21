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

void input(char board[B][B],char *play){
    int x,y;
    std::cout << "Enter Column: " << std::endl;
    std::cin >> x;
    std::cout << "Enter Row: " << std::endl;
    std::cin >> y;

    if(*play == 'O'){
        *play = 'X';
    } else{
        *play = 'O';
    }

    board[y][x] = *play;
}

bool win(char board[B][B]){
    //rows and columns
    for(int i = 0; i < B; i++){
        //rows

        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 32){
            return true;
        }

        //Cols

        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 32){
            return true;
        }

    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 32){
        return true;
    }

    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != 32){
        return true;
    }

    return false;
}

int main()
{
    char board[B][B];
    board_init(board);


    char play = 'O';
    while(true){
        print_board(board);
        input(board, &play);
        if(win(board) == true){
            print_board(board);
            break;
        }
    }

    std::cout << play << " Has Won!" << std::endl;

    return 0;
}
