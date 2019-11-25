#include "viewer.h"

void viewer::setNumber(string PhoneNumber) { 
	this->PhoneNumber = PhoneNumber;
	VotePresence = 0;
	VoteWho[0] = "";
	VoteWho[1] = "";	
	donation = 0;
}

string viewer::getNumber() {
	return PhoneNumber;
}

string viewer::getName() {
	return VoteWho[0] + ' ' + VoteWho[1];
}

int viewer::getVotePresence() {
	return VotePresence;
}

int viewer::getDonation() {
	return donation;
}

void viewer::setPresence(int num) {
	VotePresence = num;
}
void viewer::vote(int num, string name) {
	if (num == 0) { 
		VotePresence++;
		VoteWho[0] = name;
	}
	else if (num == 1) { 
		VotePresence++;
		VoteWho[1] = name;
	}
}
void viewer::donate(int money) {
	donation += money;
}

void viewer::set(string PhoneNumber, int VotePresence, int donation) {
	this->PhoneNumber = PhoneNumber;
	this->VotePresence = VotePresence;
	this->donation = donation;
}