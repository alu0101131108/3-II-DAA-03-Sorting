#ifndef _QUICKSORTP_
#define _QUICKSORTP_

#include "../framework/Problema.h"
#include "QuickSortS.h"

class QuickSortP : public Problema
{
public:
  QuickSortP(std::vector<int> array);
  virtual ~QuickSortP();

  bool isCasoMinimo();
  pair<Problema *, Problema *> descomponer();
  void solver(Solucion *s);

private:
  std::vector<int> array_;
};

#endif /* _QUICKSORTP_ */