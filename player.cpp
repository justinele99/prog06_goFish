#include "player.h"
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

Player::Player() {    myName = "Unknown";    }
void Player::addCard(Card c) {
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}
Card Player::chooseCardFromHand() const {
    Card ans(0, (Card::Suit) 0);
    int size = getHandSize();
    if(size !=  0) {
        ans = myHand[rand()%size];
    }
    return ans;
}
bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++) {
        if(myHand[i].getRank() == c.getRank())
            return true;
    }
    return false;    
}
Card Player::removeCardFromHand(Card c) {
    bool found = false;
    vector <Card> temp;
    for(int i = 0; i < myHand.size(); i++) {
        if(c == myHand[i] && !found) {
            found = true;
        } else {
            temp.push_back(myHand[i]);
        }
    }
    myHand.clear();
    for(int i = 0; i < temp.size(); i++) {
        myHand.push_back(temp[i]);
    }
    return c;
}
string Player::showHand() const {
    string ans;
    for(int i = 0; i < myHand.size(); i++) {
        ans +=  myHand[i].toString() + " ";
    }
    return ans;
}
string Player::showBooks() const {
    string ans;
    for(int i = 0; i < myBook.size(); i++) {
        ans += myBook[i].toString() + " ";
    }
    return ans;
}
int Player::getHandSize() const {    return myHand.size();    }
int Player::getBookSize() const {    return myBook.size();    }
bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(int i = 0; i < myHand.size(); i++) {
        c1 = myHand[i];
        for(int j = i+1; j < myHand.size(); j++) {
            c2 = myHand[j];
            if(c1.getRank() == c2.getRank()) {
                return true;
            }
        }
    }
    return false;
}