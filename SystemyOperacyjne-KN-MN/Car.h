#pragma once
#include<thread>
class Car
{
public:
	//w�tek
	std::thread t;

	//id auta
	int id;

	//przypisuje id
	Car(int id);		
};

