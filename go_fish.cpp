// FILE: go_fish.cpp
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;
void dealHand(Deck &d, Player &p, int numCards);
string rankString(int r);
int main() {
    freopen("gofish_results.txt", "w", stdout);
    // ---------- SET-UP ----------
    int numCards = 7;
    string winner;
    Card c1, c2; Card c0(0, (Card::Suit) 0);
    Deck d; d.shuffle();
    Player p1("Adam");
    Player p2("Bean");

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << "---------- Start Game ----------" << endl;
    cout << p1.getName() <<": " << p1.showHand() << endl;
    cout << p2.getName() <<": " << p2.showHand() << endl;

    cout << "---------- Remove Books ----------" << endl;
    while(p1.checkHandForBook(c1, c2)) {
        p1.bookCards(c1, c2);
        cout << p1.getName() <<" books the " << rankString(c1.getRank()) << endl;
    }
    cout << p1.getName() << ": " << p1.showHand() << endl;
    while(p2.checkHandForBook(c1, c2)) {
        p2.bookCards(c1, c2);
        cout << p2.getName() <<" books the " << rankString(c1.getRank()) << endl;
    }
    cout << p2.getName() << ": " << p2.showHand() << endl;

    cout << "---------- Game Loop ----------" << endl;
    while(p1.getHandSize() > 0 || p2.getHandSize() > 0) {
        if(p1.getHandSize() > 0) {
            c1 = p1.chooseCardFromHand();
            cout << endl << p1.getName() << ": Do you have a " << rankString(c1.getRank()) << +"?" << endl;
            while (p2.cardInHand(c1)) {
                cout << p2.getName() << ": Yes. I have a " << rankString(c1.getRank()) << endl;
                cout << p1.getName() << " books the " << rankString(c1.getRank()) << endl;

                p1.addCard(p2.removeCardFromHand(c1));
                p1.checkHandForBook(c1, c2);
                p1.bookCards(c1, c2);

                if(p1.getHandSize() > 0) {
                    c1 = p1.chooseCardFromHand();
                    cout << endl << p1.getName() << ": Do you have a " << rankString(c1.getRank()) << +"?" << endl;
                }
            }
        } else {
            cout << endl << p1.getName() <<": Doesn't have any cards" << endl;
        }
        cout << p2.getName() <<": Go Fish" << endl;
        if(d.size() > 0) {
            c1 = d.dealCard();
            cout << p1.getName() << " draws " << c1.toString() << endl;
            p1.addCard(c1);
            while(p1.checkHandForBook(c1, c2)) {
                p1.bookCards(c1, c2);
                cout << p1.getName() <<" books the " << rankString(c1.getRank()) << endl;
            }
        } else {
            cout << p1.getName() << ": No cards to draw" << endl << endl;
        }

        if(p2.getHandSize() > 0) {
            c1 = p2.chooseCardFromHand();
            cout << endl << p2.getName() << ": Do you have a " << rankString(c1.getRank()) << +"?" << endl;
            while (p1.cardInHand(c1)) {
                cout << p1.getName() << ": Yes. I have a " << rankString(c1.getRank()) << endl;
                cout << p2.getName() << " books the " << rankString(c1.getRank()) << endl;

                p2.addCard(p1.removeCardFromHand(c1));
                p2.checkHandForBook(c1, c2);
                p2.bookCards(c1, c2);

                if(p2.getHandSize() > 0) {
                    c1 = p2.chooseCardFromHand();
                    cout << endl << p2.getName() << ": Do you have a " << rankString(c1.getRank()) << +"?" << endl;
                }
            }
        } else {    cout << endl << p2.getName() <<": Doesn't have any cards" << endl;}
        cout << p1.getName() <<": Go Fish" << endl;
        if(d.size() > 0) {
            c1 = d.dealCard();
            cout << p2.getName() << " draws " << c1.toString() << endl;
            p2.addCard(c1);
            while(p2.checkHandForBook(c1, c2)) {
                p2.bookCards(c1, c2);
                cout << p2.getName() <<" books the " << rankString(c1.getRank()) << endl;
            }
        } else {
            cout << p2.getName() << ": No cards to draw" << endl << endl;
        }
    }

    cout << "---------- End Game ----------" << endl;
    if(p1.getBookSize() > p2.getBookSize())
        winner = p1.getName();
    if(p2.getBookSize() > p1.getBookSize())
        winner = p2.getName();
    if(p2.getBookSize() == p1.getBookSize())
        winner = "TIE";
    cout << "The winner is " << winner << endl;

    cout << p1.getName() << " has " << p1.getHandSize() << " cards and " << p1.getBookSize() << " books." << endl;
    cout << p2.getName() << " has " << p2.getHandSize() << " cards and " << p2.getBookSize() << " books." << endl;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards) {
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
string rankString(int r) {
    if((r > 1) && (r < 11)) {
        char ans[1];
        sprintf(ans, "%d", r);
        return ans;
    } else if(r == 1) {
        return "A";
    } else if(r == 11) {
        return "J";
    } else if(r == 12) {
        return "Q";
    } else if(r == 13) {
        return "K";
    } else {
        return "";
    }
}
