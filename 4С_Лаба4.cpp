#include "заголовок.h"

int main() {

	RenderWindow window(sf::VideoMode(1280, 720), L"Убийца гоблинов", Style::Close);	//экран


	//фон  и мыш
	Texture d, t;
	Sprite фон;
	t.loadFromFile("Текстуры/персонажи/точка.png");
	фон.setTextureRect(IntRect(0, 0, 1280, 720));
	
	//вспомогательные переменные
	std::list<Интерфейс*> объекты;			//лист обьектов
	std::list<Интерфейс*>::iterator it;		//итератор для листа
	объекты.push_back(new Точка(0, 0, t));
	объекты.push_back(new САМАЛЁТ(0, 0, t, 100));

	bool t1 = 0;
	bool t2 = 0;
	bool t3 = 0;
	bool t4 = 0;
	bool t5 = 0;
	bool t6 = 0;
	bool t7 = 0;
	bool t8 = 0;
	bool t9 = 0;
	bool t10 = 0;

	Event event;//датчик событий
	while (window.isOpen())
	{
		//заставка
		 {
			/************  НАСТРОЙКИ ЭКРАНА  ***********/
			 {
				 d.loadFromFile("Текстуры/maxresdefault.jpg");
				 фон.setTexture(d);
				 window.draw(фон);

				 while (window.pollEvent(event))//обработка событий
				 {
					 //закрываем окно
					 if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::K))
						 window.close();
				 } 

			 }
			 /************  УПРОВЛЕНИЕ  ***********/
			 {
				 if (Keyboard::isKeyPressed(Keyboard::E))//покозать точку
					 t1 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::R))//показать точку на новом месте
					 t2 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::T))//перемещать точку
					 t3 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::Y))//перестать перемещать точку
					 t3 = 0;
				 if (Keyboard::isKeyPressed(Keyboard::U))// скрыть точку
					 t4 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::I))//покозать самалёт
					 t5 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::O))//показать самалёт на новом месте
					 t6 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::P))//перемещать самалёт
					 t7 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::F))//перестать перемещать самалёт
					 t7 = 0;
				 if (Keyboard::isKeyPressed(Keyboard::G))//скрыть самалёт
					 t8 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::H))//увеличить самалёт
					 t9 = 1;
				 if (Keyboard::isKeyPressed(Keyboard::J))//уменьшить самалёт
					 t10 = 1;
			 }
			/************  Т О Ч К А  ***********/
			 {
				 it = объекты.begin();
				 if (t1)//покозать точку
				 {
					 (*it)->Show();
					// точка.Show();  
					 t1 = 0;
				 }

				 if (t2)//показать точку на новом месте
				 {
					 (*it)->Переместить(100, 100);
					 //точка.Переместить(100, 100);  
					 t2 = 0;
				 }

				 if (t3)//перемещать точку
					 (*it)->Упровление(1);
					 //точка.Упровление(1);  

				 if (t4)//скрыть точку
				 {
					 (*it)->Hide();
					 //точка.Hide();  
					 t4 = 0;
				 }
			 
			 }
			/************  ФИГУРА   ***********/
			 {
				 it++;
				 if (t5)//покозать самалёт
				 {
					 (*it)->Show();
					// самалёт.Show();  
					 t5 = 0;
				 }

				 if (t6)//показать самалёт на новом месте
				 {
					 (*it)->Переместить(100, 100);
					 //самалёт.Переместить(100, 100);  
					 t6 = 0;
				 }

				 if (t7)//перемещать самалёт
					 (*it)->Упровление(5);
					// самалёт.Упровление(5);  

				 if (t8)//скрыть самалёт
				 {
					 (*it)->Hide();
					// самалёт.Hide();  
					 t8 = 0;
				 }

				 if (t9)//увеличить самалёт
				 {
					 (*it)->ИзменитьРазмер(300);
					// самалёт.ИзменитьРазмер(300);  
					 t9 = 0;
				 }

				 if (t10)//уменьшить самалёт
				 {
					 (*it)->ИзменитьРазмер(100);
					 // самалёт.ИзменитьРазмер(100);  
					 t10 = 0;
				 }
			 }
			

			//===================================================================

			//отображаем обьекты
			 for (it = объекты.begin(); it != объекты.end(); it++)
				(*it)->Отобразить(window);
				 
			//точка.Отобразить(window);
			//самалёт.Отобразить(window);
			window.display();
		}
	}
	//освоюождение памяти
	for (it = объекты.begin(); it != объекты.end();)
	{
		Интерфейс* т = *it;
		it = объекты.erase(it);
		delete т;
	}
	return 0;
}