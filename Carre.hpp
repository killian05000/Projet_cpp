#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

class Carre : public Forme {

  private :
          uint side;
          void ecrire (ostream &os) const override;

  public :
          Carre(ulong color, uint x, uint y, uint side);
          Carre(istream &is);
          ~Carre();
          virtual void dessiner(EZWindow &w, bool isActive = false) const;

          inline uint getSide() const {return side;}
          inline void setSide (uint _side) { side = _side;}
          double perimetre() const override;
};

#endif // CARRE_HPP
