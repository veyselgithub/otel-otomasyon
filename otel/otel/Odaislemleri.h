#ifndef ODAÝSLEMLERÝ_H
#define ODAÝSLEMLERÝ_H
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Oda {         //oda iþlemleri için deðerler tanýmladým
	string odaNo;
	string ucret;
}o;
struct Musteri {      //Müþteri iþlemleri için deðerler tanýmladým
	string MusteriNo;
	string MusteriTC;
	string ad;
	string soyad;
}m;
struct OdaKayit        //oda kayýt  iþlemleri için deðerler tanýmladým
{
	string odano;
	string musterino;
	string odakayitno;
}ok;
void kayitEkle()			//oda kaydý yapmak için bir parametre oluþturdum oda isimli belge oluþturdum ve dosya ya kayýtlarý yazdýrdým
{
	ofstream dosyaYaz;
	dosyaYaz.open("Oda.txt", ios::app);  //dosya yazýlmak için açýldý
	Oda oda;
	system("cls");
	cout << "Oda Numarasi :"; cin >> oda.odaNo;
	cout << "Ucret Girin :"; cin >> oda.ucret;
	dosyaYaz << oda.odaNo << "  " << oda.ucret << endl;
	dosyaYaz.close();  //dosya okuma kapatýldý
} 
void MusterikayitEkle()		//müþteri kaydý yapmak için ayný þekilde parametre oluþturdum ve müsteri ýisimli dosya olusturup içine müþteri bilgilerini yazdým
{
	ofstream dosyaYaz;  
	dosyaYaz.open("Musteri.txt", ios::app);  //dosya yazýlmak için açýldý
	Musteri musteri;
	system("cls");
	cout << "MUsteri Numarasi :"; cin >> musteri.MusteriNo;
	cout << "MUsteri Adi :"; cin >> musteri.ad;
	cout << "MUsteri Soyadi :"; cin >> musteri.soyad;
	cout << "Musteri TC :"; cin >> musteri.MusteriTC;
	dosyaYaz << musteri.MusteriNo << "     " << musteri.ad << "     " << musteri.soyad << "     " << musteri.MusteriTC << endl;
	dosyaYaz.close();  //dosya okuma kapatýldý
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
	dosyaOku.close(); //dosya okuma kapatýldý
}
void MusterikayitListele()		//Müsteri belgesini okutturdum ve listelettim
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
	dosyaOku.close(); //dosya okuma kapatýldý
}
void OdakayitEkle()		//oda kaydý iþlemleri için parametre oluþturdum ve odaKayit belgesine bunlarý yazdýrdým
{
	ofstream dosyaYaz;
	dosyaYaz.open("OdaKayit.txt", ios::app);  //dosya yazýlmak için açýldý
	OdaKayit odakayit;
	system("cls");
	cout << "Oda Kayit Numarasi :"; cin >> odakayit.odakayitno;
	cout << "Oda Numarasi :"; cin >> odakayit.odano;
	cout << "Musteri No Girin :"; cin >> odakayit.musterino;
	dosyaYaz << odakayit.odakayitno << "  " << odakayit.odano << "  " << odakayit.musterino << endl;
	dosyaYaz.close();  //dosya okuma kapatýldý
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
	dosyaOku.close(); //dosya okuma kapatýldý
}
void OdakayitSil(string Odaka)
{
	int a;		//uzunluðu kýyaslamak için atadýðým deðer 
	string sil;
	string dosyaNo;
	ifstream dosyaOku;
	dosyaOku.open("OdaKayit.txt");
	system("cls");
	ofstream Sil("Sil.txt");
	while (getline(dosyaOku, sil)) { //dosyaOku stream'inden sil deðiþkenine satirlari okuttu
		if (Odaka.size() == 1) a = Odaka.size(); //girilen sayinin kac basamakli olduðu kontrol edildi
		if (Odaka.size() == 2) a = Odaka.size() + 1;
		if (Odaka.size() == 3) a = Odaka.size() + 2;
		dosyaNo = sil.substr(0, a);// 0'dan a karakterine kadar satir okundu
		if (dosyaNo != Odaka) Sil << sil << endl; //girilen deðer ile okunan deðer karsilastirildi
	}
	system("Pause");
	Sil.close();	//sil dosyasý kapatýldý
	dosyaOku.close();//dosyaokuma kapatýldý
	remove("OdaKayit.txt"); //eski kayitlar silindi
	rename("Sil.txt", "OdaKayit.txt"); //yeni kayit dosyasýnýn adi, eski kayidin adiyla degistirildi
}
void MusterikayitSil(string musteri)
{
	int a;			//OdaKAyitSil deki iþlemlerin aynýsý müþteri kaydý silmek için uygulandý
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
	Sil.close();     //sil dosyasý kapatýldý	
	dosyaOku.close();   //dosyaokuma kapatýldý
	remove("Musteri.txt");
	rename("Sil.txt", "Musteri.txt");
}
void OdaSil(string ooda)			//OdaKAyitSil deki iþlemlerin aynýsý oda kaydý silmek için uygulandý
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
#endif // !ODAÝSLEMLERÝ_H

