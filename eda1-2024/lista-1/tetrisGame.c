/*
 * tetris.c
 *
 * compile: gcc -o tetris -lncurses tetris.c
 *
 * tetrimino types
 *  1: ####   2: ##     3:  ##   4: ##
 *               ##        ##        ##
 *
 *  5: #      6:   #    7:  #
 *     ###       ###       ###
 *
 * How to play
 *  'h': move a tetrimino to left
 *  'j': drop a tetrimino shortly
 *  'k': rotate a tetrimino anticlockwise
 *  'l': move a tetrimino to right
 *  'q': quit a game
 */
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#define WIDTH (10)
#define HEIGHT (20)
#define COUNT (40)

typedef struct tetrimino {
    int type; // 1~7
    int x, y;
    int array[4][2];
} tetrimino;

int tet_type[7][4][2] = {{{0,-1},{0,0},{0,1},{0,2}},    // type 1
                         {{0,0},{0,1},{1,0},{1,1}},     // type 2
                         {{0,0},{0,1},{1,-1},{1,0}},    // type 3
                         {{0,0},{1,0},{-1,1},{0,1}},    // type 4
                         {{-1,0},{-1,1},{0,1},{1,1}},   // type 5
                         {{1,-1},{-1,0},{0,0},{1,0}},   // type 6
                         {{0,-1},{-1,0},{0,0},{1,0}}};  // type 7


int board[WIDTH+2][HEIGHT+2] = {};

void init() {
    srand((unsigned)time(NULL)); // set random seed

    initscr();
    leaveok(stdscr, true); //no cursor
    curs_set(0); // no cursor (again)
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);         // type 1
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);   // type 2
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA); // type 3
    init_pair(5, COLOR_GREEN, COLOR_GREEN);     // type 4
    init_pair(6, COLOR_BLUE, COLOR_BLUE);       // type 5
    init_pair(7, COLOR_CYAN, COLOR_CYAN);       // type 6
    init_pair(8, COLOR_WHITE, COLOR_WHITE);     // type 7
    bkgd(COLOR_PAIR(1));
    erase();
}

void init_board() {
    for (int i=0; i<=HEIGHT+1; i++) {
        board[0][i] = 7;        // left side wall
        board[WIDTH+1][i] = 7;  // right side wall
    }
    for (int i=0; i<=WIDTH+1; i++)
        board[i][HEIGHT+1] = 7; //ground
}

void finalize() {
    endwin();
}

void gameover() {
    attron(COLOR_PAIR(1));
    move(10,4);
    addstr("G A M E  O V E R");
    timeout(-1);
    getch();
}

void display_board() {
    for (int j=0; j<=HEIGHT+1; j++) {
        for (int i=0; i<=WIDTH+1; i++) {
            attron(COLOR_PAIR(board[i][j]+1));
            move(j, i*2);
            addstr("  ");
        }
    }
}

void display_tetrimino(tetrimino *t) {
    for (int i=0; i<4; i++) {
        attron(COLOR_PAIR(t->type+1));
        move( t->y + t->array[i][1],
              (t->x + t->array[i][0]) * 2 );
        addstr("  ");
    }
}

int check_movable(tetrimino *t) {
    for (int i=0; i<4; i++) {
        if ( board[ t->x + t->array[i][0] ]
                  [ t->y + t->array[i][1] ] )
            return 0;
    }
    return 1;
}

int drop(tetrimino *t) {
    t->y++;
    if(!check_movable(t)) {
        t->y--;
        return 1;
    }
    return 0;
}

void move_left(tetrimino *t) {
    t->x--;
    if (!check_movable(t))
        t->x++;
}
void move_right(tetrimino *t) {
    t->x++;
    if (!check_movable(t))
        t->x--;
}

void rotate(tetrimino *t) {
    int swap[4][2] = {};
    for (int i=0; i<4; i++)
        for (int j=0; j<2; j++)
           swap[i][j] = t->array[i][j];
    for (int i=0; i<4; i++) {
        t->array[i][0] = swap[i][1];
        t->array[i][1] = -swap[i][0];
    }
    if (!check_movable(t))
        for (int i=0; i<4; i++)
            for (int j=0; j<2; j++)
                t->array[i][j] = swap[i][j];
}

int new_tetrimino(tetrimino *t) {
    t -> type = rand()%7 + 1;
    t -> x = WIDTH/2;
    t -> y = 1;
    for (int i=0; i<4; i++)
        for (int j=0; j<2; j++)
            t -> array[i][j] = tet_type[t->type-1][i][j];
    return check_movable(t);
}

void anchor(tetrimino *t) {
    for (int i=0; i<4; i++) {
        board[ t->x + t->array[i][0] ][ t->y + t->array[i][1] ]
             = t->type;
    }
}

int check_row(int r) {
    for (int i=1; i<=WIDTH; i++)
        if (!board[i][r])
            return 0;
    return 1;
}

void delete_row(int r) {
    for (int i=r; i>0; i--)
        for (int j=1; j<=WIDTH; j++)
            board[j][i] = board[j][i-1];
}

int main() {
    int cnt = 0;
    tetrimino tet;

    init();
    init_board();
    clear();
    new_tetrimino(&tet);
    while (1) {
        timeout(5);
        switch(getch()) {
            case 'q':
                goto END;
                break;
            case 'h':
                move_left(&tet);
                break;
            case 'j':
                drop(&tet);
                break;
            case 'k':
                rotate(&tet);
                break;
            case 'l':
                move_right(&tet);
        }
        if (cnt == COUNT) {
            if (drop(&tet)) {
                anchor(&tet);
                if (!new_tetrimino(&tet))
                    goto GAME_OVER;
                for (int i=HEIGHT; i>0; i--)
                    if (check_row(i)) {
                        delete_row(i);
                        i++;
                    }
            }
            cnt = 0;
        }
        display_board();
        display_tetrimino(&tet);
        refresh();
        cnt++;
    }
GAME_OVER:
    gameover();
END:
    finalize();
    return 0;
}