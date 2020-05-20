#include <iostream>
#include "queens.h"

queenBoard::queenBoard () {
    s = 5;
    board = new int* [5];
    for (int r = 0; r < 5; r++) {
        board[r] = new int [5];
        for (int c = 0; c < 5; c++) {
            board[r][c] = 0;
        }
    }
    printB();
}

queenBoard::queenBoard (int size) {
    s = size; 
    board = new int* [s];
    for (int r = 0; r < s; r++) {
        board[r] = new int [s];
        for (int c = 0; c < s; c++) {
            board[r][c] = 0;
        }
    }
    printB();
}

bool queenBoard::solve () {
    std::cout << "solve" << std::endl;
    return solver(0);
}

bool queenBoard::solver (int col) {
    if (col == s) {
        printB();
        //return true;
    }
    for (int r = 0; r < s; r++) {
        if (addQueen(r, col)) {
            if (solver(col+1)) {
                return true;
            }
            removeQueen(r,col);
        }
        removeQueen(r,col);
    }
    return false;
}

bool queenBoard::addQueen (int r, int c) {
    if (r < s && c < s) {
        if (board[r][c] == 0) {
            board[r][c]--;
            add(r,c);
            if (disp) {
                std::cout << "add " << r << " " << c << std::endl;
                printB();
            }
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void queenBoard::add (int r, int c) {
    for (int rr = r+1, cc = c+1; rr < s && cc < s; rr++, cc++) {
        board[rr][cc]++;
    }
    for (int rr = r-1, cc = c+1; rr > -1 && cc < s; rr--, cc++) {
        board[rr][cc]++;
    }
    for (int rr = r+1, cc = c-1; rr < s && cc > -1; rr++, cc--) {
        board[rr][cc]++;
    }
    for (int rr = r-1, cc = c-1; rr > -1 && cc > -1; rr--, cc--) {
        board[rr][cc]++;
    }
    for (int rr = r+1; rr < s; rr++) {
        board[rr][c]++;
    }
    for (int cc = c+1; cc < s; cc++) {
        board[r][cc]++;
    }
    for (int rr = r-1; rr > -1; rr--) {
        board[rr][c]++;
    }
    for (int cc = c-1; cc > -1; cc--) {
        board[r][cc]++;
    }
}

bool queenBoard::removeQueen (int r, int c) {
    if (r < s && c < s) {
        if (board[r][c] == -1) {
            board[r][c]++;
            abort(r,c);
            if (disp) {
                std::cout << "remove " << r << " " << c << std::endl;
                printB();
            }
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void queenBoard::abort (int r, int c) {
    for (int rr = r+1, cc = c+1; rr < s && cc < s; rr++, cc++) {
        board[rr][cc]--;
    }
    for (int rr = r-1, cc = c+1; rr > -1 && cc < s; rr--, cc++) {
        board[rr][cc]--;
    }
    for (int rr = r+1, cc = c-1; rr < s && cc > -1; rr++, cc--) {
        board[rr][cc]--;
    }
    for (int rr = r-1, cc = c-1; rr > -1 && cc > -1; rr--, cc--) {
        board[rr][cc]--;
    }
    for (int rr = r+1; rr < s; rr++) {
        board[rr][c]--;
    }
    for (int cc = c+1; cc < s; cc++) {
        board[r][cc]--;
    }
    for (int rr = r-1; rr > -1; rr--) {
        board[rr][c]--;
    }
    for (int cc = c-1; cc > -1; cc--) {
        board[r][cc]--;
    }
}


void queenBoard::printB () {
    for (int r = 0; r < s; r++) {
        for (int c = 0; c < s; c++) {
            if (board[r][c] == -1) {
                std::cout << " Q ";
            }
            else {
                //std::cout << "[ ]"; 
                //std::cout << "   "; 
                std::cout << " - "; 
                //std::cout << " " << board[r][c] << " " ;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int queenBoard::count () {
    return counter(0);
}

int queenBoard::counter (int col) {
    int sol = 0;
    if (col == s) {
        printB();
        return 1;
    }
    for (int r = 0; r < s; r++) {
        if (addQueen(r, col)) {
            sol += counter(col+1);
            removeQueen(r,col);
        }
        removeQueen(r,col);
    }
    return sol;
}

