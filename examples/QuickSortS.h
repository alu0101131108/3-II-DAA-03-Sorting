#ifndef _QUICKSORTS_
#define _QUICKSORTS_

#include "../framework/Solucion.h"

class QuickSortS : public Solucion
{
public:
  QuickSortS();
  virtual ~QuickSortS();

  void resolver();
  void mezcla(pair<Solucion *, Solucion *>);
  Solucion *getInstance();

  void setValor(std::vector<int>);
  std::vector<int> getValor();

private:
  std::vector<int> array_;
};

#endif /* _QUICKSORTS_ */