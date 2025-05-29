#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <vector>



using namespace std;


struct StAirInfo
{

	string UcakKodu;
	string HavaYolu;
	string Nereden;
	string Nereye;
	string KisiBBH;
	int YolcuK=120;
	float Fiyat;
	string GidisTarihi;
	string Kalkis;
	string VarisTarihi;
	string VarisS;
	char Koltuklar[20][6];
	int YolcuSayisi = 0;
	int ToplamBagajSayisi = 0;
	float ToplamBagajAgirligi=0;


};

vector <string> Vsplit(string delim, string record)
{

	short pos = 0;
	string words = "";
	vector <string> theWords;

	while ((pos = record.find(delim)) != std::string::npos)
	{
		words = record.substr(0, pos);
		//if (words != "")
		//{
		theWords.push_back(words);
		//}

		record.erase(0, pos + delim.length());

	}
	if (record != "")
	{
		theWords.push_back(record);
	}
	return theWords;
}
string ToupperAllString(string upper)
{
	for (short i = 0; i < upper.length(); i++)
	{
		upper[i] = toupper(upper[i]);
	}
	return upper;

}
short ReadValideNumber2()
{
	short Num;
	cout << "Lutfen ne yapmak istediginizi secin [1 - 3 arasi]: ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nLutfen bu numaralardan birini secin!!!  [1 to 3] :";
		cin >> Num;
		cin.ignore();
	}
	return Num;

}
short ReadValideNumber()
{
	short Num;
	cout << "Lutfen ne yapmak istediginizi secin [1 - 6 arasi]: ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nLutfen bu numaralardan birini secin!!!  [1 to 6] :";
		cin >> Num;
		cin.ignore();
	}
	return Num;

}

class ClsYolcu
{

public:

	struct StYolcu
	{
		string Ad;
		string Soyad;
		string Nereden;
		string Nereye;
		string GidisT;
		string DogumT;
		string Telefon;
		string Tc;
		string UcakKodu;
		string Seat;
		int Bagaj;

	};

	
	void KoltukHaritasi(char Koltuklar[20][6])
	{
		cout << "\t\t\t\t\t\tKoltuk Haritasi " << endl;
		cout << "\t\t\t_______________________________________________________________\n";

		cout << "\n\t\t\t\t\t  A   B   C        D   E   F\n" << endl;

		for (short i = 0; i < 20; i++)
		{
			for (short J = 0; J < 6; J++)
			{
				
				if (J == 0)
				{
					cout << "\t\t\t\t     " << setw(3) << left << i + 1 << " [";
				}
				cout << Koltuklar[i][J];
				if (J != 5)
				{
					cout << "   ";
				}
				if (J == 2)
					cout << "     ";
				if (J == 5)
				{
					cout << "]" ;
				}
			}

			cout << endl;
		}

		cout << "\t\t\t_______________________________________________________________\n";


	}

