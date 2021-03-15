#include <iostream>
#include "MergeSortS.h"

MergeSortS::MergeSortS() : Solucion::Solucion()
{
}

MergeSortS::~MergeSortS()
{
}

void MergeSortS::resolver()
{
  for (int i = 0; i < array_.size(); i++)
  {
    std::cout << "[" << array_[i] << "]";
  }
  std::cout << std::endl;
}

void MergeSortS::mezcla(pair<Solucion *, Solucion *> subSoluciones)
{
  std::vector<int> arr1 = (((MergeSortS *)subSoluciones.first))->getValor();
  std::vector<int> arr2 = ((MergeSortS *)subSoluciones.second)->getValor();
  std::vector<int> mergedArray;
  int i = 0, j = 0;
  int arr1Size = arr1.size();
  int arr2Size = arr2.size();
  while (i < arr1Size && j < arr2Size)
  {
    if (arr1[i] <= arr2[j])
    {
      mergedArray.push_back(arr1[i]);
      i++;
    }
    else 
    {
      mergedArray.push_back(arr2[j]);
      j++;
    }
  }
  while (i < arr1Size) 
  {
    mergedArray.push_back(arr1[i]);
    i++;
  }
  while (j < arr2Size)
  {
    mergedArray.push_back(arr2[j]);
    j++;
  }
  array_ = mergedArray;
  if (array_.size() != arr1Size + arr2Size) throw;
}

Solucion *MergeSortS::getInstance()
{
  return new MergeSortS();
}

void MergeSortS::setValor(vector<int> array)
{
  array_ = array;
}

std::vector<int> MergeSortS::getValor()
{
  return array_;
}
