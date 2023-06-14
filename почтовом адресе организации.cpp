//10.	Построить описание класса, содержащего информацию о почтовом адресеорганизации. 
//Предусмотреть возможность раздельного изменения составных частей адреса, создания и уничтожения объектов этого класса. 
//Написать программу, демонстрирующую работу с этим классом. 
//Программа должна содержать меню, позволяющее осуществить проверку всех методов класса.

#include <iostream>
#include <string>


using namespace std;

class PostalAddress {
private:
    string street;
    string city;
    string state;
    string postalCode;

public:
    PostalAddress(const string& _street, const string& _city, const string& _state, const string& _postalCode)
        : street(_street), city(_city), state(_state), postalCode(_postalCode) {}

    void setStreet(const string& _street) {
        street = _street;
    }

    void setCity(const string& _city) {
        city = _city;
    }

    void setState(const string& _state) {
        state = _state;
    }

    void setPostalCode(const string& _postalCode) {
        postalCode = _postalCode;
    }

    void display() const {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Postal Code: " << postalCode << endl;
    }
};

int main() {
    string street, city, state, postalCode;
    cout << "Enter the street: ";
    getline(cin, street);
    cout << "Enter the city: ";
    getline(cin, city);
    cout << "Enter the state: ";
    getline(cin, state);
    cout << "Enter the postal code: ";
    getline(cin, postalCode);

    PostalAddress address(street, city, state, postalCode);

    int choice;
    do {
        cout << "\n1. Change Street\n2. Change City\n3. Change State\n4. Change Postal Code\n5. Display Address\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Игнорирование символа новой строки после считывания числа

        switch (choice) {
            case 1: {
                cout << "Enter the new street: ";
                getline(cin, street);
                address.setStreet(street);
                cout << "Street changed successfully." << endl;
                break;
            }
            case 2: {
                cout << "Enter the new city: ";
                getline(cin, city);
                address.setCity(city);
                cout << "City changed successfully." << endl;
                break;
            }
            case 3: {
                cout << "Enter the new state: ";
                getline(cin, state);
                address.setState(state);
                cout << "State changed successfully." << endl;
                break;
            }
            case 4: {
                cout << "Enter the new postal code: ";
                getline(cin, postalCode);
                address.setPostalCode(postalCode);
                cout << "Postal code changed successfully." << endl;
                break;
            }
            case 5: {
                cout << "\nPostal Address:" << endl;
                address.display();
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
