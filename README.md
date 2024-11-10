# OOPcourse Project

This project demonstrates a simple drawing application using basic shapes to create an image. 
It utilizes CMake for building and OpenCV for handling the display of the created image.

## Prerequisites

- **OpenCV**: Make sure OpenCV is installed on your system. You can download it from [OpenCV's official website](https://opencv.org/releases/).
  - On Windows, you might need to set the `OpenCV_DIR` environment variable to point to the OpenCV installation path if it is not found automatically by CMake.

## Project Structure

- **`CMakeLists.txt`**: Contains the configuration for building the project with CMake.
- **`src/`**: Contains source files for the project.
- **`include/`**: Contains header files for the project.
- **`main.cpp`**: The main file where the drawing code is located.

## Getting Started

1. **Clone the repository**:
    ```powershell
    git clone git@github.com:LeinMS/hse-oop-project.git
    ```

2. **Set Up OpenCV Path (if needed)**:
   - If OpenCV is not found automatically, you might need to set the `OpenCV_DIR` environment variable.
   - Open PowerShell and set the path:
     ```powershell
     $env:OpenCV_DIR = "D:/opencv/opencv/build"  # Adjust this path to your OpenCV installation directory
     ```

3. **Configure and Build the Project with CMake**:
   - First, create a build directory and navigate into it:
     ```powershell
     mkdir build
     cd build
     ```

   - Configure the project with CMake:
     ```powershell
     cmake ..
     ```

   - Build the project:
     ```powershell
     cmake --build . --config Release
     ```

4. **Run the Project**:
   - After building, navigate to the output directory to run the executable:
     ```powershell
     .\bin\Release\runner.exe
     ```

## Sample Code for `main.cpp`

Below are the `main.cpp` code to draw a mushroom and house using basic shapes. Ensure you have the necessary header files (e.g., `rgb_matrix.h`, `bw_matrix.h`, `rectangle.h`, `circle.h`, `triangle.h`) in the `include/` directory.

```cpp
#include <iostream>
#include "rgb_matrix.h"
#include "bw_matrix.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int main() {
    // Set up colors for different parts of the mushroom
    int bgColor = 255;       // Background color (white)
    int capColor = 179;      // Mushroom cap color (light gray)
    int stipeColor = 128;    // Stipe (stem) color (gray)
    int bottomColor = 52;    // Bottom color (dark gray)

    // Create a black and white matrix for the drawing
    BWMatrix bw(1000, 1000, bgColor);  // 1000x1000 image with white background

    // Draw the mushroom cap
    BWColor bwColor(capColor);
    Circle cap({500, 500}, 350, bwColor);  // Cap in the center with radius 350

    // Background for the mushroom
    bwColor.changeColor(bgColor);
    Rectangle background({0, 350}, 1000, 500, bwColor);  // Background rectangle

    // Small rectangle under the cap
    Rectangle background2({400, 650}, 200, 100, bwColor);

    // Stipe (stem) of the mushroom
    bwColor.changeColor(stipeColor);
    Triangle stipe({500, 175}, {600, 750}, {400, 750}, bwColor);

    // Upper part of the stipe, aligned with the cap
    bwColor.changeColor(capColor);
    Rectangle background3({400, 175}, 200, 175, bwColor);

    // Bottom part of the mushroom stipe
    bwColor.changeColor(bottomColor);
    Circle bottom({500, 750}, 100, bwColor);

    // Draw all elements on the matrix
    bw.draw(cap);
    bw.draw(background);
    bw.draw(bottom);
    bw.draw(background2);
    bw.draw(stipe);
    bw.draw(background3);

    // Display the result
    bw.display();

    return 0;
}
```

```cpp
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
```
