/* cppbuch/k4/array2d/array2d.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <cassert>
#include <cstddef>
#include <iostream>

template <typename T> class Array2d {
public:
  Array2d(std::size_t z, std::size_t s)
      : zeilen{z}, spalten{s}, ptr{new T[z * s]} {}
  Array2d(std::size_t z, std::size_t s, const T& wert)
      : Array2d(z, s) {  // an obigen Konstruktor delegieren
    init(wert);
  }
  Array2d(const Array2d& a)
      : Array2d(a.zeilen,
                a.spalten) {  // an obigen Konstruktor delegieren
    std::size_t anzahl = zeilen * spalten;
    for (std::size_t i = 0; i < anzahl; ++i) {
      ptr[i] = a.ptr[i];
    }
  }

  ~Array2d() { delete[] ptr; }

  Array2d& operator=(const Array2d& arr) = delete;  // (noch) verbieten

  auto& assign(Array2d tmp) {
    swap(tmp);
    return *this;
  }

  auto getZeilen() const { return zeilen; }

  auto getSpalten() const { return spalten; }

  void init(const T& wert) {  // Alle Elemente mit wert initialisieren
    std::size_t anzahl = zeilen * spalten;
    for (std::size_t i = 0; i < anzahl; ++i) {
      ptr[i] = wert;
    }
  }

  const T& at(std::size_t z, std::size_t s) const {
    assert(z < zeilen && s < spalten);
    return ptr[z * spalten + s];
  }

  T& at(std::size_t z, std::size_t s) {
    assert(z < zeilen && s < spalten);
    return ptr[z * spalten + s];
  }

  void swap(Array2d& rhs) {
    std::size_t temp = zeilen;
    zeilen = rhs.zeilen;
    rhs.zeilen = temp;
    temp = spalten;
    spalten = rhs.spalten;
    rhs.spalten = temp;
    T* tempPtr = ptr;
    ptr = rhs.ptr;
    rhs.ptr = tempPtr;
  }

private:
  std::size_t zeilen;
  std::size_t spalten;
  T* ptr;
};

// Globale Funktion zur Ausgabe
template <typename T> void printArray(const Array2d<T>& a) {
  for (std::size_t z = 0; z < a.getZeilen(); ++z) {
    for (std::size_t s = 0; s < a.getSpalten(); ++s) {
      std::cout << a.at(z, s) << " ";
    }
    std::cout << '\n';
  }
}
#endif
