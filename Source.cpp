#include <iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include<algorithm>//sort - стандартный или штатный сортировщик



using namespace std;

class Pet
{
private:
	static string owner;//поле не привязывается к каждому объекту и сущкствует отдельно от них в единственном экземпляре
	string name;
	int age;
public:
	Pet(string name, int age) {
		this->name = name;
		this->age = age;
	}

	Pet() {
		name = name;
		age = age;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return this->age;
	}
	//статические методы не требуют для вызова объекта и 
	//предназначены для работы со статическими полями вызов производится через имя класса(имя::метод())
	static void setOwner(string newOwner) {
		Pet::owner = owner;

	}

	static string getOwner() {
		return Pet::owner;
	}



	virtual void voice() = 0; 

	virtual void info() = 0;
	
	friend bool cmpNameUp(Pet*, Pet*);//метод являетя другом клаасса , реализуется вне класса ,
	//имеет доступ ко всем полям и методам(даже приват) для своего вызова не требует объекта.т.е. 
	//вызывается как обычная функция. Нельзя использовать this в нем

	virtual ~Pet() {
		cout << "dictructor Pet" << endl;
	}
};
//метод образец для сравнения объектов по имени
bool cmpNameUp(Pet* p1, Pet* p2) {
	if (p1->name > p2->name)
	{
		return false;
	}
	else {
		return true;
	}

}

string Pet::owner = "Igor";

class Cat : public Pet {

public:
	Cat(string name, int age) :Pet(name, age) {
	}

	Cat() :Pet() {
	}
	void voice() {
		cout << "may-may" << endl;
	}

	void info() {

		cout << "Cat's neme: " << this->getName() << ", Age: " << this->getAge() << endl;
	}

	~Cat() {
		cout << "dictructor Cat" << endl;
	}
};

class Dog : public Pet {

public:
	Dog(string name, int age) :Pet(name, age) {
	}

	Dog() :Pet() {
	}

	void voice() {
		cout << "Gaw-gaw" << endl;
	}

	void info() {
		cout << "Dog's name: " << this->getName() << ", Age: " << this->getAge() << endl;
	}

	~Dog() {
		cout << "distruction Dog" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*Pet** pets = NULL;
	int size = 5;

	pets = new Pet * [size];
	pets[0] = new Cat("Boris", 3);
	pets[1] = new Dog("Reks", 7);
	pets[2] = new Cat("Mursic", 2);
	pets[3] = new Cat("Pushok", 1);
	pets[4] = new Dog("Barsic", 5);

	cout << "Pereclichka" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") ";
		pets[i]->info();
		pets[i]->voice();
	}
	for (int i = 0; i < size; i++)
	{
		delete pets[i];
	}
	delete[] pets;


	cout << "----------------------------------------------" << endl;

	*/
	vector <Pet*> pets;
	pets.push_back( new Cat("Boris", 3));
	pets.push_back(new Dog("Reks", 7));
	pets.push_back(new Cat("Mursic", 2));
	pets.push_back(new Cat("Pushok", 1));
	pets.push_back(new Dog("Barsic", 5));

	cout << "Size " << pets.size() << ", memory: " << pets.capacity() << endl;
	/*pets.push_back(new Cat("Marsic", 4));
	pets.push_back(NULL);
	pets[1] = new Cat("Kuza", 12);*/
	int menu1, menu2, fExit = 1;
	int tmpAge;
	string tmpName;

	do
	{
		cout << "1. Add" << endl;
		cout << "2. Pereclichka" << endl;
		cout << "3. Redactor" << endl;
		cout << "4. delete" << endl;
		cout << "5. Sort" << endl;
		cout << "Enter number menu" << endl;
		cin >> menu1;
		switch (menu1)
		{
		case 1: {
			cout << "Viberi vid animal" << endl;
			cout << "1. Cat" << endl;
			cout << "2. Dog" << endl;
			cin >> menu2;
			cout << "add name animal" << endl;
			while (cin.get() != '\n');
			getline(cin, tmpName);
			cout << "add age animal" << endl;
			cin >> tmpAge;
			switch (menu2)
			{
			case 1: {
				pets.push_back(new Cat(tmpName, tmpAge)); //добавление в конец

				/*pets.push_back(NULL);
				pets[pets.size() - 1] = new Cat(tmpName, tmpAge); //добавление в конец

				pets.insert(pets.begin(), new Cat(tmpName, tmpAge)); //вставка в начало

				pets.insert(pets.end(), new Cat(tmpName, tmpAge));//вставка в начало

				int num = 3;
				pets.insert(pets.begin()+num - 1, new Cat(tmpName, tmpAge));//вставка в пизицию*/

			}break;
			case 2: {
				pets.push_back(new Dog(tmpName, tmpAge)); 
			}break;
			default:
				break;
			}

		}break;
		case 2: {
			cout << "owner:"<<Pet::getOwner()<<endl;
			cout << "Pereclichka" << endl;
			for (size_t i = 0; i < pets.size(); i++) {
				cout << i + 1 << ") ";
				pets[i]->info();
				pets[i]->voice();
			}
		}break;
		case 3: {}break;
		case 4: {
			int num;
			cout << "enter name's del animal" << endl;
			cin >> num;
			while (num<1||num>pets.size())
			{
				cout << "no-corect entering, please enter agen" << endl;
				cin >> num;
			}
			delete pets[num - 1];
			pets.erase(pets.begin() + num - 1);

		
		
		}break;
		case 5: {
			sort(pets.begin(), pets.end(), cmpNameUp);
		
		
		
		}break;


		default:
			break;
		}
		system("pause");
		system("cls");

	} while (fExit == 1);


	//345353434
	
	return 0;
}