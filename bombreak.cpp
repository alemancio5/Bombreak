#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

char tab[1000][1000];
ifstream tabfile;

void tab_print(int N1, int N2) {
	system("clear");
	cout << "Turno di " << endl << endl;
	for (int i = 0; i < N1; i++) { 
		for (int j = 0; j < N2; j++)
			cout << tab[i][j];
		cout << endl;
	}
	cout << endl << "Movimenti rimasti: " << "    Movimento: " << endl;
}

void bomb_normal(int N1, int N2) {
	int bi = rand() % N1;
	int bj = rand() % N2;
	if (bj % 2 == 0)
		if (bj == (N2 - 1)) {
		  	bj--;
		} else {
			bj++;
		}
	tab[bi][bj] = '#';
	
	bi = rand() % N1;
	bj = rand() % N2;
	if (bj % 2 == 0)
		if (bj == (N2 - 1))
		  	bj--;
		  else
			bj++;
	tab[bi][bj] = '#';
}

void bomb_casual(int N1, int N2) {
	int nrand = rand() % 4 + 1;
	
	while (nrand > 0) {
		int bi = rand() % N1;
		int bj = rand() % N2;
		if (bj % 2 == 0)
			if (bj == (N2 - 1))
			  	bj--;
			  else
				bj++;
		tab[bi][bj] = '#';
		
		nrand --;
	}
}

void movement(int N1, int N2, char player, char space) {
	system("clear");
	cout << "Turno di " << player << endl << endl;
		        
	int pi, pj;			
	for (int i = 0; i < N1; i++) {		// tab print + pi, pj control
		for (int j = 0; j < N2; j++) {
			cout << tab [i] [j];
			if (tab[i][j] == player) {
				pi = i;
			    pj = j;
			}
		}
		cout << endl;
	}
	cout << endl;
    
	int moves = rand() % 4 + 1;
	while (moves != 0) {
		cout << "Movimenti rimasti: " << moves << "    Movimento: ";
		char move;
		cin >> move;
		
		if (move == 'w' && pi != 0) {     // w
		    if (tab[pi - 1][pj] == '#') {
		    	tab[pi][pj] = space;
		    	break;
			}
		    else {
		    	tab[pi - 1][pj] = player;
				tab[pi][pj] = space;
				moves --;
			}	
		}
		if (move == 's' && pi != (N1 - 1)) {     // s
			if (tab[pi + 1][pj] == '#') {
			    tab[pi][pj] = space;
			   	break;
			}
			else {
				tab[pi + 1][pj] = player;
				tab[pi][pj] = space;
				moves --;	
			}
		}
		if (move == 'd' && pj != (N2 - 2)) {     // d
		    if (tab[pi][pj + 2] == '#') {
			    tab[pi][pj] = space;
			   	break;
			}
			else {
				tab[pi][pj + 2] = player;
				tab[pi][pj] = space;
				moves --;
			}
		}
		if (move == 'a' && pj != 1) {     // a
			if (tab[pi][pj - 2] == '#') {
			    tab[pi][pj] = space;
			   	break;
			}
			else {
				tab[pi][pj - 2] = player;
				tab[pi][pj] = space;
				moves --;
			}	
		}
		
		system("clear");
		
        cout << "Turno di " << player << endl << endl;			
			for (int i = 0; i < N1; i++) {
				for (int j = 0; j < N2; j++) {
					cout << tab[i][j];
					if (tab [i] [j] == player) {
						pi = i;
					    pj = j;
					}
				}
				cout << endl;
			}
		cout << endl;
	}		
}

bool alive (int N1, int N2, char player) {
	for (int i = 0; i < N1; i++)
		for (int j = 0; j < N2; j++) 
			if (tab [i] [j] == player) 
				return true;
	return false;
}