	short ConvertSeat(char S)
	{
		switch (toupper(S))
		{
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'F':
			return 5;

		default:
			return -1;
			break;
		}
	}
	void SavePassengerInfoToFile(string Line)
	{
		fstream File;
		File.open("PassengerInfo.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << Line << endl;
			File.close();
		}
	}
	string ConvertPassengerInfoToLine(StYolcu Pas, string Sp = "#//#")
	{
		string Line = Pas.Ad + Sp +Pas.Soyad + Sp +Pas.Nereden + Sp +Pas.Nereye + Sp +Pas.GidisT + Sp +
			Pas.DogumT + Sp +Pas.Telefon + Sp +Pas.Tc + Sp +Pas.UcakKodu + Sp +Pas.Seat + Sp +to_string(Pas.Bagaj);
		return Line;
	}
	void SavePas(StYolcu Pas)
	{
		string Line = ConvertPassengerInfoToLine(Pas);
		SavePassengerInfoToFile(Line);
	}
	void ShowTicket(StYolcu Pas, StAirInfo Air)
	{
		
		cout << "\n\n\t\t\t==============================================================\n";
		cout << "\t\t\t\t\t\tUCUS BILETI\n";
		cout << "\t\t\t==============================================================\n";
		cout << "\t\t\tYolcu Adi Soyadi : " << Pas.Ad << " " << Pas.Soyad << endl;
		cout << "\t\t\tTC Kimlik No     : " << Pas.Tc << endl;
		cout << "\t\t\tTelefon          : " << Pas.Telefon << endl;
		cout << "\t\t\tDogum Tarihi     : " << Pas.DogumT << endl;
		cout << "\t\t\t_______________________________________________________________\n";
		cout << "\t\t\tUcus Kodu        : " << Air.UcakKodu << endl;
		cout << "\t\t\tHavayolu         : " << Air.HavaYolu << endl;
		cout << "\t\t\tNereden          : " << Air.Nereden << endl;
		cout << "\t\t\tNereye           : " << Air.Nereye << endl;
		cout << "\t\t\tGidis Tarihi     : " << Air.GidisTarihi << endl;
		cout << "\t\t\tKalkis Saati     : " << Air.Kalkis << endl;
		cout << "\t\t\tVaris Saati      : " << Air.VarisS << endl;
		cout << "\t\t\tKoltuk No        : " << Pas.Seat << endl;
		cout << "\t\t\tBagaj (kg)       : " << Pas.Bagaj << " kg" << endl;
		cout << "\t\t\tBagaj Hakki      : " << Air.KisiBBH << endl;
		cout << "\t\t\tBilet Fiyati     : " << Air.Fiyat << " TL" << endl;
		cout << "\t\t\t==============================================================\n";
		cout << "\t\t\t\t\t  Iyi Yolculuklar!\n";
		cout << "\t\t\t==============================================================\n";
	}

	bool  IsSeatAvailable(char Seats[20][6], string Choice)
	{
		
		int row = stoi(Choice.substr(0, Choice.find("\\"))); 

		int col = ConvertSeat(Choice.back()); 

		if (row >= 1 && row <= 20 && col != -1 && Seats[row - 1][col] == 'U')
			return true;

		return false;

	}
	void TakeSeat(char Seats[20][6], string Choice)
	{

		int row = stoi(Choice.substr(0, Choice.find("\\")));

		int col = ConvertSeat(Choice.back());

		Seats[row - 1][col] = 'X';
		

	}
	void AddPassenger(StYolcu &Pas,StAirInfo &Air)
	{	
		string Choice;
		cout << "\n\t\t\t===============================================================\n";
		cout << "\t\t\t\t\t       Yolcu Bilgileri \n";
		cout << "\n\t\t\tAd : ";
		getline(cin,Pas.Ad);

		cout << "\t\t\tSoyad : ";
		getline(cin, Pas.Soyad);

		cout << "\t\t\tDogum Tarihi (YYYY\\AA\\GG) : ";
		getline(cin, Pas.DogumT);

		cout << "\t\t\tTc Kimlik No : ";
		getline(cin, Pas.Tc);
		
		cout << "\t\t\tCep Telefonu : ";
		getline(cin,Pas.Telefon);

		Pas.Bagaj = 10;
		Pas.UcakKodu = Air.UcakKodu;

		cout << "\n\t\t\t_______________________________________________________________\n";
		
		KoltukHaritasi(Air.Koltuklar);
		bool Check = 1;

		
		do
		{
			if (Check==0)
			{
				cout << "\n\t\t\t[X] Koltuk uygun degil ya da gecersiz !!!\n";

			}
			cout << "\t\t\tKoltuk Secinz (Ornek 13\\B) : ";
			getline(cin, Choice);
			Check = 0;

		} while (!IsSeatAvailable(Air.Koltuklar, Choice));
		Pas.Seat = Choice;
		TakeSeat(Air.Koltuklar, Choice);
		ShowTicket(Pas, Air);
		SavePas(Pas);
	}

