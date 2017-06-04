#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

//#define Triangle MyTriangle

class Triangle : public Forme {
	private :
		uint x1, y1, x2, y2, x3, y3;
		void ecrire (ostream &os) const override;

	public :
		Triangle(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3);
		Triangle(istream &is);
		~Triangle();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		inline uint getx1() const { return x1; }
		inline uint getx2() const { return x2; }
		inline uint getx3() const { return x3; }
		inline uint gety1() const { return y1; }
		inline uint gety2() const { return y2; }
		inline uint gety3() const { return y3; }
		double perimetre () const override;
};
#endif
