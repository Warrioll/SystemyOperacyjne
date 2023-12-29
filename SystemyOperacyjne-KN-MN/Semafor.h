#pragma once
#include<mutex>
#include<condition_variable>
class Semafor
{
	std::mutex mtx;
	std::condition_variable cv;

	//liczba dost�pnych miejsc 0: nie ma miejsca, 5: prom jest pusty
	int counter;

public:
	Semafor();

	// odpowiada za blokowanie jesli nie ma mioejsca, je�li jest miejsce na promiepozwala na wykonanie instrukcji po jej wywo�aniu czyli za�adunek , roz�adunerk itp.
	void hold(bool* reverseCondition);
	
	// roz�adowuje, zwalnia miejsce w semforze
	void realase();

	//zwaraca zawartos� pola counter
	int counterState();
};

