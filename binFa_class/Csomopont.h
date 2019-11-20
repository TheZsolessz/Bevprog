#pragma once
class Csomopont
{
public:
	Csomopont(char b = '/') :betu(b), balNulla(0), jobbEgy(0)
	{
	};
	~Csomopont()
	{
	};
	// Aktuális csomópont, mondd meg nékem, ki a bal oldali gyermeked
	// (a C verzió logikájával mûxik ez is: ha nincs, akkor a null megy vissza)
	Csomopont* nullasGyermek() const
	{
		return balNulla;
	}
	// Aktuális csomópon,t mondd meg nékem, ki a jobb oldali gyermeked?
	Csomopont* egyesGyermek() const
	{
		return jobbEgy;
	}
	// Aktuális csomópont, ímhol legyen a "gy" mutatta csomópont a bal oldali gyereked!
	void ujNullasGyermek(Csomopont* gy)
	{
		balNulla = gy;
	}
	// Aktuális csomópont, ímhol legyen a "gy" mutatta csomópont a jobb oldali gyereked!
	void ujEgyesGyermek(Csomopont* gy)
	{
		jobbEgy = gy;
	}
	// Aktuális csomópont: Te milyen betût hordozol?
	// (a const kulcsszóval jelezzük, hogy nem bántjuk a példányt)
	char getBetu() const
	{
		return betu;
	}

private:
	// friend class LZWBinFa; /* mert ebben a valtozatban az LZWBinFa metódusai nem közvetlenül
	// a Csomopont tagjaival dolgoznak, hanem beállító/lekérdezõ üzenetekkel érik el azokat */

	// Milyen betût hordoz a csomópont
	char betu;
	// Melyik másik csomópont a bal oldali gyermeke? (a C változatból "örökölt" logika:
	// ha hincs ilyen csermek, akkor balNulla == null) igaz
	Csomopont* balNulla;
	Csomopont* jobbEgy;
	// nem másolható a csomópont (ökörszabály: ha van valamilye a szabad tárban,
	// letiltjuk a másoló konstruktort, meg a másoló értékadást)
	Csomopont(const Csomopont&); //másoló konstruktor
	Csomopont& operator= (const Csomopont&);
};