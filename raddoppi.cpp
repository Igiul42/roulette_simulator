#include "roulette.hpp"

t_roulette cinquanta_cinquanta (t_roulette r){

	if (r.tavolo < r.giocata){
		cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
		cout << "Numero raddoppi " << r.n_raddoppi << endl;
		exit(0);
	}
 	int random = rand() % 36;
	if (random % 2){
		r.tavolo -= r.giocata;
		r.tavolo += (r.giocata * 2);
		cout << random <<  "\033[1;32m Vinto Dispari!\033[0m" << endl;
		r.n_raddoppi = 0;
	}
	else
	{
		cout << random << "\033[1;31m Perso Pari!\033[0m" << endl;
		r.n_raddoppi++;
		r.tavolo -= r.giocata;
		r.giocata *= 2;
		if (r.tavolo > r.giocata){
			r = cinquanta_cinquanta(r);
		}
		else{
			cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
			cout << "Numero raddoppi " << r.n_raddoppi << endl;
			cout << "Mancano " << r.giocate*(0.45)/60 << "ore." << endl;
			exit(0);
		}
	}
	return (r);
}

t_roulette random_combination_raddoppi (t_roulette r){
	float tmp_giocata = r.giocata;
	int random = rand() % 36;
	if (r.tavolo < r.giocata){
		cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
				exit(0);
	}
	else if (random < 25 && (random != 0)){
		cout << random << " Vincente!" << endl;
		r.giocata = tmp_giocata;
		r.vincente++;
		r.tavolo -= r.giocata;
		r.tavolo += (r.giocata + (r.giocata / 2));
	}		
	else
	{
		cout << random << " Perdente!" << endl;
		r.perdente++;
		r.tavolo -= r.giocata;
		cout << "il tavolo provvisorio vale " << r.tavolo << endl;
		r = cinquanta_cinquanta(r);
		r.giocata = tmp_giocata;
	}
		
	return (r);
}

t_roulette soldi_su_tempo_con_raddoppi(t_roulette r){
	r.giocate = 0;
	cout << "Inserisci quanto tempo vuoi giocare in minuti ";
	cin >> r.time_4_play;
	r.time_4_play *= 60;
	r.giocate = r.time_4_play / 45;
	while (r.giocate > 0){
		r = random_combination_raddoppi (r);
		r.giocate--;
	}
	return (r);	
}