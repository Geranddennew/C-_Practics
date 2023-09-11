#include "Header.h"

int main() {
    system("chcp 1251>nul");
    system("color F0");
    cout << "������ � ���������� ������ �������������� ������ � ������������ � ������������ �� ������.\n��� ���������� ����� ������(������) ��������� ������ ������� Enter.\n�� ���������� ������ ��������� ������ ����� ���������.\n���� ������ �� ����� ���������, � ����� ��������� ��������� ���������� ������.\n����� �� ��������� ������ �������������� ��������� ����� ����.\n\n�������, ��� ����������� ��� ����������� �������!\n\n\n";
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
            cout << "\n������ ��������� ���������. ��� ��������� ��������� � ��������� ���������(Text.txt).\n";
            return 0;
        }
        else if (key == -1) {
            cout << "\n������ ��������� ���������.\n";
        }
        else cout << "\n������� �������� ��������.";
    } while (key != 0 && key != -1);
}