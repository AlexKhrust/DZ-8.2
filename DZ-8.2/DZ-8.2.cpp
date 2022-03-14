#include <iostream>
#include <time.h>
using namespace std;

const int size1 = 4; //размер массива того что загадывает прога
const int size2 = 4; //размер массива того что загадывает человек
int arr1[size1], arr2[size2];   //создание массивов
int num, cow = 0, bull = 0;

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

    for (int i = 0; i < s1; i++) {  //КОСЯК ГДЕ-ТО ЗДЕСЬ
        for (int j = 0; j < s2; i++) {
            if ((a[i] == b[j])&&(i!=j)) bull++;
        }
    }
}

void game() {                       //тело игры
    cout << "Введите четырехзначное число: ";
    cin >> num;
    digits(arr2, size2, num);
    
    Count(arr1, size1, arr2, size2);

    cout << "Быков = " << bull << ", Коров = " << cow << endl;
}


void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    randNumber(arr1, size1);
    game();

  /*  for (int i = 0; i < size1; i++) {
        cout << arr2[i]<<" ";
    }*/
}