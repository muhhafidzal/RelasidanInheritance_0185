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

class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}

    void showAllMember(vector<Member> &members) {
        cout << "===== DAFTAR MEMBER =====" << endl;

        for (int i = 0; i < members.size(); i++) {
            cout << "ID     : " << members[i].getId() << endl;
            cout << "Nama   : " << members[i].getNama() << endl;
            cout << "Email  : " << members[i].getEmail() << endl;
            cout << "Status : "
                 << (members[i].getStatus() ? "Aktif" : "Nonaktif")
                 << endl;
            cout << "--------------------------" << endl;
        }
    }

    void toggleActivationMember(Member &member) {
        member.setStatus(!member.getStatus());
    }
};

int main() {

    // Membuat objek member
    Member m1("Hafidz", "hafidz@gmail.com");
    Member m2("Budi", "budi@gmail.com", false);

    // Membuat objek admin
    Admin admin("Super Admin", "admin@gmail.com");

    vector<Member> members = {m1, m2};

    // Menampilkan semua member
    admin.showAllMember(members);

    // Toggle status member pertama
    cout << "\nMengubah status member Hafidz...\n" << endl;
    admin.toggleActivationMember(members[0]);

    // Menampilkan ulang data member
    admin.showAllMember(members);

    // Menampilkan profile salah satu member
    members[0].showProfile();

    return 0;
}