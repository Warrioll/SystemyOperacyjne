#pragma once
#include<mutex>
#include<condition_variable>
class Semafor
{
	std::mutex mtx;
	std::condition_variable cv;

	//liczba dostêpnych miejsc 0: nie ma miejsca, 5: prom jest pusty
	int counter;

public:
	Semafor();

	// odpowiada za blokowanie jesli nie ma mioejsca, jeœli jest miejsce na promiepozwala na wykonanie instrukcji po jej wywo³aniu czyli za³adunek , roz³adunerk itp.
	void hold(bool* reverseCondition);
	
	// roz³adowuje, zwalnia miejsce w semforze
	void realase();

	//zwaraca zawartosæ pola counter
	int counterState();
};

