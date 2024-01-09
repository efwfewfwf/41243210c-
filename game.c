#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include<string.h>
#define gameName "大富翁"

struct fileIO {
    char Name[20];
    char pwd[20];
    int time;
    int win;
    int lost;
};

void showindex1();
void showindex2();
void newuser();
void login();

int main() {
    showindex1();
    return 0;
}


void showindex1() {
    system("cls");
    printf("歡迎來到遊戲%s ，", gameName);
    printf("目前為首頁選擇頁面\n");
    printf("1.註冊帳號\n");
    printf("2.登入帳號\n");
    printf("3.退出\n");
    char choice;
    choice = _getch();
    switch (choice) {
    case '1':
        newuser();
        break;
    case '2':
        login();
        break;
    case '3':
        exit(0);
        break;
    }
}

void newuser() {
    system("cls");
    int same = 0;
    struct fileIO input;
    struct fileIO load;
    printf("請輸入帳號:");
    scanf("%s", input.Name);
    printf("請輸入密碼:");
    scanf("%s", input.pwd);
    FILE* READ;
    if ((READ = fopen("user.txt", "r")) == NULL) {  
        printf("用戶檔案(user.txt) 檔案無法存取"); system("pause"); return(0);
    }
    while (fscanf(READ, "%s %s %d %d %d", load.Name, load.pwd, &load.time,&load.win,&load.lost) == 5) {
        if (strcmp(input.Name, load.Name) == 0) {
            same = 1;
            break;
        }
    }
    fclose(READ);
    if (same == 1) {
        printf("此用戶名已存在，請使用其他用戶名\n");
        Sleep(1000);
        newuser();
    }
    else {
        input.time = 0;
        input.win = 0;
        input.lost = 0;

        FILE* ADD;
        if ((ADD = fopen("user.txt", "a")) == NULL) { 
            printf("用戶檔案(user.txt) 檔案無法存取"); system("pause"); return(0);
        }
        fprintf(ADD, "%s %s %d %d %d\n", input.Name, input.pwd, input.time,input.win,input.lost);
        fclose(ADD);
        showindex1();
    }
}
void login() {
    system("cls");
    int yes = 0;
    struct fileIO input;
    struct fileIO load;
    printf("請輸入帳號:");
    scanf("%s", input.Name);
    printf("請輸入密碼:");
    scanf("%s", input.pwd);
    FILE* READ;
    if ((READ = fopen("user.txt", "r")) == NULL) {  
        printf("用戶檔案(user.txt) 檔案無法存取"); system("pause"); return(0);
    }
    while (fscanf(READ, "%s %s %d %d %d", load.Name, load.pwd, &load.time,&load.win,&load.lost) == 5) {
        if (strcmp(input.Name, load.Name) == 0 && strcmp(input.pwd, load.pwd) == 0) {
            yes = 1;
            break;
        }
    }
        if (yes == 1) {
            showindex2(input);
        }
        else {
            printf("登入失敗，您的帳號或密碼錯誤\n");
            Sleep(1000);
            showindex1();
        }
}
void showindex2(struct fileIO input) {
    system("cls");
    printf("[%s]玩家，你好，歡迎遊玩%s\n",input.Name,gameName);
    printf("1.開始新遊戲\n");
    printf("2.繼續遊戲\n");
    printf("3.登出\n");
    int temp;
    int choice;
    choice = _getch();
    switch (choice) {
    case '1':
        input.time++;
        temp = gamemain(input.Name, 0);
        if (temp==1) {
            input.win++;
           showindex2(input);
        }
        else  if (temp==2) {
            input.lost++;
            showindex2(input);
        }
        break;
    case '2':
        temp = gamemain(input.Name, 1);
        if (temp == 1) {
            input.win++;
            showindex2(input);
        }
        else  if (temp == 2) {
            input.lost++;
            showindex2(input);
        }
        break;
    case '3':
        showindex1();
        break;
    }
}
