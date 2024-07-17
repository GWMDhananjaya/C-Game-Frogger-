#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// Constants
#define NUM_DEN 5
#define NUM_OGGETTI 10
#define FROG_WIDTH 3
#define FROG_HEIGHT 3
#define PLANT_WIDTH 5
#define PLANT_HEIGHT 2
#define CROC_WIDTH 7
#define CROC_HEIGHT 4
#define MAX_BULLETS 5
#define DEN_WIDTH 10 // Assuming a den width constant

// Struct for game entities
struct GameEntity
{
    char id[10];
    int x, y;
    int active;
    int index;
    int type;
    int plantIndex;
    char c;
    int num;
    time_t lastShotTime;
    int direction;
    char bulletSprite;
    int speed;
};

struct Tana
{
    int x, y;
    int available;
};

// Global variables for bullets
extern int numBullets;
extern struct GameEntity bullets[MAX_BULLETS];

// Function declarations
void *muovi_rana(void *arg);
void *muovi_coccodrillo(void *arg);
void *proiettile(void *arg);
void *madre(void *arg);
void printHaiVinto();
void printHaiPerso();
void controllo(struct GameEntity *player, struct GameEntity crocs[], int num_crocs, struct Tana tane[], int numDens, int spacing, int max_x, int max_y, int numPiante, int *lives, int *is_on_crocodile, int *current_croc_x, int *current_croc_speed, int randomX[], int randomY[], int *score);
void iniziaGioco();

#endif // GAME_H
