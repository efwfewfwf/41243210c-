#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#include "rickmanr.h"
extern int round;
extern int d;
extern char* ptr[26];
extern double price[26];
void showImages(struct playerinfo player[]) {
    system("cls");
    printf("-------");
    for (int i = 0; i < 9; i++) {
        printf("------");
    }
    printf("\n");
    printf("|");
    color(player, 0);
    printf("    1"); //1 
    printf(RESET);
    printf("|");
    color(player, 1);
    printf("    2"); //1 
    printf(RESET);
    printf("|");
    color(player, 2);
    printf("    3"); //1 
    printf(RESET);
    printf("|");
    color(player, 3);
    printf("    4"); //1 
    printf(RESET);
    printf("|");
    color(player, 4);
    printf("    2"); //1 
    printf(RESET);
    printf("|");
    color(player, 5);
    printf("    6"); //1 
    printf(RESET);
    printf("|");
    color(player, 6);
    printf("    7"); //1 
    printf(RESET);
    printf("|");
    color(player, 7);
    printf("    8"); //1 
    printf(RESET);
    printf("|");
    color(player, 8);
    printf("    9"); //1 
    printf(RESET);
    printf("|");
    color(player, 9);
    printf("   10"); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 0);
    printf("�}�l"); //1 
    printf(RESET);
    printf(" |");
    color(player, 1);
    printf("�P ��"); //1 
    printf(RESET);
    printf("|");
    color(player, 2);
    printf("�j �D"); //1 
    printf(RESET);
    printf("|");
    color(player, 3);
    printf("�e�i "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 5);
    printf("��   "); //1 
    printf(RESET);
    printf("|");
    color(player, 6);
    printf(" ��  "); //1 
    printf(RESET);
    printf("|");
    color(player, 7);
    printf(" ��  "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 9);
    printf("�R�B "); //1 
    printf(RESET);
    printf("|\n");
    printf("|     |");
    color(player, 1);
    printf("1 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 2);
    printf("2 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 3);
    printf("3 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 4);
    printf("1 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 5);
    printf("2 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 6);
    printf("3 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 7);
    printf("4 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 8);
    printf("5 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 9);
    printf("�毸 "); //1 
    printf(RESET);
    printf("|\n");
    printf("-------");
    for (int i = 0; i < 9; i++) {
        printf("------");
    }
    printf("\n");
    printf("|");
    color(player, 25);
    printf("   26"); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 10);
    printf("   11"); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 25);
    printf("��   "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|     |\n");
    printf("|");
    color(player, 25);
    printf("3 �� "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 10);
    printf("1 �� "); //1 
    printf(RESET);
    printf("|\n");
    printf("|-----|");
    printf("                                               ");
    printf("|-----|\n");
    printf("|");
    color(player, 24);
    printf("   25"); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 11);
    printf("   12"); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 24);
    printf("��   "); //1 
    printf(RESET);
    printf("|");
    printf("             �j          �I        ��          ");
    printf("|");
    color(player, 11);
    printf("�d   "); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 24);
    printf("2 �� "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 11);
    printf("2 �� "); //1 
    printf(RESET);
    printf("|\n");
    printf("|-----|");
    printf("                                               ");
    printf("|-----|\n");
    printf("|");
    color(player, 23);
    printf("   24"); //1 
    printf(RESET);;
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 12);
    printf("   13"); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 23);
    printf("��   "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 12);
    printf("��   "); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 23);
    printf("1 �� "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 12);
    printf("3 �� "); //1 
    printf(RESET);
    printf("|\n");
    printf("-------");
    for (int i = 0; i < 9; i++) {
        printf("------");
    }
    printf("\n");
    printf("|");
    color(player, 22);
    printf("   23"); //1 
    printf(RESET);
    printf("|");
    color(player, 21);
    printf("   22"); //1 
    printf(RESET);
    printf("|");
    color(player, 20);
    printf("   21"); //1 
    printf(RESET);
    printf("|");
    color(player, 19);
    printf("   20"); //1 
    printf(RESET);
    printf("|");
    color(player, 18);
    printf("   19"); //1 
    printf(RESET);
    printf("|");
    color(player, 17);
    printf("   18"); //1 
    printf(RESET);
    printf("|");
    color(player, 16);
    printf("   17"); //1 
    printf(RESET);
    printf("|");
    color(player, 15);
    printf("   16"); //1 
    printf(RESET);
    printf("|");
    color(player, 14);
    printf("   15"); //1 
    printf(RESET);
    printf("|");
    color(player, 13);
    printf("   14"); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 22);
    printf("�R�B"); //1 
    printf(RESET);
    printf(" |");
    color(player, 21);
    printf("�e�i "); //1 
    printf(RESET);
    printf("|");
    color(player, 20);
    printf("��� "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    printf("     |");
    printf("     |");
    color(player, 16);
    printf("��h "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 14);
    printf("�D   "); //1 
    printf(RESET);
    printf("|");
    color(player, 13);
    printf("�j   "); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 22);
    printf("�毸 "); //1 
    printf(RESET);
    printf("|");
    color(player, 21);
    printf("2 �� "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 19);
    printf("9 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 18);
    printf("8 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 17);
    printf("7 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 16);
    printf("2 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 15);
    printf("6 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 14);
    printf("5 �� "); //1 
    printf(RESET);
    printf("|");
    color(player, 13);
    printf("4 �� "); //1 
    printf(RESET);
    printf("|\n");
    printf("-------");
    for (int i = 0; i < 9; i++) {
        printf("------");
    }
    if (round == 1) {
        printf("   \n�ثe���a:%d�����a", round);
        printf("\n��%d��\n", player[round - 1].turn);
        if (player[round - 1].blance >= 10000)printf("����,�����H     : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 7500)printf("����,��������   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 5000)printf("����,�����Ѧʩm : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 2500)printf("����,�z�դH��   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 0)printf("����,��^��     : %s\n", player[round - 1].cName);
        printf("�겣 : %.2lf\n", player[round - 1].blance);
    }
    else {
        printf("   \n�ثe���a:%d�����a", round);
        printf("\n��%d��\n", player[round - 1].turn);
        if (player[round - 1].blance >= 10000)printf("����,�����H     : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 7500)printf("����,��������   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 5000)printf("����,�����Ѧʩm : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 2500)printf("����,�z�դH��   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 0)printf("����,��^��     : %s\n", player[round - 1].cName);
        printf("�겣 : %.2lf\n", player[round - 1].blance);
    }
}