#include<iostream>
#include "Semafor.h"


Semafor::Semafor() : counter(5)
{
}

void Semafor::hold( bool *reverseCondition)
{
	std::unique_lock<std::mutex> blocade(mtx);
	
	while ((this->counter == 0 && !( * reverseCondition)))
		{	cv.wait(blocade);
	}
	counter--;
	std::cout << "Counter: " << counter << std::endl;
}

void Semafor::realase()
{
	std::unique_lock<std::mutex> blocade(mtx);
	counter++;
	cv.notify_all();
	std::cout << "Counter: " << counter << std::endl;
}

int Semafor::counterState() {
	return counter;
}



