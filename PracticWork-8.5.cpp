#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    string name;
    cout << "Как тебя зовут? ";
    cin >> name;
    cin.ignore(100, '\n');
    cout << "Привет " << name << "! ";
    int distance;
    do {
        cout << "Сколько километров ты пробежал сегодня? ";        
        cin >> distance;
        cin.ignore(100, '\n');
        if (distance < 1) cout << "Ошибка!!! Введите не отрицательное значение!\n";
    } while (distance < 1);
    int time = 0;
    int min;
    int sec;
    char clear;
    for (int i = 1; i <= distance; i++) {
        start:
        cout << "Укажите время в формате (минуты,секунды)\n";
        cout << "Какое время у тебя было на " << i << " километре? ";
        cin >> min >> clear >> sec;
        cin.ignore(100, '\n');
        if (min < 0 || sec < 0 || sec > 59) {
            cout << "Ошибка ввода!\n";
            goto start;
        }
        time += min * 60 + sec;
        //cout << time << endl;
    }
    cout << "Итого\n";
    int tempMin = (time / distance) / 60;
    int tempSec = (time / distance) % 60;
    cout << name << "Твой темп: " << tempMin << ending(tempMin, 109) << " " << tempSec << ending(tempSec, 115) << endl;


    return 0;
}