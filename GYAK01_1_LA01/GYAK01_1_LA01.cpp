#include <iomanip>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

struct versenyzo {
    int rajtszam=0, suly=0, lokes=0, szakitas=0, osszesen=0;
    string nev;
};

int main()
{
    versenyzo versenyzok[15];
    int i = 0, negyszaz = 0, szazalatt = 0, letszam = 0;
    srand((unsigned)time(NULL));
    fstream file("nevek.txt");
    
    for ( i = 0; i < 15 && !file.eof(); i++)
    {
        file >> versenyzok[i].szakitas;
        file >> versenyzok[i].lokes;
        getline(file, versenyzok[i].nev);
        versenyzok[i].rajtszam = rand() % 89 + 10;
        versenyzok[i].osszesen = 
            versenyzok[i].szakitas + versenyzok[i].lokes;
        do{
            cout << "Adja meg a "<< versenyzok[i].nev << " versenyzo sulyat : ";
            cin >> versenyzok[i].suly;
            cin.ignore();

            if (versenyzok[i].suly < 95 || versenyzok[i].suly > 150)
            {
                cout << "A versenyzonek 95 es 150 kg kozott kell lennie" << endl;
            }
        } while (versenyzok[i].suly < 95 || versenyzok[i].suly > 150);
        letszam++;
    }
    file.close();

    // 1 feladat
    cout << "A vesenyen " << letszam << " versenyzo indult el!" << endl;


    // 3-4 feladat
    cout.setf(ios::right);
    for ( i = 0; i < letszam; i++)
    {
        cout << setw(20) << versenyzok[i].nev << "\t"
            << versenyzok[i].rajtszam << "\t"
            << versenyzok[i].osszesen << endl;
    }

    // 5 feladat
    for ( i = 0; i < letszam; i++)
    {
        if (versenyzok[i].osszesen > 400) {
            negyszaz++;
            cout << "\nA versenyzo " << versenyzok[i].nev << " emelt 400 kg felett!";
        }
        if (versenyzok[i].suly < 100)
        {
			szazalatt++;
		}
    }

    cout << "\nA versenyen " << negyszaz 
        << " versenyzo emelt 400 kg felett!" << endl;
    cout << szazalatt << " versenyzo van 100 kg alatt!" << endl;

    cout << "Az utolso versenyzo adatai: " 
        << versenyzok[letszam - 1].rajtszam 
        << versenyzok[letszam - 1].nev << endl;

    ofstream file2("eredmeny.txt");
    if (file2.is_open())
    {
        for (i = 0; i < letszam; i++) {
            file2 << versenyzok[i].rajtszam << "\t";
            file2 << versenyzok[i].nev << "\t";
            file2 << versenyzok[i].suly << "\t";
            file2 << versenyzok[i].osszesen << endl;

        }
		file2.close();
        cout << "A fajl irasa sikeres!" << endl;
	}
    else
    {
		cout << "Nem sikerult megnyitni a fajlt!" << endl;
	}


}
