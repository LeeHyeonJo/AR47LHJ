#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    int a_hp = 100;
    int a_dmg = 10;
    int b_hp = 120;
    int b_dmg = 15;

    while (1) {
        system("cls");
        printf_s("A's HP: %d\nA's DMG: %d\n\nB's HP: %d\nB's DMG: %d\n\n", a_hp, a_dmg, b_hp, b_dmg);
        printf_s("A가 B를 공격합니다.\n");
        _getch();
        int before_b_hp = b_hp; // 이전 B의 체력 저장
        b_hp -= a_dmg;
        if (b_hp <= 0) {
            printf_s("A wins!");
            break;
        }

        system("cls");
        printf_s("A's HP: %d\nA's DMG: %d\n\nB's HP: %d\nB's DMG: %d\n\n", a_hp, a_dmg, b_hp, b_dmg);
        printf_s("B의 체력이 %d에서 %d로 변경됐습니다.\n", before_b_hp, b_hp); // 변경된 B의 체력 출력
        printf_s("B가 A를 공격합니다.\n");
        _getch();
        int before_a_hp = a_hp; // 이전 A의 체력 저장
        a_hp -= b_dmg;
        if (a_hp <= 0) {
            printf_s("B wins!");
            break;
        }
        system("cls");
        printf_s("A's HP: %d\nA's DMG: %d\n\nB's HP: %d\nB's DMG: %d\n\n", a_hp, a_dmg, b_hp, b_dmg);
        printf_s("A의 체력이 %d에서 %d로 변경됐습니다.\n", before_a_hp, a_hp); // 변경된 A의 체력 출력
        _getch();
    }

    return 0;
}
