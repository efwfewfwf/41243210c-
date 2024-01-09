#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "rickmanr.h"
int round = 1;
int d;
char* ptr[26] = { "起點","星空大道1號豪宅","星空大道2號豪宅","前進3格","蓮潭路1號民宅","蓮潭路2號豪宅","蓮潭路3號民宅","蓮潭路4號民宅","蓮潭路5號民宅","命運驛站","康莊大道1號民宅","康莊大道2號豪宅","康莊大道3行民宅","康莊大道4號民宅","康莊大道5號民宅","康莊大道6號豪宅","後退2格","康莊大道7號民宅","康莊大道8號民宅","康莊大道9號豪宅","賭場","前進2格","命運驛站","中正路1號民宅","中正路2號豪宅","中正路3號民宅" };
double price[26] = { 99999999,1000,2500,9999999,1000,2500,1000,1000,1000,99999999,1000,2500,1000,1000,1000,1000,99999999,1000,1000,2500,9999999,9999999,9999999,1000,2500,1000 };

int gamemain(char playname[], int load) {
    switch (load) {
    case 0:
        strcpy(player[0].cName, playname);
        player[0].blance = 5000;
        memcpy(player[0].house, (int[26]) { 0 }, sizeof(int[26]));
        player[0].turn = 0;
        player[0].location = 0;
        strcpy(player[1].cName, "Computerplayer");
        player[1].blance = 5000;
        memcpy(player[1].house, (int[26]) { 0 }, sizeof(int[26]));
        player[1].turn = 0;
        player[1].location = 0;
        break;
    case 1:
            for (int i = 0; i < 10; i++) {
                printf("讀取檔案中");
                for (int j = 0; j < i; j++) {
                    printf(".");
                }
                Sleep(100);
                system("cls");

            }
        
            FILE* read;
            if ((read = fopen("gametemp.txt", "r")) == NULL) {
                strcpy(player[0].cName, playname);
                player[0].blance = 5000;
                memcpy(player[0].house, (int[27]) { 0 }, sizeof(int[27]));
                player[0].turn = 0;
                player[0].location = 0;
                strcpy(player[1].cName, "Computerplayer");
                player[1].blance = 5000;
                memcpy(player[1].house, (int[27]) { 0 }, sizeof(int[27]));
                player[1].turn = 0;
                player[1].location = 0;
            }
            else {
                fscanf(read, "%s %lf", player[0].cName, &player[0].blance);
                for (int i = 0; i < 26; i++) {
                    fscanf(read, "%d ", &player[0].house[i]);
                }
                fscanf(read, "%d %d %d", &player[0].turn, &player[0].location, &player[0].ban);
                fscanf(read, "%s %lf", player[1].cName, &player[1].blance);
                for (int i = 0; i < 26; i++) {
                    fscanf(read, "%d ", &player[1].house[i]);
                }
                fscanf(read, "%d %d %d", &player[1].turn, &player[1].location, &player[1].ban);
                printf("讀檔成功");
                Sleep(1000);
            }
            break;
            fclose(read);
        }

    while (player[0].blance >= 0 && player[1].blance >= 0 && player[0].blance <= 25000 && player[1].blance <= 25000) {
        showImages(player);
        switch (round) {
        case 1:
            playchoice(player);
            break;
        case 2:
            aiaction(player);
        }
    }
    if (player[0].blance < 0) {
        system("cls");
        printf("%s玩家贏了,因為玩家%s破產了(破產玩家資產小於0\n", player[1].cName, player[0].cName);
        printf("按下任意鍵回遊戲選擇頁面...");
        _getch();
        system("cls");
        return 2;
    }
    else if (player[1].blance < 0) {
        system("cls");
        printf("%s玩家贏了,因為玩家%s破產了(破產玩家資產小於0\n", player[0].cName, player[1].cName);
        printf("按下任意鍵回遊戲選擇頁面...");
        _getch();
        system("cls");
        return 1;

    }
    else if (player[0].blance > 25000) {
        system("cls");
        printf("%s玩家贏了,因為玩家%s變成大富翁了(資產超過25000\n", player[0].cName, player[0].cName);
        printf("按下任意鍵回遊戲選擇頁面...");
         _getch();
        system("cls");
        return 1;

    }
    else if (player[0].blance > 25000) {
        system("cls");
        printf("%s玩家贏了,因為玩%s變成大富翁了(資產超過25000\n", player[1].cName, player[1].cName);
        printf("按下任意鍵回遊戲選擇頁面...");
        _getch();
        system("cls");
        return 2;

    }
}

