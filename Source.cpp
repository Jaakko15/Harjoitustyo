#include <iostream>
#include <random>
#include <string>
using namespace std;
int main();

// Luodaan varaaja huoneelle.
struct varaaja {

	string kokonimi;
	string osoite;
	string kaupunki;
	string postikoodi;
	string sposti;
	string puhelinNumero;
	string tulopaiva;
	int yot; // y�t


};

// Funktio varauksien tarkasteluun
void tarkasteleVarauksia(int& varausnumero, varaaja& v, int& huoneenhinta, int& huone) {

	system("cls");
	int toiminto2{};
	cout << "Sy�tt�k�� varausnumeronne! " << endl;
	int uusivarausnumero;
	cin >> uusivarausnumero;
	// Vertaillaan k�ytt�j�n sy�tt�m�� varausnumeroa funktioon parametrin� tuotua varausnumeroa.. Jos oikein, n�ytt�� se k�ytt�j�n varauksen.
	if (uusivarausnumero == varausnumero) {
		cout << "Varauksenne l�ytyi!" << endl;
		cout << v.kokonimi << endl;
		cout << v.osoite << endl;
		cout << v.kaupunki << endl;
		cout << v.postikoodi << endl;
		cout << v.puhelinNumero << endl;
		cout << "--------------------" << endl;
		cout << "Kirajutumisp�iv�nne:" << v.tulopaiva << endl;
		cout << "Varatut y�t: " << v.yot << endl;
		cout << "Hinta: " << huoneenhinta * v.yot << " euroa." << endl;
		cout << "Huone numero: " << huone << endl;
		cout << "-------------------------" << endl;
		cout << "1. P��valikko" << endl;

		cin >> toiminto2;

		switch (toiminto2) {
		case 1:
			main();
		}

	}
	else
		cout << "Varaustanne ei l�ytynyt! " << endl;
	cout << endl;
	main();

}
// Funktio huoneen varaukseen, parametrit structistam ja varausnumero.
void varaahuone(varaaja& v, int& varausnumero, int& huoneenhinta) {
	int haluttuhuone;
	int low = 10000, high = 99999; //M��rittelee varausnumeron rajat
	//arpoo varausnumeron v�lil�t 10000-99999
	srand(static_cast<unsigned int>(time(nullptr)));
	varausnumero = (rand() % (high - low + 1)) + low;
	bool virhe;
	// Laskee kokonaishinnan n y�lle.
	int kokonaishinta = 0;
	kokonaishinta = huoneenhinta * v.yot;


	//arpoo huoneet v�lilt� 30-70
	random_device rd;
	uniform_int_distribution<int> dist(30, 70);
	//Kertoo paljonko huoneita on
	cout << "Vapaita huoneita on: " << dist(rd) << endl;
	while (true) {
		cout << "Mink� huoneen haluaisitte?: " << endl;
		//Looppissa verrataan k�ytt�j�n valitsemaa huonetta huoneiden m��r��n ja ilmoitetaan onko huone vapaana
		cin >> haluttuhuone;
		// Tarkistaa ettei k�ytt�j� sy�t� kirjaimia, joka bugaa ohjelman!
		if (cin.fail())
		{
			cout << "Virheellinen sy�te! Sy�tt�k�� numeroita!" << endl;
			virhe = true;
			cin.clear();
			cin.ignore(80, '\n');




		}

		else if (haluttuhuone < dist(rd)) {
			cout << "Huone on vapaana. Olette varanneet huoneen: " << haluttuhuone << endl;
			break;
		}
		else if (haluttuhuone > dist(rd)) {
			cout << "Huone on varattu. Valitkaa uusi huone: " << endl;

		}

	}
	// Kysyt��n k�ytt�j�n tietoja ja tallennetaan ne structiin

	cout << "Varausnumeronne on: " << varausnumero << endl;
	cout << "Kirjautumisp�iv�nne? " << endl;
	cin >> v.tulopaiva;
	cout << "Kuinka monta y�t� haluatte varata?" << endl;
	cin >> v.yot;
	cout << "Sy�tt�k�� kokonimenne: " << endl;
	cin >> ws;
	getline(cin, v.kokonimi);
	cout << "Sy�tt�k�� osoitteenne: " << endl;
	getline(cin, v.osoite);
	cout << "Sy�tt�k�� kaupunki: " << endl;
	cin >> v.kaupunki;
	cout << "Sy�tt�k�� postinumeronne: " << endl;
	cin >> v.postikoodi;
	cout << "Sy�tt�k�� puhelinnumeronne: " << endl;
	cin >> v.puhelinNumero;
	cout << "Huoneen hinta " << v.yot << " y�lle on: " << huoneenhinta * v.yot << endl;;
	cout << "-------------------------------------------------------" << endl;
	cout << "KIITOS TIETONNE OVAT TALLENTUNEET TIETOJ�RJESTELM��MME!" << endl;
	int toiminto1;
	cout << "-------------------------------------------------------" << endl;
	cout << "1. P��valikko:" << endl;
	cout << "2. Varaa uusi huone:" << endl;
	cout << "3. Tarkastele varauksiasi:" << endl;
	cin >> toiminto1;

	switch (toiminto1) {
	case 1:
		main();
	case 2:
		varaahuone(v, varausnumero, huoneenhinta);

	case 3:
		tarkasteleVarauksia(varausnumero, v, huoneenhinta, haluttuhuone);

	}


}




int main() {
	setlocale(LC_ALL, "fi_FI");
	// arpoo huoneen hinnan v�lilt� 70 - 100
	int huone{};
	int huoneenhinta = 0;
	bool virhe;
	int ala = 70, yl� = 100;
	srand(static_cast<unsigned int>(time(nullptr)));
	huoneenhinta = (rand() % (yl� - ala + 1)) + ala;
	random_device yd;
	uniform_int_distribution<int> dist(70, 100);
	// -------------------------------------------
	varaaja v;
	int varausnumero{};
	int toiminto;
	do
	{
		virhe = false;
		cout << "TERVETULOA JAAKON HOTELLIIN!" << endl;
		cout << endl;
		cout << endl;
		cout << "-------------------------" << endl;
		cout << "Antakaa luku v�lilt� 1-3: " << endl;
		cout << "1. Varaa huone:" << endl;
		cout << "2. Tarkastele varauksia:" << endl;
		cout << "3. Lopeta ohjelma: " << endl;
		cout << "-------------------------" << endl;
		cin >> toiminto;
		switch (toiminto) {
		case 1:
			varaahuone(v, varausnumero, huoneenhinta);
			break;
		case 2:
			tarkasteleVarauksia(varausnumero, v, huoneenhinta, huone);
			break;
		case 3:
			cout << "N�kemiin!";
			break;


		}// tarkistaa ettei k�ytt�j� sy�t� kirjaimia joka lopettaa ohjelman!!!
		if (cin.fail())
		{
			cout << "Virhe. Anna luku uudestaan!" << endl;
			virhe = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (virhe);
	return 0;
}







