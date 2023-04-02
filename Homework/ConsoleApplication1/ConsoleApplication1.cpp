#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
    const int screenysize = 5;
    const int screenxsize = 5;

    char map[screenysize][screenxsize] = {};

    for (int y = 0; y < screenysize; y++)
    {
        for (int x = 0; x < screenxsize; x++)
        {
            map[y][x] = 'a';
        }
    }

    int playery = screenysize / 2;
    int playerx = screenxsize / 2;

    map[playery][playerx] = '*';

    system("cls");

    while (true)
    {
        map[playery][playerx] = 'a';
        system("cls");

        if (_kbhit())
        {
            char key = _getch();

            switch (key)
            {
            case 'a':
            case 'A':
                if (playerx > 0) {
                    playerx -= 1;
                }
                break;

            case 'd':
            case 'D':
                if (playerx < screenxsize - 1) {
                    playerx += 1;
                }
                break;

            case 's':
            case 'S':
                if (playery < screenysize - 1) {
                    playery += 1;
                }
                break;

            case 'w':
            case 'W':
                if (playery > 0) {
                    playery -= 1;
                }
                break;
            }
        }

        map[playery][playerx] = '*';

        for (int y = 0; y < screenysize; y++)
        {
            for (int x = 0; x < screenxsize; x++)
            {
                printf_s("%c", map[y][x]);
            }
            printf_s("\n");
        }

        Sleep(500);
    }

    return 0;
}