	StYolcu ConvertPassengerInfoToRecord(string Line)
	{
		StYolcu yolcu;
		vector <string> parts = Vsplit("#//#", Line);

		yolcu.Ad = parts[0];
		yolcu.Soyad = parts[1];
		yolcu.Nereden = parts[2];
		yolcu.Nereye = parts[3];
		yolcu.GidisT = parts[4];
		yolcu.DogumT = parts[5];
		yolcu.Telefon = parts[6];
		yolcu.Tc = parts[7];
		yolcu.UcakKodu = parts[8];
		yolcu.Seat = parts[9];
		yolcu.Bagaj = stoi(parts[10]);

		return yolcu;


	}
	vector <StYolcu> LoadYolcuFromFile()
	{
		vector <StYolcu> Yolcular;
		ifstream File;
		
		File.open("PassengerInfo.txt", ios::in);

		string line;
		while (getline(File, line))
		{
			Yolcular.push_back(ConvertPassengerInfoToRecord(line));
		}

		File.close();
		return Yolcular;
	}
	void YolcuSatiriYaz(StYolcu yolcu)
	{
		string tamIsim = yolcu.Ad + " " + yolcu.Soyad;

		cout << "\t\t\t|" << setw(20) << left << tamIsim;
		cout << "|" << setw(12) << left << yolcu.Nereden;
		cout << "|" << setw(12) << left << yolcu.Nereye;
		cout << "|" << setw(8) << left << yolcu.Seat;
		cout << "|" << setw(10) << left << yolcu.UcakKodu << "|\n";
	}

	void YolcuListesiBaslik()
	{
		cout << "\t\t\t\t\t==============================================" << endl;
		cout << "\t\t\t\t\t\t\t   Yolcu Listesi\n";
		cout << "\t\t\t\t\t==============================================\n";
	}

	void YolcuListesiGoruntule()
	{
		string tarih, ucakKodu;
		YolcuListesiBaslik();
		cout << "\t\t\tUcak kodunu giriniz: ";
		getline(cin >> ws, ucakKodu);

		cout << "\t\t\tUcus tarihini giriniz (YYYY/AA/GG): ";
		getline(cin >> ws, tarih);

		vector <StYolcu> Yolcular = LoadYolcuFromFile(); 
		

		cout << "\n\t\t\t_____________________________________________________________________________________\n";
		cout << "\t\t\t|Isim                |Nereden     |Nereye      |Koltuk  |Ucak Kodu |\n";
		cout << "\t\t\t_____________________________________________________________________________________\n";

		bool bulundu = false;
		for (StYolcu y : Yolcular)
		{
			if (y.UcakKodu == ucakKodu && y.GidisT == tarih)
			{
				YolcuSatiriYaz(y);
				bulundu = true;
			}
		}

		if (!bulundu)
		{
			cout << "|\t\t\tKayit Bulunamadı...\t\t\t|\n";
		}

		cout << "\t\t\t_____________________________________________________________________________________\n";
	}





};


class Ucak:public ClsYolcu
{
private:


public:
	

	void KoltukOlustur(StAirInfo&Koltuk)
	{
	
		for (short i = 0; i < 20; i++)
		{
			for (short J = 0; J < 6; J++)
			{
				Koltuk.Koltuklar[i][J] = 'U';
			}
		}

	}

	string ConvertSeatsToLine(char Seat[20][6])
	{
		string Seats="";

		for (short i = 0; i < 20; i++)
		{
			for (short A = 0; A < 6; A++)
			{
				Seats += Seat[i][A];
			}
		}
		return Seats;
	}

	void ConvertLineToSeats(string Seates, char Seate[20][6])
	{
	
		short Count = 0;


		for (short i = 0; i < 20; i++)
		{
			for (short A = 0; A < 6; A++)
			{
		
				Seate[i][A] = Seates[Count];
				Count++;
			}
		}

	
	}