bool winner (int N1, int N2, char p1, char p2, char p3, char p4) {
	if (alive(N1, N2, p1) && !alive(N1, N2, p2) && !alive(N1, N2, p3) && !alive(N1, N2, p4)) {
			cout << endl << "             " << p1 << " VINCE !!!" << endl;
			return true;
		}
		else 
			if (!alive(N1, N2, p1) && alive(N1, N2, p2) && !alive(N1, N2, p3) && !alive(N1, N2, p4)) {
				cout << endl << "             " << p2 << " VINCE !!!" << endl;
				return true;
			}
			else 
				if (!alive(N1, N2, p1) && !alive(N1, N2, p2) && alive(N1, N2, p3) && !alive(N1, N2, p4)) {
					cout << endl << "             " << p3 << " VINCE !!!" << endl;
					return true;
				}
		    	else 
					if (!alive(N1, N2, p1) && !alive(N1, N2, p2) && !alive(N1, N2, p3) && alive(N1, N2, p4)) {
						cout << endl << "             " << p4 << " VINCE !!!" << endl;
						return true;
					}
					else
					    if (!alive(N1, N2, p1) && !alive(N1, N2, p2) && !alive(N1, N2, p3) && !alive(N1, N2, p4)) {
						    cout << endl << "               PAREGGIO" << endl;
						    return true;
					    }
	return false;
}



int main () {
	srand((unsigned)time(NULL));

	int play = 1;
	while (play) {
		char tabname[100];

		while (!tabfile.is_open()) {
			system("clear");
			cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl << "|_|_|_|_|_|_|_|_|B|O|M|B|R|E|A|K|_|_|_|_|_|_|_|_|" << endl << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
			cout << "Enter the name of the game field --> ";
			cin >> tabname;
			string fullpath = "tables/" + string(tabname);
			tabfile.open(fullpath);
		}

		int N1, N2;
		tabfile >> N1;
		tabfile >> N2;
		for (int i = 0; i < N1; i++) 
			for (int j = 0; j < N2; j++)
				tabfile >> tab[i][j];
		tabfile.close();
		
		int gamemode = 0;
		int mode_ok = 0;
		while (!mode_ok) {
			system("clear");
	        cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl << "|_|_|_|_|_|_|_|_|B|O|M|B|R|E|A|K|_|_|_|_|_|_|_|_|" << endl << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
			cout << "Enter the name of the game field --> " << tabname << endl;
			cout << "Enter game mode (1 = normal | 2 = casual) --> ";
			cin >> gamemode;
			if (gamemode == 1 || gamemode == 2)
			    mode_ok = 1;
		}		
		
		char space = tab[0][3];
		char p1 = tab[0][1];
		char p2 = tab[0][N2-2];
		char p3 = tab[N1-1][1];
		char p4 = tab[N1-1][N2-2];
		char player;
		int turn_counter = 0;
		
		while (!winner(N1, N2, p1, p2, p3, p4)) {
			// Round of p1
		    player = p1;
			if (alive(N1, N2, player))     
				movement(N1, N2, player, space);
	        turn_counter ++;
	
			if (gamemode == 1)
			    bomb_normal(N1, N2);
			if (gamemode == 2)
			    bomb_casual(N1, N2);
			tab_print (N1, N2);
			if (winner (N1, N2, p1, p2, p3, p4))
			    break;
			
			// Round of p2
			player = p2;
			if (alive (N1, N2, player))     	    
				movement(N1, N2, player, space);	
	        turn_counter ++;
	        
	        if (gamemode == 1)
	        	bomb_normal(N1, N2);
	        if (gamemode == 2)
			    bomb_casual(N1, N2);
			tab_print(N1, N2);     
	        if (winner(N1, N2, p1, p2, p3, p4))
			    break;
	
			// Round of p3
	        player = p3;
			if (alive(N1, N2, player))
				movement(N1, N2, player, space);
			turn_counter ++;	
			
			if (gamemode == 1)
				bomb_normal(N1, N2);
			if (gamemode == 2)
			    bomb_casual(N1, N2);
			tab_print(N1, N2);   
			if (winner(N1, N2, p1, p2, p3, p4))
			    break;
			
			// Round of p4
			player = p4;
			if (alive(N1, N2, player))     
				movement(N1, N2, player, space);
			turn_counter ++;
			
			if (gamemode == 1)
				bomb_normal (N1, N2);
			if (gamemode == 2)
			    bomb_casual (N1, N2);
			tab_print(N1, N2);    
			if (winner(N1, N2, p1, p2, p3, p4))
			    break;
		}
		
		cout << endl << "Rounds played = " << turn_counter << endl << "Play again? (Yes = 1, No = 0) --> ";
		cin >> play;
    }
    
    system("clear");
    cout << "Bye!" << endl;
	
	return 0;
}
