#include "roulette.hpp"

t_roulette init_struct (t_roulette roulette){
	roulette.giocata = 0;
	roulette.tavolo = 0;
	roulette.max_doubler = 0;
	roulette.time_4_play = 0;
	roulette.time = 45;
	for (int i = 0; i < 25; i++){
		roulette.numbers[i] = i;
	}
	roulette.n_raddoppi = 0;
	roulette.vincente = 0;
	roulette.perdente = 0;
	
	return (roulette);
}

t_roulette	caso_peggiore (t_roulette roulette){
	while (roulette.tavolo > roulette.giocata){
		roulette.tavolo -= roulette.giocata;
		roulette.giocata *= 2;
		roulette.max_doubler ++;
	}
	return (roulette);
}

int main () {
	t_roulette roulette;
	roulette = init_struct(roulette);
	int i = 0;

	cout << "Inserisci 0 per il caso peggiore, 1 per combinazioni random, 2 metodo raddoppi ";
	cin >> i;
	switch (i){
		case 0:
			{

				cout << "Inserire importo tavolo ";
				cin >> roulette.tavolo;
				cout << "Inserire importo giocata ";
				cin >> roulette.giocata;
				roulette = caso_peggiore (roulette);
				cout << "Il tavolo rimasto è " << roulette.tavolo << " e i raddoppi sono stati " << roulette.max_doubler << endl;
				cout << "Il tempo di gioco è stato di " << roulette.time * roulette.max_doubler / 60 << " minuti" << endl;
			}
			break;
		case 1:
			{
				cout << "Inserire importo tavolo ";
				cin >> roulette.tavolo;
				cout << "Inserire importo giocata ";
				cin >> roulette.giocata;
				roulette = soldi_su_tempo(roulette);
				cout << "Il tavolo rimasto dopo " << roulette.time_4_play / 60 << " minuti vale " << roulette.tavolo << endl;
				cout << "Hai vinto " << roulette.vincente << " volte e hai perso " << roulette.perdente << " volte" << endl;
			}
			break;
		case 2: 
			{
				cout << "Inserire importo tavolo ";
				cin >> roulette.tavolo;
				cout << "Inserire importo giocata ";
				cin >> roulette.giocata;
				roulette = soldi_su_tempo_con_raddoppi(roulette);
				cout << "Il tavolo rimasto dopo " << roulette.time_4_play / 60 << " minuti vale " << roulette.tavolo << endl;
				cout << "Numero raddoppi " << roulette.n_raddoppi << endl;
				cout << "Hai vinto " << roulette.vincente << " volte e hai perso " << roulette.perdente << " volte" << endl;
			}
			break;
		default:
			break;
	}

	cout << "-------------------------------------------------------------------------------------------------" << endl;

	return (0);
}