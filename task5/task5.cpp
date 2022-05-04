// task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

void Task123(FILE* s) {

	char* buff = new char[128];
	fgets(buff, 128, s);

	using namespace std;
	unsigned int count = 0;

	for (int i = 0; i < strlen(buff); i++) {

		if (buff[i] <= 32) {

			count++;

		}

	}

	char* IN_Str = new char[128];


	cout << "Write sence string:" << endl;
	cin >> IN_Str;

	if (strstr(buff, IN_Str) != NULL) {
		cout << "SubString exists: " << strstr(buff, IN_Str) << endl;
	}
	else {
		cout << "NO SubString" << endl;
	}
	cout << buff << endl;
	cout << "No visible char: " << count << endl;


}

void Task4() {


	typedef struct mem {
		char* str;
		struct mem* next;
	}mem;

	FILE* in = fopen("Task4.txt", "r");

	mem* Mem_pointer = new mem;
	Mem_pointer->str = nullptr;
	Mem_pointer->next = nullptr;

	mem* Mem_head = Mem_pointer;

	while (1) {

		char buff[1024] = { 0 };
		if (fgets(buff, 1024, in) == 0) break;

		char* point_1 = nullptr;
		char* point_2 = nullptr;
		char* point_3 = nullptr;

		point_1 = strstr(buff, "-");

		if (point_1 == nullptr) continue;

		point_2 = strstr(point_1 + 1, "-");
		point_3 = strstr(buff, "\f");

		char* str_out = new char[strlen(buff)];
		memset(str_out, 0, strlen(buff));

		char Num_Str[2] = { 0 };
		memcpy(Num_Str, point_1 + 1, 2);

		if (point_3 != nullptr) *point_3 = ' ';

		strcpy(str_out, point_2 + 2);
		str_out[strlen(str_out) - 1] = ' ';
		strcat(str_out, Num_Str);
		str_out[strlen(str_out) - 1] = 0;


		printf("%s\n", str_out);


		Mem_pointer->str = str_out;
		Mem_pointer->next = new mem;
		Mem_pointer = Mem_pointer->next;
		Mem_pointer->next = nullptr;

	}

	fclose(in);

	Mem_pointer = Mem_head;

	FILE* out = fopen("Task4O.txt", "w");

	while (1) {

		fprintf(out, "%s ", Mem_pointer->str);
		if (Mem_pointer->next != nullptr) {
			Mem_pointer = Mem_pointer->next;
		}
		else break;

	}

	fclose(out);

}

void Task56(char* name, int key) {

	typedef struct mem {
		char* str;
		struct mem* next;
	}mem;

	FILE* in = fopen((char*)name, "r");
	if (in == NULL) {
		puts("�� ���������� ������� ����");
		return;
	}

	mem* Mem_pointer = new mem;
	Mem_pointer->str = nullptr;
	Mem_pointer->next = nullptr;

	mem* Mem_head = Mem_pointer;

	if (key == -1) {

		puts("������� key: ");
		scanf("%i", &key);

	}
	printf("%i", key);

	while (1) {

		Mem_pointer->str = new char[1024];
		memset(Mem_pointer->str, 0, 1024);
		if (fgets(Mem_pointer->str, 1024, in) == 0) break;

		for (int i = 0; i < strlen(Mem_pointer->str); i++) {

			Mem_pointer->str[i] ^= key;

		}

		Mem_pointer->next = new mem;
		Mem_pointer = Mem_pointer->next;
		Mem_pointer->next = nullptr;

	}

	fclose(in);

	in = fopen((char*)name, "w");

	Mem_pointer = Mem_head;

	while (1) {

		fprintf(in, "%s", Mem_pointer->str);
		if (Mem_pointer->next != nullptr) {
			Mem_pointer = Mem_pointer->next;
		}
		else break;

	}



}

int main(int argc, char* argv[]) {


	using namespace std;
	setlocale(LC_ALL, "Russian");
	char ch, name[50] = { 0 };
	int key = -1;

	if (argc > 1) {

		if (argc == 2) {

			key = atoi(argv[1]);
			puts("������� ��� �����: ");
			scanf("%s", name);

		}
		if (argc == 3) {

			strcpy(name, argv[1]);
			key = atoi(argv[2]);

		}
		if (argc > 3) {

			printf("������� ����� ���������");
			return 1;

		}

	}
	else {

		puts("������� ��� �����: ");
		scanf("%s", name);

	}





	//	Task123(in);
	//	Task4();

	Task56(name, key);




	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
