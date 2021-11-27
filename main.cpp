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

void rand_ai(char board[B][B], const char *ai){
    std::cout << "RAND" << std::endl;

    while(true){
        int r_x = rand() % 3;
        int r_y = rand() % 3;
        if(board[r_y][r_x] == 32){
            board[r_y][r_x] = *ai;
            break;
        }
    }
}


bool smart_ai(char board[B][B], char *enem, char *them){

    //GOING GOLD
    int ally;
    int x, y;


    bool pos_c = false;
    for(int i = 0; i < B; i++){
        x = 0;
        y = 0;
        ally = 0;
        for(int j = 0; j < B; j++){
            if(board[i][j] == *them){
                ally++;
            }
            if(board[i][j] == 32){
                y = i;
                x = j;
                pos_c = true;
            }

        }

        if(ally == 2 && pos_c == true){
            board[y][x] = *enem;
            return true;

        }
    }
    pos_c = false;
    for(int i = 0; i < B; i++){
        ally = 0;
        x = 0;
        y = 0;
        for(int j = 0; j < B; j++){
            if(board[j][i] == *them){
                ally++;
            }
            if(board[j][i] == 32){
                y = j;
                x = i;
                pos_c = true;

            }
        }
        if(ally == 2 && pos_c == true){
            board[y][x] = *enem;
            return true;

        }
    }
    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;

    //TODO: Find out a better way to do this
    /*
     \
      \
       \
       */
    if(board[0][0] == *them){
        ally++;
    }
    if(board[1][1] == *them){
        ally++;
    }
    if(board[2][2] == *them){
        ally++;
    }
    if(board[0][0] == 32){
        x = 0;
        y = 0;
        pos_c = true;
    }
    if(board[1][1] == 32){
        y = 1;
        x = 1;
        pos_c = true;
    }

    if(board[2][2] == 32){
        x = 2;
        y = 2;
        pos_c = true;
    }

    if(ally == 2 && pos_c == true){

        board[x][y] = *enem;
        return true;
    }
    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;
    /*
       /
      /
     /
       */
    if(board[0][2] == *them){
        ally++;
    }
    if(board[1][1] == *them){
        ally++;
    }
    if(board[2][0] == *them){
        ally++;
    }
    if(board[0][2] == 32){
        x = 0;
        y = 2;
        pos_c = true;

    }
    if(board[1][1] == 32){
        x = 1;
        y = 1;
        pos_c = true;

    }
    if(board[2][0] == 32){
        x = 2;
        y = 0;
        pos_c = true;

    }

    if(ally == 2 && pos_c == true){

        board[x][y] = *enem;

        return true;
    }

    rand_ai(board, enem);

    return false;
}

bool fsmart_ai(char board[B][B], char *enem, char *play){
    char them = *play;


    //GOING GOLD
    int ally;
    int x, y;


    bool pos_c = false;
    for(int i = 0; i < B; i++){
        x = 0;
        y = 0;
        ally = 0;
        for(int j = 0; j < B; j++){
            if(board[i][j] == them){
                ally++;
            }
            if(board[i][j] == 32){
                y = i;
                x = j;
                pos_c = true;
            }

        }

        if(ally == 2 && pos_c == true){
            board[y][x] = *enem;
            return true;

        }
    }
    pos_c = false;
    for(int i = 0; i < B; i++){
        ally = 0;
        x = 0;
        y = 0;
        for(int j = 0; j < B; j++){
            if(board[j][i] == them){
                ally++;
            }
            if(board[j][i] == 32){
                y = j;
                x = i;
                pos_c = true;

            }
        }
        if(ally == 2 && pos_c == true){
            board[y][x] = *enem;
            return true;

        }
    }
    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;

    //TODO: Find out a better way to do this
    /*
     \
      \
       \
       */
    if(board[0][0] == them){
        ally++;
    }
    if(board[1][1] == them){
        ally++;
    }
    if(board[2][2] == them){
        ally++;
    }
    if(board[0][0] == 32){
        x = 0;
        y = 0;
        pos_c = true;
    }
    if(board[1][1] == 32){
        y = 1;
        x = 1;
        pos_c = true;
    }

    if(board[2][2] == 32){
        x = 2;
        y = 2;
        pos_c = true;
    }

    if(ally == 2 && pos_c == true){

        board[x][y] = *enem;
        return true;
    }
    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;
    /*
       /
      /
     /
       */
    if(board[0][2] == them){
        ally++;
    }
    if(board[1][1] == them){
        ally++;
    }
    if(board[2][0] == them){
        ally++;
    }
    if(board[0][2] == 32){
        x = 0;
        y = 2;
        pos_c = true;

    }
    if(board[1][1] == 32){
        x = 1;
        y = 1;
        pos_c = true;

    }
    if(board[2][0] == 32){
        x = 2;
        y = 0;
        pos_c = true;

    }

    if(ally == 2 && pos_c == true){

        board[x][y] = *enem;

        return true;
    }



    rand_ai(board, enem);

    return false;


}

