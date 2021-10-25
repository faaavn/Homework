#include <iostream>
#include <random> 
#include <stdlib.h> 
#include <chrono>
#include <locale.h>
#include "TicTacToe.h"

using namespace std;
 

void __fastcall initGame (Game& g)
{
    g.ppField = new field * [g.SIZE];
    for (size_t i = 0; i < g.SIZE; i++)
    {
        g.ppField[i] = new field[g.SIZE];
    }
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            g.ppField[y][x] = EMPTY;
        }

    }
 
    if (getRandomNumber(0, 1000) > 500)
    {
        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    }
    else
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }
}

void __fastcall deInitGame(Game& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}

void __fastcall drawGame(const Game& g)
{
    cout << endl << "    ";
    for (size_t x = 0; x < g.SIZE; x++)
    {

        cout << x + 1 << "   ";
    }
    cout << endl;

    for (size_t y = 0; y < g.SIZE; y++)
    {
        cout << y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
             
            cout << g.ppField[y][x] << " | ";
        }
        cout << endl;
    }

    cout << endl << "Human: " << g.human << endl << "Computer: " << g.ai << endl;

}


Location __fastcall getHumanLoc(const Game& g)
{
    Location c;
    do
    {
        cout << "Enter x (from 1 to 3) : ";
        cin >> c.x;
        cout << "Enter y (from 1 to 3) : ";
        cin >> c.y;
        c.x--;
        c.y--;
    } while (c.x >2 || c.y >2 || g.ppField[c.y][c.x] != EMPTY);
    
    return c;
}

void __fastcall congrats(const Game& g)
{
    if (g.progress == won_human)
        cout << "Human won! Nice one." << endl;
    else if (g.progress == won_ai)
        cout << "Ai won! Better luck next time." << endl;
    else if (g.progress == draw)
        cout << "It`s a draw!" << endl;
}

int main()
{   
    Game g;
    initGame(g);
    int difficulty= 0;
    cout << "Choose the difficulty (0 - easy) ( 1 - hard): " << endl;
    cin >> difficulty;

    clearScr();
    drawGame(g);
    
    do {    
        if (g.turn % 2 == 0)
        {
            Location c = getHumanLoc(g);
            g.ppField[c.y][c.x] = g.human;
        }
        else if (difficulty == 0)
        {
            Location c = getAILocEasy(g);
            g.ppField[c.y][c.x] = g.ai;
        }
        else if (difficulty == 1)
        {
            Location c = getAILocHard(g);
            g.ppField[c.y][c.x] = g.ai;
        }
        else if (difficulty != 1 && difficulty != 0) 
        {
            break;
        }
       
        clearScr();
        drawGame(g);
        g.turn++;
        g.progress = getWon(g);

    } while (g.progress == in_progress); 
    
    congrats(g);
    
    deInitGame(g);
    return 0;
}

