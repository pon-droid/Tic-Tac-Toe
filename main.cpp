#include <iostream>
#include <math.h>
#include <vector>
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
/*
    if(*play == 'O'){
        *play = 'X';
    } else{
        *play = 'O';
    }
*/
    if(board[y][x] == 32){
        board[y][x] = *play;
    }else{
        std::cout << "ILLEGAL MOVE" << std::endl;
    }
}

bool win(char board[B][B]){
    //rows and columns
    for(int i = 0; i < B; i++){
        //rows

        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 32){
            std::cout << board[i][0] << " Has Won!" << std::endl;
            return true;
        }

        //Cols

        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 32){
            std::cout << board[0][i] << " Has Won!" << std::endl;
            return true;
        }

    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 32){
        std::cout << board[0][0] << " Has Won!" << std::endl;
        return true;
    }

    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != 32){
        std::cout << board[2][0] << " Has Won!" << std::endl;
        return true;
    }

    return false;
}

bool draw(char board[B][B]){

    int draw = 0;

    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                draw++;
            }
    }
    }
    std::cout << draw << std::endl;
    if(draw == 9){
        std::cout << "DRAW" << std::endl;
        return true;
    }
    return false;
}

void rand_ai(char board[B][B]){


    while(true){
        int r_x = rand() % 3;
        int r_y = rand() % 3;
        if(board[r_y][r_x] == 32){
            board[r_y][r_x] = 'O';
            break;
        }
    }
}


void smart_ai(char board[B][B]){

    //GOING GOLD
    int ally;
    int x, y;

    for(int i = 0; i < B; i++){
        x = 0;
        y = 0;
        ally = 0;
        for(int j = 0; j < B; j++){
            if(board[i][j] == 'X'){
                ally++;
            }
            if(board[i][j] == 32){
                y = i;
                x = j;
            }

        }

        if(ally == 2){
            board[y][x] = 'X';
        }
    }
    for(int i = 0; i < B; i++){
        ally = 0;
        x = 0;
        y = 0;
        for(int j = 0; j < B; j++){
            if(board[j][i] == 'X'){
                ally++;
            }
            if(board[j][i] == 32){
                y = j;
                x = i;
            }
        }
        if(ally == 2){
            board[y][x] = 'X';
        }
    }

    ally = 0;
    x = 0;
    y = 0;

    //TODO: Find out a better way to do this
    if(board[0][2] == 'X'){
        ally++;
    }
    if(board[1][1] == 'X'){
        ally++;
    }
    if(board[2][0] == 'X'){
        ally++;
    }
    if(board[0][2] == 32){
        x = 0;
        y = 2;
    }
    if(board[1][1] == 32){
        y = 1;
        x = 1;
    }

    if(board[0][2] == 32){
        x = 0;
        y = 2;
    }

    if(ally == 2){
        board[x][y] = 'X';
    }
/*
    ally = 0;
    x = 0;
    y = 0;
    if(board[0][0] == 'X'){
        ally++;
    }
    if(board[1][1] == 'X'){
        ally++;
    }
    if(board[2][2] == 'X'){
        ally++;
    }
    if(board[0][0] == 32){
        y = 0;
        x = 0;
    }
    if(board[1][1] == 32){
        y = 1;
        x = 1;
    }
    if(board[2][2] == 32){
        y = 2;
        x = 2;
    }
    if(ally == 2){
        board[y][x] = 'X';
    }
*/
    ally = 0;
    x = 0;
    y = 0;

    if(board[0][0] == 'X'){
        ally++;
    }
    if(board[1][1] == 'X'){
        ally++;
    }
    if(board[2][0] == 'X'){
        ally++;
    }
    if(board[0][0] == 32){
        x = 0;
        y = 0;
    }
    if(board[1][1] == 32){
        x = 0;
        y = 0;
    }
    if(board[2][0] == 32){
        x = 2;
        y = 0;
    }

    if(ally == 2){
        board[x][y] = 'X';
    }

}

int main()
{
/*   char board[B][B] = {
        {'X','X',32},
        {'O','O',32},
        {'O','X','O'}
    };*/

   /* char board[B][B] = {
        {'O','X',32},
        {32,'X',32},
        {'O',32,'O'}
    };*/

    char board[B][B] = {
            {'O','O','X'},
            {32,'X',32},
            {32,32,'O'}
        };
    std::cout << board[0][2] << std::endl;
    //board_init(board);
    srand(time(NULL));
    //USE AMOUNT OF FRIENDS AND RECORD FRIEND POSITIONS, FIND MISSING ONE IN ROW/COL PER ROW. ALL EMPTY SPOTS
    char play = 'X';
    print_board(board);
    smart_ai(board);
    print_board(board);
/*
    while(true){
        input(board,&play);
        print_board(board);
        if(win(board) == true || draw(board) == true){
            print_board(board);
            break;
        };
        smart_ai(board);
        if(win(board) == true || draw(board) == true){
            print_board(board);
            break;
        };
        print_board(board);


    }

*/
    return 0;
}