void color(struct playerinfo player[], int x) {
    if (player[0].location == x && player[1].location == x)printf(MAGENTA);
    else if (player[0].location == x)printf(BLUE);
    else if (player[1].location == x)printf(YELLOW);
    else if (player[0].house[x] == 1)printf(GREEN);
    else if (player[1].house[x] == 1)printf(RED);
}



void checkhouse(struct playerinfo* file)
{
    system("cls");
    printf("%s 玩家持有房產\n", file->cName);
    for (int i = 0; i < 26; i++) {
        if (file->house[i] == 1) printf("%s,", ptr[i]);
    }
    printf("\n");
    printf("按下任意鍵繼續大富翁...");
    _getch();
    showImages(player);
}

void playchoice(struct playerinfo player[]) {
    fflush(stdin);
    rewind(stdin);
    printf("請選擇你的操作:0.存檔   1.查看個人房產   2.擲骰子");
    char choice;
    choice = _getch();
    switch (choice) {
    case '0':
        save(player);
        break;
    case '1':
        checkhouse(&player[0]);
        break;
    case '2':
        playeraction(player);
        break;
   /*test case '3':
        player[0].blance = 24999;
        break;
    case '4':
        player[0].blance = 1;
        break;*/
    }
}
void save(struct playerinfo player[]) {
    FILE* save;
    if ((save = fopen("gametemp.txt", "w")) == NULL) {
        printf("gametemp.txt檔案開啟失敗");
    }
    fprintf(save,"%s %lf ",player[0].cName,player[0].blance);
    for (int i = 0; i < 26; i++) {
        fprintf(save, "%d ", player[0].house[i]);
    }
    fprintf(save, "%d %d %d\n", player[0].turn, player[0].location,player[0].ban);
    fprintf(save, "%s %lf ", player[1].cName, player[1].blance);
    for (int i = 0; i < 26; i++) {
        fprintf(save, "%d ", player[1].house[i]);
    }
    fprintf(save, "%d %d %d\n", player[1].turn, player[1].location, player[1].ban);
    fclose(save);
    system("cls");
    showImages(player);
    printf("存檔成功");
    Sleep(1000);
}
void houseown(struct playerinfo player[], int location, int p, int c, int ai) {
    if (player[c].house[location] == 1) {
        player[p].blance -= price[location] * 0.45;
        showImages(player);
        printf("%s經過了%s玩家的土地，被收取過路費%.0lf\n", player[p].cName, player[c].cName, price[location] * 0.45);
        player[c].blance += price[location] * 0.45;
        Sleep(1000);
    }
    else {
        if (player[p].house[location] == 0) {
            switch (ai) {
            case 0:
                printf("目前%s無人持有，價格為:%.0lf，是否購買?(y/n):\n",ptr[location],price[location]);
                char d;
                d = _getch();
                if (d == 'y') {
                    if (player[p].blance >= price[location]) {
                        player[p].blance -= price[location];
                        player[p].house[location] = 1;
                        showImages(player);
                        printf("%s玩家選擇購買了%s，現在獲得了%s一棟", player[p].cName, ptr[location], ptr[location]);
                        Sleep(1000);
                    }
                    else {
                        showImages(player);
                        printf("%s玩家選擇購買%s，但餘額不足，購買失敗", player[p].cName, ptr[location]);
                        Sleep(1000);
                    }
                }
                break;
            case 1:
                if (player[p].blance >= 1000) {
                    if (player[p].blance >= price[location]) {
                        player[p].blance -= price[location];
                        player[p].house[location] = 1;
                        showImages(player);
                        printf("%s玩家選擇購買了%s，現在獲得了%s一棟", player[p].cName, ptr[location], ptr[location]);
                        Sleep(1000);
                    }
                    else {
                        showImages(player);
                        printf("%s玩家選擇購買%s，但餘額不足，購買失敗", player[p].cName, ptr[location]);
                        Sleep(1000);
                    }
                }
                break;
            }
        }
    }
}

