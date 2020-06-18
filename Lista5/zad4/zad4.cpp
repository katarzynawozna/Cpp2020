#include <iostream>
#include "random.h"
#include <vector>
#include <iomanip> 
#include <ctime>
using namespace std;

int main()
{
	vector<int> liczba_w_zakresach(5);
	Random r;
	for (int i = 0; i < 5000 ; i++)
	{
		double wylosowana = r();
		if (wylosowana > 0 && wylosowana <= 0.2) { liczba_w_zakresach[0]++; }
		if (wylosowana > 0.2 && wylosowana <= 0.4) { liczba_w_zakresach[1]++; }
		if (wylosowana > 0.4 && wylosowana <= 0.6) { liczba_w_zakresach[2]++; }
		if (wylosowana > 0.6 && wylosowana <= 0.8) { liczba_w_zakresach[3]++; }
		if (wylosowana > 0.8 && wylosowana <= 1) { liczba_w_zakresach[4]++; }	
	}
	for (int i = 0; i < liczba_w_zakresach.size(); i++)
	{
		if (i == 0) { cout << "W zakresie (0;0.2] wylosowano " << liczba_w_zakresach[0] << " liczb\n"; }
		if (i == 1) { cout << "W zakresie (0.2;0.4] wylosowano " << liczba_w_zakresach[1] << " liczb\n"; }
		if (i == 2) { cout << "W zakresie (0.4;0.6] wylosowano " << liczba_w_zakresach[2] << " liczb\n"; }
		if (i == 3) { cout << "W zakresie (0.6;0.8] wylosowano " << liczba_w_zakresach[3] << " liczb\n"; }
		if (i == 4) { cout << "W zakresie (0.8;1] wylosowano " << liczba_w_zakresach[4] << " liczb\n"; }
	}
	return 0;
}


