#pragma once

class queenBoard {
public: 
    queenBoard ();
    queenBoard (int s);
    bool solve ();
    int count ();

private:
    int s;
    int **board;
    bool disp = false;
    bool solver (int col);
    bool addQueen (int r, int c);
    void add (int r, int c);
    bool removeQueen (int r, int c);
    void abort (int r, int c);
    void printB ();
    int counter (int col);
};
