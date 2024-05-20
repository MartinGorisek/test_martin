#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct Ucenik
{
    char ImePrezime[50];
    float prosjek;
};

bool cmp(Ucenik &a, Ucenik &b)
{
    return a.prosjek > b.prosjek;
}

int main()
{
    struct Ucenik ucenici[100];
    int brUcenika = 0;
    fstream datoteka1("C:/Users/Ga-gama/Documents/GitHub/test_martin/data.bin", ios::binary | ios::in);

    while (datoteka1.read((char *)&ucenici[brUcenika], sizeof(Ucenik)))
    {
        cout << ucenici[brUcenika].ImePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }
    datoteka1.close();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(ucenici[brUcenika + i].ImePrezime, 50);
        cin >> ucenici[brUcenika].prosjek;
    }
    sort(ucenici, ucenici + brUcenika + n, cmp);

    fstream datoteka2("C:/Users/Ga-gama/Documents/GitHub/test_martin/data.bin", ios::binary | ios::out | ios::trunc);
    datoteka2.write((char *)ucenici, sizeof(Ucenik) * (brUcenika + n));
    datoteka2.close();
    return 0;
}