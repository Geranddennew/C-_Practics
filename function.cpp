#include "Header.h"

int menu() {
    int key;
    cout << "\n(1)�������� �����.\n";
    cout << "(2)��������������.\n";
    cout << "(3)��������.\n";
    cout << "(4)����������.\n";
    cout << "(5)����������.\n";
    cout << "(0)����� c �����������.\n";
    cout << "(-1)����� ��� ����������.\n";
    cout << "\n\n�������� ���� �� ������� ����: ";
    cin >> key;
    return key;
}


void print(Book* mas, int n) {
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            cout << "����� " << i + 1 << ": ";
            cout << mas[i].author << " - ";
            cout << mas[i].name << " - ";
            cout << mas[i].ctd << '\n';
        }
    }
    else
        cout << "\n���� ����\n";
}


void change(Book* mas, int n) {
    char Name[ML];
    int newn;
    if (n > 0) {
        cout << "������� ����� �������, ������� ������ ��������.(�� 1 �� " << n << "): ";
        cin >> newn;
        newn--;
        if (newn >= 0 && newn < n) {
            cout << "\n����� ����� " << newn + 1 << ":\n";
            cout << "������� ������: ";
            cin.get();
            cin.getline(Name, ML, '\n');
            mas[newn].author = new char[strlen(Name) + 1];
            strcpy_s(mas[newn].author, strlen(Name) + 1, Name);
            cout << "������� ��������: ";
            cin.getline(Name, ML, '\n');
            mas[newn].name = new char[strlen(Name) + 1];
            strcpy_s(mas[newn].name, strlen(Name) + 1, Name);
            cout << "������� ���������� �����������: ";
            cin >> mas[newn].ctd;
            cout << "\n������ ��������!" << endl;
        }
        else
            cout << "����� ����� �������!" << endl;
    }
    else cout << "\n���� ����!\n";

}


void del(Book* mas, int& n) {
    Book book;
    int newn;
    if (n > 0) {
        cout << "\n������� ����� �������, ������� ������ �������.(�� 1 �� " << n << "): ";
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
            cout << "\n������� �������!\n";
        }
        else
            cout << "\n����� ����� �������!\n";
    }
    else cout << "\n���� ����!\n";
}

void add(Book* mas, int& n) {
    char Name[ML];
    cout << "\n����� ����� " << n + 1 << ":\n";
    cout << "������� ������: ";
    cin.get();
    cin.getline(Name, ML, '\n');
    mas[n].author = new char[strlen(Name) + 1];
    strcpy_s(mas[n].author, strlen(Name) + 1, Name);
    cout << "������� ��������: ";
    cin.getline(Name, ML, '\n');
    mas[n].name = new char[strlen(Name) + 1];
    strcpy_s(mas[n].name, strlen(Name) + 1, Name);
    cout << "������� ���������� �����������: ";
    cin >> mas[n].ctd;
    ++n;
    cout << "\n������ ������� ���������!\n";
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
        cout << "������ �������������� �� ���������� �����������!" << endl;
    }
    else cout << "\n���� ����!\n";
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