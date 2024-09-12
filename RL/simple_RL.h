#include <stdio.h>

#define N_ACTION 4
#define LAMBDA 0.1
#define GAMMA 1

typedef struct Reward{
    int** arr;

    Reward* (*init_reward)(int size_x,int size_y,Reward*);
    double (*get_reward)(int x, int y,Reward*);

}Reward;

// prototype of reward
Reward* init_reward(int size_x,int size_y,Reward* r);
Reward* get_reward(int x,int y,Reward* r);

typedef struct QTable {
    int *** values;

    QTable* (*init_q_table)(int size_x,int size_y,QTable*);
    double (*get_value)(int x, int y, int action,QTable*);
    void (*update_value)(int x,int y, int action,QTable*);

} QTable;

// prototype of reward
QTable* init_q_table(int size_x,int size_y,QTable*);
double get_value(int x, int y, int action,QTable*);
void update_value(int x,int y, int action,QTable*);