#include "card.h"
#include <iostream>
#include <cstdio>
using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}
Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}
string Card::rankString(int r) const {
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
string Card::toString() const {
    string ans = rankString(myRank);
    if(ans != "")
        ans = ans + suitString(mySuit);
    return ans;
}
bool Card::sameSuitAs(const Card& c) const {
    return (c.mySuit == mySuit);
}
int Card::getRank() const {
    return myRank;
}
string Card::suitString(Suit s) const {
    if(s == Card::spades) {
        return "s";
    } else if(s == Card::hearts) {
        return "h";
    } else if(s == Card::diamonds) {
        return "d";
    } else if(s == Card::clubs) {
        return "c";
    } else {
        return "";
    }
}
bool Card::operator ==(const Card& rhs) const{
    //return ( (rhs.getRank()==getRank()) && (sameSuitAs(rhs)));
    return (rhs.getRank()==getRank());
}
bool Card::operator !=(const Card& rhs) const{
    //return ( (rhs.getRank()!=getRank()) || (!sameSuitAs(rhs)));
    return (rhs.getRank()!=getRank());
}
ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;
}
