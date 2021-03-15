#ifndef _MERGESORTP_
#define _MERGESORTP_

#include "../framework/Problema.h"
#include "MergeSortS.h"

class MergeSortP : public Problema
{
public:
  MergeSortP(std::vector<int>);
  virtual ~MergeSortP();

  bool isCasoMinimo();
  pair<Problema *, Problema *> descomponer();
  void solver(Solucion *s);

private:
  std::vector<int> array_;
};

#endif /* _MERGESORTP_ */