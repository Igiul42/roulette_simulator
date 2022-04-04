#include "roulette.hpp"

t_roulette dispari(t_roulette r){
    while(r.tavolo >= r.giocata && r.giocate < 100){
        if (r.tavolo < r.giocata){
	    	cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
	    			exit(0);
	    }
        int random = rand() % 36;
        if (random % 2){
            r.tavolo -= r.giocata;
            r.tavolo += (r.giocata * 2);
            cout << random <<  "\033[1;32m Vinto Dispari!\033[0m" << endl;
            r.giocate++;
            r.giocata = r.giocata_iniziale;
        }
        else
        {
            cout << random << "\033[1;31m Perso Pari!\033[0m" << endl;
            r.giocate++;
            r.tavolo -= r.giocata;
            r.giocata *= 2;
            if (r.tavolo > r.giocata){
                r = dispari(r);
            }
            else{
                cout << "Tavolo insufficiente, caricare altri soldi! Il tavolo rimasto è " << r.tavolo << endl;
                cout << "Numero giocate totali " << r.giocate << " per un totale di " << (r.giocata * 45)/60 << " minuti." << endl;
                exit(0);
            }
        }
    }
    return (r);
}
 