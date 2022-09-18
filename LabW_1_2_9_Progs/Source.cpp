#include "Libraries.h"

//Функции фабрика
class dataPerson {
public:
	dataPerson() {}
	dataPerson(string surname, string name, string pathr, dataPerson* id = NULL)
	{
		this->surname = surname;
		this->name = name;
		this->pathr = pathr;
		this->id = id;
	}
	void showPerson() {
		cout << "Surname: " << surname
			<< " Name: " << name
			<< " Pathr: " << pathr << endl;
	}
private:
	string surname;
	string name;
	string pathr;
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
	list<dataPerson> dataList;
	int size, sizeDelete;
public:
	void addback(dataPerson data) override
	{
		dataList.push_front(data);
		size += 1;
	}
	void Delete(int num)override
	{
		list<dataPerson>::iterator iter = dataList.begin();
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
		sizeDelete += 1;
		size -= 1;
	}
	void show() override
	{
		for (dataPerson n : dataList)
		{
			n.showPerson();
		}
		cout << "SizeAdd: " << size << endl;
		cout << "SizeDelete: " << sizeDelete << endl;
	}
};
class setList :InterfaceList {
private:
	set<dataPerson> dataList;
	set<dataPerson> new_dataList;
public:
	//Добавление не работает, не может сравнить элементы
	void addback(dataPerson data) override
	{
		//new_dataList.insert(data);
	}
	void Delete(int num) override
	{
		set<dataPerson>::iterator iter = dataList.begin();
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
		for (dataPerson n : dataList)
		{
			n.showPerson();
		}
		dataList = new_dataList;
		new_dataList.clear();
	}
	//template <>
	//template <class _Ty1, class _Ty2>
	//_NODISCARD constexpr bool less<void>::operator()(_Ty1&& _Left, _Ty2&& _Right) const {
	//	return _Left->dataList < _Right->dataList;
	//}
	//
	//bool operator==(const setList& v1) 
	//{
	//	return this->new_dataList == v1.new_dataList;
	//}
	//bool operator<(setList v1)
	//{
	//	return this->new_dataList < v1.new_dataList;
	//}
	//bool operator>(const setList& v1) const
	//{
	//	return this->new_dataList > v1.new_dataList;
	//}
};
class mapList :InterfaceList {
private:
	map<string, dataPerson> dataList;
	string key;
	int size, sizeDelete;
	void Delete(int key) {}
public:
	void addback(dataPerson data) override
	{
		cout << "Ключ: " << endl;
		cin >> key;
		dataList.emplace(key, data);
		size++;
	}
	//Удаление по ключу
	void Delete(string key)
	{
		dataList.erase(key);
		size--;
		sizeDelete++;
	}
	void show() override
	{
		string key;
		cout << "КлючShow: " << endl;
		cin >> key;
		dataList[key].showPerson();
	}
};

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
			dataPerson* person = new dataPerson("Leo", "Melee", "Koa");
			test.addback(*person);
			person = new dataPerson("Rick", "Sanches", "Math");
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
			dataPerson *person = new dataPerson("Leo", "Melee", "Koa");
			test.addback(*person);
			person = new dataPerson("Rick", "Sanches", "Math");
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
			dataPerson* person = new dataPerson("Leo", "Melee","Koa");
			//test.addback(*person);
			person = new dataPerson("Rick", "Sanches", "Math");
			//test.addback(*person);
			test.show();
			test.show();
			return 0;
		}
		case(4): {
			//Тестирование map
			dataPerson* person = new dataPerson("Leo", "Melee", "Koa");
			mapList test;
			test.addback(*person);
			person = new dataPerson("Rick", "Sanches", "Math");
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