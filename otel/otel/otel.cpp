/**************************************************************************
**								SAKARYA ÜNİVERSİTESİ
**						BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**						BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ
**								PROGRAMLAMAYA GİRİŞ	DERSİ
**									2017-2018 GÜZ DÖNEMİ
**
**							ÖDEV NUMARASI.........: 5
**							ÖĞRENCİ ADI...........: VEYSEL DOĞAN
**							ÖĞRENCİ NUMARASI......: b171200041
**							DERSİN ALINDIĞI GRUP..: A GRUBU
****************************************************************************/

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Odaislemleri.h"
using namespace std;

	int main()
	{
		int secim;  //ana menüden seçim yaptıracak tanım
		int secim2;  //alt menüden seçim yaptıracak tanım
		do
		{
			do {			//ana ekran menüsü oluşturdum
				system("cls");
				cout << "Otel İslemleri\n";
				cout << "1-Oda islemleri" << endl;
				cout << "2-Musteri islemleri" << endl;
				cout << "3-Oda Kayit islemleri" << endl;
				cout << "99-Cikis" << endl;
				cout << "Seciminiz :";
				cin >> secim;
				system("Cls");
				switch (secim)
				{
				case 1:  //1.seçenek seçildiği zaman çıkacak menüyü oluşturdum
					cout << "1-Oda ekle" << endl;
					cout << "2-Oda Sil" << endl;
					cout << "3-Odalari Listele" << endl;
					cout << "99-Ust Menu" << endl;
					cout << "Seciminiz :";
					cin >> secim2;
					switch (secim2)
					{
					case 1:kayitEkle(); break;		//alt menü başlıklarındaki işlemler yapıldı
					case 99:break;
					case 2:cout << "Silmek istediginiz Oda No :"; cin >>o.odaNo;
						OdaSil(o.odaNo); break;
					case 3:kayitListele(); break;
					default:cout << "Hatali Secim" << endl; //belirtilenlerin dışında değer seçilirse uyarı mesajı 
						system("pause");
						break;
					}
					break;
				case 2:		//2.seçenek seçildiği zaman çıkacak menüyü oluşturdum
					cout << "1-Musteri ekle" << endl;
					cout << "2-Musteri  Sil" << endl;
					cout << "3-Musterileri Listele" << endl;
					cout << "99-Ust Menu" << endl;
					cout << "Seciminiz :";
					cin >> secim2;
					switch (secim2)
					{
					case 1: MusterikayitEkle(); break;  //alt menü başlıklarındaki işlemler yapıldı
					case 99:break;
					case 2:cout << "Silmek istediginiz Musteri No :"; cin >> m.MusteriNo;
						MusterikayitSil(m.MusteriNo); break;
					case 3:MusterikayitListele(); break;
					default:cout << "Hatali Secim" << endl; //belirtilenlerin dışında değer seçilirse uyarı mesajı 
						system("pause");
						break;
					}
					break;
				case 3:		//3.seçenek seçildiği zaman çıkacak menüyü oluşturdum
					cout << "1-Oda Kaydi ekle" << endl;
					cout << "2-Oda Kaydi  Sil" << endl;
					cout << "3-Kayitlari Listele" << endl;
					cout << "99-Ust Menu" << endl;
					cout << "Seciminiz :";
					cin >> secim2;
					switch (secim2)
					{
					case 1: OdakayitEkle(); break;		//alt menü başlıklarındaki işlemler yapıldı
					case 2:cout << "Silmek istediginiz Oda Kayit No :"; cin >> ok.odakayitno;
						OdakayitSil(ok.odakayitno); break;
					case 3:OdakayitListele(); break;
					case 99:break;  //menüden çıkmak için 
					default:cout << "Hatali Secim" << endl;   //belirtilenlerin dışında değer seçilirse uyarı mesajı 
						system("pause");
						break;
					}
					break;

				case 99:break; 
				default:cout << "Hatali Secim";
					system("pause");
					break;
				}
				break;
			} while (secim2 != 99);  //alt menüden çıkış
			
		} while (secim != 99);  //ana menüden çıkış 


		return 0;
	}


