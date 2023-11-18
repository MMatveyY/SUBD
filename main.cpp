#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Метод, возвращающий заполненный пользователем массив.
 * @param size_ размер массива.
 * @return заполненный массив.
 */
int *InputArray(const size_t size_);

/**
 * @brief Вывод массива на консоль.
 * @param array массив.
 * @param size_ размер массива.
 */
string ToString(const int *array, const size_t size_);

/**
 * @brief сортировка .
 * @param array массив.
 * @param size_ размер массива.
 * @return отсортированный массив.
 */
int Sorting(int *array, const size_t size_);

/**
 * @brief ввод и проверка на корректное число элементов массива.
 * @param message вывод определённой фразы при выполнении.
 * @param size размер массива.
 */
size_t GetSize(const std::string &message);

/**
 * @brief поиск наименьшего числа в массиве.
 * @param array массив.
 * @param size_ размер массива.
 * @param start начальная позиция.
 * @return индекс наименьшего числа.
 */
int FindSmallestPosition(int *array, int start, const size_t size_);

int main() {

  try {
    size_t sizeArr;

    sizeArr = GetSize("Input size array: ");

    size_t size = sizeArr;
    int *NewArray = nullptr;

    NewArray = InputArray(size);

    cout << ToString(NewArray, size);

    Sorting(NewArray, size);

    cout << ToString(NewArray, size);

    if (NewArray != nullptr) {
      delete[] NewArray;
      NewArray = nullptr;
    }

  } catch (const std::invalid_argument &e) {
    std::cout << "Ошибка: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}

size_t GetSize(const std::string &message) {
  int size = -1;
  std::cout << message;
  std::cin >> size;

  if (size <= 0) {
    throw std::out_of_range(
        "Incorrect size. Value has to be greater or equal zero.");
  }
  size_t newSize = static_cast<size_t>(size);

  return newSize;
}

int *InputArray(const size_t size_) {

  int *array = new int[size_];

  cout << "Введите данные в массив\n";

  for (size_t index = 0; index < size_; index++) {
    cin >> array[index];
  }

  return array;
}

string ToString(const int *array, const size_t size_) {
  std::stringstream buffer{};

  for (size_t index = 0; index < size_; index++) {
    buffer << array[index] << " ";
  }
  buffer << "\n";

  return buffer.str();
}

int findSmallestPosition(int *array, int start, const size_t size_)
{
  size_t smallestPosition = static_cast<size_t>(start);
  for(int i = start; i < size_; i++)
  {
    if(array[i] < array[smallestPosition])
      smallestPosition = i;
  }
  return smallestPosition;
}

int Sorting(int *array, const size_t size_) {	
  for(int i = 0; i < size_; i++)
  {
    int smallestPosition = findSmallestPosition(array, i, size_);
    swap(array[i], array[smallestPosition]);
  }
  return *array;
}
