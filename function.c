#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "rickmanr.h"
int round = 1;
int d;
char* ptr[26] = { "�_�I","�P�Ťj�D1�����v","�P�Ťj�D2�����v","�e�i3��","�����1�����v","�����2�����v","�����3�����v","�����4�����v","�����5�����v","�R�B�毸","�d���j�D1�����v","�d���j�D2�����v","�d���j�D3����v","�d���j�D4�����v","�d���j�D5�����v","�d���j�D6�����v","��h2��","�d���j�D7�����v","�d���j�D8�����v","�d���j�D9�����v","���","�e�i2��","�R�B�毸","������1�����v","������2�����v","������3�����v" };
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
                printf("Ū���ɮפ�");
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
                printf("Ū�ɦ��\");
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
        printf("%s���aĹ�F,�]�����a%s�}���F(�}�����a�겣�p��0\n", player[1].cName, player[0].cName);
        printf("���U���N��^�C����ܭ���...");
        _getch();
        system("cls");
        return 2;
    }
    else if (player[1].blance < 0) {
        system("cls");
        printf("%s���aĹ�F,�]�����a%s�}���F(�}�����a�겣�p��0\n", player[0].cName, player[1].cName);
        printf("���U���N��^�C����ܭ���...");
        _getch();
        system("cls");
        return 1;

    }
    else if (player[0].blance > 25000) {
        system("cls");
        printf("%s���aĹ�F,�]�����a%s�ܦ��j�I�ΤF(�겣�W�L25000\n", player[0].cName, player[0].cName);
        printf("���U���N��^�C����ܭ���...");
         _getch();
        system("cls");
        return 1;

    }
    else if (player[0].blance > 25000) {
        system("cls");
        printf("%s���aĹ�F,�]����%s�ܦ��j�I�ΤF(�겣�W�L25000\n", player[1].cName, player[1].cName);
        printf("���U���N��^�C����ܭ���...");
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
    printf("%s ���a�����в�\n", file->cName);
    for (int i = 0; i < 26; i++) {
        if (file->house[i] == 1) printf("%s,", ptr[i]);
    }
    printf("\n");
    printf("���U���N���~��j�I��...");
    _getch();
    showImages(player);
}

