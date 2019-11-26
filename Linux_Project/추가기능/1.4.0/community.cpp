#include "community.h"

void community::Community(vector<string> &com) {
	int out = 0;
	int key = 0;
	string ma;
	while (out != 1) {
		cout << "1 : Writing 2: View the text 3 : Exit" << endl;
		cin >> key;
		switch (key) {
		case 1:
			cout << "Writing (the last letter : ;)" << endl;
			getline(cin, ma, ';');


			if (ma == "") {
				cout << "You've entered something wrong !!" << endl;
				break;
			}
			else {

				com.push_back(ma);
				if (com.size() == 11) com.erase(com.begin());

			}
			break;
		case 2:
			if (com.size() == 0) {
				cout << "There is no article registered." << endl;
			}
			else {
				for (int i = 0; i < com.size(); i++) cout << i + 1 << " :: " << com[i] << endl;
			}
			break;
		case 3:
			out = 1;
			break;
		default:
			cout << "wrong input!" << endl;
			break;
		}
	}
}