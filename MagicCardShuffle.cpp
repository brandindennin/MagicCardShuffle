#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

This program will take in a list of magic cards and store them in the class magic deck. 
Then it will perform a shuffle on the magic deck if you call the sixPileShuffle method

*/


class MagicDeck {
private:
	
	int cards[60];
	//[rows][] represent which card in pile
	//[][cols] represent which pile
	//Will be explained in the sorting method.
	int stack[10][6];
	int cardPos;
	

public:
	//Constructor
	MagicDeck() {

		cout << "New deck has been made" << endl << endl;
		addCards();
		
	}
	
	void addCards() {
		for (int i = 0; i < 60; i++) {
			cards[i] = i+1;
		}
	}




	//Method to view the deck
	void showDeck() {
		cout << "The deck: " << endl;
		for (int i = 0; i < 60; i++) {
			if (cards[i] < 41) {
				cout << i+1 << ": Spell Card" << endl;
			}
			else {
				cout << i+1 << ": Land Card" << endl;
			}
			
		}
	}


	//Method used to view the stack, mostly for testing purposes and shouldnt be used.
	void showStack() {
		cout << "The stack: " << endl;
		for (int i = 0; i < 6; i++) {
			cout << "Pile : " << i+1 << endl;
			for (int j = 0; j < 10; j++) {
				
				cout << stack[j][i] << endl;
				
			}
		}
	}
	
	

	//Method used for shuffling into the sixPileShuffle,... a Magic the Gathering staple.
	
	//Start by placing the cards into 6 piles...
	/*
	[0-10][0]pile 1: 1,7,13,19,25,31,37,43,49,55
	[0-10][1]pile 2: 2,8,14,20,26,32,38,44,50,56
	[0-10][2]pile 3: 3,9,15,21,27,33,39,45,51,57
	[0-10][3]pile 4: 4,10,16,22,28,34,40,46,52,58
	[0-10][4]pile 5: 5,11,17,23,29,35,41,47,53,59
	[0-10][5]pile 6: 6,12,18,24,30,36,42,48,54,60
	*/
	//Next put each pile in reverse order, because that is how they are placed.

	void sixPileshuffle() {

		//Place cards in the two-dimensional array stack[][], representing 6 piles of 10.
		int row = 0;
		int count = 0;
		cardPos = 0;
		while (cardPos < 60) {

			stack[row][count] = cards[cardPos];
			cardPos++;
			count++;
			if (count > 5) {
				count = 0;
				row++;
			}
		}
		
		//Reverse the cards by adding them to a temp array.
		for (int row = 0; row < 6; row++) {
			int start = 0;
			int end = 9;
			while (start < end) {
				int temp = stack[start][row];
				stack[start][row] = stack[end][row];
				stack[end][row] = temp;
				start++;
				end--;
			}
		}

		//take the 6 piles and stack them on top of each other, finished :D
		cardPos = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 10; j++) {
				cards[cardPos] = stack[j][i];
				cardPos++;
			}
		}


	}

};


int main() {
	//Make a MagicDeck Object
	MagicDeck deck1;

	//ShowDeck before the shuffle
	deck1.showDeck();

	//Shuffle method
	deck1.sixPileshuffle();

	//ShowDeck after shuffle
	deck1.showDeck();
	
	system("Pause");
	return 0;
}