#include<iostream>



class Apple {
private:
	int nutritionalValue;
	int timeToRiot;
	//приватный конструктор, который гарантирует, что экземпляр класса
	//может быть создан только внутри класса
	Apple() :nutritionalValue(100), timeToRiot(10) {
		std::cout << "Apple created" << std::endl;
	}
	//указатель на единственный экземпляр класса
	static Apple* instance;

	// Запрещаем копирование и присваивание
	Apple(const Apple&) = delete;
	Apple& operator = (const Apple&) = delete;



public:
	// Метод для получения экземпляра класса
	static Apple* getinstance() {
		if (instance==nullptr) {
			instance = new Apple();
		}
		return instance;
	}

	//Методы получения и изменения полей
	
	void SetNutritionalValue(int value) {
		nutritionalValue = value;
	}

	void SetTimeToRiot(int time) {
		timeToRiot = time;
	}
	
	int GetNutritionalValue() {
		return nutritionalValue;
	}

	int GetTimeToRiot(){
		return timeToRiot;
	}
	 


};

//инициализация статического указателя на экземпляр класса
Apple* Apple::instance = nullptr;

int main() {
	//получаем экземпляр класса
	Apple* apple1 = Apple::getinstance();
	std::cout << "NutritionalValue" << apple1->GetNutritionalValue() << std::endl;
	std::cout << "TimeToRiot" << apple1->GetTimeToRiot() << std::endl;
	//Меняем значения полей
	apple1 -> SetNutritionalValue(90);
	apple1 -> SetTimeToRiot(5);
	
	//Получаем экземпляр класса и проверяем, что значения полей совпадают
	Apple* apple2 = Apple::getinstance();
	
	std::cout << "NutritionalValue" << apple2->GetNutritionalValue() << std::endl;
	std::cout << "TimeToRiot" << apple2->GetTimeToRiot() << std::endl;

	return 0;
}