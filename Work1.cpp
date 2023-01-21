﻿// Work1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.\
// 
/* «Шифрование»

Реализуйте класс, который будет выполнять шифрование и дешифрование сообщения на английском языке.Длина сообщения не более 30 слов.Словом называется последовательность символов до первого пробела.Знак препинания после символов тоже входит в слово.
Ключом является последовательность Фибоначчи.

Пример
Есть сообщение

Hello, my name is Ivan.

Поставим в соответствие каждому слову в сообщении число из последовательности

Hello, my	name	is	Ivan.
1	2	3	5	8

Пусть ключ для этого сообщения 2, 8, 5, 1, 3, тогда зашифрованное сообщение примет вид

my Ivan.is Hello, name

Для расшифровки сообщения, нужно слова переставить так, чтобы получилась верная последовательность Фибоначчи.

Реализация
В классе реализуйте методы Encode и Decode, предусмотрите возможность ввести и вывести ключ, а также обработку ошибок при некорректном вводе.
Помните, что вашим классом могут пользоваться другие разработчики, оставьте публичными только необходимые для работы методы.
Продемонстрируйте работу с классом.
*/
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

std::string message = "Hello, my name is Ivan.";

class encryption {
private:
    std::vector<std::string> m_words;
    std::string * m_message;
    int word_count;
    std::vector<int> key;

    std::string split_by_spaces(const std::string message) {
        
    }

    template <typename Out>
    void split(const std::string& s, char delim, Out result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, item, delim)) {
            *result++ = item;
        }
    }
    std::vector<std::string> split(const std::string& s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }
public:
    encryption(std::string message) {

    }

};

int main()
{
    std::cout << "Hello World!\n";
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
