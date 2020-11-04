#ifndef ODA�SLEMLER�_H
#define ODA�SLEMLER�_H
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Oda {         //oda i�lemleri i�in de�erler tan�mlad�m
	string odaNo;
	string ucret;
}o;
struct Musteri {      //M��teri i�lemleri i�in de�erler tan�mlad�m
	string MusteriNo;
	string MusteriTC;
	string ad;
	string soyad;
}m;
struct OdaKayit        //oda kay�t  i�lemleri i�in de�erler tan�mlad�m
{
	string odano;
	string musterino;
	string odakayitno;
}ok;
void kayitEkle()			//oda kayd� yapmak i�in bir parametre olu�turdum oda isimli belge olu�turdum ve dosya ya kay�tlar� yazd�rd�m
{
	ofstream dosyaYaz;
	dosyaYaz.open("Oda.txt", ios::app);  //dosya yaz�lmak i�in a��ld�
	Oda oda;
	system("cls");
	cout << "Oda Numarasi :"; cin >> oda.odaNo;
	cout << "Ucret Girin :"; cin >> oda.ucret;
	dosyaYaz << oda.odaNo << "  " << oda.ucret << endl;
	dosyaYaz.close();  //dosya okuma kapat�ld�
} 
void MusterikayitEkle()		//m��teri kayd� yapmak i�in ayn� �ekilde parametre olu�turdum ve m�steri �isimli dosya olusturup i�ine m��teri bilgilerini yazd�m
{
	ofstream dosyaYaz;  
	dosyaYaz.open("Musteri.txt", ios::app);  //dosya yaz�lmak i�in a��ld�
	Musteri musteri;
	system("cls");
	cout << "MUsteri Numarasi :"; cin >> musteri.MusteriNo;
	cout << "MUsteri Adi :"; cin >> musteri.ad;
	cout << "MUsteri Soyadi :"; cin >> musteri.soyad;
	cout << "Musteri TC :"; cin >> musteri.MusteriTC;
	dosyaYaz << musteri.MusteriNo << "     " << musteri.ad << "     " << musteri.soyad << "     " << musteri.MusteriTC << endl;
	dosyaYaz.close();  //dosya okuma kapat�ld�
}
void kayitListele()   //oda kayitlarini okuttum ve listelettim
{
	ifstream dosyaOku;
	dosyaOku.open("Oda.txt");
	system("cls");
	Oda oda;
	cout << "Oda No         Ucret\n-------------------------\n";
	while (!dosyaOku.eof()) {
		dosyaOku >> oda.odaNo >> oda.ucret;
		cout << oda.odaNo << "               " << oda.ucret << endl;
	}
	system("Pause");
	dosyaOku.close(); //dosya okuma kapat�ld�
}
void MusterikayitListele()		//M�steri belgesini okutturdum ve listelettim
{
	ifstream dosyaOku;
	dosyaOku.open("Musteri.txt");
	system("cls");
	Musteri musteri;
	cout << "No     Ad   Soyad    TC       \n-------------------------\n";
	while (!dosyaOku.eof()) {
		dosyaOku >> musteri.MusteriNo >> musteri.ad >> musteri.soyad >> musteri.MusteriTC;
		cout << musteri.MusteriNo << "  " << musteri.ad << "   " << musteri.soyad << "   " << musteri.MusteriTC << endl;
}
	system("Pause");
	dosyaOku.close(); //dosya okuma kapat�ld�
}
void OdakayitEkle()		//oda kayd� i�lemleri i�in parametre olu�turdum ve odaKayit belgesine bunlar� yazd�rd�m
{
	ofstream dosyaYaz;
	dosyaYaz.open("OdaKayit.txt", ios::app);  //dosya yaz�lmak i�in a��ld�
	OdaKayit odakayit;
	system("cls");
	cout << "Oda Kayit Numarasi :"; cin >> odakayit.odakayitno;
	cout << "Oda Numarasi :"; cin >> odakayit.odano;
	cout << "Musteri No Girin :"; cin >> odakayit.musterino;
	dosyaYaz << odakayit.odakayitno << "  " << odakayit.odano << "  " << odakayit.musterino << endl;
	dosyaYaz.close();  //dosya okuma kapat�ld�
}
void OdakayitListele()	//odaKayit belgesini okutturdum 
{
	ifstream dosyaOku;
	dosyaOku.open("OdaKayit.txt");
	system("cls");
	OdaKayit odakayit;
	cout << "Oda Kayit No      Oda No      Musteri No\n-------------------------\n";
	while (!dosyaOku.eof()) {
		dosyaOku>> odakayit.odakayitno >> odakayit.odano >> odakayit.musterino;
		cout << odakayit.odakayitno<<"                  " << odakayit.odano << "               " << odakayit.musterino << endl;
	}
	system("Pause");
	dosyaOku.close(); //dosya okuma kapat�ld�
}
void OdakayitSil(string Odaka)
{
	int a;		//uzunlu�u k�yaslamak i�in atad���m de�er 
	string sil;
	string dosyaNo;
	ifstream dosyaOku;
	dosyaOku.open("OdaKayit.txt");
	system("cls");
	ofstream Sil("Sil.txt");
	while (getline(dosyaOku, sil)) { //dosyaOku stream'inden sil de�i�kenine satirlari okuttu
		if (Odaka.size() == 1) a = Odaka.size(); //girilen sayinin kac basamakli oldu�u kontrol edildi
		if (Odaka.size() == 2) a = Odaka.size() + 1;
		if (Odaka.size() == 3) a = Odaka.size() + 2;
		dosyaNo = sil.substr(0, a);// 0'dan a karakterine kadar satir okundu
		if (dosyaNo != Odaka) Sil << sil << endl; //girilen de�er ile okunan de�er karsilastirildi
	}
	system("Pause");
	Sil.close();	//sil dosyas� kapat�ld�
	dosyaOku.close();//dosyaokuma kapat�ld�
	remove("OdaKayit.txt"); //eski kayitlar silindi
	rename("Sil.txt", "OdaKayit.txt"); //yeni kayit dosyas�n�n adi, eski kayidin adiyla degistirildi
}
void MusterikayitSil(string musteri)
{
	int a;			//OdaKAyitSil deki i�lemlerin ayn�s� m��teri kayd� silmek i�in uyguland�
	string sil;
	string dosyaNo;
	ifstream dosyaOku;
	dosyaOku.open("Musteri.txt");
	system("cls");
	ofstream Sil("Sil.txt");
	while (getline(dosyaOku, sil)) {
		if (musteri.size() == 1) a = musteri.size();
		if (musteri.size() == 2) a = musteri.size() + 1;
		if (musteri.size() == 3) a = musteri.size() + 2;
		dosyaNo = sil.substr(0, a);
		if (dosyaNo != musteri) Sil << sil << endl;
	}
	system("Pause");
	Sil.close();     //sil dosyas� kapat�ld�	
	dosyaOku.close();   //dosyaokuma kapat�ld�
	remove("Musteri.txt");
	rename("Sil.txt", "Musteri.txt");
}
void OdaSil(string ooda)			//OdaKAyitSil deki i�lemlerin ayn�s� oda kayd� silmek i�in uyguland�
{
	int a;
	string sil;
	string dosyaNo;
	ifstream dosyaOku;
	dosyaOku.open("Oda.txt");
	system("cls");
	ofstream Sil("Sil.txt");
	while (getline(dosyaOku, sil)) {
		if (ooda.size() == 1) a = ooda.size();
		/*if (ooda.size() == 2) a = ooda.size() + 1;
		if (ooda.size() == 3) a = ooda.size() + 2;*/
		dosyaNo = sil.substr(0, a);
		if (dosyaNo != ooda) Sil << sil << endl;
	}
	system("Pause");
	Sil.close();
	dosyaOku.close();
	remove("Oda.txt");
	rename("Sil.txt", "Oda.txt");
}
#endif // !ODA�SLEMLER�_H

