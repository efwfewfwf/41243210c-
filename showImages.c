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
    printf("開始"); //1 
    printf(RESET);
    printf(" |");
    color(player, 1);
    printf("星 空"); //1 
    printf(RESET);
    printf("|");
    color(player, 2);
    printf("大 道"); //1 
    printf(RESET);
    printf("|");
    color(player, 3);
    printf("前進 "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 5);
    printf("蓮   "); //1 
    printf(RESET);
    printf("|");
    color(player, 6);
    printf(" 潭  "); //1 
    printf(RESET);
    printf("|");
    color(player, 7);
    printf(" 路  "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 9);
    printf("命運 "); //1 
    printf(RESET);
    printf("|\n");
    printf("|     |");
    color(player, 1);
    printf("1 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 2);
    printf("2 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 3);
    printf("3 格 "); //1 
    printf(RESET);
    printf("|");
    color(player, 4);
    printf("1 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 5);
    printf("2 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 6);
    printf("3 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 7);
    printf("4 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 8);
    printf("5 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 9);
    printf("驛站 "); //1 
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
    printf("中   "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|     |\n");
    printf("|");
    color(player, 25);
    printf("3 號 "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 10);
    printf("1 號 "); //1 
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
    printf("正   "); //1 
    printf(RESET);
    printf("|");
    printf("             大          富        翁          ");
    printf("|");
    color(player, 11);
    printf("康   "); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 24);
    printf("2 號 "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 11);
    printf("2 號 "); //1 
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
    printf("路   "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 12);
    printf("莊   "); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 23);
    printf("1 號 "); //1 
    printf(RESET);
    printf("|");
    printf("                                               ");
    printf("|");
    color(player, 12);
    printf("3 號 "); //1 
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
    printf("命運"); //1 
    printf(RESET);
    printf(" |");
    color(player, 21);
    printf("前進 "); //1 
    printf(RESET);
    printf("|");
    color(player, 20);
    printf("賭場 "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    printf("     |");
    printf("     |");
    color(player, 16);
    printf("後退 "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 14);
    printf("道   "); //1 
    printf(RESET);
    printf("|");
    color(player, 13);
    printf("大   "); //1 
    printf(RESET);
    printf("|\n");
    printf("|");
    color(player, 22);
    printf("驛站 "); //1 
    printf(RESET);
    printf("|");
    color(player, 21);
    printf("2 格 "); //1 
    printf(RESET);
    printf("|");
    printf("     |");
    color(player, 19);
    printf("9 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 18);
    printf("8 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 17);
    printf("7 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 16);
    printf("2 格 "); //1 
    printf(RESET);
    printf("|");
    color(player, 15);
    printf("6 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 14);
    printf("5 號 "); //1 
    printf(RESET);
    printf("|");
    color(player, 13);
    printf("4 號 "); //1 
    printf(RESET);
    printf("|\n");
    printf("-------");
    for (int i = 0; i < 9; i++) {
        printf("------");
    }
    if (round == 1) {
        printf("   \n目前玩家:%d號玩家", round);
        printf("\n第%d天\n", player[round - 1].turn);
        if (player[round - 1].blance >= 10000)printf("身分,有錢人     : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 7500)printf("身分,中產階級   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 5000)printf("身分,平民老百姓 : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 2500)printf("身分,弱勢人民   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 0)printf("身分,臭乞丐     : %s\n", player[round - 1].cName);
        printf("資產 : %.2lf\n", player[round - 1].blance);
    }
    else {
        printf("   \n目前玩家:%d號玩家", round);
        printf("\n第%d天\n", player[round - 1].turn);
        if (player[round - 1].blance >= 10000)printf("身分,有錢人     : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 7500)printf("身分,中產階級   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 5000)printf("身分,平民老百姓 : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 2500)printf("身分,弱勢人民   : %s\n", player[round - 1].cName);
        else if (player[round - 1].blance >= 0)printf("身分,臭乞丐     : %s\n", player[round - 1].cName);
        printf("資產 : %.2lf\n", player[round - 1].blance);
    }
}