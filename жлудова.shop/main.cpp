#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <limits>
#include <String>

// функиции
void Start();
bool Login();
void CreateStorage();
void isStorageCreated();
inline void Getline(std::string& str);
inline void Err(int time = 1500);

// учетные записи 
size_t userSize = 2;
std::string userStatus[3]{"Супер администратор", "Администратор", "Сотрудник"};
std::string* loginArr = new std::string[userSize]{ "admin", "cats" };
std::string* passArr = new std::string[userSize]{ "admin", "12345" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus;

// склад товаров кофейни
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	
	Start();
	delete[]loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}
	return 0;
}

// функции
void Start() 
{
	std::cout << "\t\t\t\tКотоКофейня\n\n\n\n"; 
    
	if (Login())
	{
		if (currentStatus == userStatus[0]) 
		{
			//открытие склада + создание
		}
		else if (currentStatus == userStatus[1]) 
		{
			//открытие склада + создание
		}
		else if (currentStatus == userStatus[2]) 
		{
			//открытие склада + создание
		}
	}
	
}

bool Login() 
{
	std::string login, pass;
	while (true) 
	{
		std::cout << "Введите логин: ";
		Getline(login);
		std::cout << "Введите пароль: ";
		Getline(pass);

		if (login == "exit" && pass == "exit")
		{
			return false; 
		}

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[0] && pass == passArr[0]) {
				std::cout << "Пользователь: " << loginArr[0] << "\t\t\t\t\n\n\n\nДобро пожаловать в систему кофейни!";
				std::cout << "Ваш статус: " << statusArr[0] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err();
	}

}

inline void Getline(std::string& str) 
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time) 
{
	std::cout << "Некорректный ввод\n\n";
	Sleep(time);
	system("cls");
}

void CreateStorage()
{
	const int staticSize = 11;
	unsigned int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10,11};
	std::string name[staticSize];
	{   //напитки
		"Чай травяной", " Фирменный чай от кошечки", "Горячий шоколад", "Капуино", "Латте", "Экспрессо", "Смузи с пыльцой фей";
		//выпечка
		"Булочка с корицей", "Пироженое Cote шоколад", "Пироженое Cote клубника-банан", "Минипцца пепероне от коте";
	};
	unsigned int count[staticSize]{ 20,29,28,30,40,40,40,7,30,30,42 };
	double price[staticSize]{ 200.99, 250.99, 200.99, 199.99, 150.99, 99.99, 300.99, 99.99, 199.99, 199.99, 150.99 };
	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	isStorageCreated = true;



}
