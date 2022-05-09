#include "Libraries.h"

//Функции фабрика
class dataPerson {
public:
	dataPerson() {}
	dataPerson(string name, string role, int damage, dataPerson* id = NULL)
	{
		this->name = name;
		this->role = role;
		this->damage = damage;
		this->id = id;
	}
	void showPerson() {
		cout << "Name: " << name << endl;
		cout << "Role: " << role << endl;
		cout << "Damage: " << damage << endl;
	}
private:
	string name;
	string role;
	int damage;
	dataPerson* id;
};
class InterfaceList {
public:
	virtual void addback(dataPerson data) = 0;
	virtual void Delete(int num) = 0;
	virtual void show() = 0;
};
class vectorList :InterfaceList {
private:
	vector<dataPerson> dataList;
	string styleFight;
public:

	void addback(dataPerson data) override
	{
		dataList.push_back(data);
	}
	void Delete(int num)override
	{
		vector<dataPerson>::iterator iter = dataList.begin();
		int i = 0;
		while (iter != dataList.end())
		{
			if (num == i)
			{
				break;
			}
			iter++;
			i++;
		}
		dataList.erase(iter);
	}
	void show() override
	{
		for (int i = 0; i < dataList.size(); i++)
		{
			dataList[i].showPerson();
		}
	}
};
class listList :InterfaceList {
private:
	list<dataPerson> dataList1;
	int size, sizeDelete;
public:
	void addback(dataPerson data) override
	{
		dataList1.push_front(data);
		size += 1;
	}
	void Delete(int num)override
	{
		list<dataPerson>::iterator iter = dataList1.begin();
		int i = 0;
		while (iter != dataList1.end())
		{
			if (num == i)
			{
				break;
			}
			iter++;
			i++;
		}
		dataList1.erase(iter);
		sizeDelete += 1;
		size -= 1;
	}
	void show() override
	{
		for (dataPerson n : dataList1)
		{
			n.showPerson();
		}
		cout << "Size: " << size << endl;
		cout << "SizeDelete: " << sizeDelete << endl;
	}
};
class setList :InterfaceList {
private:
	set<dataPerson> dataList2;
	set<dataPerson> new_dataList2;
public:
	//Добавление не работает, не может сравнить элементы
	void addback(dataPerson data) override
	{
		/*new_dataList2.insert(data);*/
	}
	void Delete(int num)override
	{
		set<dataPerson>::iterator iter = dataList2.begin();
		int i = 0;
		while (iter != dataList2.end())
		{
			if (num == i)
			{
				break;
			}
			iter++;
			i++;
		}
		dataList2.erase(iter);
	}
	void show() override
	{
		for (dataPerson n : dataList2)
		{
			n.showPerson();
		}
		dataList2 = new_dataList2;
		new_dataList2.clear();
	}
	/*bool operator()(const setList& v1, const setList& v2) const
	{
		return v1.dataList2 < v2.new_dataList2;
	}*/
	bool operator<(setList v1)
	{
		return this->new_dataList2 < v1.new_dataList2;
	}
	bool operator>(const setList& v1) const
	{
		return this->new_dataList2 > v1.new_dataList2;
	}


};
class mapList :InterfaceList {
private:
	map<string, dataPerson> dataList3;
	string key;
	int size, sizeDelete;
public:
	//или сделать Key интом и приращивать в этой же функции
	void addback(dataPerson data) override
	{
		cout << "Ключ: " << endl;
		cin >> key;
		dataList3.emplace(key, data);
		size++;
	}
	//Удаление по ключу - в интефейсе int 
	void Delete(int key)
	{
	}
	void Delete(string key)
	{
		dataList3.erase(key);
		size--;
		sizeDelete++;
	}
	void show() override
	{
		string key;
		cout << "КлючShow: " << endl;
		cin >> key;
		dataList3[key].showPerson();
	}
};

void selector() {

}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	cout << "\n\t1 - Тетирования вектора"
		<< "\n\t2 - Тетирования списка"
		<< "\n\t3 - Тестирование set"
		<< "\n\t4 - Тестирование map"
		<< "\n\t0 - Выход\n\t";
	char charInputNum;
	cin >> charInputNum;
	int inputNum = isInteger(charInputNum);

	switch (inputNum) {
		case (0): return 0;
		case(1): {
			//Тетирования вектора
			vectorList test;
			dataPerson* person = new dataPerson("FIO", "Melee", 15);
			test.addback(*person);
			person = new dataPerson("OIF", "Range", 10);
			test.addback(*person);
			test.show();
			test.Delete(0);
			cout << "**********************************************************************" << endl;
			test.show();
			return 0;
		}
		case(2): {
			//Тетирования списка
			listList test;
			dataPerson *person = new dataPerson("FIO", "Melee", 15);
			test.addback(*person);
			person = new dataPerson("OIF", "Range", 10);
			test.addback(*person);
			test.show();
			test.Delete(0);
			cout << "**********************************************************************" << endl;
			test.show();
			return 0;
		}
		case(3): {
			//Тестирование set
			setList test;
			dataPerson* person = new dataPerson("FIO", "Melee",15);
			test.addback(*person);
			test.show();
			return 0;
		}
		case(4): {
			//Тестирование map
			dataPerson* person = new dataPerson("FIO", "Melee", 15);
			mapList test;
			test.addback(*person);
			person = new dataPerson("OIF", "Range", 10);
			test.addback(*person);
			test.show();
			return 0;
		}
		default: {
			cout << "\n\tОшибка ввода\n";
			system("pause");
			system("cls");
			return 0;
		}
	}
	return 0;
}