#include "QuickSortP.h"

QuickSortP::QuickSortP(std::vector<int> array) : Problema::Problema()
{
  array_ = array;
}

QuickSortP::~QuickSortP()
{
}

bool QuickSortP::isCasoMinimo()
{
  return array_.size() <= 1;
}

pair<Problema *, Problema *> QuickSortP::descomponer()
{
  pair<Problema *, Problema *> subProblemas;
  int arrSize = array_.size();
  
  // QuickSort alg
  int pivotValue = array_[arrSize - 1];
  int pivotIndex, temp;
  int i = -1;
  for (int j = 0; j < arrSize; j++)
  {
    if (array_[j] < pivotValue)
    {
      i++;
      // swap array_[i] and array_[j]
      temp = array_[i];
      array_[i] = array_[j];
      array_[j] = temp;
    }
  }
  // swap array_[i + 1] and array_[arrSize - 1]
  temp = array_[i + 1];
  array_[i + 1] = array_[arrSize - 1];
  array_[arrSize - 1] = temp;
  pivotIndex = i + 1;

  std::vector<int> arr1, arr2;
  if (i + 1 == 0) // El pibote queda al principio del array resultante.
  {
    // Del inicio al pibote y del valor siguiente al pibote al final.
    arr1 = std::vector<int>(array_.begin(), array_.begin() + pivotIndex + 1);
    arr2 = std::vector<int>(array_.begin() + pivotIndex + 1, array_.end());
  }
  else 
  {
    // Del inicio al valor anterior al pibote, y del pibote al final.
    arr1 = std::vector<int>(array_.begin(), array_.begin() + pivotIndex);
    arr2 = std::vector<int>(array_.begin() + pivotIndex, array_.end());
  }

  subProblemas.first = new QuickSortP(arr1);
  subProblemas.second = new QuickSortP(arr2);
  return subProblemas;
}

void QuickSortP::solver(Solucion *s)
{
  ((QuickSortS *)s)->setValor(array_);
}
