#include "Ferry.h"

bool Ferry::ferryReturned = false;

Semafor Ferry::sem;

Ferry::Ferry(){
	ferryReturned = false;

}

void Ferry::tryBoardCar(Car* car)
{
    car->t = std::thread(boardCar, car->id);

}

 void Ferry::boardCar(int carId) 
{

		
		 sem.hold(&ferryReturned);				//zaduje auto jeœli moze jeœlio nie to czeka
		 std::cout << "Watek " << carId << " dziala " << /*clock() / CLOCKS_PER_SEC << */std::endl;
	 
	
		while (!ferryReturned) {		//sluzy do czekania do poki auto bedzie moglo oposcic prom
		}
	
	
	sem.realase();					//oposzczenie promu
	std::cout << "Watek " << carId << " konczy" << /*clock() / CLOCKS_PER_SEC << */ std::endl;
	if (sem.counterState() == 5) {							//jesli to bylo ostatnie auto komunikat i zmiana zmiennej która umo¿liwi wejsæie nowym autom na prom
		std::cout << "Prom gotowy do zaladnku!\n";
		ferryReturned = false;
		
	}
	//std::cout << "board end!!!!!\n";
}

void Ferry::ferryWork() {
	while (true) {
		if (sem.counterState() == 0 && !ferryReturned) {					//jesli zaladowany i zmienna pozwala to odplywa
			
			std::cout << "Odplywa\n";
			std::this_thread::sleep_for(std::chrono::seconds(5));		//odzcekanie a¿ prom wróci
			ferryReturned = true;
		}
		
	}
}