	string ConvertAirInfoToLine(StAirInfo Bu,string Sp="#//#")
	{
		string Seats=ConvertSeatsToLine(Bu.Koltuklar);
		string Ucak;
		Ucak = Bu.UcakKodu + Sp + Bu.HavaYolu + Sp + Bu.Nereden + Sp + Bu.Nereye + Sp + Bu.KisiBBH + Sp + to_string(Bu.Fiyat)
			+ Sp + Bu.GidisTarihi + Sp + Bu.Kalkis + Sp + Bu.VarisTarihi + Sp + Bu.VarisS + Sp + to_string(Bu.YolcuK)+Sp+
			to_string(Bu.YolcuSayisi)+Sp+to_string(Bu.ToplamBagajSayisi)+Sp+to_string(Bu.ToplamBagajAgirligi)+Sp+Seats;
		return Ucak;
	}

	void SaveAirInfoToFile(string Line)
	{
		fstream AirFile;

		AirFile.open("AirInfo.txt", ios::out |ios::app);

		if (AirFile.is_open())
		{
			AirFile << Line << endl;
		}
		AirFile.close();

	}

	StAirInfo ConvertAirLineToRecord(string Line)
	{
		vector <string> Info;
		Info = Vsplit("#//#", Line);

		StAirInfo Record;
		Record.UcakKodu = Info[0];
		Record.HavaYolu = Info[1];
		Record.Nereden = Info[2];
		Record.Nereye = Info[3];
		Record.KisiBBH = Info[4];
		Record.Fiyat = stoi(Info[5]);
		Record.GidisTarihi = Info[6];
		Record.Kalkis = Info[7];
		Record.VarisTarihi = Info[8];
		Record.VarisS = Info[9];
		Record.YolcuK = stoi(Info[10]);
		Record.YolcuSayisi = stoi(Info[11]);
		Record.ToplamBagajSayisi = stoi(Info[12]);
		Record.ToplamBagajAgirligi = stof(Info[13]);
		ConvertLineToSeats(Info[14], Record.Koltuklar);

		return Record;
		

	}

	vector <StAirInfo> LoadAirDataFromFile()
	{
		fstream UFile;
		string AirLine;
		vector <StAirInfo> AirRecord;
		UFile.open("AirInfo.txt", ios::in);

		if (UFile.is_open())
		{
			while (getline(UFile,AirLine))
			{
				AirRecord.push_back(ConvertAirLineToRecord(AirLine));
			}

		}
		return AirRecord;

	}

	void Save(StAirInfo Ucak)
	{
		string Line=ConvertAirInfoToLine(Ucak);

		SaveAirInfoToFile(Line);

	}

	void UpdateAfterR(StAirInfo Ucak)
	{
		vector <StAirInfo> Records = LoadAirDataFromFile(); 
		fstream File;

		File.open("AirInfo.txt", ios::out);
		if (File.is_open())
		{
			for (StAirInfo Rec : Records)
			{
				if (Rec.UcakKodu == Ucak.UcakKodu)
				{
					File << ConvertAirInfoToLine(Ucak) << endl;
				}
				else
				{
					File << ConvertAirInfoToLine(Rec) << endl;
				}
			}
			File.close();
		}
	}

	void AddAieHeader()
	{
		cout << "==============================================" << endl;
		cout << "\t\tUcak Ekle\n";
		cout << "==============================================" << endl;
	}

	bool IsFlightCodeExist(string AirCode)
	{
		vector <StAirInfo> Airs = LoadAirDataFromFile();
		for (StAirInfo A:Airs)
		{
			if (AirCode==A.UcakKodu)
			{
				return false;
			}
		}
		return true;
	}

