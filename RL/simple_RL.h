#include <stdio.h>

#define N_ACTION 4
#define ALPHA 0.1
#define LAMBDA 1

/* 
* Reward class
*/

typedef struct Reward{
    int** arr;

    Reward* (*init_reward)(int size_x,int size_y);
    double (*get_reward)(int x, int y,Reward*);
    void (*update_reward)(int x, int y, Reward*);

}Reward;

// prototype of reward
Reward* init_reward(int size_x,int size_y);
double get_reward(int x,int y,Reward* r);
void update_reward(int x, int y, int old_x, int old_y ,Reward*);

/* 
* QTable class
*/

typedef struct QTable {
    int *** values;

    QTable* (*init_q_table)(int size_x,int size_y);
    double (*get_value)(int x, int y, int action,QTable*);
    void (*update_value)(int x,int y, int action,QTable*);

} QTable;

// prototype of reward
QTable* init_q_table(int size_x,int size_y);
void update_value(int x,int y, int action,QTable*, Reward* r);