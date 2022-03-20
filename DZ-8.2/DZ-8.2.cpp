#include <iostream>
#include <time.h>
using namespace std;

const int size1 = 4; //размер массива того что загадывает прога
const int size2 = 4; //размер массива того что загадывает человек
int arr1[size1], arr2[size2];   //создание массивов
int num, cow = 0, bull = 0, proba=0;

int randNumber(int a[], int b) {    //заполнение массива числа от компа
    for (int i = 0; i < b; i++) {
        a[i] = rand() % 10;
    }
    return 0;
}

int digits(int a[], int b, int n) { //заполнение массива числом введенным пользователем
    for (int i = 3; i >= 0; i--) {
        a[i] = n % 10;
        n /= 10;
    }
    return 0;
}

void Count(int a[], int s1, int b[], int s2) {
    for (int i = 0; i < s1; i++) {
        if (a[i] == b[i]) cow++;
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            if ((a[i] == b[j]) && (i!=j)) bull++;
        }
    }
    if (bull > 4) bull = 4; // Да! Заплатка б@$ть!
}

void game() {                       //тело игры
    cout << "Введите четырехзначное число: ";
    cin >> num;
    digits(arr2, size2, num);
    
    Count(arr1, size1, arr2, size2);

    cout << "Быков = " << bull << ", Коров = " << cow << endl;
    proba++;                        //счетчик попыток
    if (cow == 4) { 
        cout << "OK!\n";
        cout << "Вы победили после " << proba << " попыток." << endl;
    }
    else {
        cow = 0;                    //обнуление счетчиков коров и быков
        bull = 0;                   //чтобы при след. рекурсии они не суммировались
        game();
    }
}


void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    randNumber(arr1, size1);
    
    for (int i = 0; i < size1; i++) {
        cout << arr1[i]<<" ";
    }
    game();
}

/*Задание
Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий
должен угадать его. После ввода пользователем числа программа сообщает, сколько цифр числа
угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). После отгадывания
числа на экран необходимо вывести количество сделанных пользователем попыток. В
программе необходимо использовать рекурсию.*/