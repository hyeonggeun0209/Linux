#include "vector_cast.h"

void vector_cast::cast_add(vector<cast>& casts, string name, int age, string Entertainment) {
	cast *p = new cast;
	p->set(name, age, Entertainment);

	casts.push_back(*p);

}
void vector_cast::cast_delete(vector<cast> &casts, string name) {


	for (int it = 0; it < casts.size(); it++) {
		if (casts[it].getname() == name) {
			casts.erase(casts.begin() + it);
		}
	}
}
void vector_cast::cast_modify(vector<cast> &casts, string name) {

	for (int i = 0; i < casts.size(); i++) {
		if (casts[i].getname() == name) {
			string a, b;
			int c;
			cout << "Please enter name, age, entertainment ";
			cin >> a >> c >> b;
			casts[i].setname(a);
			casts[i].setage(c);
			casts[i].setEntertainment(b);
		}
	}
}
void vector_cast::show(vector<cast> &casts) {
	for (int it = 0; it < casts.size(); it++) {
		cout << casts[it].getname() << ' ' << casts[it].getage() << ' ' << casts[it].getEntertainment() << endl;
	}
}
void vector_cast::end_vote(vector<cast> casts, int &end_vote) {
	cout << "END_vote!!" << endl;
	end_vote = 1;
}
void vector_cast::show_vote(vector<cast> &cast) {
	for (int it = 0; it < cast.size(); it++) {
		cout << cast[it].getname() << " : votes -> " << cast[it].getvote() << " ranks -> " << cast[it].getrank() << endl;
	}
}

void vector_cast::sort(vector<cast> &casts) {
	vector<cast> temp;
	cast a;
	temp.push_back(a);
	for (int i = 0; i < casts.size() - 1; i++) {
		for (int j = 0; j < casts.size() - 1; j++) {
			if (casts[j].getvote() < casts[j + 1].getvote()) {
				temp[0] = casts[j];
				casts[j] = casts[j + 1];
				casts[j + 1] = temp[0];
			}
		}
	}
	int x = 1;
	int k = 0;
	for (int i = 0; i < casts.size() - 1; i++) {
		if (casts[i].getvote() > casts[i + 1].getvote()) {
			casts[i].getrank() = x++;
		}
		else {
			casts[i].getrank() = x;
		}
		k++;
	}

	if (casts[k - 1].getvote() > casts[k].getvote()) {
		casts[k].getrank() = x++;
	}
	else if (casts[k - 1].getvote() == casts[k].getvote()) {
		casts[k].getrank() = x;
	}
}