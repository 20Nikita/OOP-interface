#ifndef _МояИгра_Н
#define _МояИгра_Н
#include <SFML/Graphics.hpp>
#include <list>
using namespace sf;

class Интерфейс 
{	
public:   //эти методы доступны извне всем в программе

	virtual int GetX() = 0;								//получить X координату точки
	virtual int GetY() = 0;								//получить Y координату точки
	virtual void Show() = 0;							//показать фигуру ТОЧКА
	virtual void Hide() = 0;							//спрятать фигуру ТОЧКА
	virtual void Отобразить(RenderWindow& window) = 0;	//отобразить фигуру ТОЧКА
	virtual void ИзменитьРазмер(int а) = 0;
	virtual void Переместить(int NewX, int NewY)=0;		//переместить фигуру
	virtual void Упровление(int Step)=0;				//буксировка фигуры

};//end class Location

/*-----------------------  Класс МЕСТОПОЛОЖЕНИЕ -------------------------*/
class МЕСТОПОЛОЖЕНИЕ : public Интерфейс
{
protected:		//предоставляет возможность потомкам (производному 
				//классу) иметь доступ к частным данным
	int X;		//координата X
	int Y;		//координата Y

public:   //эти методы доступны извне всем в программе

	МЕСТОПОЛОЖЕНИЕ(int InitX, int InitY);	//конструктор
	МЕСТОПОЛОЖЕНИЕ() {}						//конструктор
	~МЕСТОПОЛОЖЕНИЕ();						//деструктор
	virtual int GetX();								//получить X координату точки
	virtual int GetY();								//получить Y координату точки
	};//end class Location

/*-----------------------  Класс ТОЧКА ----------------------------------*/
class Точка : public МЕСТОПОЛОЖЕНИЕ
{
protected:							
	bool Видна;		//светится точка или нет
	Sprite точка;
	Texture t;
public:
	Точка(int InitX, int InitY, Texture& Точка);	//конструктор класса
	Точка() {}										//конструктор класса
	~Точка();										//деструктор
	bool IsVisible();								//узнать про светимость точки
	//виртуальные функции
	virtual void Переместить(int NewX, int NewY);	//переместить фигуру
	virtual void Упровление(int Step);				//буксировка фигуры
	virtual void Show();							//показать фигуру ТОЧКА
	virtual void Hide();							//спрятать фигуру ТОЧКА
	virtual void Отобразить(RenderWindow& window);	//отобразить фигуру ТОЧКА
	virtual void ИзменитьРазмер(int а) {};

};//end class Point

/*-----------------------  Класс ПРЯМАУГОЛЬНИК ----------------------------------*/
class ПРЯМАУГОЛЬНИК : public Точка
{
protected:
	int длинна;
	int ширина;

public:
	ПРЯМАУГОЛЬНИК(int InitX, int InitY, Texture& Точка, int а, int б);				//конструктор класса
	ПРЯМАУГОЛЬНИК() {}																//конструктор класса
	~ПРЯМАУГОЛЬНИК();																//деструктор
	void Set(int InitX, int InitY, Texture& Точка, int а, int б);					//изменить размер прямаугольника
	//виртуальные функции
	virtual void Отобразить(RenderWindow& window);									//отобразить фигуру ТОЧКА
	virtual void Упровление(int Step) { Точка::Упровление(Step); }					//буксировка фигуры
	virtual void Переместить(int NewX, int NewY) { Точка::Переместить(NewX, NewY); }//переместить фигуру
	virtual void Show() { Точка::Show(); }											//показать фигуру ТОЧКА
	virtual void Hide() { Точка::Hide(); };											//спрятать фигуру ТОЧКА
};//end class Point

/*-----------------------  Класс САМАЛЁТ ----------------------------------*/
class САМАЛЁТ : public ПРЯМАУГОЛЬНИК
{
protected:
	ПРЯМАУГОЛЬНИК корпус;
	ПРЯМАУГОЛЬНИК крыло;
	ПРЯМАУГОЛЬНИК хвост;

public:
	САМАЛЁТ(int InitX, int InitY, Texture& Точка, int а);	//конструктор класса
	~САМАЛЁТ();						//деструктор

	//виртуальные функции
	virtual void Отобразить(RenderWindow& window);	//отобразить фигуру ТОЧКА
	virtual void Упровление(int Step);				//буксировка фигуры
	virtual void Переместить(int NewX, int NewY);	//переместить фигуру
	virtual void Show();							//показать фигуру ТОЧКА
	virtual void Hide();							//спрятать фигуру ТОЧКА
	virtual void ИзменитьРазмер(int а);				//спрятать фигуру ТОЧКА
};//end class Point

#endif