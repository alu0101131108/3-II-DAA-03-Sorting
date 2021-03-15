#include <iostream>
#include "QuickSortS.h"

QuickSortS::QuickSortS() : Solucion::Solucion()
{
}

QuickSortS::~QuickSortS()
{
}

void QuickSortS::resolver()
{
  for (int i = 0; i < array_.size(); i++)
  {
    std::cout << "[" << array_[i] << "]";
  }
  std::cout << std::endl;
}

void QuickSortS::mezcla(pair<Solucion *, Solucion *> subSoluciones)
{ 
  std::vector<int> arr1 = (((QuickSortS *)subSoluciones.first))->getValor();
  std::vector<int> arr2 = ((QuickSortS *)subSoluciones.second)->getValor();
  array_.insert(array_.begin(), arr1.begin(), arr1.end());
  array_.insert(array_.end(), arr2.begin(), arr2.end());
}

Solucion *QuickSortS::getInstance()
{
  return new QuickSortS();
}

void QuickSortS::setValor(vector<int> array)
{
  array_ = array;
}

std::vector<int> QuickSortS::getValor()
{
  return array_;
}
