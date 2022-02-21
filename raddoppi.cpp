#include "roulette.hpp"

t_roulette cinquanta_cinquanta (t_roulette r){
	if (r.tavolo < r.giocata){
		cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
		exit(0);
	}
 	int random = rand() % 36;
	if (random % 2){
		r.tavolo -= r.giocata;
		r.tavolo += (r.giocata * 2);
		cout << random << " Vinto dispari!" << endl;
	}
	else
	{
		cout << random << " Perso pari!" << endl;
		r.tavolo -= r.giocata;
		r.giocata *= 2;
		if (r.tavolo > r.giocata){
			r = cinquanta_cinquanta(r);
			r.n_raddoppi++;
		}
		else{
			cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
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
		r = cinquanta_cinquanta(r);
		r.giocata = tmp_giocata;
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