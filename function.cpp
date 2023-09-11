#include "Header.h"

int menu() {
    int key;
    cout << "\n(1)Просмотр файла.\n";
    cout << "(2)Редактирование.\n";
    cout << "(3)Удаление.\n";
    cout << "(4)Добавление.\n";
    cout << "(5)Сортировка.\n";
    cout << "(0)Выход c сохранением.\n";
    cout << "(-1)Выход без сохранения.\n";
    cout << "\n\nВыберите один из пунктов меню: ";
    cin >> key;
    return key;
}


void print(Book* mas, int n) {
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            cout << "Номер " << i + 1 << ": ";
            cout << mas[i].author << " - ";
            cout << mas[i].name << " - ";
            cout << mas[i].ctd << '\n';
        }
    }
    else
        cout << "\nФайл пуст\n";
}


void change(Book* mas, int n) {
    char Name[ML];
    int newn;
    if (n > 0) {
        cout << "Введите номер строчки, которую хотите изменить.(от 1 до " << n << "): ";
        cin >> newn;
        newn--;
        if (newn >= 0 && newn < n) {
            cout << "\nКнига номер " << newn + 1 << ":\n";
            cout << "Введите автора: ";
            cin.get();
            cin.getline(Name, ML, '\n');
            mas[newn].author = new char[strlen(Name) + 1];
            strcpy_s(mas[newn].author, strlen(Name) + 1, Name);
            cout << "Введите название: ";
            cin.getline(Name, ML, '\n');
            mas[newn].name = new char[strlen(Name) + 1];
            strcpy_s(mas[newn].name, strlen(Name) + 1, Name);
            cout << "Введите количество экземпляров: ";
            cin >> mas[newn].ctd;
            cout << "\nДанные изменены!" << endl;
        }
        else
            cout << "Номер введён неверно!" << endl;
    }
    else cout << "\nФайл пуст!\n";

}


void del(Book* mas, int& n) {
    Book book;
    int newn;
    if (n > 0) {
        cout << "\nВведите номер строчки, которую хотите удалить.(от 1 до " << n << "): ";
        cin >> newn;
        newn--;
        if (newn >= 0 && newn < n) {
            mas[newn].author = NULL;
            mas[newn].name = NULL;
            mas[newn].ctd = NULL;
            n--;
            for (int i = newn; i < n; ++i) {
                book = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = book;
            }
            cout << "\nСтрочка удалена!\n";
        }
        else
            cout << "\nНомер введён неверно!\n";
    }
    else cout << "\nФайл пуст!\n";
}

void add(Book* mas, int& n) {
    char Name[ML];
    cout << "\nКнига номер " << n + 1 << ":\n";
    cout << "Введите автора: ";
    cin.get();
    cin.getline(Name, ML, '\n');
    mas[n].author = new char[strlen(Name) + 1];
    strcpy_s(mas[n].author, strlen(Name) + 1, Name);
    cout << "Введите название: ";
    cin.getline(Name, ML, '\n');
    mas[n].name = new char[strlen(Name) + 1];
    strcpy_s(mas[n].name, strlen(Name) + 1, Name);
    cout << "Введите количество экземпляров: ";
    cin >> mas[n].ctd;
    ++n;
    cout << "\nДанные успешно добавлены!\n";
}


void sort(Book* mas, int n) {
    Book vremen;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mas[i].ctd > mas[j].ctd) {
                    vremen = mas[j];
                    mas[j] = mas[i];
                    mas[i] = vremen;
                }

            }
        }
        cout << "Данные отсортированны по количеству экземпляров!" << endl;
    }
    else cout << "\nФайл пуст!\n";
}


void save(Book* mas, int n, const char* Text) {
    ofstream write(Text);
    for (int i = 0; i < n; ++i) {
        write << mas[i].author << '\n';
        write << mas[i].name << '\n';
        write << mas[i].ctd;
    }
    write.close();
}