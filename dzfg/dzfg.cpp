#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void displayMenu() {
    cout << "\nМеню управления контактами:\n";
    cout << "1. Добавить контакт\n";
    cout << "2. Удалить контакт\n";
    cout << "3. Найти контакт\n";
    cout << "4. Изменить контакт\n";
    cout << "5. Показать все контакты\n";
    cout << "6. Сохранить в файл\n";
    cout << "7. Загрузить из файла\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}
int main() {
    vector<Contact> contacts;
    int choice;
    setlocale(LC_ALL, "");
    cout << "Программа управления контактами\n";

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            deleteContact(contacts);
            break;
        case 3:
            findContact(contacts);
            break;
        case 4:
            editContact(contacts);
            break;
        case 5:
            displayContacts(contacts);
            break;
        case 6:
            saveToFile(contacts);
            break;
        case 7:
            loadFromFile(contacts);
            break;
        case 0:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}