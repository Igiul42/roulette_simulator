#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <stdlib.h>     //for using the function sleep
#include <chrono>
#include <thread>
#include <cstdlib>
#include <unistd.h>


using namespace std;

typedef struct s_roulette {
	float tavolo;
	float giocata;
	int max_doubler;
	float time;
	float time_4_play;
	int numbers[25];
	int n_raddoppi;
	int vincente;
	int perdente;
} t_roulette;


t_roulette soldi_su_tempo_con_raddoppi(t_roulette r);
t_roulette soldi_su_tempo(t_roulette r);


#endif