void rule(struct playerinfo player[], int p, int c, int ai, char* ptr[]) {
    char d;
    player[p].turn++;
    switch (player[p].location) {
    case 1:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 2:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 3:
        for (int i = 0; i < 3; i++) {
            player[p].location++;
            if (player[p].location == 26) {
                player[p].location = 0;
            }
            showImages(player);
            printf("%s玩家%s\n", player[p].cName, ptr[3]);
            Sleep(500);
        }
        houseown(player, player[p].location, p, c, ai);
        break;
    case 4:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 5:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 6:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 7:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 8:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 9:
        srand(time(NULL));
        d = rand() % 100 + 1;
        if (d >= 1 && d <= 10) {
            while (player[p].location != 0) {
                printf("%s人品大爆發，保送終點(開始)一次", player[p].cName);
                player[p].location++;
                if (player[p].location == 26) player[p].location = 0;
                Sleep(500);
                showImages(player);
            }
            houseown(player, player[p].location, p, c, ai);
        }
        else if (d >= 11 && d <= 20) {
            player[p].blance += 1500;
            printf("天上掉錢，玩家%s，刮樂透刮到1500塊錢", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 21 && d <= 35) {
            player[p].blance += 950;
            printf("玩家%s好心腸，撿到錢包歸還給失主獲得失主的感謝紅包950", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 36 && d <= 50) {
            player[p].blance -= 500;
            printf("玩家%s真倒楣，被扒手拿走了500塊錢", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 51 && d <= 70) {
            player[p].blance -= 750;
            printf("玩家%s扶起了地上的老人，被碰瓷了750塊錢", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 71 && d <= 95) {
            player[p].blance -= -1650;
            printf("玩家%s因偷東西，被罰款1650元", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 96 && d <= 100) {
            player[p].blance -= -2500;
            player[p].ban = 3;
            printf("玩家%s試圖搶劫銀行，被抓住裁法2500塊錢，並且被關進監獄3天(提示:禁止行動3天", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        break;
    case 10:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 11:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 12:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 13:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 14:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 15:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 16:
        for (int i = 0; i < 2; i++) {
            player[p].location--;
            if (player[p].location == 26) {
                player[p].location = 0;
            }
            showImages(player);
            printf("%s玩家%s\n", player[p].cName, ptr[16]);
            Sleep(500);
        }
        houseown(player, player[p].location, p, c, ai);
        break;
    case 17:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 18:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 19:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 20:
        switch (ai) {
        case 0:
            printf("請問是否進入賭場賭博(y/n)(警告:進入賭場極大概率會輸錢");
            d = _getch();
            showImages(player);
            if (d == 'y') {
                srand(time(NULL));
                d = rand() % 100 + 1;
                if (d == 1) {
                    player[p].blance += 8000;
                    printf("%s運氣堪比神明，搬空賭場8000元", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 2 && d <= 5) {
                    player[p].blance += 1;
                    printf("%s表現極佳，賺到賭場1塊錢", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 6 && d <= 9) {
                    player[p].blance += 5000;
                    printf("%s人品大爆發，讓賭場失去了一筆巨額金額5000元", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 10 && d <= 15) {
                    player[p].blance += 3000;
                    printf("玩家%s運氣極度好，讓賭場血虧3000元", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 16 && d <= 25) {
                    player[p].blance += 150;
                    printf("玩家%s運氣不錯，不僅沒輸錢還讓賭場倒貼150元", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 26 && d <= 50) {
                    player[p].blance += 50;
                    printf("玩家%s運氣好，贏走50元", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 51 && d <= 70) {
                    player[p].blance -= 500;
                    printf("玩家%s運氣不佳，小試伸手輸掉了500塊錢", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 71 && d <= 85) {
                    player[p].blance -= 1500;
                    printf("運氣較倒楣，輸掉了1500", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 86 && d <= 95) {
                    player[p].blance -= -3000;
                    printf("玩家%s運氣極為倒楣，輸掉了3000元", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 96 && d <= 100) {
                    player[p].blance -= 9999999999999999999;
                    printf("玩家%s真倒楣一夜之間把錢輸光了還背下驚天巨債%lf", player[p].cName, player[p].blance);
                    showImages(player);
                    Sleep(1000);
                }
            }
            else {
                printf("%s玩家放棄入場賭博賺大錢的機會", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            break;
        case 1:
            showImages(player);
            srand(time(NULL));
            d = rand() % 100 + 1;
            if (d == 1) {
                player[p].blance += 8000;
                printf("%s運氣堪比神明，搬空賭場8000元", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 2 && d <= 5) {
                player[p].blance += 1;
                printf("%s表現極佳，賺到賭場1塊錢", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 6 && d <= 9) {
                player[p].blance += 5000;
                printf("%s人品大爆發，讓賭場失去了一筆巨額金額5000元", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 10 && d <= 15) {
                player[p].blance += 3000;
                printf("玩家%s運氣極度好，讓賭場血虧3000元", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 16 && d <= 25) {
                player[p].blance += 150;
                printf("玩家%s運氣不錯，不僅沒輸錢還讓賭場倒貼150元", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 26 && d <= 50) {
                player[p].blance += 50;
                printf("玩家%s運氣好，贏走50元", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 51 && d <= 70) {
                player[p].blance -= 500;
                printf("玩家%s運氣不佳，小試伸手輸掉了500塊錢", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 71 && d <= 85) {
                player[p].blance -= 1500;
                printf("運氣較倒楣，輸掉了1500", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 86 && d <= 95) {
                player[p].blance -= -3000;
                printf("玩家%s運氣極為倒楣，輸掉了3000元", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 96 && d <= 100) {
                player[p].blance -= 9999999999999999999;
                printf("玩家%s真倒楣一夜之間把錢輸光了還背下驚天巨債%lf", player[p].cName, player[p].blance);
                showImages(player);
                Sleep(1000);
            }
        }
        break;
    case 21:
        for (int i = 0; i < 2; i++) {
            player[p].location++;
            if (player[p].location == 26) {
                player[p].location = 0;
            }
            showImages(player);
            printf("%s玩家%s\n", player[p].cName, ptr[21]);
            Sleep(500);
        }
        houseown(player, player[p].location, p, c, ai);
        break;
    case 22:
        srand(time(NULL));
        d = rand() % 100 + 1;
        if (d >= 1 && d <= 10) {
            while (player[p].location != 0) {
                printf("%s人品大爆發，保送終點(開始)一次\n", player[p].cName);
                player[p].location++;
                if (player[p].location == 26) player[p].location = 0;
                Sleep(500);
                showImages(player);
            }
            houseown(player, player[p].location, p, c, ai);
        }
        else if (d >= 11 && d <= 20) {
            player[p].blance += 1500;
            printf("天上掉錢，玩家%s，刮樂透刮到1500塊錢", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 21 && d <= 35) {
            player[p].blance += 950;
            printf("玩家%s好心腸，撿到錢包歸還給失主獲得失主的感謝紅包950", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 36 && d <= 50) {
            player[p].blance -= 500;
            printf("玩家%s真倒楣，被扒手拿走了500塊錢", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 51 && d <= 70) {
            player[p].blance -= 750;
            printf("玩家%s扶起了地上的老人，被碰瓷了750塊錢", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 71 && d <= 95) {
            player[p].blance -= -1650;
            printf("玩家%s因偷東西，被罰款1650元", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 96 && d <= 100) {
            player[p].blance -= -2500;
            player[p].ban = 3;
            printf("玩家%s試圖搶劫銀行，被抓住裁法2500塊錢，並且被關進監獄3天(提示:禁止行動3天", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        break;
    case 23:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 24:
        houseown(player, player[p].location, p, c, ai);
        break;
    case 25:
        houseown(player, player[p].location, p, c, ai);
        break;
    }
}

void playeraction(struct playerinfo  player[]) {
    if (player[0].ban <= 0) {
        srand(time(NULL));
        d = rand() % 6 + 1;
        for (int i = 0; i < d; i++) {
            player[0].location++;
            if (player[0].location == 26) {
                player[0].location = 0;
            }
            showImages(player);

            printf("玩家的回合:\n");
            printf("玩家抽到了%d點\n", d);
            if (player[0].location == 0) {
                printf("玩家回到了起點，獎勵玩家資產+2500");
                player[0].blance += 2500;
                Sleep(1000);
            }
            Sleep(500);
        }
        showImages(player);
        rule(player, 0, 1, 0, ptr);
    }
    else {
        printf("玩家%s,禁止行動剩下天數%d", player[0].cName, player[0].ban);
        player[0].ban--;
        player[0].turn++;
        Sleep(1000);
        showImages(player);
    }
    round = 2;
}

void aiaction(struct playerinfo player[]) {
    if (player[1].ban <= 0) {
        srand(time(NULL));
        d = rand() % 6 + 1;
        for (int i = 0; i < d; i++) {
            player[1].location++;
            if (player[1].location == 26) {
                player[1].location = 0;
            }
            showImages(player);
            printf("電腦的回合:\n");
            printf("電腦抽到了%d點\n", d);
            if (player[1].location == 0) {
                printf("電腦回到了起點，獎勵電腦資產+2500");
                player[1].blance += 2500;
                Sleep(1000);
            }
            Sleep(500);
        }
        showImages(player);
        rule(player, 1, 0, 1, ptr);
    }

    else {
        printf("玩家%s,禁止行動剩下天數%d", player[1].cName, player[1].ban);
        player[1].ban--;
        player[1].turn++;
        Sleep(1000);
        showImages(player);
    }
    round = 1;
}
