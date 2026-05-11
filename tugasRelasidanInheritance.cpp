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

// Inisialisasi static variable
int User::globalId = 0;

class Member : public User {
private:
    bool status;

public:
    Member(string nama, string email, bool status = true)
        : User(nama, email) {
        this->status = status;
    }

    void showProfile() {
        cout << "===== PROFILE MEMBER =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << endl;
    }

    void setStatus(bool status) {
        this->status = status;
    }

    bool getStatus() {
        return status;
    }
};