// #include <iostream>
// #include "rgb_matrix.h"
// #include "bw_matrix.h"
// #include "rectangle.h"
// #include "circle.h"
// #include "triangle.h"

// int main() {
//     // Задаем цвета для различных частей изображения
//     int bgColor = 255;       // Цвет фона (белый)
//     int capColor = 179;      // Цвет "шляпки" (светло-серый)
//     int stipeColor = 128;    // Цвет "ножки" (серый)
//     int bottomColor = 52;    // Цвет "основания" (темно-серый)

//     // Создаем объект матрицы для черно-белого изображения с меньшим разрешением
//     BWMatrix bw(1000, 1000, bgColor);  // Изображение 1000x1000 пикселей с фоном bgColor (белый)

//     // Создаем и задаем цвет для шляпки гриба
//     BWColor bwColor(capColor);
//     Circle cap({500, 500}, 350, bwColor);  // Шляпка в центре (500, 500) радиусом 350

//     // Фон изображения
//     bwColor.changeColor(bgColor);
//     Rectangle background({0, 350}, 1000, 500, bwColor);  // Фон прямоугольника размером 1000x500

//     // Маленький прямоугольник под шляпкой
//     Rectangle background2({400, 650}, 200, 100, bwColor);

//     // Ножка гриба
//     bwColor.changeColor(stipeColor);
//     Triangle stipe({500, 175}, {600, 750}, {400, 750}, bwColor);

//     // Верхняя часть ножки (выровнена под шляпкой)
//     bwColor.changeColor(capColor);
//     Rectangle background3({400, 175}, 200, 175, bwColor);

//     // Основание ножки
//     bwColor.changeColor(bottomColor);
//     Circle bottom({500, 750}, 100, bwColor);

//     // Рисуем все элементы на матрице
//     bw.draw(cap);
//     bw.draw(background);
//     bw.draw(bottom);
//     bw.draw(background2);
//     bw.draw(stipe);
//     bw.draw(background3);

//     // Отображаем результат
//     bw.display();

//     return 0;
// }



#include <iostream>
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main() {
    // Создаем матрицу для изображения 1000x1000 пикселей с черным фоном
    RGBMatrix rgb(1000, 1000, 0); // Черный фон по умолчанию

    // Небо
    RGBColor rgbColor(102, 205, 255); // Голубой цвет
    Rectangle sky({0, 0}, 1000, 750, rgbColor); 

    // Трава
    rgbColor.changeColor(0, 153, 0); // Зеленый цвет
    Rectangle grass({0, 750}, 1000, 250, rgbColor); 

    // Солнце
    rgbColor.changeColor(255, 255, 0); // Желтый цвет
    Circle sun({150, 150}, 100, rgbColor); 

    // Лучи солнца
    Triangle ray1({250, 150}, {325, 135}, {325, 165}, rgbColor);
    Triangle ray2({200, 200}, {275, 235}, {260, 255}, rgbColor);
    Triangle ray3({150, 250}, {135, 325}, {165, 325}, rgbColor);

    // Стены дома
    rgbColor.changeColor(102, 51, 0); // Коричневый цвет
    Rectangle wall({300, 450}, 500, 400, rgbColor); 

    // Дымоход
    rgbColor.changeColor(0, 0, 0); // Черный цвет
    Rectangle flue({650, 275}, 50, 100, rgbColor);

    // Крыша дома
    rgbColor.changeColor(51, 0, 0); // Темно-коричневый цвет
    Triangle roof({280, 450}, {550, 250}, {820, 450}, rgbColor);

    // Дверь
    rgbColor.changeColor(204, 102, 0); // Оранжевый цвет
    Rectangle door({700, 675}, 75, 150, rgbColor); 

    // Ручка двери
    rgbColor.changeColor(0, 0, 0); // Черный цвет
    Circle knob({768, 750}, 3, rgbColor); 

    // Окна
    rgbColor.changeColor(102, 163, 255); // Голубой цвет для окон
    Rectangle window1({350, 475}, 150, 175, rgbColor);
    Rectangle window2({600, 475}, 150, 175, rgbColor); 

    // Рисуем все элементы на матрице
    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);

    // Отображаем результат
    rgb.display();

    return 0;
}

