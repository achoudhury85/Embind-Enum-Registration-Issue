#include <iostream>
#include <emscripten/bind.h>
#include <stdexcept>

using namespace emscripten;

enum class Enum1 : uint8_t
{
  Value1,
  Value2,
  Value3,
  Value4,
  Value5,
  Count
};

enum class Enum2 : uint8_t
{
  Value1,
  Value2,
  Value3,
  Count
};

template<class T>
T GetEnum(unsigned int value)
{
    if (value >= static_cast<unsigned int>(T::Count))
    {
        throw new std::invalid_argument("Invalid value passed in!!!");
    }

    return static_cast<T>(value);
}

// Instantiate templates
template<Enum1>
Enum1 GetEnum(unsigned int value);

template<Enum2>
Enum2 GetEnum(unsigned int value);

EMSCRIPTEN_BINDINGS(test_embind)
{
  enum_<Enum1>("Enum1")
        .value("Value1", Enum1::Value1)
        .value("Value2", Enum1::Value2)
        .value("Value3", Enum1::Value3)
        .value("Value4", Enum1::Value4)
        .value("Value5", Enum1::Value5)
        ;

  enum_<Enum2>("Enum2")
      .value("Value1", Enum2::Value1)
      .value("Value2", Enum2::Value2)
      .value("Value3", Enum2::Value3)
      ;

  function("GetEnum1", &GetEnum<Enum1>);
  function("GetEnum2", &GetEnum<Enum2>);
}


