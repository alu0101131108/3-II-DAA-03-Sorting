#include "MergeSortP.h"

MergeSortP::MergeSortP(std::vector<int> array) : Problema::Problema()
{
  array_ = array;
}

MergeSortP::~MergeSortP()
{
}

bool MergeSortP::isCasoMinimo()
{
  return (array_.size() < 2);
}

pair<Problema *, Problema *> MergeSortP::descomponer()
{
  pair<Problema *, Problema *> subProblemas;
  int arrSize = array_.size();
  std::vector<int> arr1, arr2;
  for (int i = 0; i < arrSize; i++)
  {
    if (i < arrSize / 2)
    {
      arr1.push_back(array_[i]);
    }
    else
    {
      arr2.push_back(array_[i]);
    }
  }
  subProblemas.first = new MergeSortP(arr1);
  subProblemas.second = new MergeSortP(arr2);
  return subProblemas;
}

void MergeSortP::solver(Solucion *s)
{
  ((MergeSortS *)s)->setValor(array_);
}
