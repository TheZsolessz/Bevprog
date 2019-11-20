#include <iostream>		// mert olvassuk a std::cin, írjuk a std::cout csatornákat
#include <cmath>		// mert vonunk gyököt a szóráshoz: std::sqrt
#include <fstream>		// fájlból olvasunk, írunk majd
#include <vector>
#include <string>
#include "Csomopont.h"
#include "LZWBinFa.h"
using namespace std;

using std::vector;

// Néhány függvényt az osztálydefiníció után definiálunk, hogy lássunk ilyet is ... :)
// Nem erõltetjük viszont a külön fájlba szedést, mert a sablonosztályosított tovább
// fejlesztésben az linkelési gondot okozna, de ez a téma már kivezet a laborteljesítés
// szükséges feladatából: http://progpater.blog.hu/2011/04/12/imadni_fogjak_a_c_t_egy_emberkent_tiszta_szivbol_3

// Egyébként a melyseg, atlag és szoras fgv.-ek a kiir fgv.-el teljesen egy kaptafa.

int
LZWBinFa::getMelyseg(void)
{
	melyseg = maxMelyseg = 0;
	rmelyseg(&gyoker);
	return maxMelyseg - 1;
}

double
LZWBinFa::getAtlag(void)
{
	melyseg = atlagosszeg = atlagdb = 0;
	ratlag(&gyoker);
	atlag = ((double)atlagosszeg) / atlagdb;
	return atlag;
}

double
LZWBinFa::getSzoras(void)
{
	atlag = getAtlag();
	szorasosszeg = 0.0;
	melyseg = atlagdb = 0;

	rszoras(&gyoker);

	if (atlagdb - 1 > 0)
		szoras = std::sqrt(szorasosszeg / (atlagdb - 1));
	else
		szoras = std::sqrt(szorasosszeg);

	return szoras;
}

void
LZWBinFa::rmelyseg(Csomopont* elem)
{
	if (elem != NULL)
	{
		++melyseg;
		if (melyseg > maxMelyseg)
			maxMelyseg = melyseg;
		rmelyseg(elem->egyesGyermek());
		// ez a postorder bejáráshoz képest
		// 1-el nagyobb mélység, ezért -1
		rmelyseg(elem->nullasGyermek());
		--melyseg;
	}
}

void
LZWBinFa::ratlag(Csomopont* elem)
{
	if (elem != NULL)
	{
		++melyseg;
		ratlag(elem->egyesGyermek());
		ratlag(elem->nullasGyermek());
		--melyseg;
		if (elem->egyesGyermek() == NULL && elem->nullasGyermek() == NULL)
		{
			++atlagdb;
			atlagosszeg += melyseg;
		}
	}
}

void
LZWBinFa::rszoras(Csomopont* elem)
{
	if (elem != NULL)
	{
		++melyseg;
		rszoras(elem->egyesGyermek());
		rszoras(elem->nullasGyermek());
		--melyseg;
		if (elem->egyesGyermek() == NULL && elem->nullasGyermek() == NULL)
		{
			++atlagdb;
			szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));
		}
	}
}

void
usage(void)
{
	std::cout << "Usage: lzwtree in_file -o out_file" << std::endl;
}

int
main(int argc, char* argv[])
{
	// http://progpater.blog.hu/2011/03/12/hey_mikey_he_likes_it_ready_for_more_3
	// alapján a parancssor argok ottani elegáns feldolgozásából kb. ennyi marad:
	// "*((*++argv)+1)"...

	// a kiírás szerint ./lzwtree in_file -o out_file alakra kell mennie, ez 4 db arg:
	if (argc != 4)
	{
		// ha nem annyit kapott a program, akkor felhomályosítjuk errõl a júzetr:
		usage();
		// és jelezzük az operációs rendszer felé, hogy valami gáz volt...
		return -1;
	}

	// "Megjegyezzük" a bemenõ fájl nevét
	char* inFile = *++argv;

	// a -o kapcsoló jön?
	if (*((*++argv) + 1) != 'o')
	{
		usage();
		return -2;
	}

	// ha igen, akkor az 5. elõadásból kimásoljuk a fájlkezelés C++ változatát:
	std::fstream beFile(inFile, std::ios_base::in);

	// fejlesztgetjük a forrást: http://progpater.blog.hu/2011/04/17/a_tizedik_tizenegyedik_labor
	if (!beFile)
	{
		std::cout << inFile << " nem letezik..." << std::endl;
		usage();
		return -3;
	}

	std::fstream kiFile(*++argv, std::ios_base::out);

	unsigned char b;		// ide olvassik majd a bejövõ fájl bájtjait
	LZWBinFa binFa;		// s nyomjuk majd be az LZW fa objektumunkba

	// a bemenetet binárisan olvassuk, de a kimenõ fájlt már karakteresen írjuk, hogy meg tudjuk
	// majd nézni... :) l. az említett 5. ea. C -> C++ gyökkettes átírási példáit

	while (beFile.read((char*)& b, sizeof(unsigned char)))
		if (b == 0x0a)
			break;

	bool kommentben = false;

	while (beFile.read((char*)& b, sizeof(unsigned char)))
	{

		if (b == 0x3e)
		{			// > karakter
			kommentben = true;
			continue;
		}

		if (b == 0x0a)
		{			// újsor
			kommentben = false;
			continue;
		}

		if (kommentben)
			continue;

		if (b == 0x4e)		// N betû
			continue;

		// egyszerûen a korábbi d.c kódját bemásoljuk
		// laboron többször lerajzoltuk ezt a bit-tologatást:
		// a b-ben lévõ bájt bitjeit egyenként megnézzük
		for (int i = 0; i < 8; ++i)
		{
			// maszkolunk eddig..., most már simán írjuk az if fejébe a legmagasabb helyiértékû bit vizsgálatát
			// csupa 0 lesz benne a végén pedig a vizsgált 0 vagy 1, az if megmondja melyik:
			if (b & 0x80)
				// ha a vizsgált bit 1, akkor az '1' betût nyomjuk az LZW fa objektumunkba
				binFa.insert('1');
			else
				// különben meg a '0' betût:
				binFa.insert('0');
			b <<= 1;
		}

	}

	//std::cout << binFa.kiir (); // így rajzolt ki a fát a korábbi verziókban de, hogy izgalmasabb legyen
	// a példa, azaz ki lehessen tolni az LZWBinFa-t kimeneti csatornára:

	kiFile << binFa;		// ehhez kell a globális operator<< túlterhelése, lásd fentebb
	// (jó ez az OO, mert mi ugye nem igazán erre gondoltunk, amikor írtuk, mégis megy, hurrá)

	kiFile << "depth = " << binFa.getMelyseg() << std::endl;
	kiFile << "mean = " << binFa.getAtlag() << std::endl;
	kiFile << "var = " << binFa.getSzoras() << std::endl;

	kiFile.close();
	beFile.close();

	return 0;
}