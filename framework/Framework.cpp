
#include "Framework.h"

Framework::Framework() {
}

Framework::~Framework() {
}

void Framework::divideyVenceras(Problema* p, Solucion* s){
	if (p->isCasoMinimo()){
		p->solver(s);
	}
	else{
		pair<Problema*,Problema*> subProblemas;
		pair<Solucion*,Solucion*> subSoluciones;
		subProblemas = p->descomponer();
		subSoluciones.first = s->getInstance();
		subSoluciones.second = s->getInstance();
		divideyVenceras(subProblemas.first, subSoluciones.first);
		divideyVenceras(subProblemas.second, subSoluciones.second);
		s->mezcla(subSoluciones);
	}
};

