#include<iostream>

#include "transicionesDFA.h"


/// Sobrecargas
bool operator==(const TrancisionesDFA& trancision1, const TrancisionesDFA& trancision2) {
  return trancision1.getEstadoActual() == trancision2.getEstadoActual() && trancision1.getSimbolo() == trancision2.getSimbolo() && trancision1.getEstadoSiguiente() == trancision2.getEstadoSiguiente();
}

bool operator!=(const TrancisionesDFA& trancision1, const TrancisionesDFA& trancision2) {
  return !(trancision1 == trancision2);
}

bool operator<(const TrancisionesDFA& trancision1, const TrancisionesDFA& trancision2) {
  return trancision1.getEstadoActual() < trancision2.getEstadoActual() || (trancision1.getEstadoActual() == trancision2.getEstadoActual() && trancision1.getSimbolo() < trancision2.getSimbolo()) || (trancision1.getEstadoActual() == trancision2.getEstadoActual() && trancision1.getSimbolo() == trancision2.getSimbolo() && trancision1.getEstadoSiguiente() < trancision2.getEstadoSiguiente());
}

bool operator>(const TrancisionesDFA& trancision1, const TrancisionesDFA& trancision2) {
  return trancision2 < trancision1;
}

std::ostream& operator<<(std::ostream& out, const TrancisionesDFA& trancision) {
  out << "Simbolo: " << trancision.getSimbolo() << " -> ";
  
  for (const auto& estado : trancision.getEstadoSiguiente()) {
    out << estado.get_identificador();
  }

  out << std::endl;
  return out;
}