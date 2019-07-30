#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	//stack[rows] represent which card in pile
	//stack[cols] represent which pile
	
	int stack[10][6];
	int cards[60];
	int cards2[60];
	int cards3[60];
	int cardPos = 0;

	for (int i = 0; i < 60; i++) {
		cards[i] = i;
	}

	// Cards have been added
	// Time to shuffle the deck

	//[0][0] -> [0][9] put card in position [cardPos] except the first
	//put cards[0] in stack[0][0]
	//put cards[1] in stack[0][1]
	//put cards[2] in stack[0][2]
	//put cards[3] in stack[0][3]
	//put cards[4] in stack[0][4]
	//put cards[5] in stack[0][5]
	//put cards[6] in stack[1][0]
	//put cards[7] in stack[1][1]
	//put cards[8] in stack[1][2]
	//put cards[9] in stack[1][3]
	//put cards[10] in stack[1][4]
	//put cards[11] in stack[1][5]
	int row = 0;
	int count = 0;
	cardPos = 0;
	while (cardPos < 60) {
		
		stack[row][count] = cards[cardPos];
		//cout << cardPos+1 << ": " << stack[row][count] << endl;
		cardPos++;
		count++;
		if (count > 5) {
			count = 0;
			row++;
		}
	}

	//reverse the stacks for each pile (this is just one)
	//for (int i = 0; i < 6; i++) {
		
		
	//}


	//put stack[0][0] + stack[9][0] -> cards2[0-9]
	//put stack[0][1] + stack[9][1] -> cards2[10-19]
	//put stack[0][2] + stack[9][2] -> cards2[20-29]
	//put stack[0][3] + stack[9][3] -> cards2[30-39]
	//put stack[0][4] + stack[9][4] -> cards2[40-49]
	//put stack[0][5] + stack[9][5] -> cards2[50-59]
	cardPos = 0;
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			cards2[cardPos] = stack[j][i];
			//cout << cardPos << ": " << cards2[cardPos] << endl;
			cardPos++;
		}
	}
	int l = 0;
	int r = 9;
	for (int i = 0; i < 6; i++) {
	while (l < r) {
		int temp = cards2[l];
		cards2[l] = cards2[r];
		cards2[r] = temp;
		l++;
		r--;
	}
	}
	l = 10;
	r = 19;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards2[l];
			cards2[l] = cards2[r];
			cards2[r] = temp;
			l++;
			r--;
		}
	}
	l = 20;
	r = 29;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards2[l];
			cards2[l] = cards2[r];
			cards2[r] = temp;
			l++;
			r--;
		}
	}
	l = 30;
	r = 39;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards2[l];
			cards2[l] = cards2[r];
			cards2[r] = temp;
			l++;
			r--;
		}
	}
	l = 40;
	r = 49;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards2[l];
			cards2[l] = cards2[r];
			cards2[r] = temp;
			l++;
			r--;
		}
	}
	l = 50;
	r = 59;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards2[l];
			cards2[l] = cards2[r];
			cards2[r] = temp;
			l++;
			r--;
		}
	}
	cardPos = 0;

	for (int i = 0; i < 60; i++) {
		if (cards2[i] <= 10) {
			cout << i+1 << ": " << "Red Land" << endl;
		}
		else if (cards2[i] < 20 && cards[i] > 10) {
			cout << i + 1 << ": " << "Blue Land" << endl;
		}
		else{
			cout << i + 1 << ": " << "White Card" << endl;
		}
		
	}
	cout << endl << endl;
	// TIME TO SHUFFLE AGAIN

	row = 0;
	count = 0;
	cardPos = 0;
	while (cardPos < 60) {

		stack[row][count] = cards2[cardPos];
		//cout << cardPos+1 << ": " << stack[row][count] << endl;
		cardPos++;
		count++;
		if (count > 5) {
			count = 0;
			row++;
		}
	}

	// TIME TO REVERSE ORDER AGAIN SUPER EFFICIENTLY

	cardPos = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			cards3[cardPos] = stack[j][i];
			//cout << cardPos << ": " << cards2[cardPos] << endl;
			cardPos++;
		}
	}
	l = 0;
	r = 9;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards3[l];
			cards3[l] = cards3[r];
			cards3[r] = temp;
			l++;
			r--;
		}
	}
	l = 10;
	r = 19;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards3[l];
			cards3[l] = cards3[r];
			cards3[r] = temp;
			l++;
			r--;
		}
	}
	l = 20;
	r = 29;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards3[l];
			cards3[l] = cards3[r];
			cards3[r] = temp;
			l++;
			r--;
		}
	}
	l = 30;
	r = 39;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards3[l];
			cards3[l] = cards3[r];
			cards3[r] = temp;
			l++;
			r--;
		}
	}
	l = 40;
	r = 49;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards3[l];
			cards3[l] = cards3[r];
			cards3[r] = temp;
			l++;
			r--;
		}
	}
	l = 50;
	r = 59;
	for (int i = 0; i < 6; i++) {
		while (l < r) {
			int temp = cards3[l];
			cards3[l] = cards3[r];
			cards3[r] = temp;
			l++;
			r--;
		}
	}
	for (int i = 0; i < 60; i++) {
		if (cards3[i] <= 10) {
			cout  <<  i + 1  << ": " << setw(5) << "Red Land" << endl;
		}
		else if (cards3[i] < 20 && cards3[i] > 10) {
			cout  << i + 1 << ": " << setw(5) << "Blue Land" << endl;
		}
		else {
			cout  << i + 1 << ": " << setw(5) << "White Card" << endl;
		}

	}

	system("PAUSE");
	return 0;
}