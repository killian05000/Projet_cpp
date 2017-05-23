#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {

  private :
    uint side;
    uint radius;
    void ecrire (ostream &os) const override;

  public :
    Cercle(ulong color, uint x, uint y, uint side);
    Cercle(istream &is);
    ~Cercle();
    virtual void dessiner(EZWindow &w, bool isActive = false) const;
    inline uint getRadius() const {return radius;}
    inline uint getSide() const {return side;}
    inline void setSide (uint _side) { side = _side;}
    double perimetre() const override;
};

#endif // CERCLE_HPP
