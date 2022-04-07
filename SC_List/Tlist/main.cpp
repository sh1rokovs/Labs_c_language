#include <iostream>
#include <cstdlib>
#include "TList.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    TList list;
    int k = 1, v = 0, l = 0, p = 0;
    while (k)
    {
        system("cls");
        cout << "1. Создать список" << endl;
        cout << "2. Посмотреть список" << endl;
        cout << "3. Удалить элемент списка" << endl;
        cout << "4. Вставить элемент в список" << endl;
        cout << "5. Выход" << endl;
        cout << "-->|:";
        cin >> v;
        switch (v)
        {
        case 1:
        {
            system("cls");
            cout << "Введите количество элементов в списке\n:";
            cin >> l;
            for (int i = 0; i < l; i++)
            {
                cout << i+1 <<" элемент "<<"-->:";
                cin >> p;
                list.InsLast(p);
            }
            for (int i = 0; i < 100; i++) { cout << "-"; }
            cout << endl;
            for (int i = 0; i < list.GetSize(); i++)
            {
                if (i != l - 1)
                    cout << "[" << list[i] << "]" << " - ";
                else
                    cout << "[" << list[i] << "]";
            }
            cout << endl;
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            for (int i = 0; i < 100; i++) { cout << "-"; }
            cout << endl;
            for (int i = 0; i < list.GetSize(); i++)
            {
                if (i != list.GetSize() - 1)
                    cout << "[" << list[i] << "]" << " - ";
                else
                    cout << "[" << list[i] << "]";
            }
            cout << endl;
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "1. Удалить список" << endl;
            cout << "2. Удалить элемент в начале" << endl;
            cout << "3. Удалить определенный элемент" << endl;
            cout << "4. Удалить элемент в конце" << endl;
            cout << "5. Назад" << endl;
            cin >> v;
            switch (v)
            {
            case 1:
                list.clear();
                break;
            case 2:
                list.DelFirst();
                for (int i = 0; i < 100; i++) { cout << "-"; }
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != l - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                cout << endl;
                system("pause");
                break;
            case 3:
                cout << "Введите индекс удаляемого звена" << endl;
                cout << "-->:";
                cin >> p;
                list.DelElem(p);
                for (int i = 0; i < 100; i++) { cout << "-"; }
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != l - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                cout << endl;
                system("pause");
                break;
            case 4:
                list.DelLast();
                for (int i = 0; i < 100; i++) { cout << "-"; }
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != l - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                cout << endl;
                system("pause");
                break;
            case 5:
                break;
            }
            break;
        }
        case 4:
        {
            system("cls");
            cout << "1. Вставить в начало" << endl;
            cout << "2. Вставить элемент в произвольное место" << endl;
            cout << "3. Вставить в конец" << endl;
            cout << "4. Назад" << endl;
            cin >> v;
            switch (v)
            {
            case 1:
            {
                cout << "Элемент для вставки" << endl;
                cout << "-->:";
                cin >> p;
                cout << "Список до изменения:" << endl;
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != list.GetSize() - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                list.InsFirst(p);
                cout << endl;
                cout << "Список после изменения:" << endl;
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != list.GetSize() - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 2:
            {
                cout << "Элемент для вставки" << endl;
                cout << "-->:";
                cin >> p;
                cout << "Индекс для вставки" << endl;
                cout << "-->:";
                cin >> l;
                cout << "Список до изменения:" << endl;
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != list.GetSize() - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                list.InsElem(p, l);
                cout << endl;
                cout << "Список после изменения:" << endl;
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != list.GetSize() - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 3:
            {
                cout << "Элемент для вставки" << endl;
                cout << "-->:";
                cin >> p;
                cout << "Список до изменения:" << endl;
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != list.GetSize() - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                list.InsLast(p);
                cout << endl;
                cout << "Список после изменения:" << endl;
                cout << endl;
                for (int i = 0; i < list.GetSize(); i++)
                {
                    if (i != list.GetSize() - 1)
                        cout << "[" << list[i] << "]" << " - ";
                    else
                        cout << "[" << list[i] << "]";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 4:
                break;
            }
            break;
        }
        case 5:
            return k = 0;
            break;
        }
           

    }
}