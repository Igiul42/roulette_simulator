#include "roulette.hpp"

t_roulette cinquanta_cinquanta (t_roulette r){

 	 srand (time(NULL));

 	int random = rand() % 36;
	if (random % 2)
		r.tavolo += (r.giocata * 2);
	else
	{
		r.giocata *= 2;
		if (r.tavolo > r.giocata){
			r.tavolo -= r.giocata;
			r = cinquanta_cinquanta(r);
			r.n_raddoppi++;
		}
		else{
			cout << "Tavolo insufficiente, caricare altri soldi! Sono stati fatti " << r.n_raddoppi << " raddoppi." << endl;
			exit(0);
		}
	}
	return (r);
}

t_roulette random_combination_raddoppi (t_roulette r){
	float tmp_giocata = r.giocata;
	
 	 srand (time(NULL));

 	int random = rand() % 36;
	if ((random < 25) && (random != 0)){
		r.giocata = tmp_giocata;
		r.tavolo -= r.giocata;
		r.tavolo += (r.giocata + r.giocata/2);
	}
	else
	{
		r.tavolo -= r.giocata;
		r = cinquanta_cinquanta(r);
	}
		
	return (r);
}

t_roulette soldi_su_tempo_con_raddoppi(t_roulette r){
	int giocate = 0;
	cout << "Inserisci quanto tempo vuoi giocare in minuti ";
	cin >> r.time_4_play;
	r.time_4_play *= 60;
	giocate = r.time_4_play / 45;
	while (giocate > 0){
		r = random_combination_raddoppi (r);
		giocate--;
	}
	return (r);	
}