void h_ai(char board[B][B], const char *enem, const char *ai){
    int ally;
    int x, y;

    bool pos_c = false;


    //WIN
    for(int i = 0; i < B; i++){
        x = 0;
        y = 0;
        ally = 0;
        for(int j = 0; j < B; j++){
            if(board[i][j] == *ai){
                ally++;
            }
            if(board[i][j] == 32){
                y = i;
                x = j;
                pos_c = true;
            }

        }

        if(ally == 2 && pos_c == true && board[y][x] == 32){
            board[y][x] = *ai;
            return;

        }
    }

    pos_c = false;
    for(int i = 0; i < B; i++){
        ally = 0;
        x = 0;
        y = 0;
        for(int j = 0; j < B; j++){
            if(board[j][i] == *ai){
                ally++;
            }
            if(board[j][i] == 32){
                y = j;
                x = i;
                pos_c = true;

            }
        }
        if(ally == 2 && pos_c == true && board[y][x] == 32){
            board[y][x] = *ai;
            return;

        }
    }


    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;

    //TODO: Find out a better way to do this
    /*
     \
      \
       \
       */
    for(int i = 0; i < B; i++){
        if(board[i][i] == *ai){
            ally++;
        } else {
            x = i;
            y = i;
            pos_c = true;
        }
    }

    if(ally == 2 && pos_c == true && board[x][y] == 32){

        board[x][y] = *ai;
        return;
    }

    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;
    /*
       /
      /
     /
       */

    for(int i = 0; i < B; i++){
        for(int j = 2; j > 0; j--){
            if(board[i][j] == *ai){
                ally++;
            } else {
                x = i;
                y = j;
                pos_c = true;
            }
        }
    }

    if(ally == 2 && pos_c == true && board[x][y] == 32){

        board[x][y] = *ai;

        return;
    }


    //BLOCK
    pos_c = false;



    for(int i = 0; i < B; i++){
        x = 0;
        y = 0;
        ally = 0;
        for(int j = 0; j < B; j++){
            if(board[i][j] == *enem){
                ally++;
            }
            if(board[i][j] == 32){
                y = i;
                x = j;
                pos_c = true;
            }

        }

        if(ally == 2 && pos_c == true && board[y][x] == 32){
            board[y][x] = *ai;
            return;

        }
    }
    pos_c = false;

    for(int i = 0; i < B; i++){
        ally = 0;
        x = 0;
        y = 0;
        for(int j = 0; j < B; j++){
            if(board[j][i] == *enem){
                ally++;
            }
            if(board[j][i] == 32){
                y = j;
                x = i;
                pos_c = true;

            }
        }
        if(ally == 2 && pos_c == true && board[y][x] == 32){
            board[y][x] = *ai;
            return;

        }
    }
    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;

    //TODO: Find out a better way to do this
    /*
     \
      \
       \
       */
    for(int i = 0; i < B; i++){
        if(board[i][i] == *enem){
            ally++;
        } else {
            x = i;
            y = i;
            pos_c = true;
        }
    }

    if(ally == 2 && pos_c == true && board[x][y] == 32){

        board[x][y] = *ai;
        return;
    }
    pos_c = false;
    ally = 0;
    x = 0;
    y = 0;
    /*
       /
      /
     /
       */
    for(int i = 0; i < B; i++){
        for(int j = 2; j > 0; j--){
            if(board[i][j] == *enem){
                ally++;
            } else {
                x = i;
                y = j;
                pos_c = true;
            }
        }
    }

    if(ally == 2 && pos_c == true && board[x][y] == 32){

        board[x][y] = *ai;

        return;
    }
    rand_ai(board, ai);


    return;
}

struct pos {
  int x;
  int y;
};

int minimax_s(char board[B][B], const char *enem, const char *ai){
    //rows and columns
    for(int i = 0; i < B; i++){
        //rows

        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 32){
            if(board[i][0] == *ai){
                return 10;
            } else {
                return -10;
            }
        }

        //Cols

        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 32){
            if(board[0][i] == *ai){
                return 10;
            } else {
                return -10;
            }
        }

    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 32){
        if(board[0][0] == *ai){
            return 10;
        } else{
            return -10;
        }
    }

    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != 32){
        if(board[2][0] == *ai){
            return 10;
        } else{
            return -10;
        }
    }
    if(draw(board) == true){
        return 0;
    }
    char n_board[B][B];
    std::vector<pos> pos;

    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            //copy
            n_board[i][j] = board[i][j];
            //find holes
            if(n_board[i][j] == 32){
                pos.push_back({i,j});
            }
        }
    }

    std::vector<int> scores;

    for(int i = 0; i < pos.size(); i++){
        n_board[pos[i].x][pos[i].y] = *enem;
        int score = minimax_s(n_board,enem,ai);
        scores.push_back(score);
    }
    return 0;
}


int main()
{
    char board[B][B] = {
        {'X','O','O'},
        {32,'X',32},
        {32,'X',32}
    };
    //board_init(board);
    srand(time(NULL));
    //USE AMOUNT OF FRIENDS AND RECORD FRIEND POSITIONS, FIND MISSING ONE IN ROW/COL PER ROW. ALL EMPTY SPOTS
    char pl = 'O';
    char ai = 'X';

/*
    print_board(board);
    //int score = minimax_s(board,&pl,&ai);
    h_ai(board,&pl,&ai);
    //smart_ai(board,&ai,&pl);
    print_board(board);
    //std::cout << "Score is: " << score << std::endl;
*/

    print_board(board);
    while(true){
        //input(board,&pl);
        print_board(board);
        if(win(board) == true || draw(board) == true){
            print_board(board);
            break;
        };
        h_ai(board,&pl, &ai);
        if(win(board) == true || draw(board) == true){
            print_board(board);
            break;
        };
        print_board(board);


    }


    return 0;
}
