#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    static int generateId() {
        return ++globalId;
    }

    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};