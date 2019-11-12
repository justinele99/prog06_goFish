#include "deck.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Deck::Deck() {
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);

    myIndex = 0;
    int rank = 0;
    int suit;
    for(int i = 0; i<SIZE; i++) {
        suit = (i%4);
        if(suit == 0) {rank++;}
        Card c(rank, (Card::Suit)suit);
        myCards[i] = c;
    }
}
void Deck::shuffle() {
    for(int i = 0; i < SIZE; i++) {
        int j = rand()%SIZE;
        Card temp = myCards[i];
        myCards[i] = myCards[j];
        myCards[j] = temp;
    }
    myIndex = 0;
}
Card Deck::dealCard() {
    Card ans(0,(Card::Suit)0);
    if(size() > 0) {
        ans = myCards[myIndex];
        myIndex++;
    }
    return ans;
}
int Deck::size() const {
    return SIZE - myIndex;
}
