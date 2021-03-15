#ifndef _MERGESORTS_
#define _MERGESORTS_

#include "../framework/Solucion.h"

class MergeSortS : public Solucion
{
public:
  MergeSortS();
  virtual ~MergeSortS();

  void resolver();
  void mezcla(pair<Solucion *, Solucion *>);
  Solucion *getInstance();

  void setValor(std::vector<int>);
  std::vector<int> getValor();

private:
  std::vector<int> array_;
};

#endif /* _MERGESORTS_ */