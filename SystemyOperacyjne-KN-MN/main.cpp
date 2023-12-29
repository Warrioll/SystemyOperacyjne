#include"Ferry.h"

int main() {
	Ferry ferry;

	Car car1(1), car2(2), car3(3), car4(4), car5(5), car6(6), car7(7), car8(8), car9(9), car10(10);

	ferry.tryBoardCar(&car1);
	ferry.tryBoardCar(&car2);
	ferry.tryBoardCar(&car3);
	ferry.tryBoardCar(&car4);
	ferry.tryBoardCar(&car5);
	ferry.tryBoardCar(&car6);
	ferry.tryBoardCar(&car7);
	ferry.tryBoardCar(&car8);
	ferry.tryBoardCar(&car9);
	ferry.tryBoardCar(&car10);

	ferry.ferryWork();

	car1.t.join();
	car2.t.join();
	car3.t.join();
	car4.t.join();
	car5.t.join();
	car6.t.join();
	car7.t.join();
	car8.t.join();
	car9.t.join();
	car10.t.join();
	
	return 0;
}


