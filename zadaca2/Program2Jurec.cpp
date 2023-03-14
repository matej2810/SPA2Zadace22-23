#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Database {
    Database(int k);

    vector<bool> ct;

    int h1(const string& str);
    int h2(const string& str);
    int h3(const string& str);
    int h4(const string& str);

    void insert(const string& username);
    string search(const string &username);
};

Database::Database(int n) {
    ct.resize(n, false);
}

int Database::h1(const string &str) {
    int l = ct.size();
    unsigned long long suma = 0;

    for (int i = 0; i < str.size(); i++)
        suma += str[i] % l;

    return suma % l;
}

int Database::h2(const string &str) {
    int l = ct.size();
    unsigned long long suma = 0;

    for (int i = 0; i < str.size(); i++)
        suma += (str[i] * int(pow(19, i))) % l;

    return (1 + suma) % l;
}

int Database::h3(const string &str) {
    int l = ct.size();
    unsigned long long suma = 0;

    for (int i = 0; i < str.size(); i++)
        suma += (str[i] * int(pow(30, i))) % l;

    return (7 + suma) % l;
}

int Database::h4(const string &str) {
    int l = ct.size();
    unsigned long long suma = 0;

    for (int i = 0; i < str.size(); i++)
        suma += (str[i] * int(pow(3, i)) * int(pow(7, i))) % l;

    return (3 + suma) % l;
}


string Database::search(const string &user) {
    string fejl = "Elem not in table";
    string uspjeh = "Elem maybe in table";

    if (!ct[h1(user)])
        return fejl;
    if (!ct[h2(user)])
        return fejl;
    if (!ct[h3(user)])
        return fejl;
    if (!ct[h4(user)])
        return fejl;

    return uspjeh;
}

void Database::insert(const string &user) {
    ct[h1(user)] = true;
    ct[h2(user)] = true;
    ct[h3(user)] = true;
    ct[h4(user)] = true;
}


int main() {
    Database db(100);

    vector<string> names = {
            "jopis107", "hstranput", "Matej293", "MateaCucman", "JosipCestar",
            "lanamak", "DanijelaValjak", "filipuranjek", "domagojziros", "lsanic",
            "TomislavVinkovic", "IvoSusac", "matej2810", "KresimirSecan",
            "inespejic", "InesSimunovic", "IvanFrantal", "Frle001", "inesstrapac",
            "mkolak", "Dpritisa", "istvavk", "mtoldi", "lbrodar5", "mkristic",
            "andreamatasovic", "balentovicanja", "IvanaVinkovic", "prakidzija",
            "DMV1204", "JMesaric", "KarloKampic", "jurick1910", "LarisaDarojkovic"
    };

    for (auto name : names)
        db.insert(name);


    cout << db.search("MatejJurec") << endl;
    cout << db.search("matej2810") << endl;
    cout << db.search("ces") << endl;
    cout << db.search("JosipCestar") << endl;
    cout << db.search("IvoSuly") << endl;
    cout << db.search("IvoSusac") << endl;
    cout << db.search("Mrgud") << endl;



    return 0;
}