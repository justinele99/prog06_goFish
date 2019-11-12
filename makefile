final: card_demo.o player.o deck.o card.o
	g++ -otest card_demo.o player.o deck.o card.o 
card_demo: card_demo.cpp deck.h card.h player.h
	g++ -c card_demo.cpp
player.o: player.cpp player.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp
