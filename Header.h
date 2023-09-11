#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#define ML 128

struct Book
{
    char* author;
    char* name;
    int ctd;
};

int menu();
void print(Book*, int n);
void change(Book*, int);
void del(Book*, int&);
void add(Book*, int&);
void sort(Book*, int);
void save(Book*, int, const char*);

