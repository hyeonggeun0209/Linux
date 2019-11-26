#include "my_star.h"

void my_star::My_star(vector<cast> casts, vector<string> &my_star) {
	out = 0;
	cout << " ====== Pick 3 stars! ====== " << endl << "!! Once selected star cannot be changed. !!" << endl;
	while (out != 1) {
		cout << " 1: Registering Your Star 2: See your own star 3: Go to the previous screen. " << endl;
		cin >> key;

		switch (key) {
		case 1:
			if (j == 3) {
				cout << "All already registered !!" << endl;
				break;
			}
			cin >> name;
			for (int it = 0; it < casts.size(); it++) {
				if (casts[it].getname() == name) {
					cout << "Should I register " << name << "? (y or n) " << endl;
					cin >> keystr;
					if (keystr == 'y' || keystr == 'Y') {
						cout << "Registered!!" << endl;
						my_star.push_back(name);
						names[j++] = name;
						break;
					}
					else if (keystr == 'n' || keystr == 'N') {
						cout << "Please choose someone else!!" << endl;
						break;

					}
					else {
						cout << "You've entered something wrong !!" << endl;
						break;
					}
				}
				if (it == casts.size() - 1) cout << "You've entered something wrong !!" << endl;
			}


			break;
		case 2:
			for (int it = 0; it < casts.size(); it++)
				for (int i = 0; i < j; i++)
					if (names[i] == casts[it].getname()) cout << casts[it].getname() << ' ' << casts[it].getage() << ' ' << casts[it].getEntertainment() << endl;
			break;
		case 3:
			out = 1;
		}

	}
}