void playchoice(struct playerinfo player[]) {
    fflush(stdin);
    rewind(stdin);
    printf("�п�ܧA���ާ@:0.�s��   1.�d�ݭӤH�в�   2.�Y��l");
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
        printf("gametemp.txt�ɮ׶}�ҥ���");
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
    printf("�s�ɦ��\");
    Sleep(1000);
}
void houseown(struct playerinfo player[], int location, int p, int c, int ai) {
    if (player[c].house[location] == 1) {
        player[p].blance -= price[location] * 0.45;
        showImages(player);
        printf("%s�g�L�F%s���a���g�a�A�Q�����L���O%.0lf\n", player[p].cName, player[c].cName, price[location] * 0.45);
        player[c].blance += price[location] * 0.45;
        Sleep(1000);
    }
    else {
        if (player[p].house[location] == 0) {
            switch (ai) {
            case 0:
                printf("�ثe%s�L�H�����A���欰:%.0lf�A�O�_�ʶR?(y/n):\n",ptr[location],price[location]);
                char d;
                d = _getch();
                if (d == 'y') {
                    if (player[p].blance >= price[location]) {
                        player[p].blance -= price[location];
                        player[p].house[location] = 1;
                        showImages(player);
                        printf("%s���a����ʶR�F%s�A�{�b��o�F%s�@��", player[p].cName, ptr[location], ptr[location]);
                        Sleep(1000);
                    }
                    else {
                        showImages(player);
                        printf("%s���a����ʶR%s�A���l�B�����A�ʶR����", player[p].cName, ptr[location]);
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
                        printf("%s���a����ʶR�F%s�A�{�b��o�F%s�@��", player[p].cName, ptr[location], ptr[location]);
                        Sleep(1000);
                    }
                    else {
                        showImages(player);
                        printf("%s���a����ʶR%s�A���l�B�����A�ʶR����", player[p].cName, ptr[location]);
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
            printf("%s���a%s\n", player[p].cName, ptr[3]);
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
                printf("%s�H�~�j�z�o�A�O�e���I(�}�l)�@��", player[p].cName);
                player[p].location++;
                if (player[p].location == 26) player[p].location = 0;
                Sleep(500);
                showImages(player);
            }
            houseown(player, player[p].location, p, c, ai);
        }
        else if (d >= 11 && d <= 20) {
            player[p].blance += 1500;
            printf("�ѤW�����A���a%s�A��ֳz���1500����", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 21 && d <= 35) {
            player[p].blance += 950;
            printf("���a%s�n�߸z�A�ߨ���]�k�ٵ����D��o���D���P�¬��]950", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 36 && d <= 50) {
            player[p].blance -= 500;
            printf("���a%s�u�˷��A�Q���⮳���F500����", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 51 && d <= 70) {
            player[p].blance -= 750;
            printf("���a%s�߰_�F�a�W���ѤH�A�Q�I���F750����", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 71 && d <= 95) {
            player[p].blance -= -1650;
            printf("���a%s�]���F��A�Q�@��1650��", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 96 && d <= 100) {
            player[p].blance -= -2500;
            player[p].ban = 3;
            printf("���a%s�չϷm�T�Ȧ�A�Q�����k2500�����A�åB�Q���i�ʺ�3��(����:�T����3��", player[p].cName);
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
            printf("%s���a%s\n", player[p].cName, ptr[16]);
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
            printf("�аݬO�_�i�J������(y/n)(ĵ�i:�i�J������j���v�|���");
            d = _getch();
            showImages(player);
            if (d == 'y') {
                srand(time(NULL));
                d = rand() % 100 + 1;
                if (d == 1) {
                    player[p].blance += 8000;
                    printf("%s�B����񯫩��A�h�Ž��8000��", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 2 && d <= 5) {
                    player[p].blance += 1;
                    printf("%s��{���ΡA�Ȩ���1����", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 6 && d <= 9) {
                    player[p].blance += 5000;
                    printf("%s�H�~�j�z�o�A��������h�F�@�����B���B5000��", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 10 && d <= 15) {
                    player[p].blance += 3000;
                    printf("���a%s�B�𷥫צn�A���������3000��", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 16 && d <= 25) {
                    player[p].blance += 150;
                    printf("���a%s�B�𤣿��A���ȨS�����������˶K150��", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 26 && d <= 50) {
                    player[p].blance += 50;
                    printf("���a%s�B��n�AĹ��50��", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 51 && d <= 70) {
                    player[p].blance -= 500;
                    printf("���a%s�B�𤣨ΡA�p�զ���鱼�F500����", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 71 && d <= 85) {
                    player[p].blance -= 1500;
                    printf("�B����˷��A�鱼�F1500", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 86 && d <= 95) {
                    player[p].blance -= -3000;
                    printf("���a%s�B�𷥬��˷��A�鱼�F3000��", player[p].cName);
                    Sleep(1000);
                    showImages(player);
                }
                else if (d >= 96 && d <= 100) {
                    player[p].blance -= 9999999999999999999;
                    printf("���a%s�u�˷��@�]�����������F�٭I�U��ѥ���%lf", player[p].cName, player[p].blance);
                    showImages(player);
                    Sleep(1000);
                }
            }
            else {
                printf("%s���a���J������Ȥj�������|", player[p].cName);
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
                printf("%s�B����񯫩��A�h�Ž��8000��", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 2 && d <= 5) {
                player[p].blance += 1;
                printf("%s��{���ΡA�Ȩ���1����", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 6 && d <= 9) {
                player[p].blance += 5000;
                printf("%s�H�~�j�z�o�A��������h�F�@�����B���B5000��", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 10 && d <= 15) {
                player[p].blance += 3000;
                printf("���a%s�B�𷥫צn�A���������3000��", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 16 && d <= 25) {
                player[p].blance += 150;
                printf("���a%s�B�𤣿��A���ȨS�����������˶K150��", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 26 && d <= 50) {
                player[p].blance += 50;
                printf("���a%s�B��n�AĹ��50��", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 51 && d <= 70) {
                player[p].blance -= 500;
                printf("���a%s�B�𤣨ΡA�p�զ���鱼�F500����", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 71 && d <= 85) {
                player[p].blance -= 1500;
                printf("�B����˷��A�鱼�F1500", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 86 && d <= 95) {
                player[p].blance -= -3000;
                printf("���a%s�B�𷥬��˷��A�鱼�F3000��", player[p].cName);
                Sleep(1000);
                showImages(player);
            }
            else if (d >= 96 && d <= 100) {
                player[p].blance -= 9999999999999999999;
                printf("���a%s�u�˷��@�]�����������F�٭I�U��ѥ���%lf", player[p].cName, player[p].blance);
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
            printf("%s���a%s\n", player[p].cName, ptr[21]);
            Sleep(500);
        }
        houseown(player, player[p].location, p, c, ai);
        break;
    case 22:
        srand(time(NULL));
        d = rand() % 100 + 1;
        if (d >= 1 && d <= 10) {
            while (player[p].location != 0) {
                printf("%s�H�~�j�z�o�A�O�e���I(�}�l)�@��\n", player[p].cName);
                player[p].location++;
                if (player[p].location == 26) player[p].location = 0;
                Sleep(500);
                showImages(player);
            }
            houseown(player, player[p].location, p, c, ai);
        }
        else if (d >= 11 && d <= 20) {
            player[p].blance += 1500;
            printf("�ѤW�����A���a%s�A��ֳz���1500����", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 21 && d <= 35) {
            player[p].blance += 950;
            printf("���a%s�n�߸z�A�ߨ���]�k�ٵ����D��o���D���P�¬��]950", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 36 && d <= 50) {
            player[p].blance -= 500;
            printf("���a%s�u�˷��A�Q���⮳���F500����", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 51 && d <= 70) {
            player[p].blance -= 750;
            printf("���a%s�߰_�F�a�W���ѤH�A�Q�I���F750����", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 71 && d <= 95) {
            player[p].blance -= -1650;
            printf("���a%s�]���F��A�Q�@��1650��", player[p].cName);
            Sleep(1000);
            showImages(player);
        }
        else if (d >= 96 && d <= 100) {
            player[p].blance -= -2500;
            player[p].ban = 3;
            printf("���a%s�չϷm�T�Ȧ�A�Q�����k2500�����A�åB�Q���i�ʺ�3��(����:�T����3��", player[p].cName);
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

            printf("���a���^�X:\n");
            printf("���a���F%d�I\n", d);
            if (player[0].location == 0) {
                printf("���a�^��F�_�I�A���y���a�겣+2500");
                player[0].blance += 2500;
                Sleep(1000);
            }
            Sleep(500);
        }
        showImages(player);
        rule(player, 0, 1, 0, ptr);
    }
    else {
        printf("���a%s,�T���ʳѤU�Ѽ�%d", player[0].cName, player[0].ban);
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
            printf("�q�����^�X:\n");
            printf("�q�����F%d�I\n", d);
            if (player[1].location == 0) {
                printf("�q���^��F�_�I�A���y�q���겣+2500");
                player[1].blance += 2500;
                Sleep(1000);
            }
            Sleep(500);
        }
        showImages(player);
        rule(player, 1, 0, 1, ptr);
    }

    else {
        printf("���a%s,�T���ʳѤU�Ѽ�%d", player[1].cName, player[1].ban);
        player[1].ban--;
        player[1].turn++;
        Sleep(1000);
        showImages(player);
    }
    round = 1;
}
