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

	static bool ferryReturned;				//odpowiada za to czy prom powr�ci�

	//podpi�ta pod watek danego auta - je�li jest mo�liwo�� to �aduje auto na prom i czeka a� b�dzie mog�o go op�ci� po drugiej stronie
	static void boardCar(int carId);		
	


public:
	//w sumie to ten konstuktor nie jest potrzebny
	Ferry();

	//przypisuje w�tkowi funckj� boardCar
	void tryBoardCar(Car* car);

	// cykl promu - je�li jest za�adowany to odp�ywa (czeka s) i daje mo�liwo�� op�szenia promu
	void ferryWork();

};

