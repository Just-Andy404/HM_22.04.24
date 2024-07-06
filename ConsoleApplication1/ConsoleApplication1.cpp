/*
Создайте шаблонный класс односвязного списка для
работы с целыми значениями. Нужно создать реализации для 
типичных операций над элементами:
■ AddToHead - добавление элемента в голову списка;
■ AddToTail() - добавление элемента в хвост списка;
■ DeleteFromHead() - удаление элемента из головы списка;
■ DeleteFromTail - удаление элемента из хвоста списка;
■ DeleteAll() - удаление всех элементов;
Show - вывод всех элементов списка на экран.
========================
Добавить в класс из задания 1 следующие функции: 
вставка элемента в заданную позицию, 
удаление элемента из заданной позиции, 
поиск заданного элемента (функция возвращает позицию найденного элемента в случае 
успеха или NULL в случае неудачи), 
поиск и замена заданного элемента (функция возвращает количество замененных
элементов в случае успеха или -1 в случае неудачи), 
переворачивание списка.
*/
#include <iostream>
#include "List.h"

using namespace std;

void displayMenu() {
    cout << "====================================================\n";
    cout << "Choose an option:\n";
    cout << "1. Add Node to Head\n";
    cout << "2. Add Node to Tail\n";
    cout << "3. Delete Node from Head\n";
    cout << "4. Delete Node from Tail\n";
    cout << "5. Display List\n";
    cout << "6. Add Node to Specific Position\n";
    cout << "7. Delete Node from Specific Position\n";
    cout << "8. Find Element\n";
    cout << "9. Change Element at Position\n";
    cout << "10. Reverse List\n";
    cout << "11. Clear List\n";
    cout << "0. Exit\n";
    cout << "====================================================\n";
}

int main() {
    List<Node> newList; // Initialize the list
    int choice, value, position;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter integer value for new Node: ";
            cin >> value;
            newList.addToHead(new Node(value));
            break;
        case 2:
            cout << "Enter integer value for new Node: ";
            cin >> value;
            newList.addToTail(new Node(value));
            break;
        case 3:
            newList.deleteFromHead();
            break;
        case 4:
            newList.deleteFromTail();
            break;
        case 5:
            newList.show();
            break;
        case 6:
            cout << "Enter integer value for new Node: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            newList.addToPosition(new Node(value), position);
            break;
        case 7:
            cout << "Enter position to delete: ";
            cin >> position;
            newList.deleteFromPosition(position);
            break;
        case 8:
            cout << "Enter value to find: ";
            cin >> value;
            cout << "Element position: " << newList.findElement(value) << endl;
            break;
        case 9:
            cout << "Enter position to change: ";
            cin >> position;
            newList.changeElement(position);
            break;
        case 10:
            newList.reverse();
            break;
        case 11:
            newList.deleteAll();
            break;
        case 0: 
            cout << "Goodbye!\n"; 
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
