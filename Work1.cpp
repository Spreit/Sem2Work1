// Work1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.\
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
#include <iterator>
#include <algorithm>
#include <functional>

std::string message = "Hello, my name is Ivan.";

class encryption {
private:
    std::vector<std::string> m_words;
    std::vector<int> key_index;
    std::vector<int> key_full;
    std::vector<int> key_encode;
    int word_count;

private:
    void split_by_spaces(const std::string &message) {
        int mes_size = message.size();
        std::string word;
        int word_begin = 0;
        int word_len = 0;

        for (int i = 0; i < mes_size; i++) {
            if (message[i] == ' ') {
                m_words.emplace_back(message.substr(word_begin, word_len + 1));
                word_len = 0;
                word_begin = i + 1;
            }else {
                word_len++;
            }

            if (i == mes_size - 1) {
                m_words.emplace_back(message.substr(word_begin, word_len));
            }
        }
    }

    int Fib(int i) {
        if (i < 1) return 0;
        if (i == 1) return 1;
return Fib(i - 1) + Fib(i - 2);
    }

    int Fib_to_index(int fibnum) {
        if (fibnum == 0) {
            return 0;
        }
        else if (fibnum == 1) {
            return 1;
        }
        else {
            int nres = 0;
            int i = 2;
            while (nres < fibnum) {
                nres = Fib(i);
                i++;
                if (nres == fibnum) {
                    return i - 2;
                };
                if (nres > fibnum) {
                    return -1;
                };
            };
        };

    }

    void key_to_index() {
        int ind;
        for (int i = 0; i < word_count; i++) {
            ind = Fib_to_index(key_index[i]);
            if (ind >= 0) {
                key_index[i] = ind;
            }
            else {
                std::cout << "Invalid fib sequence." << std::endl;
                remove_key();
                break;
            }
        }

    }

    void check_seq(std::vector<int> key) {
        std::vector<int> temp_key = key;
        std::sort(temp_key.begin(), temp_key.end());

        for (int i = 0; i < temp_key.size() - 1; i++) {
            if (temp_key[i] == temp_key[i + 1]) {
                std::cout << "Invalid fib sequence." << std::endl;
                remove_key();
            }
        }
    }

    void encrypt(std::vector<int> index_key) {

        std::vector<std::string> m_cr;

        for (int i = 0; i < word_count; i++) {
            m_cr.emplace_back(m_words[index_key[i]]);
        }
        m_words = m_cr;

    };

    void decrypt(std::vector<int> index_key) {

        std::vector<std::string> m_cr;

        for (int i = 0; i < word_count; i++) {
            m_cr.emplace_back(m_words[index_key[i]]);
        }
        m_words = m_cr;
    }

    void print_message() {
        for (int i = 0; i < word_count; i++) {
            std::cout << m_words[i];
        }
        std::cout << std::endl;
    };

public:
    encryption(const std::string &message) {
        split_by_spaces(message);
        word_count = m_words.size();
    };

    void input_key(std::vector<int> inserted_key) {
        if (key_index.size() != 0) {
            std::cout << "Key is already inserted. Remove key to insert." << std::endl;
        }
        else {

            std::cout << "Key inserted." << std::endl;

            if (inserted_key.size() != word_count) {
                std::cout << "Incorrect key size!" << std::endl;
                remove_key();
            }
            else {
                key_full  = inserted_key;
                key_index = inserted_key;
                key_to_index();
            }

            //Correct sequence check
            if (key_index.size() != 0){
                check_seq(key_index);
            }

        }

    }

    void remove_key() {
        key_full.erase(key_full.begin(), key_full.end());
        key_index.erase(key_index.begin(), key_index.end());
        std::cout << "Key removed." << std::endl;
    }

    void encode() {

        if (key_index.size() == 0) {
            std::cout << "Key is missing!" << std::endl;
        }
        else {
            encrypt(key_index);
            key_encode = key_full;
            print_message();
        }
    }
    
    void decode() {

        if (key_index.size() == 0) {
            std::cout << "Key is missing!" << std::endl;
        }
        else if(key_full != key_encode){
            std::cout << "Wrong key!!" << std::endl;
        }
        else {
            decrypt(key_index);
            print_message();
        }
    }



};

int main()
{
    std::vector<int> new_key = { 5,3,2,1,0 };
    encryption masage(message);

    std::cout << new_key.size() << std::endl;
    masage.input_key(new_key);
    masage.encode();

//    masage.remove_key();
//    new_key = { 5,1,2,3,0 };
//    masage.input_key(new_key);
    
    masage.decode();
    masage.remove_key();
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
