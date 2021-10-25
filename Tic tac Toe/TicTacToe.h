#include <iostream>
#include <random> 
#include <stdlib.h> 
#include <chrono>

#pragma once
using namespace std;



enum field : char { CROSS = 'X', ZERO = 'O', EMPTY = '_' };

struct Location
{
    size_t y{ 0 };
    size_t x{ 0 };
};

enum Progress
{
    in_progress,
    won_human,
    won_ai,
    draw
};

#pragma pack (push,1)
struct Game
{
    field** ppField = nullptr;
    const size_t SIZE = 3;
    size_t turn = 0;
    Progress progress = in_progress;
    field human;
    field ai;
};
#pragma pack (pop)

void clearScr()
{
    system("cls");
}

int32_t getRandomNumber(int32_t min, int32_t max)
{
    const static auto speed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(speed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

Progress __fastcall getWon(const Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
                return won_human;

            if (g.ppField[y][0] == g.ai)
                return won_ai;
        }
    }

    for (size_t x = 0; x < g.SIZE; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
                return won_human;

            if (g.ppField[0][x] == g.ai)
                return won_ai;
        }
    }

    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[1][1] == g.human)
            return won_human;

        if (g.ppField[1][1] == g.ai)
            return won_ai;
    }
    if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[0][2])
    {
        if (g.ppField[1][1] == g.human)
            return won_human;

        if (g.ppField[1][1] == g.ai)
            return won_ai;
    }

    bool Draw = true;

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                Draw = false;
                break;
            }
        }
        if (!Draw)
            break;
    }

    if (Draw)
        return draw;

    return in_progress;
}

Location __fastcall getAILocHard(Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] == g.ai;
                if (getWon(g) == won_ai)
                {
                    g.ppField[y][x] == EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] == EMPTY;
            }
        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] == g.human;
                if (getWon(g) == won_human)
                {
                    g.ppField[y][x] == EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] == EMPTY;
            }
        }
    }




    if (g.ppField[1][1] == EMPTY)
        return { 1,1 };

    Location arr[4];
    size_t num = 0;
    if (g.ppField[0][0] == EMPTY)
    {
        arr[num++] = { 0,0 };
    }
    if (g.ppField[2][2] == EMPTY)
    {
        arr[num++] = { 2,2 };
    }
    if (g.ppField[2][0] == EMPTY)
    {
        arr[num++] = { 2,0 };
    }
    if (g.ppField[0][2] == EMPTY)
    {
        arr[num++] = { 0,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNumber(0, 1000) % num;
        return arr[index];
    }

    num = 0;

    if (g.ppField[0][1] == EMPTY)
    {
        arr[num++] = { 0,1 };
    }
    if (g.ppField[2][1] == EMPTY)
    {
        arr[num++] = { 2,1 };
    }
    if (g.ppField[1][0] == EMPTY)
    {
        arr[num++] = { 1,0 };
    }
    if (g.ppField[1][2] == EMPTY)
    {
        arr[num++] = { 1,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNumber(0, 1000) % num;
        return arr[index];
    }
}

Location __fastcall getAILocEasy(Game& g)
{
    if (g.ppField[1][1] == EMPTY)
        return { 1,1 };

    Location arr[4];
    size_t num = 0;
    if (g.ppField[0][0] == EMPTY)
    {
        arr[num++] = { 0,0 };
    }
    if (g.ppField[2][2] == EMPTY)
    {
        arr[num++] = { 2,2 };
    }
    if (g.ppField[2][0] == EMPTY)
    {
        arr[num++] = { 2,0 };
    }
    if (g.ppField[0][2] == EMPTY)
    {
        arr[num++] = { 0,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNumber(0, 1000) % num;
        return arr[index];
    }

    num = 0;

    if (g.ppField[0][1] == EMPTY)
    {
        arr[num++] = { 0,1 };
    }
    if (g.ppField[2][1] == EMPTY)
    {
        arr[num++] = { 2,1 };
    }
    if (g.ppField[1][0] == EMPTY)
    {
        arr[num++] = { 1,0 };
    }
    if (g.ppField[1][2] == EMPTY)
    {
        arr[num++] = { 1,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNumber(0, 1000) % num;
        return arr[index];
    }
}