	void AddAir()
	{
	
		StAirInfo Ucak1;
		bool Check = 0;

		do
		{
			system("cls");
			AddAieHeader();
			if (Check==1)
			{
				cout << "\nBu ucak kodu zaten mevcut. Lutfen farkli bir kod girin.\n";
			}
			cout << "\nUcak Kodu Giriniz : ";
			getline(cin, Ucak1.UcakKodu);
			Check = 1;
		} while (!IsFlightCodeExist(Ucak1.UcakKodu));
		


		cout << "\nHavayolu Giriniz : ";
		getline(cin, Ucak1.HavaYolu);

		cout << "\nUcak Nereden Kalkack : ";
		getline(cin, Ucak1.Nereden);

		cout << "\nUcak Nereye Gidecek : ";
		getline(cin, Ucak1.Nereye);


		cout << "\nBir Yolcunun Bagaj Hakki Giriniz : ";
		getline(cin, Ucak1.KisiBBH);
		
		cout << "\nBilet Fiyati Giriniz : ";
		cin >> Ucak1.Fiyat;
		cin.ignore();

		cout << "\nGidis Tarihi Girinz : ";
		getline(cin, Ucak1.GidisTarihi);

		cout << "\nKalkis Saati Girinz : ";
		getline(cin, Ucak1.Kalkis);

		cout << "\nVaris Tarihi Girinz : ";
		getline(cin, Ucak1.VarisTarihi);
	
		cout << "\nVaris Saati Girinz : ";
		getline(cin, Ucak1.VarisS);

		KoltukOlustur(Ucak1);


		Save(Ucak1);
		cout << "\n-----------------------------------------------\n";
		cout << "\t  { Ucus basariyla eklendi }";
		cout << "\n-----------------------------------------------\n";

		cout << endl << endl;

	}

	void KoltukHaritasi(char Koltuklar[20][6])
	{
		
		cout << "\t\t|________________________________________|\n" ;
		cout  << "\t\t|\t   A  B  C      D  E  F"<< setw(12) << right << "|\n" ;
		for (short i = 0; i < 20; i++)
		{
			for (short J = 0; J < 6; J++)
			{
				//Koltuklar[i][J] = 'U';
				if (J == 0)
				{
					cout << "\t\t|   " << setw(3) << left << i + 1 << "   [";
				}
				cout << Koltuklar[i][J];
				if (J != 5)
				{
					cout << "  ";
				}
				if (J == 2)
					cout << "    ";
				if (J == 5)
				{
					cout << "]" << setw(10) <<right<<"|";
				}
			}
			
			cout << endl;
		}
		cout << "\t\t \\______________________________________/\n";


	}


	
	void UcakBilgileri(StAirInfo Ucak)
	{
		cout << "|" << setw(6) << left << Ucak.UcakKodu;
		cout << "|" << setw(10) << left << Ucak.HavaYolu;
		cout << "|" << setw(10) << left << Ucak.Nereden;
		cout << "|" << setw(10) << left << Ucak.Nereye;
		cout << "|" << setw(11) << left << Ucak.KisiBBH;
		cout << "|" << setw(9) << left << Ucak.Fiyat;
		cout << "|" << setw(12) << left << Ucak.GidisTarihi;
		cout << "|" << setw(6) << left << Ucak.Kalkis;
		cout << "|" << setw(12) << left << Ucak.VarisTarihi;
		cout << "|" << setw(9) << left << Ucak.VarisS<<endl;
	}

	void Ucuslarheaders()
	{
		cout << "\t\t\t\t\t==============================================" << endl;
		cout << "\t\t\t\t\t\t\t   Ucuslar\n";
		cout << "\t\t\t\t\t==============================================" << endl;
	}

	void ShowFlights()
	{
		vector <StAirInfo> Ucaklar = LoadAirDataFromFile();
		Ucuslarheaders();

		cout << "\n___________________________________________________________________";
		cout << "___________________________________________________________________\n\n";
		cout << "|U.Kodu|Havayolu  |Nereden   |Nereye    |Bagaj Hakki|Fiyat(TL)|Gidis Tarihi|Kalkis|Varis Tarihi|Varis Saati\n";
		cout << "___________________________________________________________________";
		cout << "___________________________________________________________________\n\n";
		for (StAirInfo S:Ucaklar)
		{
			UcakBilgileri(S);

		}
		cout << "___________________________________________________________________";
		cout << "___________________________________________________________________\n\n";
	}


