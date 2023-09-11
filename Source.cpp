#include "Header.h"

int main() {
    system("chcp 1251>nul");
    system("color F0");
    cout << "Работа с программой должна осуществляться строго в соответствии с инструкциями на экране.\nПри завершении ввода данных(строки) требуется нажать клавижу Enter.\nДо завершения работы программы данные нужно сохранить.\nЕсли данные не будут сохранены, в файле останутся последние сохранённые данные.\nВыход из программы должен осущечтвляться корректно через меню.\n\nСпасибо, что используете наш программный продукт!\n\n\n";
    int n = 0, key;
    char Text[] = "Text.txt",
        Name[ML], sym;

    Book book[100];
    ifstream reading(Text);

    for (int i = 0; i < 100; ++i) {
        book[i].author = NULL;
        book[i].name = NULL;
        book[i].ctd = NULL;
    }

    while (reading.peek() != EOF) {
        reading.getline(Name, ML);
        book[n].author = new char[strlen(Name) + 1];
        strcpy_s(book[n].author, strlen(Name) + 1, Name);
        reading.getline(Name, ML);
        book[n].name = new char[strlen(Name) + 1];
        strcpy_s(book[n].name, strlen(Name) + 1, Name);
        reading >> book[n].ctd;
        ++n;
    }
    reading.close();

    do {
        key = menu();
        if (key == 1) {
            print(book, n);
        }
        else if (key == 2) {
            change(book, n);
        }
        else if (key == 3) {
            del(book, n);
        }
        else if (key == 4) {
            add(book, n);
        }
        else if (key == 5) {
            sort(book, n);
        }
        else if (key == 0) {
            save(book, n, Text);
            cout << "\nРабота программы завершена. Все изменения сохранены в текстовом документе(Text.txt).\n";
            return 0;
        }
        else if (key == -1) {
            cout << "\nРабота программы завершена.\n";
        }
        else cout << "\nВведено неверное значение.";
    } while (key != 0 && key != -1);
}