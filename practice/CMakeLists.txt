cmake_minimum_required(VERSION 3.0.0)
project(OOPcourse VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# Установка директорий для исполняемых файлов и библиотек
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Указываем путь к OpenCV
# set(OpenCV_DIR "D:/opencv/opencv/build") # <---- point out your own ABSOLUTE PATH to OpenCV if it needed
find_package(OpenCV REQUIRED)

# Подключение директории include
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}  # Добавляем директорию заголовков OpenCV
)

# Определение исходных файлов для статической библиотеки
file(GLOB lib_src
    "src/*.cpp"
)

# Создание статической библиотеки
add_library(${PROJECT_NAME} STATIC
    ${lib_src}
)

# Линковка библиотеки с OpenCV
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
)

# Подключение директорий заголовков
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# Определение исходных файлов для исполняемого файла
file(GLOB src_files
    "*.cpp"
)

# Создание исполняемого файла
add_executable(runner ${src_files})

# Линковка исполняемого файла с библиотекой
target_link_libraries(runner
    ${PROJECT_NAME}
    ${OpenCV_LIBS}  # Линковка с OpenCV
)


