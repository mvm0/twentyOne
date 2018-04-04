#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

char karty[][35] = {
	"6 черви",
	"6 пики",
	"6 крести",
	"6 буби",
	"7 черви",
	"7 пики",
	"7 крести",
	"7 буби",
	"8 черви",
	"8 пики",
	"8 крести",
	"8 буби",
	"9 черви",
	"9 пики",
	"9 крести",
	"9 буби",
	"10 черви",
	"10 пики",
	"10 крести",
	"10 буби",
	"Валет черви",
	"Валет пики",
	"Валет крести",
	"Валет буби",
	"Дама черви",
	"Дама пики",
	"Дама крести",
	"Дама буби",
	"Король черви",
	"Король пики",
	"Король крести",
	"Король буби",
	"Туз черви",
	"Туз пики",
	"Туз крести",
	"Туз буби"
};

int i = 0, c = 0, ochki = 0, isumma = 0, csumma = 0, us = 1, kmax = 0;
int arr[35];
char e, m;

int glmain();
int igrok();
int computer();
int winer();
int nachzan();
int igra();

int nastroyki();
int spravka();


int main()
{
	setlocale(0, "rus");
	glmain();

	return 0;
}

int glmain()
{
	system("cls");
	printf("%s %i %s", "                                  Меню"
		"\n\n\n\n\n                         1. Игра"
		"\n                         2. Настройка ->", us,
		"\n                         3. Справка"
		"\n                         4. Выход"
		"\n\n\n\nВыберите пункт меню: ");
	cin >> m;

	switch (m)
	{
	case '1':
		system("cls");
		igra();
		break;
	case '2':
		system("cls");
		nastroyki();
		break;
	case '3':
		system("cls");
		spravka();
		break;
	case '4':
		exit(1);
		break;
	default:
		system("cls");
		glmain();
		break;
	}

	return 0;
}

int igrok()
{
	printf("\nВаши карты: ");

	while (c <= 1)
	{
		srand((unsigned)time(NULL));

		do
		{
			i = rand() % 35;
		} while (arr[i] == 1);

		arr[i] = 1;

		kmax++;

		if (i == 0 || i == 1 || i == 2 || i == 3)     ochki = 6;
		if (i == 4 || i == 5 || i == 6 || i == 7)     ochki = 7;
		if (i == 8 || i == 9 || i == 10 || i == 11)   ochki = 8;
		if (i == 12 || i == 13 || i == 14 || i == 15) ochki = 9;
		if (i == 16 || i == 17 || i == 18 || i == 19) ochki = 10;
		if (i == 20 || i == 21 || i == 22 || i == 23) ochki = 2;
		if (i == 24 || i == 25 || i == 26 || i == 27) ochki = 3;
		if (i == 28 || i == 29 || i == 30 || i == 31) ochki = 4;
		if (i == 32 || i == 33 || i == 34 || i == 35) ochki = 11;

		isumma = isumma + ochki;

		printf("%s %s", "\n", karty[i]);
		c++;

		if (c == 2 && kmax <= 8)
		{
			printf("%s %i", "\nВаши очки: ", isumma);
			printf("\n\nЕщё? [y/n]: ");
			cin >> e;
			if (e == 'y') c = 1;
			if (e == 'n') c = 3;

		}
	}
	printf("%s %i", "\nВаши очки: ", isumma);

	return 0;
}


int computer()
{
	c = 0, i = 0, ochki = 0;

	printf("\n\n===========================================");
	printf("\nКарты компьютера: ");

	while (c <= 1)
	{

		do
		{
			i = rand() % 35;
		} while (arr[i] == 1);

		arr[i] = 1;

		if (i == 0 || i == 1 || i == 2 || i == 3)     ochki = 6;
		if (i == 4 || i == 5 || i == 6 || i == 7)     ochki = 7;
		if (i == 8 || i == 9 || i == 10 || i == 11)   ochki = 8;
		if (i == 12 || i == 13 || i == 14 || i == 15) ochki = 9;
		if (i == 16 || i == 17 || i == 18 || i == 19) ochki = 10;
		if (i == 20 || i == 21 || i == 22 || i == 23) ochki = 2;
		if (i == 24 || i == 25 || i == 26 || i == 27) ochki = 3;
		if (i == 28 || i == 29 || i == 30 || i == 31) ochki = 4;
		if (i == 32 || i == 33 || i == 34 || i == 35) ochki = 11;

		csumma = csumma + ochki;

		printf("%s %s", "\n", karty[i]);
		c++;

		switch (us)
		{
		case 1:
			if (csumma <= 15) c = 1;
			break;
		case 2:
			if ((csumma<isumma) && (isumma <= 21)) c = 1;
			else c = 3;
			if (csumma <= 12) c = 1;
			break;
		case 3:
			if ((csumma<isumma) && (isumma <= 21)) c = 1;
			else c = 3;
			if (csumma <= 12) c = 1;
			break;
		}


	}
	printf("%s %i", "\n\nОчки компьютера: ", csumma);

	return 0;
}

int winer()
{
	if ((isumma == 21) || (csumma == 21)) printf("\nОчко !");
	if (isumma>21) printf("\nУ Вас перебор !");
	if (csumma>21) printf("\nУ АИ перебор !");

	if ((isumma == csumma) || (isumma>21 && csumma>21)) printf("\nНичья !");

	if ((isumma>csumma &&isumma <= 21) || (csumma>21 && isumma <= 21))  printf("\nYOU WIN!");
	if ((csumma>isumma &&csumma <= 21) || (isumma>21 && csumma <= 21))  printf("\nCOMPUTER WIN!");

	return 0;
}


int igra()
{
	igrok();
	computer();
	winer();
	nachzan();

	return 0;
}



int nastroyki()
{
	system("cls");

	printf("\n\n\n "
		"              =============== Уровень сложности ================\n\n"
		"                                 1. Нормальный    \n\n"
		"                               2. Профи\n\n"
		"                                 3. Шулер  \n\n\n"
		"               ---================ Настройки =================---\n\n\n"
		"Выберите уровень сложности: ");

	scanf_s("%i", &us);

	if (us == 1 || us == 2 || us == 3) glmain();
	else nastroyki();

	return 0;
}


int spravka()
{
	e = 0;
	system("cls");
	cout << "Справка";

	cout << "\n\nВернутся в меню [y/n]: ";
	cin >> e;

	switch (e)
	{
	case 'y':
		glmain();
		break;
	case 'n':
		spravka();
		break;
	default:
		spravka();
		break;
	}

	return 0;
}

int nachzan()
{
	int k = 0;
	i = 0, m = 0, c = 0, ochki = 0, isumma = 0, csumma = 0, kmax = 0;

	do
	{
		arr[k] = 0;
		k++;
	} while (k <= 35);

	printf("\n\nЕщё? [y/n]: ");
	cin >> e;

	system("cls");

	switch (e)
	{
	case 'y':
		igra();
		break;
	case 'n':
		glmain();
		break;
	default:
		glmain();
		break;
	}

	return 0;
}
