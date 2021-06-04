// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_COORDINATE_H_
#define INCLUDE_WHUODHS_COORDINATE_H_

#include <iostream>
#include <cmath>
#include <type_traits>
#include <array>
#include <initializer_list>

namespace Whuodhs
{
  template <typename T, unsigned int N>
    class Coordinate final
      {
    public:
      static_assert(
                    N > 0,
                    "Size of static-sized vector should be greater than zero."
      );
      static_assert(
                    std::is_floating_point<T>::value,
                    "Coordinate only can be instantiated with floating point types."
      );

      Coordinate();
      template <typename... Params>
        explicit Coordinate(Params... params);

      void set(const T& s);

      template <typename U>
      explicit Coordinate(const std::initializer_list<T>& lst);
      
      template <typename U>
        void set(const std::initializer_list<U>& lst);

      Coordinate(const Coordinate& other);

      void set(const Coordinate& other);

      template <typename U>
      Coordinate& operator=(const std::initializer_list<U>& lst);

      Coordinate& operator=(const Coordinate& other);

      const T& operator[](unsigned int i) const;

      T& operator[](unsigned int i);

    private:
      std::array<T, N> elements_;

      void setAt(unsigned int i, T v);
      };

  template <typename T, unsigned int N>
    Coordinate<T, N>::Coordinate()
      {
        for (auto& elem: _elements) {
            elem = static_cast<T>(0);
        }
      }

  template <typename T, unsigned int N>
    template <typename... Params>
    Coordinate<T, N>::Coordinate(Params... params)
      {
        static_assert(
                      sizeof...(params) == N,
                      "Invalid number of parameter."
        );
        setAt(0, params...);
      }

  template <typename T, unsigned int N>
    template<typename U>
    Coordinate<T, N>::Coordiante(const std::initializer_list<U>& lst)
      {
        set(lst);
      }

  template <typename T, unsigned int N>
    template <typename U>
    void Coordinate<T, N>::set(const std::initializer_list<U>& lst)
      {
        unsigned int i = 0;
        for (const auto& inputElem : lst)
          {
            _elements[i] = static_cast<T>(inputElem);
            ++i;
          }
      }

  template <typename T, unsigned int N>
    void Coordinate<T, N>::setAt(unsigned int i, T v)
      {
        _elements[i] = v;
      }
}
#endif
