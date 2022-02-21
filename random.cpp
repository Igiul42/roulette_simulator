#include "roulette.hpp"

t_roulette random_combination (t_roulette r){
	
 	int random = rand() % 36;
	if (r.tavolo < r.giocata){
		cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
				exit(0);
	}
	else if (random < 25 && (random != 0)){
		cout << random << " Vincente!" << endl;
		r.vincente++;
		r.tavolo -= r.giocata;
		r.tavolo += (r.giocata + (r.giocata / 2));
	}		
	else{
			cout << random << " Perdente!" << endl;
			r.perdente++;
			if (r.tavolo > r.giocata){
				r.tavolo -= r.giocata;
			}
			else{
				cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
				exit(0);
			}
	}
	return (r);
}



t_roulette soldi_su_tempo(t_roulette r){
	int giocate = 0;
	cout << "Inserisci quanto tempo vuoi giocare in minuti ";
	cin >> r.time_4_play;
	r.time_4_play *= 60;
	giocate = r.time_4_play / 45;
	while (giocate > 0){
		r = random_combination (r);
		giocate--;
	}
	return (r);	
}