	void AirDetail(StAirInfo Air)
	{
	
		cout << "\t\t    //_______________________________\\\\\n";
		cout << "\t\t  .'          UCUS BILGILERI           '.\n";
		cout << "\t\t /______________________________________\\\n";
		cout << "\t\t| Uçak Kodu   : " << setw(25) << left << Air.UcakKodu << "|\n";
		cout << "\t\t| Havayolu    : " << setw(25) << left << Air.HavaYolu << "|\n";
		cout << "\t\t| Nereden     : " << setw(25) << left << Air.Nereden << "|\n";
		cout << "\t\t| Nereye      : " << setw(25) << left << Air.Nereye << "|\n";
		cout << "\t\t| Bagaj Hakki : " << setw(25) << left << Air.KisiBBH << "|\n";
		cout << "\t\t| Fiyat (TL)  : " << setw(25) << left << Air.Fiyat << "|\n";
		cout << "\t\t| Gidis Tarihi: " << setw(25) << left << Air.GidisTarihi << "|\n";
		cout << "\t\t| Kalkis      : " << setw(25) << left << Air.Kalkis << "|\n";
		cout << "\t\t| Varis Tarihi: " << setw(25) << left << Air.VarisTarihi << "|\n";
		cout << "\t\t| Varis Saati : " << setw(25) << left << Air.VarisS << "|\n";
		cout << "\t\t \\______________________________________/\n";
		cout << "\t\t\t \\_____KOLTUKLAR_____/ \n";

		KoltukHaritasi(Air.Koltuklar);
	}
	void FlightDetailHeader()
	{
		cout << "==============================================" << endl;
		cout << "\t\tUcus Detayi\n";
		cout << "==============================================" << endl;

	}
	void FlightDetail()
	{
		FlightDetailHeader();
		string UcakK = "";
		string GidisTarihi="";
		cout << "\nLutfen Ucak Kodu Giriniz : ";
		getline(cin, UcakK);

		cout << "\nGidis Tarihi Giriniz {YYYY\\MM\\DD} : ";
		getline(cin, GidisTarihi);
		cin.ignore();

		vector <StAirInfo> Airs = LoadAirDataFromFile();

		for (StAirInfo S: Airs)
		{
			if (S.UcakKodu== UcakK && S.GidisTarihi== GidisTarihi)
			{
				AirDetail(S);
				return;
			}
		}
		
		cout << "\t{Ucus bulunamadi. Bilgileri kontrol edin.}\n\n\n";
		
	

	}

	void ReservationFlight(StAirInfo Flight)
	{
		cout << "\t\t\t|" << setw(6) << left <<Flight.UcakKodu;
		cout << "|" << setw(15) << left << Flight.HavaYolu;
		cout << "|" << setw(10) << left << Flight.KisiBBH;
		cout << "|" << setw(16) << left << Flight.Kalkis+" --> "+Flight.VarisS;
		cout << "|" << setw(5) << left << Flight.Fiyat<<endl;

	}
	vector <StAirInfo> ChooseFlight(string Nereden,string Nereye,string GidisT)
	{
		vector <StAirInfo> Ucaklar = LoadAirDataFromFile();

		cout << "\n\t\t\t_______________________________________________________________\n";
		cout << "\t\t\t|U. No |Havayolu       |Bagaj     |    Kalkis      |Fiyat (TL)      " << endl;
		cout << "\t\t\t_______________________________________________________________\n";

		vector < StAirInfo> ThisDayFlights;

		for (StAirInfo S : Ucaklar)
		{
			if (ToupperAllString(S.Nereden)== ToupperAllString(Nereden) && ToupperAllString(S.Nereye)== ToupperAllString(Nereye)&& S.GidisTarihi == GidisT)
			{
				ThisDayFlights.push_back(S);
				ReservationFlight(S);
			}
		
		}
		cout << "\t\t\t_______________________________________________________________\n";

		return ThisDayFlights;
	}
	void ReservationHeader()
	{
		
		cout << "\t\t\t===============================================================" << endl;
		cout << "\t\t\t\t\t       Rezervasyon Menusu\n";
		cout << "\t\t\t===============================================================" << endl;
		
	}
	void MakeaReservation()
	{
		ReservationHeader();
		string UcusNo;
		vector <StAirInfo> Flights;

		StYolcu Yolcu;
		cout << "\n\t\t\tNereden : ";
		getline(cin ,Yolcu.Nereden);
	
		cout << "\n\t\t\tNereye : ";
	   getline(cin, Yolcu.Nereye);
	
		cout << "\n\t\t\tGidis Tarihi : ";
		getline(cin, Yolcu.GidisT);

	   cout << "\n\t\t\tNereden : " + Yolcu.Nereden + "------> Nereye : " + Yolcu.Nereye + "  |Gidis Tarihi : " + Yolcu.GidisT<<endl;
	   Flights=ChooseFlight(Yolcu.Nereden,Yolcu.Nereye,Yolcu.GidisT);

	   if (!Flights.empty())
	   {
		  
		cout << "\n\t\t\tUcus No giriniz : ";
		cin >> UcusNo;
		cin.ignore();

		for (StAirInfo &S: Flights)
		{
			if (S.UcakKodu==UcusNo)
			{
				AddPassenger(Yolcu,S);
				UpdateAfterR(S);
				return;
			}
		}
	   }
	   else
	   {
		   cout << "\n\t\t\t\tUygun ucus bulunamadi. Lutfen tekrar deneyin.\n";
		   cout << "\t\t\t_______________________________________________________________\n";
	   }
	

	}

