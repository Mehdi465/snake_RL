#include "simple_RL.h"

Reward* init_reward(int size_x,int size_y,Reward* r){
    Reward* res_reward = malloc(sizeof(Reward));

    res_reward->arr = (int** ) malloc(sizeof(int)*size_x);
    for (int i = 0; i < size_x; i++) {
        res_reward->arr[i] = (int *)malloc(size_y * sizeof(int));
    }

    
}