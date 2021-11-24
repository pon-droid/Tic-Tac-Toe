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

/*
    while(true){
        int r_x = rand() % 3;
        int r_y = rand() % 3;
        if(board[r_y][r_x] == 32){
            board[r_y][r_x] = 'X';
            break;
        }
    }
*/

    for(int i = 0; i < B; i++){
        //rows
            if(board[i][0] == board[i][1] && board[i][2] == 32 && board[i][0] == 'X'){
                board[i][2] = 'X';
                std::cout << "SMART W" << i << " XX " << 2 << std::endl;
                break;

            }

            //Cols

            if(board[0][i] == board[1][i] && board[2][i] == 32 && board[0][i] == 'X'){
                board[2][i] = 'X';
                std::cout << "SMART V" << std::endl;

                break;

            }



    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 32){
        std::cout << board[0][0] << " Has Won!" << std::endl;

    }

    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != 32){
        std::cout << board[2][0] << " Has Won!" << std::endl;

    }

   /* while(true){
        int r_x = rand() % 3;
        int r_y = rand() % 3;
        if(board[r_y][r_x] == 32){
            board[r_y][r_x] = 'X';
            break;
        }
    }*/

}

void smart_ai2(char board[B][B]){
    int ai = 0;
    int empty = 0;
    int px,py;
    for(int y = 0; y < B; y++){
        for(int x = 0; x < B; x++){
            if(board[y][x] == 'X'){
                ai++;
                std::cout << "FRIEND" << std::endl;
            }
            if(board[y][x] == 32){
                empty++;
                px = x;
                py = y;
                std::cout << "EMPTY" << std::endl;

            }
        }
    }



    if(board[py][px] == 32 && empty == 2){
        board[py][px] = 'X';
        std::cout << "SET" << std::endl;

    }
}

struct pos{
  int y;
  int x;
};

void count_ai(char board[B][B]){
    int ally = 0;
    int empt = 0;
    int enem = 0;
    //Array of empty positions, cycle through and find one with adjacent allies
    std::vector<pos> clr;
    for(int y = 0; y < B; y++){
        for(int x = 0; x < B; x++){
            switch(board[y][x]){
            case 'X':
            ally++;
            break;
            case 'O':
            enem++;
            break;
            default:
            empt++;
            clr.push_back({y,x});
            break;
            }
        }
    }
    /*
    for(int i = -2; i < 2; i++){
        for(int j = 0; j < clr.size(); j++){
            int nx = clr[j].x + i;
            int ny = clr[j].y + i;
            if(nx >=0 && nx <=2 && ny >=0 && ny <=2){
                board[ny][nx] = '!';
                std::cout << ny << " ++ " << nx << std::endl;
            }
        }
    }
    */
    //GOING GOLD
    int al2;
    int px2, py2;
    for(int i = 0; i < B; i++){
        px2 = 0;
        py2 = 0;
        al2 = 0;
        for(int j = 0; j < B; j++){
            if(board[i][j] == 'X'){
                al2++;
            }
            if(board[i][j] == 32){
                py2 = i;
                px2 = j;
            }

        }
        std::cout << "AL " << al2 << std::endl;
        if(al2 == 2){
            std::cout << "op " << py2 << " opx " << px2 << std::endl;
        }
    }
    std::cout << ally << " " << enem << " " << empt << " " << clr[1].x << clr[1].y << std::endl;
}

int main()
{
   char board[B][B] = {
        {'X','X',32},
        {'O','O',32},
        {'O','X','O'}
    };
/*
    char board[B][B] = {
        {'O','X',32},
        {32,'X',32},
        {'O',32,'O'}
    };
*/
    //board_init(board);
    srand(time(NULL));
    //USE AMOUNT OF FRIENDS AND RECORD FRIEND POSITIONS, FIND MISSING ONE IN ROW/COL PER ROW. ALL EMPTY SPOTS
    char play = 'X';
    print_board(board);
    count_ai(board);
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