	void AirMainMenu()
	{
		cout << "=============================================="<<endl;
		cout << "\t\tUcus Yonetim Menusu\n";
		cout << "=============================================="<<endl;
		cout << "\t\t[1] Ucak Ekle\n";
		cout << "\t\t[2] Ucus Detayi\n";
		cout << "\t\t[3] Ucuslar Goruntule\n";
		cout << "\t\t[4] Rezervasyon Yap\n";
		cout << "\t\t[5] Yolcu Listesi\n";
		cout << "\t\t[6] Sistemden Cikis\n";
		cout << "==============================================" << endl;
		
	}

	void GoBackToAirMenu()
	{
		cout<<"\nUcus Yonetim Menusune donmek icin herhangi bir tusa basin...";
		system("pause>0");
	}


	void Admin()
	{
		short Secenek;
	
		do
		{
			system("cls");
			system("color 0F");
			AirMainMenu();
			Secenek = ReadValideNumber();
			cin.ignore();
			switch (Secenek)
			{
			case 1:
				system("cls");
				AddAir();
				GoBackToAirMenu();
				break;
			case 2:
				system("cls");
				FlightDetail();
				GoBackToAirMenu();
				break;
			case 3:
				system("cls");
				ShowFlights();
				GoBackToAirMenu();
				break;
			case 4:
				system("cls");
				MakeaReservation();
				GoBackToAirMenu();
				break;
			case 5:
				system("cls");
				YolcuListesiGoruntule();
				GoBackToAirMenu();
				break;


			default:
				break;
			}

		} while (Secenek!=6);
		return;
	}
	


};



void Havaalani()
{
	Ucak Test;

	short Sec = 1;

	do
	{
		system("cls");
		system("color 0F");
		cout << "==================================================\n";
		cout << "\tHAVAALANI REZERVASYON SISTEMI\n";
		cout << "==================================================\n";
	
		cout << "\t\t[1] Yonetici Girisi (Admin)\n";
		cout << "\t\t[2] Yolcu Rezervasyonu\n";
		cout << "\t\t[3] Cikis\n";
		cout << "==================================================\n";

		Sec = ReadValideNumber2();
		switch (Sec)
		{
		case 1:
			system("cls");
			system("color 0F");
			Test.Admin();
			break;
		case 2:
			system("cls");
			system("color 0F");
			cin.ignore();
			Test.MakeaReservation();
			break;
		default:
			break;
		}

	} while (Sec !=3);
	
	

}

int main()
{
	
	
	Havaalani();

	
	return 0;

}

