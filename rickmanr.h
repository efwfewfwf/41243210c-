#ifndef _RICKMANR_H_
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

struct playerinfo {
    char cName[20];
    double blance;
    int house[26];
    int turn;
    int location;
    int ban;
} player[2];

int gamemain(struct playerinfo [],int);
void showImages(struct playerinfo[]);
void checkhouse(struct playerinfo*);
void playchoice(struct playerinfo[]);
void playeraction(struct player[]);
void aiaction(struct player[]);
void rule(struct player[], int, int, int, char* []);
void houseown(struct playerinfo[], int, int, int, int);
void color(struct playerinfo[], int);
void save(struct playerinfo[]);

#define _RICKMANR_H_
#endif 