#include "simple_RL.h"
#include <stdlib.h>  
#include <time.h>    

/* 
* Reward class
*/

// Constructor of Reward class
Reward* init_reward(int size_x,int size_y){
    Reward* res_reward = malloc(sizeof(Reward));

    // init vector
    res_reward->arr = (int** ) malloc(sizeof(int)*(size_x+2));
    for (int i = 0; i < size_x; i++) {
        res_reward->arr[i] = (int *)malloc((size_y+2) * sizeof(int));
    }

    // init values
    // 0
    for (int i = 1; i < size_x+1; i++) {
        for(int j = 1;j < size_y+1; j++)
            res_reward->arr[i][j] = 0;
    }

    // -1
    for (int i = 1; i < size_x+1; i++) {
        res_reward->arr[i][0] = -1;
        res_reward->arr[i][size_y] = -1;
    }

    for (int j = 1; j < size_y+1; j++) {
        res_reward->arr[j][0] = -1;
        res_reward->arr[j][size_x] = -1;
    }

    return res_reward;

}

// get reward of a position
double get_reward(int x, int y,Reward* r){
    return r->arr[x+1][y+1];
}

// update reward of a position (only for the apple)
void update_reward(int x, int y, int old_x, int old_y ,Reward* r){
    r->arr[old_x+1][old_y+1] = 0;
    r->arr[x+1][y+1] = 1;
}

/* 
* QTable class
*/

QTable* init_q_table(int size_x,int size_y){
    QTable* res_table = malloc(sizeof(QTable));

    srand(time(0));

    res_table->values = (double*** ) malloc(sizeof(int)*(size_x+2));
    for (int i = 0; i < size_x; i++) {
        res_table->values[i] = (double** )malloc((size_y) * sizeof(int));
        for(int j = 0;j<size_y;j++){
            res_table->values[i][j] = (double* )malloc(sizeof(int)*N_ACTION);
            for(int k = 0;k<N_ACTION;k++){
                double random_number = (double) rand()/RAND_MAX;
                res_table->values[i][j][k] = random_number;
            }    
        }
    }
    return res_table;
}

void update_value(int x,int y, int action,QTable* q_table,Reward* r){
    
    double new_q_value = q_table->values[x][y][action] + ALPHA*(r->arr[])
}

