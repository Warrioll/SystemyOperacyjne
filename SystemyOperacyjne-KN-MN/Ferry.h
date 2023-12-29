#pragma once
#include<iostream>
#include<thread>
#include<mutex>
#include<ctime>
#include"Semafor.h"
#include"Car.h"

class Ferry
{

	static Semafor sem;						//semafor

	static bool ferryReturned;				//odpowiada za to czy prom powróci³

	//podpiêta pod watek danego auta - jeœli jest mo¿liwoœæ to ³aduje auto na prom i czeka a¿ bêdzie mog³o go opó¿ciæ po drugiej stronie
	static void boardCar(int carId);		
	


public:
	//w sumie to ten konstuktor nie jest potrzebny
	Ferry();

	//przypisuje w¹tkowi funckjê boardCar
	void tryBoardCar(Car* car);

	// cykl promu - jeœli jest za³adowany to odp³ywa (czeka s) i daje mo¿liwoœæ opószenia promu
	void ferryWork();

};

