// 진행중.. 

#include <iostream> 
#include <conio.h> 
#include <Windows.h> 

const int ScreenYSize = 3;
const int ScreenXSize = 3;

class ConsoleScreen {
private:
    char Arr[ScreenYSize][ScreenXSize] = {};
    int PlayerY;
    int PlayerX;
public:
    ConsoleScreen() {
        for (size_t y = 0; y < ScreenYSize; y++) {
            for (size_t x = 0; x < ScreenXSize; x++) {
                Arr[y][x] = 'a';
            }
        }
        PlayerY = ScreenYSize / 2;
        PlayerX = ScreenXSize / 2;
        Arr[PlayerY][PlayerX] = '*';
    }

    void updatePlayerPosition(char direction) {
        Arr[PlayerY][PlayerX] = 'a'; // 이전 위치를 'a'로 변경
        switch (direction) {
        case 'a':
        case 'A':
            PlayerX -= 1;
            break;
        case 'd':
        case 'D':
            PlayerX += 1;
            break;
        case 'w':
        case 'W':
            PlayerY -= 1;
            break;
        case 's':
        case 'S':
            PlayerY += 1;
            break;
        default:
            break;
        }
        PlayerY = std::max(0, std::min(PlayerY, ScreenYSize - 1)); // 플레이어가 화면 바운드 안에 있도록 보장
        PlayerX = std::max(0, std::min(PlayerX, ScreenXSize - 1));
        Arr[PlayerY][PlayerX] = '*'; // 새 위치를 '*'로 변경
    }

    void drawScreen() {
        system("cls");
        for (size_t y = 0; y < ScreenYSize; y++) {
            for (size_t x = 0; x < ScreenXSize; x++) {
                printf_s("%c", Arr[y][x]);
            }
            printf_s("\n");
        }
        Sleep(200);
    }
};

int main() {
    ConsoleScreen game;
    while (true) {
        game.drawScreen();
        if (_kbhit()) {
            char ch = _getch();
            game.updatePlayerPosition(ch);
        }
    }
    return 0;
}