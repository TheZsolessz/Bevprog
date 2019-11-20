#include <iostream>		// mert olvassuk a std::cin, �rjuk a std::cout csatorn�kat
#include <cmath>		// mert vonunk gy�k�t a sz�r�shoz: std::sqrt
#include <fstream>		// f�jlb�l olvasunk, �runk majd
#include <vector>
#include <string>
#include "Csomopont.h"
#include "LZWBinFa.h"
using namespace std;

using std::vector;

// N�h�ny f�ggv�nyt az oszt�lydefin�ci� ut�n defini�lunk, hogy l�ssunk ilyet is ... :)
// Nem er�ltetj�k viszont a k�l�n f�jlba szed�st, mert a sablonoszt�lyos�tott tov�bb
// fejleszt�sben az linkel�si gondot okozna, de ez a t�ma m�r kivezet a laborteljes�t�s
// sz�ks�ges feladat�b�l: http://progpater.blog.hu/2011/04/12/imadni_fogjak_a_c_t_egy_emberkent_tiszta_szivbol_3

// Egy�bk�nt a melyseg, atlag �s szoras fgv.-ek a kiir fgv.-el teljesen egy kaptafa.

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
		// ez a postorder bej�r�shoz k�pest
		// 1-el nagyobb m�lys�g, ez�rt -1
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
	// alapj�n a parancssor argok ottani eleg�ns feldolgoz�s�b�l kb. ennyi marad:
	// "*((*++argv)+1)"...

	// a ki�r�s szerint ./lzwtree in_file -o out_file alakra kell mennie, ez 4 db arg:
	if (argc != 4)
	{
		// ha nem annyit kapott a program, akkor felhom�lyos�tjuk err�l a j�zetr:
		usage();
		// �s jelezz�k az oper�ci�s rendszer fel�, hogy valami g�z volt...
		return -1;
	}

	// "Megjegyezz�k" a bemen� f�jl nev�t
	char* inFile = *++argv;

	// a -o kapcsol� j�n?
	if (*((*++argv) + 1) != 'o')
	{
		usage();
		return -2;
	}

	// ha igen, akkor az 5. el�ad�sb�l kim�soljuk a f�jlkezel�s C++ v�ltozat�t:
	std::fstream beFile(inFile, std::ios_base::in);

	// fejlesztgetj�k a forr�st: http://progpater.blog.hu/2011/04/17/a_tizedik_tizenegyedik_labor
	if (!beFile)
	{
		std::cout << inFile << " nem letezik..." << std::endl;
		usage();
		return -3;
	}

	std::fstream kiFile(*++argv, std::ios_base::out);

	unsigned char b;		// ide olvassik majd a bej�v� f�jl b�jtjait
	LZWBinFa binFa;		// s nyomjuk majd be az LZW fa objektumunkba

	// a bemenetet bin�risan olvassuk, de a kimen� f�jlt m�r karakteresen �rjuk, hogy meg tudjuk
	// majd n�zni... :) l. az eml�tett 5. ea. C -> C++ gy�kkettes �t�r�si p�ld�it

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
		{			// �jsor
			kommentben = false;
			continue;
		}

		if (kommentben)
			continue;

		if (b == 0x4e)		// N bet�
			continue;

		// egyszer�en a kor�bbi d.c k�dj�t bem�soljuk
		// laboron t�bbsz�r lerajzoltuk ezt a bit-tologat�st:
		// a b-ben l�v� b�jt bitjeit egyenk�nt megn�zz�k
		for (int i = 0; i < 8; ++i)
		{
			// maszkolunk eddig..., most m�r sim�n �rjuk az if fej�be a legmagasabb helyi�rt�k� bit vizsg�lat�t
			// csupa 0 lesz benne a v�g�n pedig a vizsg�lt 0 vagy 1, az if megmondja melyik:
			if (b & 0x80)
				// ha a vizsg�lt bit 1, akkor az '1' bet�t nyomjuk az LZW fa objektumunkba
				binFa.insert('1');
			else
				// k�l�nben meg a '0' bet�t:
				binFa.insert('0');
			b <<= 1;
		}

	}

	//std::cout << binFa.kiir (); // �gy rajzolt ki a f�t a kor�bbi verzi�kban de, hogy izgalmasabb legyen
	// a p�lda, azaz ki lehessen tolni az LZWBinFa-t kimeneti csatorn�ra:

	kiFile << binFa;		// ehhez kell a glob�lis operator<< t�lterhel�se, l�sd fentebb
	// (j� ez az OO, mert mi ugye nem igaz�n erre gondoltunk, amikor �rtuk, m�gis megy, hurr�)

	kiFile << "depth = " << binFa.getMelyseg() << std::endl;
	kiFile << "mean = " << binFa.getAtlag() << std::endl;
	kiFile << "var = " << binFa.getSzoras() << std::endl;

	kiFile.close();
	beFile.close();

	return 0;
}