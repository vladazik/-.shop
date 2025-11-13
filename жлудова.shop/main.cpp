#include <iostream>
#include <String>
#include <Windows.h>
#include <limits>
#include <iomanip>

// вход
size_t userSize = 2;
std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "admin", "cats" };
std::string* passArr = new std::string[userSize]{ "admin", "12345" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus{};

//Cклад
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

void CreateStorage();
void ShowStorage(int mode = 0);
void Start();
bool Login();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);

void AddStorageItrm();

template<typename ArrType>
void FillArray(ArrType* dinamicArray, ArrType* staticArray, size_t arraySize);




inline void GetLine(std::string& str);
inline void Err(int time = 1500);


int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[] loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[] idArr, nameArr, countArr, priceArr;
	}
	return 0;
}
void ShowStorage(int mode)   
{
	if (mode == 0) {
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Кол-во\n" << "Цена\n";
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t\t" << "Цена\n";
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << "\t" << priceArr[i] << "\n";
		}
	}
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длинны числа. Максимум девятизначные числа! \n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введенные данные не являются числом!";
			Sleep(1500);
			return false;
		}
	}
	return true;
}
void CreateStorage()
{
	const int staticSize = 11;
	unsigned int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10,11 };
	std::string name[staticSize]{   //напитки
		"Чай травяной", "Фирменный чай от кошечки", "Горячий шоколад", "Капуино", "Латте", "Экспрессо", "Смузи с пыльцой фей",
		//выпечка
		"Булочка с корицей", "Пироженое Cote шоколад", "Пироженое Cote клубника-банан", "Минипцца пепероне от коте"};
	unsigned int count[staticSize]{ 20,29,28,30,40,40,40,7,30,30,42 };
	double price[staticSize]{ 200.99, 250.99, 200.99, 199.99, 150.99, 99.99, 300.99, 99.99, 199.99, 199.99, 150.99 };
	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	countArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	priceArr = new double[storageSize];

	isStorageCreated = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(priceArr, price, storageSize);
}

void Start()
{
	std::string choose;
	std::cout << "\n\n\n\t\t\tКотоКофейня\n\n\n";
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{  
			while (true)
			{
				std::cout << "Выберите склад\n1- Готовый склад\n2 - Создать новый\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					
					system("cls");
					CreateStorage();
					ShowSuperAdminMenu();

				}
				else if (choose == "2")
				{
					// создать новый склад
				}
				else
				{
					Err();
				}
			}
			CreateStorage();
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[1])
		{
			CreateStorage();
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			CreateStorage();
			// Открытие + создание склада
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершения работы программы" << std::endl << std::endl;
	}
}

bool Login()
{
	std::string login, pass;

	while (true)
	{
		
		std::cout << "Введите логин: ";
		GetLine(login);
		std::cout << "Введите пароль: ";
		GetLine(pass);
		if (login == "exit" && pass == "exit")
		{
			
			currentStatus = "";
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобро пожаловать в КотоКофейню!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}

	}
}

inline void GetLine(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time)
{
	std::cout << "Некоректный ввод" << std::endl << std::endl;
	Sleep(time);
	system("cls");
}

template<typename ArrType>
void FillArray(ArrType* dinamicArray, ArrType* staticArray, size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		dinamicArray[i] = staticArray[i];
	}
}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Редактировать склад\n";
		std::cout << "7 - Редоктировать персонал\n";
		std::cout << "8 - Отчет о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		GetLine(choose);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else 
		{
			std::cout << "Error";
		}
	}
}

void AddStorageItrm()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции пополнения!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введие кол-во товаров для пополнения: ";
		GetLine(chooseCount);

		std::stoi

	}
}