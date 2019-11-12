// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main() {
    /*
    // ------testing card.h and card.cpp------
    Card c;
    cout << c << endl;
    Card c1(13,(Card::Suit) 2 );
    cout << c1 << endl;    

    if (c == c1)
	cout << c << " is equal to " << c1 << endl;
    if (c != c1)
        cout << c << " is not equal to " << c1 << endl;
  
    // ------testing deck.h and deck.cpp------
    Deck d1;
    cout << d1.size() << endl;
    Card c2 = d1.dealCard();
    cout << c2 << " and size is " << d1.size() << endl;
    c2 = d1.dealCard();
    cout << c2 << " and size is " << d1.size() << endl;

    Card c3(0,(Card::Suit)0);
    cout << c3 << endl;

    d1.shuffle();

    int cc = 0;
    for(int i = 0; i < 55; i++){
        c3 = d1.dealCard(); cc++;
        cout << c3 << " ";}
    cout << cc << endl;

    d1.shuffle();
    int test = d1.size();
    cout << test << endl; 
    */
    // ------testing player.h and player.cpp------
    Player p1("Joe");
    Player p2("Jane");
    Player p3;
    
    Card c; Card cc(12,(Card::Suit) 3);
    p1.addCard(c); p1.addCard(c); p1.addCard(c); p1.addCard(c);
    cout << p1.getName() <<" has: " << p1.showHand() << endl;  
    cout << "Hand size - " << p1.getHandSize() << endl;  
    cout << "Book size - " << p1.getBookSize() << endl;    
    if(p1.cardInHand(cc))
        cout << p1.getName() <<" has " << cc << endl;
    else
        cout << p1.getName() <<" doesn't have " << cc << endl;

    int numCards = 5;
    Deck d; d.shuffle();

    dealHand(d, p2, numCards);
    dealHand(d, p3, numCards);

    cout << p3.getName() <<" has: " << p3.showHand() << endl;
    cout << p2.getName() <<" has: " << p2.showHand() << endl;
    Card card = p2.chooseCardFromHand();
    cout << "Do you have a " << card.getRank() << + "?" << endl;
    p2.removeCardFromHand(card);
    cout << p2.getName() <<" has: " << p2.showHand() << endl;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
