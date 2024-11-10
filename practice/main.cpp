#include <iostream>
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

#include <iostream>
#include "rgb_matrix.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main() {
    // Создаем матрицу для изображения 1000x1000 пикселей с темным фоном
    RGBMatrix rgb(1000, 1000, 0); // Черный фон по умолчанию (ночь)

    // Ночное небо
    RGBColor rgbColor(10, 10, 50); // Темно-синий цвет для ночного неба
    Rectangle sky({0, 0}, 1000, 1000, rgbColor); 

    // Пол с травой
    rgbColor.changeColor(34, 139, 34); // Темно-зеленый цвет для травы
    Rectangle grass({0, 800}, 1000, 200, rgbColor); 

    // Луна
    rgbColor.changeColor(255, 255, 204); // Светло-желтый цвет для луны
    Circle moon({800, 200}, 80, rgbColor);

    // Кратеры на луне
    rgbColor.changeColor(210, 210, 170); // Более темный цвет для кратеров
    Circle crater1({780, 180}, 15, rgbColor);
    Circle crater2({820, 220}, 10, rgbColor);
    Circle crater3({790, 230}, 7, rgbColor);
    Circle crater4({830, 180}, 12, rgbColor);

    // Звезды
    rgbColor.changeColor(255, 255, 255); // Белый цвет для звезд
    Circle star1({150, 150}, 5, rgbColor);
    Circle star2({200, 300}, 3, rgbColor);
    Circle star3({400, 100}, 4, rgbColor);
    Circle star4({600, 200}, 3, rgbColor);
    Circle star5({700, 50}, 4, rgbColor);
    Circle star6({900, 300}, 5, rgbColor);

    // Горы с коричневым цветом и снежными вершинами
    rgbColor.changeColor(101, 67, 33); // Темно-коричневый цвет для гор
    Triangle mountain1({50, 800}, {300, 500}, {550, 800}, rgbColor);
    Triangle mountain2({450, 800}, {700, 550}, {950, 800}, rgbColor);

    // Снежные шапки на горах
    rgbColor.changeColor(255, 255, 255); // Белый цвет для снега
    Triangle snow1({260, 550}, {300, 500}, {340, 550}, rgbColor); // Переместил шапку вверх на гору
    Triangle snow2({660, 590}, {700, 550}, {740, 590}, rgbColor); // Переместил шапку вверх на гору

    // Дерево
    rgbColor.changeColor(139, 69, 19); // Коричневый цвет для ствола
    Rectangle trunk({600, 700}, 30, 100, rgbColor);

    rgbColor.changeColor(34, 139, 34); // Темно-зеленый цвет для листвы
    Circle foliage1({615, 680}, 50, rgbColor);
    Circle foliage2({590, 640}, 40, rgbColor);
    Circle foliage3({640, 640}, 40, rgbColor);

    // Рисуем все элементы на матрице
    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(moon);
    rgb.draw(crater1);
    rgb.draw(crater2);
    rgb.draw(crater3);
    rgb.draw(crater4);
    rgb.draw(star1);
    rgb.draw(star2);
    rgb.draw(star3);
    rgb.draw(star4);
    rgb.draw(star5);
    rgb.draw(star6);
    rgb.draw(mountain1);
    rgb.draw(mountain2);
    rgb.draw(snow1);
    rgb.draw(snow2);
    rgb.draw(trunk);
    rgb.draw(foliage1);
    rgb.draw(foliage2);
    rgb.draw(foliage3);

    // Отображаем результат
    rgb.display();

    return 0;
}
