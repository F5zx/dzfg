#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <limits>
#include <Windows.h>

using namespace std;

// Структура 
struct Contact {
    string name;
    string phone;
    string email;
};

//отображения меню


//добавления контакта
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "\nВведите имя: ";
    getline(cin >> ws, newContact.name);
    cout << "Введите телефон: ";
    getline(cin, newContact.phone);
    cout << "Введите email: ";
    getline(cin, newContact.email);

    contacts.push_back(newContact);
    cout << "Контакт добавлен!\n";
}

//отображения всех контактов
void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "\nСписок контактов пуст.\n";
        return;
    }

    cout << "\nСписок контактов:\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].name
            << ", " << contacts[i].phone
            << ", " << contacts[i].email << "\n";
    }
}

// удаления контакта
void deleteContact(vector<Contact>& contacts) {
    displayContacts(contacts);
    if (contacts.empty()) return;

    int index;
    cout << "Введите номер контакта для удаления: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(contacts.size())) {
        cout << "Неверный номер контакта!\n";
        return;
    }

    contacts.erase(contacts.begin() + index - 1);
    cout << "Контакт удален!\n";
}

//поиска контакта
void findContact(const vector<Contact>& contacts) {
    string searchTerm;
    cout << "\nВведите имя, телефон или email для поиска: ";
    getline(cin >> ws, searchTerm);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name.find(searchTerm) != string::npos ||
            contact.phone.find(searchTerm) != string::npos ||
            contact.email.find(searchTerm) != string::npos) {
            cout << "Найден контакт: " << contact.name
                << ", " << contact.phone
                << ", " << contact.email << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Контакты не найдены.\n";
    }
}

// изменения контакта
void editContact(vector<Contact>& contacts) {
    displayContacts(contacts);
    if (contacts.empty()) return;

    int index;
    cout << "Введите номер контакта для изменения: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(contacts.size())) {
        cout << "Неверный номер контакта!\n";
        return;
    }

    Contact& contact = contacts[index - 1];
    cout << "Текущие данные:\n";
    cout << "Имя: " << contact.name << "\n";
    cout << "Телефон: " << contact.phone << "\n";
    cout << "Email: " << contact.email << "\n";

    cout << "\nВведите новые данные (оставьте пустым, чтобы не изменять):\n";

    string input;
    cout << "Новое имя: ";
    getline(cin >> ws, input);
    if (!input.empty()) contact.name = input;

    cout << "Новый телефон: ";
    getline(cin, input);
    if (!input.empty()) contact.phone = input;

    cout << "Новый email: ";
    getline(cin, input);
    if (!input.empty()) contact.email = input;

    cout << "Контакт изменен!\n";
}

// сохранения контактов в файл
void saveToFile(const vector<Contact>& contacts, const string& filename = "contacts.txt") {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи!\n";
        return;
    }

    for (const auto& contact : contacts) {
        outFile << contact.name << "," << contact.phone << "," << contact.email << "\n";
    }

    outFile.close();
    cout << "Контакты сохранены в файл '" << filename << "'\n";
}

// загрузки контактов из файла
void loadFromFile(vector<Contact>& contacts, const string& filename = "contacts.txt") {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения!\n";
        return;
    }

    contacts.clear();
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            Contact contact;
            contact.name = line.substr(0, pos1);
            contact.phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
            contact.email = line.substr(pos2 + 1);
            contacts.push_back(contact);
        }
    }

    inFile.close();
    cout << "Контакты загружены из файла '" << filename << "'\n";
}

int main() 
{
    setlocale(LC_ALL, "");
}
