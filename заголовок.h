#ifndef _�������_�
#define _�������_�
#include <SFML/Graphics.hpp>
#include <list>
using namespace sf;

class ��������� 
{	
public:   //��� ������ �������� ����� ���� � ���������

	virtual int GetX() = 0;								//�������� X ���������� �����
	virtual int GetY() = 0;								//�������� Y ���������� �����
	virtual void Show() = 0;							//�������� ������ �����
	virtual void Hide() = 0;							//�������� ������ �����
	virtual void ����������(RenderWindow& window) = 0;	//���������� ������ �����
	virtual void ��������������(int �) = 0;
	virtual void �����������(int NewX, int NewY)=0;		//����������� ������
	virtual void ����������(int Step)=0;				//���������� ������

};//end class Location

/*-----------------------  ����� �������������� -------------------------*/
class �������������� : public ���������
{
protected:		//������������� ����������� �������� (������������ 
				//������) ����� ������ � ������� ������
	int X;		//���������� X
	int Y;		//���������� Y

public:   //��� ������ �������� ����� ���� � ���������

	��������������(int InitX, int InitY);	//�����������
	��������������() {}						//�����������
	~��������������();						//����������
	virtual int GetX();								//�������� X ���������� �����
	virtual int GetY();								//�������� Y ���������� �����
	};//end class Location

/*-----------------------  ����� ����� ----------------------------------*/
class ����� : public ��������������
{
protected:							
	bool �����;		//�������� ����� ��� ���
	Sprite �����;
	Texture t;
public:
	�����(int InitX, int InitY, Texture& �����);	//����������� ������
	�����() {}										//����������� ������
	~�����();										//����������
	bool IsVisible();								//������ ��� ���������� �����
	//����������� �������
	virtual void �����������(int NewX, int NewY);	//����������� ������
	virtual void ����������(int Step);				//���������� ������
	virtual void Show();							//�������� ������ �����
	virtual void Hide();							//�������� ������ �����
	virtual void ����������(RenderWindow& window);	//���������� ������ �����
	virtual void ��������������(int �) {};

};//end class Point

/*-----------------------  ����� ������������� ----------------------------------*/
class ������������� : public �����
{
protected:
	int ������;
	int ������;

public:
	�������������(int InitX, int InitY, Texture& �����, int �, int �);				//����������� ������
	�������������() {}																//����������� ������
	~�������������();																//����������
	void Set(int InitX, int InitY, Texture& �����, int �, int �);					//�������� ������ ��������������
	//����������� �������
	virtual void ����������(RenderWindow& window);									//���������� ������ �����
	virtual void ����������(int Step) { �����::����������(Step); }					//���������� ������
	virtual void �����������(int NewX, int NewY) { �����::�����������(NewX, NewY); }//����������� ������
	virtual void Show() { �����::Show(); }											//�������� ������ �����
	virtual void Hide() { �����::Hide(); };											//�������� ������ �����
};//end class Point

/*-----------------------  ����� ����˨� ----------------------------------*/
class ����˨� : public �������������
{
protected:
	������������� ������;
	������������� �����;
	������������� �����;

public:
	����˨�(int InitX, int InitY, Texture& �����, int �);	//����������� ������
	~����˨�();						//����������

	//����������� �������
	virtual void ����������(RenderWindow& window);	//���������� ������ �����
	virtual void ����������(int Step);				//���������� ������
	virtual void �����������(int NewX, int NewY);	//����������� ������
	virtual void Show();							//�������� ������ �����
	virtual void Hide();							//�������� ������ �����
	virtual void ��������������(int �);				//�������� ������ �����
};//end class Point

#endif